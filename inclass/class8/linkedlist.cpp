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
			}
			Chunk *placer = head;
			Chunk *adder = new Chunk(value);
			for(int i = 0; i<pos-1 && placer->next != nullptr; i++)
			{
				placer = placer->next;
			}
			adder->next = placer->next;
			placer->next = adder;
			cap++;
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
			if (head == nullptr)
			{
				//delete head;
				//head = nullptr;
				//cap--;
				return;
			}
			remover = placer->next;
			if (remover == nullptr)
			{
				head = remover->next;
				delete remover;
				cap--;
				return;
			}
			placer->next = placer->next->next;
			delete remover;
			cap--;
		}
	}
	void display()
	{
		cout << "hi\n";
		if (head != nullptr)
		{
		Chunk * temp = head;
		while (temp->next !=nullptr)
		{
			cout << temp->x << "\n";
			temp = temp->next;
		}
		cout << temp->x << "\n"  << cap << "\n";
		}
	}
	
};

int main (int argc, char const* argv[])
{
	LL myLL;
	myLL.insert(0,2);
	myLL.remove(0);
	myLL.display();
	myLL.insert(1,0);
	myLL.insert(2,1);
	myLL.insert(3,1);
	myLL.insert(4,2);
	myLL.display();
	myLL.remove(0);
	//myLL.display();
	return 0;
}
