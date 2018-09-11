#include <iostream>

using namespace std;

void hanoi(int disks, char source, char inter, char dest)
{
static int count = 0;
 if (disks == 1)
{
    cout << ++count << " Move disk " << disks << " from " << source << "-->" << dest << "\n";
}
 else
 {
    hanoi(disks-1, source, dest, inter);
    cout << ++count<<" Move disk " << disks << " from " << source << "-->" << dest << "\n";
    hanoi(disks-1, inter, source, dest);
 }
}


int main ()
{
 int N;
 char S = 's', I = 'i', D = 'd';
 cout << "Please Enter number of disks \n";
 cin >> N;
 hanoi (N, S, I, D);
 
}
