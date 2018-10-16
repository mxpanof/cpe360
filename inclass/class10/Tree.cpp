#include <iostream>
using namespace std;

class TreeChunk
{
	int x;
	TreeChunk *left, *right, *parent;
	TreeChunk (int xin = 0): left(nullptr), right(nullptr), x(xin), parent(nullptr){}
};
class Tree
{
	bool balanced;
	bool complete;
	int height;
	TreeChunk *root;
	Tree (int rootVal): root = new TreeChunk(rootVal), height(1), balanced(true), complete(true){}
	
};
