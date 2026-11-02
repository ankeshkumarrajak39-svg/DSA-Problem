#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int mid = nums.size() / 2;
    int ans = 0;

    for(int i = 0; i < nums.size(); i++) {
        int a = abs(nums[mid] - nums[i]);
        ans += a;
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};

    int ans = minMoves2(nums);

    cout << ans;

    return 0;
}