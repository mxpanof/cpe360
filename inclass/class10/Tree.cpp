#include <iostream>
using namespace std;

class TreeChunk
{
public:
	int x;
	TreeChunk *left, *right, *parent;
	TreeChunk (int xin = 0): left(nullptr), right(nullptr), x(xin), parent(nullptr){}
};
class Tree
{
public:
	bool balanced;
	bool complete;
	int height;
	TreeChunk *root;
	Tree (): root(nullptr), height(1), balanced(true), complete(true){}
	void add (int val)
	{
		if(root == nullptr)
		{
			root = new TreeChunk(val);
			root->parent = nullptr;
			return;
		}
		
		TreeChunk *temp = root;
		while (temp->left !=nullptr && temp->right != nullptr)
		{
			if(val > temp->x)
				temp = temp->right;
			else if (val < temp->x)
				temp = temp->left;
		}
		if(val > temp->x)
		{
			temp->right = new TreeChunk (val);
			temp->right->parent = temp;
		}
		else if (val < temp->x)
		{
			temp->left = new TreeChunk (val);
			temp->left->parent = temp;
		}
		return;
	}
	TreeChunk * search (int val)
	{
		TreeChunk *temp = root;
		while (val != temp->x && temp !=nullptr)//->right !=nullptr && temp->left !=nullptr)
		{
			if(val > temp->x)
			{
				temp = temp->right;
				cout << "-->\n";
			}
			else if (val < temp->x)
			{
				temp = temp->left;
				cout << "<--\n";
			}
			if (val == temp->x)
			return temp;
		}
		return temp;
	}
	
};
int main (int argc, char const* argv[])
{
	Tree myOak;
	myOak.add(75);
	myOak.add(25);
	myOak.add(49);
	myOak.add(51);
	myOak.add(50);
	myOak.search(51);
	return 0;
}
