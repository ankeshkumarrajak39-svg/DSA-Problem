
#include<iostream>
#include<string>

using namespace std;

string digitSum(string s, int k) {

    while (s.length() > k) {
        string ans = "";
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {

            sum += s[i] - '0';

            if ((i + 1) % k == 0) {
                ans += to_string(sum);
                sum = 0;
            }
        }

        if (s.length() % k != 0) {
            ans += to_string(sum);
        }

        s = ans;
    }

    return s;
}

int main() {

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    cout << "Result: " << digitSum(s, k) << endl;

    return 0;
}
