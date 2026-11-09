#include <iostream>
using namespace std;
int minSteps(int n)
{
  int minStep = 0;
  if (n == 0 || n == 1)
  {
    return 0;
  }
  for (int i = 2; i <= n; i++)
  {
    while (n % i == 0)
    {
      minStep += i;
      n = n / i;
    }
  }
  return minStep;
}

int main()
{
 cout<<minSteps(6);
  return 0;
}