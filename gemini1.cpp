#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>Product(vector<int>nums){
  vector<int>ans;
  int pro=1;
  for(int i=0;i<nums.size();i++){
    pro*=nums[i];

  }
  for(int i=0;i<nums.size();i++){
    ans.push_back(pro/nums[i]);
  }
  return ans;
}

int main(){
  vector<int>nums={1,2,3,4};
  vector<int>temp=Product(nums);
  for(int i=0;i<temp.size();i++){
    cout<<temp[i]<<" ";
  }

  
  return 0;
}