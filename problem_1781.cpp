#include<iostream>
#include<string>
#include<algorithm>
// int beautySum(string s){

// }

using namespace std;

int main(){
  string s="aabcb";
  string ans;
  for(int i=0;i<s.length();i++){
    ans.clear();
    for(int j=i;j<s.length();j++){
      ans.push_back(s[j]);
    }
    for(int i=0;i<ans.length();i++){
      cout<<ans[i];
    }
    cout<<endl;
  }
  
  return 0;
}