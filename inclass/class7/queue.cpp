//
// ** Make sure to use c++11 to compile, for example: g++ -std=c++11 queue.cpp -o Queue
// ** Or find and replace all instanes of nullptr for NULL
//

#include <iostream>

using namespace std;

class chunk 
{

protected:
 	int x;
 	const int chunkID;
 	chunk *nextChunk;
 	static int chunkCount;

public:
 	chunk (int xin = 0): x(xin), nextChunk(nullptr),chunkID(chunkCount)
 	{
 		chunkCount++;
 	}
 	~chunk()
 	{
 		nextChunk = nullptr;
 	}
 	const int getChunk()
 	{
 		return x;
 	}
 	void setChunk (const int value = 0)
 	{
 		x = value;
 	}
 	const int getChunkCount()
 	{
 		return chunkCount;
 	}
 	const int getChunkID()
 	{
 		return chunkID;
 	}
 	chunk * const getNext ()
 	{
 		return nextChunk;
 	}
 	void setNext(chunk * const in)
 	{
 		nextChunk = in;
 	}
 };
 
class Queue
{

protected:
	chunk *head;
	int capacity;
	
public:
	chunk * const getHead ()
	{
		return head;
	}
	void setHead (chunk * const in)
	{
		head = in;
	}
	const int getCapacity ()
	{
		return capacity;
	}
	Queue (int startSize = 0, int value = 0): capacity(startSize), head(nullptr)
	{
		enQueue(value,startSize);
	}
	~Queue ()
	{
		deQueue(capacity);
	}
	void enQueue (int value = 0, int amount = 1)
	{
			chunk *fast=head;
			for (unsigned int i = 0; i < amount; i += 1)
			{
				if(capacity == 0)
				{
					fast = new chunk(value);
					head = fast;
					capacity++;
				}
				else
				{
					while(fast->getNext()!=nullptr)
					{
						fast = fast->getNext();
					}
					fast->setNext(new chunk(value));
					capacity++;
				}
			}
	}
	void deQueue (int amount = 1)
	{
		for (unsigned int i = 0; i < amount; i += 1)
		{
			if (head !=nullptr)
			{
				chunk *temp = head;
				head = head->getNext();
				delete temp;
				capacity--;
			}
		}
	}
	const void display ()
	{
		chunk *displayptr = head;
		while ( displayptr != nullptr)
		{
			cout << "Chunk ID: " <<displayptr->getChunkCount() << ", Chunk x Value: " << displayptr->getChunk() << "\n";
			displayptr=displayptr->getNext();
		}
	}
};

int chunk::chunkCount = 0;

int main (int argc, char const* argv[])
{
Queue myQueue;
 int choice = 0;
 int value = 0;
 while(1)
 {
 	cout << "Push 1 to Enqueue\n";
 	cout << "Push 2 to Dequeue\n";
 	cout << "Push 3 to Display\n";
 	cout << "Push 4 to see how many chunks have been created and how many exist\n";
 	cout << "Push anything else to Quit\n\n";
 	cin >> choice;
 	cout << "\n";
 	switch (choice)
 	{
 		case 1:
 		cout << "Please enter a value followed by the number of chunks to be created with that value\n\n";
 		cin >> value;
 		cin >> choice;
 		cout << "\n";
 			myQueue.enQueue(value, choice);
 			break;
 		case 2:
 			cout << "Please enter the number of chunks to remove\n";
 			cin >> choice;
 			myQueue.deQueue(choice);
 			cout << "\n";
 			break;
 		case 3:
 			myQueue.display();
 			cout << "\n";
 			break;
 		case 4:
 			cout << "There have been " << myQueue.getHead()->getChunkCount() << " chunks created\n";
 			cout << "There are currently " << myQueue.getCapacity() << " chunks\n\n";
 			break;
 		default:
 			return 0;
 	}
 
 }
	return 0;
}

