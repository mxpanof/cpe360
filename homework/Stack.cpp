//
// ** Make sure to use c++11 to compile, aka g++ -std=c++11 play.cpp -o Play
//
#include <iostream>
using namespace std;

class chunk {
 public:
 	static int chunkCount;
 	int x;
 	chunk *next;
 	chunk (int xin = 0): x(xin), next(nullptr)
 	{
 		chunkCount++;
 	}
 	~chunk()
 	{
 		next =nullptr;
 	}
 	int readChunk()
 	{
 		return x;
 	}
 	void setChunk (int value = 0)
 	{
 		x = value;
 	}
 	int readChunkCount()
 	{
 		return chunkCount;
 	}
 	
 };
int chunk::chunkCount = 0;
class Stack
{
public:
	chunk *top;
	int capacity;
	Stack (int startSize = 0): capacity(startSize), top(nullptr)
	{
		pushChunk(startSize);
	}
	~Stack ()
	{
		pullChunk(capacity);
	}
	void pushChunk (int amount = 1, int value = 0)
	{
		chunk *temp;
		for (unsigned int i = 0; i < amount; i += 1)
		{
			temp = new chunk;
			temp->next = top;
			top = temp; 
			top->setChunk(value);
			capacity++;
		}
	}
	int pullChunk(int amount = 1)
	{
	
		chunk *temp;
		for (unsigned int i = 0; i < amount; i += 1)
		{
			if (capacity != 0)
			{
				temp = top;
				cout << top->readChunk() << " " << top->readChunkCount() << "\n";
				top = top->next;
				delete temp;
				capacity--;
			}
			else
			{
				top = nullptr;
				break;
			}
		}
	}
	void display ()
	{
		chunk *displayptr = top;
		while ( displayptr != nullptr)
		{
			cout << displayptr->readChunk() << " " << displayptr->readChunkCount() << "\n";
			displayptr=displayptr->next;
			
		}
	}
	
};
int main (int argc, char const* argv[])
{
	/*chunk * head, *temp;
 	head = new chunk;
 	temp = new chunk;
 	temp->next = head;
 	head = temp;
 	temp = new chunk;
 	temp->next = head;
 	head = temp;
 	
 	temp = head;
 	head = head->next;
 	delete temp;*/
 Stack myStack;
 int choice = 0;
 int value = 0;
 while(1)
 {
 	cout << "Push 1 to Push\n";
 	cout << "Push 2 to Pull\n";
 	cout << "Push 3 to display\n";
 	cout << "Push 4 to anything eles to quit\n";
 	cin >> choice;
 	switch (choice)
 	{
 		case 1:
 		cout << "enter amount and value for all new chunks to have\n";
 		cin >> choice;
 		cin >> value;
 			myStack.pushChunk(choice, value);
 			break;
 		case 2:
 			myStack.pullChunk();
 			break;
 		case 3:
 			myStack.display();
 			break;
 		default:
 			return 0;
 	}
 
 }
	return 0;
}

