#include <iostream>
using namespace std;

class chunk 
{
public:
	int value;
	chunk*next;
	chunk(int xin=0):value(xin),next(nullptr){}
};
class Queue{
public:
	chunk* head;
	int capacity;
	Queue():head(nullptr),capacity(0){}
	void enqueue (int x)
	{
		if (head==nullptr)
			head = new chunk;
		else
		{
			chunk * temp = new chunk(x);
			temp->next = head;
			head = temp;
		}
		capacity++;
	}
	void dequeue()
	{

		if(head->next == nullptr)
		{
			delete head;
			head = nullptr;
			capacity--;
		}
		else if(head!=nullptr)
		{
			chunk*temp = head->next;
			while (temp->next->next!=nullptr)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}
		else
			cout << "empty\n";
		
	}
	};
int main (int argc, char const* argv[])
{
	Queue myqueue;
	myqueue.enqueue(3);
	myqueue.enqueue(4);
	myqueue.dequeue();
	return 0;
}
