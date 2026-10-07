#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <set>

using namespace std;

// function for check valid
bool isvalid(string a) {
    int balance = 0;

    for (char ch : a) {

        if (ch == '(') {
            balance++;
        }
        else if (ch == ')') {
            balance--;

            if (balance < 0)
                return false;
        }
    }

    return balance == 0;
}

vector<string> answer(string s) {

    vector<string> ans;
    set<string> organs;

    // Ek-ek character remove karke check
    for (int i = 0; i < s.length(); i++) {

        // '(' ya ')' dono remove karenge
        if (s[i] == '(' || s[i] == ')') {

            string copy = s;

            // i-th character remove
            copy.erase(i, 1);

            // valid hai to set me store
            if (isvalid(copy)) {
                organs.insert(copy);
            }
        }
    }

    // set ko vector me convert
    for (string x : organs) {
        ans.push_back(x);
    }

    return ans;
}

int main() {

    string s = "()())()";

    vector<string> ans = answer(s);

    for (string x : ans) {
        cout << x << endl;
    }

    return 0;
}