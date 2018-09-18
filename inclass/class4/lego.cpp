#include <iostream>
#include <vector>
using namespace std;

class legoChunk
{
	public:
	int x, y;
	legoChunk * next, *prev;
	legoChunk (int xin = 0, int yin = 0):x(xin),y(yin)
	{
		next=prev=NULL;
	}
};

int main ()
{
	vector<legoChunk> legoList;
	legoChunk * ptr;
	ptr = new legoChunk;
	ptr->x = 50;
	ptr->y = 90;
	legoList.push_back(*ptr);
	legoChunk * prevPtr;
	prevPtr = ptr;
	ptr->next=new legoChunk;
	ptr = ptr->next;
	ptr->prev = prevPtr;
	
	return 1;
}
