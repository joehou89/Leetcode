#include <iostream>

using namespace std;

int digital_count(int num)
{
  int data = num;
  int count = 0;
  while (data)
  {
    data /= 10;
    count++;
  }
  return count;
}

int main()
{
  int num = digital_count(12345);  
  return 0;
}



