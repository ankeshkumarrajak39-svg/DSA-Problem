
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    vector<int> skill(n);
    for (int i = 0; i < n; i++) {
        cin >> skill[i];
    }

    // Map player name to index
    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++) {
        mp[names[i]] = i;
    }

    int n1;
    cin >> n1;

    vector<pair<int, int>> friends;

    for (int i = 0; i < n1; i++) {
        string a, b;
        cin >> a >> b;

        friends.push_back({mp[a], mp[b]});
    }

    int n2;
    cin >> n2;

    vector<pair<int, int>> rivals;

    for (int i = 0; i < n2; i++) {
        string a, b;
        cin >> a >> b;

        rivals.push_back({mp[a], mp[b]});
    }

    int limit;
    cin >> limit;

    // Find all players involved in constraints
    vector<bool> involved(n, false);

    for (auto [a, b] : friends) {
        involved[a] = true;
        involved[b] = true;
    }

    for (auto [a, b] : rivals) {
        involved[a] = true;
        involved[b] = true;
    }

    // Separate constrained and free players
    vector<int> special;
    vector<int> freePlayers;

    for (int i = 0; i < n; i++) {
        if (involved[i]) {
            special.push_back(i);
        } else {
            freePlayers.push_back(i);
        }
    }

    // Knapsack DP for free players
    vector<int> dp(limit + 1, 0);

    for (int idx : freePlayers) {
        for (int j = limit; j >= skill[idx]; j--) {
            dp[j] = max(dp[j], dp[j - skill[idx]] + 1);
        }
    }

    // Map original index to special index
    vector<int> pos(n, -1);

    for (int i = 0; i < (int)special.size(); i++) {
        pos[special[i]] = i;
    }

    int k = special.size();
    int ans = 0;

    // Enumerate all subsets of constrained players
    for (int mask = 0; mask < (1 << k); mask++) {

        int totalSkill = 0;
        int count = 0;

        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                totalSkill += skill[special[i]];
                count++;
            }
        }

        // Check skill limit
        if (totalSkill > limit) {
            continue;
        }

        bool valid = true;

        // Check friends condition
        for (auto [a, b] : friends) {
            int x = pos[a];
            int y = pos[b];

            bool selectedA = mask & (1 << x);
            bool selectedB = mask & (1 << y);

            if (selectedA != selectedB) {
                valid = false;
                break;
            }
        }

        if (!valid) continue;

        // Check rivals condition
        for (auto [a, b] : rivals) {
            int x = pos[a];
            int y = pos[b];

            bool selectedA = mask & (1 << x);
            bool selectedB = mask & (1 << y);

            if (selectedA && selectedB) {
                valid = false;
                break;
            }
        }

        if (!valid) continue;

        // Add maximum possible free players
        int remaining = limit - totalSkill;

        ans = max(ans, count + dp[remaining]);
    }

    cout << ans << endl;

    return 0;
}
