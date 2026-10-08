#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
string frequencySort(string s) {
        string str;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        vector<pair<char, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(),
             [](auto& a, auto& b) { return a.second > b.second; });

        for (auto& p : v) {
            int x=p.second;
            char ch=p.first;
            while(x!=0){
                str+=ch;
                x--;
            }
            
        }
        return str;
    }

int main(){
  string s="tree";
  cout<<frequencySort(s);
  
  return 0;
}