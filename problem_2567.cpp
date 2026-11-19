#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> nums = {8, 28, 42, 58, 75};
  int score1 = abs(nums[nums.size() - 1] - nums[2]);
  int score2 = abs(nums[nums.size() - 3] - nums[0]);
  int score3 = abs(nums[1] - nums[nums.size() - 2]);
  int a = min(score1, score2);
  int ans = min(a, score3);
  cout<<ans;

  return 0;
}