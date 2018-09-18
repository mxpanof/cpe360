#include <iostream>
#include <vector>
#include <functional>
using namespace std;



class amazonCustomer
{
protected:
	int Age;
	static int Idcounter;
	int Id;
	float Balance;
public:
	amazonCustomer (int a=18, int b=0):Age(a),Balance(b),Id(Idcounter++)
	{}
	void addItemToCart ()
	{
		cout<<"Added something to cart \n";
	}
	int getAge ()
	{
		return Age;
	}
	void setAge (int a)
	{
		this->Age = a;
	}
	int getId ()
	{
		return Id;
	}
};

int amazonCustomer::Idcounter = 1;
int main ()
{
	//create vector of objects to refer to
	vector<amazonCustomer> customerVector;
	amazonCustomer * ptr;
	ptr = new amazonCustomer;
	customerVector.push_back(*ptr);
	cout << customerVector.back().getAge() << "\n";
	customerVector.back().setAge(25);
	cout << customerVector.back().getAge() << "\n";
	cout << customerVector.back().getId() << "\n";
	ptr = new amazonCustomer;
	customerVector.push_back(*ptr);
	cout << customerVector.back().getAge() << "\n";
	customerVector.back().setAge(26);
	cout << customerVector.back().getAge() << "\n";
	cout << customerVector.back().getId() << "\n";
	
	
	return 1;
}
