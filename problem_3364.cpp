
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int minSum = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int size = 0;
            int sum = 0;

            for (int j = i; j < nums.size(); j++) {
                size++;
                sum += nums[j];

                if (size >= l && size <= r && sum > 0) {
                    minSum = min(minSum, sum);
                }

                if (size > r) break;
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};

int main() {
    vector<int> nums = {3, -2, 1, 4};

    int l = 2;
    int r = 3;

    Solution obj;

    cout << obj.minimumSumSubarray(nums, l, r);

    return 0;
}
