#include <iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
  map<int, int> mp;

  for (int i = 0; i < nums.size(); i++)
  {
    mp[nums[i]]++;
  }

  int k = 0;

  for (auto it : mp)
  {
    int value = it.first;
    int freq = it.second;

    nums[k++] = value;

    if (freq >= 2)
    {
      nums[k++] = value;
    }
  }

  return k;
}

int main()
{

  return 0;
}