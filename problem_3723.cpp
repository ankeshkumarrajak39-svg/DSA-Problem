
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool helper(int x, int y)
{
  int c = 0;

  while (x > 0)
  {
    int last = x % 10;
    c += last;
    x = x / 10;
  }

  return c == y;
}

string solution(int num, int sum)
{
  vector<int> temp;
  string ans = "";

  int start = pow(10, num - 1);
  int end = pow(10, num) - 1;

  for (int i = start; i <= end; i++)
  {
    if (helper(i, sum))
    {
      temp.push_back(i);
    }
  }

  // apply operation on temp
  vector<int> maxSq;
  for (int i = 0; i < temp.size(); i++)
  {
    int a = temp[i];
    int sq;
    while (a > 0)
    {
      int last = a % 10;
      sq += last * last;
    }
    maxSq.push_back(sq);
  }
  int index = max_element(maxSq.begin(), maxSq.end()) - maxSq.begin();
  char ch = static_cast<char>(temp[index]);
  ans.push_back(ch);
  return ans;
}

int main()
{
  

  return 0;
}
