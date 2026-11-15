#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> arr={1,3,5};
   vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            ans.clear();
            for(int j=i;j<arr.size();j++){
                ans.push_back(arr[j]);

            }
            for(int k=0;k<ans.size();k++){
              cout<<ans[k] <<" ";

            }
            cout<<endl;
        }
  
  return 0;
}