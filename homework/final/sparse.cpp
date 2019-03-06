/*
// Please make sure to compile with c++ 11
// $ g++ --std=c++11 sparse.cpp
*/
#include <iostream>
using namespace std;

class Chunk
{
	private: //No one should need to touch these directly
		int x, y, value;
		Chunk* next;
	public:
		Chunk (int X, int Y, int V):x(X),y(Y),value(V), next(nullptr){};//init
		int get_x()//These how you interact with Chunk data
		{
			return this->x;
		}
		void set_x(int input)
		{
			 this->x=input;
			 return;
		}
		int get_y()
		{
			return this->y;
		}
		void set_y(int input)
		{
			 this->y=input;
			 return;
		}int get_value()
		{
			return this->value;
		}
		void set_value(int input)
		{
			 this->value=input;
			 return;
		}
		Chunk * get_next ()
		{
			return this->next;
		}
		void set_next (Chunk * input)
		{
			this->next = input;
			return;
		}
};
class SparseMatrix
{
	private:
		Chunk * dim;//start of every matrix is are dimensions
		//Chunk * start;
	public:
		SparseMatrix (int X = 0, int Y = 0, bool automatic = false)//Create dims
		{
			if (automatic == true)
			{	
			 dim = new Chunk(X,Y, 0);
			}	
			else{
			cout << "What is the size of the matix to create?\nPlease enter the X dimension\n";
			cin >> X;
			cout<<"Now please enter the Y dimension\n";
			cin >> Y;
			dim = new Chunk (X,Y,0);
			}
		}
		int getDim_x ()//read dims
		{
			return dim->get_x();
		}
		int getDim_y ()
		{
			return dim->get_y();
		}
		void addValue (int X = 0, int Y = 0, int V = 0, bool automatic = false)
		{
			if(automatic == false)
			{
			cout << "Where is the value to add?\nPlease enter the X location\n";
			cin >> X;
			cout << "Now please enter the Y location\n";
			cin >> Y;
			cout << "And finally the value\n";
			cin >> V;
			}
			if(X >= getDim_x() || Y >= getDim_y() || X<0 || Y<0)//only valid locations
			{
				cout << "Invalid location: Please remember that the matrix starts at 0 and ends at n-1\n Please try again\n";
				return;
			}
			else
			{
				Chunk * temp = dim;
				while(temp->get_next() != nullptr) // place new Chunk in correct location
				{
					if(X<=temp->get_next()->get_x()) //is it along a row that has a value?
					{	
						if(Y<temp->get_next()->get_y()) // where in the row is it? before?
						{
							Chunk * holder = new Chunk (X,Y,V);
							holder->set_next(temp->get_next());
							temp->set_next(holder);
							return;
						}
						else if (Y>temp->get_next()->get_y())//after?
						{
							Chunk * holder = new Chunk(X,Y,V);
							holder->set_next(temp->get_next()->get_next());
							temp->get_next()->set_next(holder);
							return;
						}
						else if(Y == temp->get_next()->get_y())//that spot?
						{
							temp->get_next()->set_value(V);
							return;
						}
					}
					temp=temp->get_next();
				}
				temp->set_next(new Chunk (X,Y,V));//or is it after all values?
			}
		}
		void finish(Chunk * input)
		{
			Chunk * temp = dim;
			while(temp->get_next() != nullptr)
			{ temp = temp->get_next();}
			while(input != nullptr)
			{
				temp->set_next(new Chunk (input->get_x(), input->get_y(), input->get_value()));
				temp = temp->get_next();
				input = input->get_next();
			}
		}
		SparseMatrix operator + ( SparseMatrix B)// add some stuff
		{
			Chunk * firstMatrix = this->dim;
			Chunk * secondMatrix = B.dim;
			if(B.getDim_x() != this->getDim_x() || B.getDim_y() != this->getDim_y())
			{
				cout << "Matrices must have matching dimensions\n";
				return NULL;
			}
			SparseMatrix temp(this->getDim_x(),this->getDim_y(), true);
			firstMatrix= firstMatrix->get_next();
			secondMatrix = secondMatrix->get_next();
			while(firstMatrix != nullptr && secondMatrix != nullptr)
			{
				if (firstMatrix->get_x() < secondMatrix->get_x())
				{
					temp.addValue(firstMatrix->get_x(), firstMatrix->get_y(), firstMatrix->get_value(),true);
					if(firstMatrix->get_next() != nullptr)
					{

						firstMatrix=firstMatrix->get_next();
					}
					else
					{

						temp.finish(secondMatrix);
						return temp;
					}
				}
				else if(firstMatrix->get_x() > secondMatrix->get_x())
				{
					
					temp.addValue(secondMatrix->get_x(), secondMatrix->get_y(), secondMatrix->get_value(),true);
					if(secondMatrix->get_next() != nullptr)
					{	

						secondMatrix=secondMatrix->get_next();
					}
					else
					{

						temp.finish(firstMatrix);
						return temp;
					}
				}
				else if(firstMatrix->get_x() == secondMatrix->get_x())
				{
					if(firstMatrix->get_y() < secondMatrix->get_y())
					{
						temp.addValue(firstMatrix->get_x(), firstMatrix->get_y(), firstMatrix->get_value(),true);
						if(firstMatrix->get_next() != nullptr)
						{

							firstMatrix=firstMatrix->get_next();
						}
						else
						{

							temp.finish(secondMatrix);
							return temp;
						}
					}
					else if(firstMatrix->get_y() > secondMatrix->get_y())
					{

						temp.addValue(secondMatrix->get_x(), secondMatrix->get_y(), secondMatrix->get_value(),true);
						if(secondMatrix->get_next() != nullptr)
						{

							secondMatrix=secondMatrix->get_next();
						}
						else
						{

							temp.finish(firstMatrix);
							return temp;
						}
					}
					else if(firstMatrix->get_y() == secondMatrix->get_y())
					{
						temp.addValue(firstMatrix->get_x(), firstMatrix->get_y(), firstMatrix->get_value()+secondMatrix->get_value(),true);
						if(secondMatrix->get_next() == nullptr || firstMatrix->get_next() == nullptr)
						{
							if(secondMatrix->get_next() ==nullptr && firstMatrix->get_next() == nullptr)
							{
							
								return temp;
							}
							else if(firstMatrix->get_next() == nullptr)
							{
							
								finish(secondMatrix);
								return temp;
							}
							else
							{
									
								finish(firstMatrix);
								return temp;
							}
						}
					}
				}
			
			}
			return temp;
		}
		void display()
		{
			cout << "\n";
			Chunk * temp = dim->get_next();
			for(int c = 0; c<getDim_x(); c++)
			{
				for (int r = 0; r< getDim_y(); r++)
				{
					if(c == temp->get_x() && r== temp->get_y())
					{
						cout << temp->get_value() << " ";
						if(temp->get_next() != nullptr)
						{
							temp = temp->get_next();
						}
					}
					else
					{
						cout << "0 ";
					}
				}
				cout << "\n";
			}
		}
};
int main (int argc, char const* argv[])
{
	SparseMatrix A(1000, 1000, true);
	SparseMatrix B(1000, 1000, true);
	SparseMatrix C(5, 5, true);
	A.addValue(1, 1, 3, true);
	A.addValue(1, 3,2, true);
	A.addValue(2, 1, 5, true);
	B.addValue(3, 5,7, true);
	A.display();
	B.display();
	
	SparseMatrix D = A+B;
	D.display();
	return 0;
}
