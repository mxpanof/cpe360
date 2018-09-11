#include <iostream>
 using namespace std;

int recurse (int fact)
{
  
  while (fact >1)
  {
    return fact *recurse(fact -1);
  }
  return fact;
}
int main () {
 int x;
 cin >> x;
 cout << recurse(x);
 
}
