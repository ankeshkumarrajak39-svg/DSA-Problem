#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sumOfBeauty = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int freq[26] = {0};

                for (int k = i; k <= j; k++) {
                    freq[s[k] - 'a']++;
                }

                int maxi = INT_MIN;
                int mini = INT_MAX;

                for (int ch = 0; ch < 26; ch++) {
                    if (freq[ch] == 0) continue;

                    maxi = max(maxi, freq[ch]);
                    mini = min(mini, freq[ch]);
                }

                sumOfBeauty += (maxi - mini);
            }
        }

        return sumOfBeauty;
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    cout << "Beauty Sum: " << obj.beautySum(s) << endl;

    return 0;
}