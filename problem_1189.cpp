#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//my solution

    int maxNumberOfBalloons(string text) {
        unordered_map<char,int > mp;
        for(int i=0;i<text.size();i++){
            char ch=text[i];
            mp[ch]++;
        }
        string str="balloon";
        vector<int> temp;
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            if(ch=='l'){
                temp.push_back(mp[ch]/2);
            }else if(ch=='o'){
                temp.push_back(mp[ch]/2);
            } else{
                temp.push_back(mp[ch]);
            }
           
        }
        int mn=*min_element(temp.begin(),temp.end());
        return mn;
        
    }

  // optimize 
   /* int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;

        for(char ch : text)
            mp[ch]++;

        return min({
            mp['b'],
            mp['a'],
            mp['l'] / 2,
            mp['o'] / 2,
            mp['n']
        });
    }*/


int main(){
    cout<<maxNumberOfBalloons("bbshshjsjs");
    return 0;
}