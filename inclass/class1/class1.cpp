#include <iostream>



int main ()
{
//declare varibles
  int x = 10;
  float y = 3.1456;
  char c = 'y';

// I/O
  std::cout << "Hello World! \n";
  std::cin >> x;

//equations
  x = x + 1;

//loops
  y = 1/y;
  for(int i =0; i<5; i++)
  {
   float x = x*y;
  }
  y = 1/y;

  while (x <= 0)
  {
    x++;
  }
// return values and end program
  std::cout << x << "\n" << y << "\n";
  return 1;
}
