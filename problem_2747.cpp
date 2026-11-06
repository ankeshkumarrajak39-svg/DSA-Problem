
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n = 3;
    int x = 8;

    vector<vector<int>> logs = {
        {1, 35},
        {1, 32},
        {1, 11},
        {1, 39},
        {2, 29}
    };

    vector<int> queries = {
        38, 30, 23, 33, 15, 31, 34, 22, 11, 14
    };

    // Sort logs according to timestamp
    sort(logs.begin(), logs.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        }
    );

    // Store queries with original index
    vector<pair<int, int>> q;

    for (int i = 0; i < queries.size(); i++) {
        q.push_back({queries[i], i});
    }

    sort(q.begin(), q.end());

    vector<int> ans(queries.size(), 0);
    vector<int> freq(n + 1, 0);

    int left = 0;
    int right = 0;
    int activeServers = 0;

    for (int i = 0; i < q.size(); i++) {

        int time = q[i].first;
        int idx = q[i].second;

        int start = time - x;

        // Add logs into sliding window
        while (right < logs.size() &&
               logs[right][1] <= time) {

            int id = logs[right][0];

            freq[id]++;

            if (freq[id] == 1) {
                activeServers++;
            }

            right++;
        }

        // Remove logs outside sliding window
        while (left < right &&
               logs[left][1] < start) {

            int id = logs[left][0];

            freq[id]--;

            if (freq[id] == 0) {
                activeServers--;
            }

            left++;
        }

        ans[idx] = n - activeServers;
    }

    // Print answer
    cout << "Output: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
