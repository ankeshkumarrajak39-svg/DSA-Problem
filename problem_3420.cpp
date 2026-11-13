#include<iostream>
#include<vector>
using namespace std;
long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long reqOP = 0;
            int maxVal = nums[i];

            for (int j = i; j < n; j++) {

                maxVal = max(maxVal, nums[j]);

                reqOP += max(0, maxVal - nums[j]);

                if (reqOP <= k) {
                    ans++;
                }
            }
        }

        return ans;
    }
int main(){
  vector<int>nums={6,3,1,2,4,4};
  cout<<countNonDecreasingSubarrays(nums , 7);
  
  return 0;
}