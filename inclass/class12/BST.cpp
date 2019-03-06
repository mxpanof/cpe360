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
	int count;
	int height;
	TreeChunk *root;
	Tree (): root(nullptr), height(0), balanced(true){}
	void add (int val)
	{
		if(root == nullptr)
		{
			root = new TreeChunk(val);
			root->parent = nullptr;
			height++;
			return;
		}
		if (search(val) != nullptr)
		{
			cout << "found! \n";
			return;
		}
		else
		{
			TreeChunk *temp = root;
			while (temp != nullptr)
			{
				if (val == temp->x)
				{
					cout << "found! \n";
					return;
				}
				else if(val < temp->x)
				{
					if (temp->left != nullptr)
						temp = temp->left;
					else
					{
						cout << "not found \n";
						temp->left = new TreeChunk(val);
						temp->left->parent = temp;
						return;
					}
				}
				else 
				{
					if (temp->right != nullptr)
						temp = temp->right;
					else
					{
						cout << "not found \n";
						temp->right = new TreeChunk(val);
						temp->right->parent = temp;
						return;
					}
				}
			}
		}
	}
	TreeChunk * search (int val)
	{
		TreeChunk *temp = root;
		if(temp == nullptr)
		{
			cout << "not found \n";
			return nullptr;
		}
		else
		{
			while (temp != nullptr)
			{
				if (val == temp->x)
				{
					cout << "found! \n";
					return temp;
				}
				else if(val < temp->x)
				{
					if (temp->left != nullptr)
						temp = temp->left;
					else
					{
						cout << "not found \n";
						return nullptr;
					}
				}
				else 
				{
					if (temp->right != nullptr)
						temp = temp->right;
					else
					{
						cout << "not found \n";
						return nullptr;
					}
				}
			}
		}
	}
	void preOrderTraversal (TreeChunk *start)
	{
		if(start == nullptr)
			return;
		else
		{
			cout << start->x << " \n";
			preOrderTraversal (start->left);
			preOrderTraversal (start->right);
		}
	}
	void postOrderTraversal (TreeChunk *start)
	{
		if(start == nullptr)
			return;
		else
		{
			postOrderTraversal (start->left);
			postOrderTraversal (start->right);
			cout << start->x << " \n";
		}
	}
	void inOrderTraversal (TreeChunk *start)
	{
		if(start == nullptr)
			return;
		else
		{
			inOrderTraversal (start->left);
			cout << start->x << " \n";
			inOrderTraversal (start->right);
		}
	}
	void deleteTreeChunk (int val, TreeChunk * start)
	{
		TreeChunk * temp = search(val);
		if (temp == nullptr)
		{
			cout << "not found \n";
			return;
		}
		else if (temp->left ==nullptr && temp->right == nullptr)
		{
			if (temp->parent->left == temp)
			{
				temp->parent->left = nullptr;
			}
			else if (temp->parent->right == temp)
			{
				temp->parent->right = nullptr;
			}
			delete temp;
			cout << "Deleted leaf \n";
			return;
		}
		else if (temp->right ==nullptr)
		{
			temp->left->parent = temp->parent;
			temp->parent->left = temp->left;
			delete temp;
			cout << "deleted branch \n";
			return;
		}
		else if (temp->left ==nullptr)
		{
			temp->right->parent = temp->parent;
			temp->parent->right = temp->right;
			delete temp;
			cout << "deleted branch \n";
			return;
		}
		else 
		{
			TreeChunk * min = getMinRightSubTree (temp);
			temp->x = min->x;
			cout << "deleted fork \n";
			if(min->parent != root)
				min->parent->left = nullptr;
			else if(min->parent ==root)
				min->parent->right = nullptr;
			delete min;
			return;
			
		}
		
	}
	TreeChunk * getMinRightSubTree ( TreeChunk* start)
	{
		TreeChunk * temp = start->right;
		while (temp != nullptr)
		{
			if (temp->left != nullptr)
				temp = temp->left;
			else
			{
				cout << "found min \n";
				return temp;
			}
		}
		return temp;
	}
	
};
int main (int argc, char const* argv[])
{
	int choice;
	Tree myOak;
	while(1)
	{
	cout << "Press 1 to add \n";
	cout << "Press 2 to search \n";
	cout << "Press 3 to display \n";
	cout << "Press 4 to delete \n";
	cout << "Press 5 to exit \n";
	cin >> choice;
	switch (choice)
	{
		case 1:
			cout << "add what? \n";
			cin >> choice;
			myOak.add (choice);
			break;
		case 2:
			cout << "look for what? \n";
			cin >> choice;
			myOak.search (choice);
			break;
		case 3:
			cout << "\n";
			myOak.preOrderTraversal (myOak.root);
			break;
		case 4:
			cout << "delete what? \n";
			cin >> choice;
			myOak.deleteTreeChunk (choice, myOak.root);
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "try again, bad input \n";
			break;
	}
	}
	return 0;
}
