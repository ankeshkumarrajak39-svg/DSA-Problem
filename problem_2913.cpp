
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 1};
    int n = nums.size();
    set<int> st;
    int sq = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            st.clear();

            for (int k = i; k <= j; k++) {
                st.insert(nums[k]);
            }

            int count = st.size();
            sq += count * count;
        }
    }

    cout << "ans = " << sq;
    return 0;
}
