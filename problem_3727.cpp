#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
long long maxAlternatingSum(vector<int> &nums)
{
  long long score = 0;
  int n = nums.size();
  int m = n;
  int large;
  int small;
  sort(nums.begin(), nums.end());
  vector<int> temp(n);
  for (int i = 0; i < n; i++)
  {
    large = nums[m - 1];
    small = nums[i];
    if (i % 2 == 0)
    {
      temp[i] = large;
    }
    else
    {
      temp[i] = small;
    }
    m--;
  }
  for(int i = 0; i < temp.size(); i++)
  {
    if (i % 2 == 0)
    {
      score += temp[i] * temp[i];
    }
    else
    {
      score -= temp[i] * temp[i];
    }
  }
  return score;
}
using namespace std;

int main()
{

  return 0;
}