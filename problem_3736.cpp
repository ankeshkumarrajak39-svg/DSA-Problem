#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int minMoves(vector<int> &nums)
{
  int count = 0;
  int large = *max_element(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++)
  {
    count += abs(large - nums[i]);
  }
  return count;
}

int main()
{
  vector<int> nums={4,4,5};
  int ans = minMoves(nums);
  cout<<ans;
  return 0;
}