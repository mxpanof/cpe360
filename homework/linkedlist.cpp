#include <iostream>
using namespace std;

class Chunk
{
public:
	int x;
	Chunk *next;
	Chunk (int xin=0):x(xin),next(nullptr){}
};

class LL
{
public:
	int cap;
	Chunk *head;
	LL(int startCap = 0):cap(startCap),head(nullptr){}
	void insert (int value, unsigned int pos)
	{
		if (pos<=cap+1)
		{	
			if (head == nullptr)
			{
				head = new Chunk(value);
				cap++;
				return;
				//cout << "hi";
			}
			else {
			Chunk *placer = head;
			Chunk *adder = new Chunk(value);
			//cout << "hi";
			for(int i = 0; i<pos-1 && placer->next != nullptr; i++)
			{
				placer = placer->next;
			//cout << "hi";
			}
			adder->next = placer->next;
			placer->next = adder;
			cap++;
			}
		}
		else
			cout << "Bad insert Posistion\n";
		return;
	}
	void remove (unsigned int pos)
	{
		if (pos <= cap)
		{
			Chunk *placer = head;
			Chunk *remover;
			for (unsigned int i = 0; i < pos; i++)
			{
				placer = placer->next;
			}
						//cout << "hi\n";
			if (head == nullptr)
			{
				//delete head;
				//head = nullptr;
				//cap--;
							//cout << "hi\n";
				return;
			}
			remover = placer;
			//cout << "hi\n";
			if (remover == head)
			{
				head = head->next;
				delete remover;
				cap--;
				return;
			}
			if (remover->next == nullptr)
			{
			
				head = nullptr;
				delete remover;
				cap--;
				return;
			}
			
			delete remover;
			placer = placer->next;
			cap--;
						//cout << "hi\n";
		}
	}
	void display()
	{
		
		if (head != nullptr)
		{
		Chunk * temp = head;
		while (temp->next !=nullptr)
		{
			cout << temp->x << "\n";
			temp = temp->next;
		}
		cout << temp->x << "\n"  << "\n";
		}
	}
	
};

int main (int argc, char const* argv[])
{
	LL myLL;
	int choice = 0;
 	int value = 0;
 while(1)
 {
 	cout << "Push 1 to add\n";
 	cout << "Push 2 to remove\n";
 	cout << "Push 3 to Display\n";
 	//cout << "Push 4 to see how many chunks have been created and how many exist\n";
 	cout << "Push anything else to Quit\n\n";
 	cin >> choice;
 	cout << "\n";
 	switch (choice)
 	{
 		case 1:
 		cout << "Please enter a value followed by the position to be created with that value\n\n";
 		cin >> value;
 		cin >> choice;
 		cout << "\n";
 			myLL.insert(value, choice);
 			break;
 		case 2:
 			cout << "Please enter chunks to remove\n";
 			cin >> choice;
 			myLL.remove(choice);
 			cout << "\n";
 			break;
 		case 3:
 			myLL.display();
 			cout << "\n";
 			break;
 		/*case 4:
 			cout << "There have been " << myQueue.getHead()->getChunkCount() << " chunks created\n";
 			cout << "There are currently " << myQueue.getCapacity() << " chunks\n\n";
 			break;*/
 		default:
 			return 0;
 	}
 
 }
	return 0;
}

