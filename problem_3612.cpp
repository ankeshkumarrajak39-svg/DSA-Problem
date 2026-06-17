#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
 string processStr(string s) {
        string ans;
        for(int i=0;i<s.length();i++){
            if(islower(s[i])){
                ans+=s[i];
            }
            if(s[i]=='#'){
                ans=ans.append(ans);
            }
            if(s[i]=='*'){
                if(!ans.empty()){
                    ans.pop_back();
                }
            }
            if(s[i]=='%'){
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
        
    }

int main(){
    cout<< processStr("adc#h*F%") ;
    
    return 0;
}