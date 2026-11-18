#include<iostream>
#include<string>
using namespace std;
int minChanges(string s) {
        int ans=0;
        for(int i=1;i<s.length();i+=2){
            if(s[i]=='0' && s[i-1]=='1'){
                ans++;
            }else if(s[i]=='1'&& s[i-1]=='0'){
                ans++;
            }
        }
        return ans;
        
    }

int main(){
  string s="1001";
  cout<<minChanges(s);
  
  return 0;
}