#include<iostream>
#include<vector>
using namespace std;
int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0; //for size =1

        int increase = 1;
        int decrease = 1;
        int maxSize = 1;
        int minSize = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                increase++;
                decrease = 1;
            }
            else if (nums[i] < nums[i - 1]) {
                decrease++;
                increase = 1;
            }
            else {
                increase = 1;
                decrease = 1;
            }

            maxSize = max(increase, maxSize);
            minSize = max(decrease, minSize);
        }

        return max(maxSize, minSize);
    }

int main(){
  vector<int>nums={1,4,3,3,2};
  cout<<longestMonotonicSubarray(nums);
  
  return 0;
}