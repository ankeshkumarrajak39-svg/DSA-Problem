#include<iostream>
#include<vector>
using namespace std;
int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int  ans=0;
        for(int i=0;i<nums.size();i++){
            int  even=0;
            int   odd=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0){  //even
                  even++; 
                }else{
                    odd++;
                }
                if(odd!=0){
                    if ((even*b)<=(odd*a)){
                        ans++;
                    }
                }
            }
        }
        return ans;
        
    }

int main(){
  vector<int> nums={1,2,1,2};
  cout<<countRatioSubarrays(nums,3,2);
  return 0;
}