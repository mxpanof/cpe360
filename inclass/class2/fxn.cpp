#include <iostream>
using namespace std;


int Add (int a, int b)
{
  return a+b;
}
int main ()
{
  int x;
  int y;
  int result;
  cout << "Give me x and y: \n";
  cin >> x;
  cin >> y;

  cout << "Adding them : \n" << Add(x,y) << "\n";
  result = Add(x,y);

}
