#include<iostream>
#include<vector>
using namespace std;
int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ret = 0;
        for (auto n : arr1) {
            for (auto m : arr2) {
                if (abs(m-n) <= d) {
                    goto end;
                }
            }
            ret++;
            end:
            ; //for no warning 
        }
        return ret;
    }

int main(){
  vector<int>arr1={4,5,8};
   vector<int>arr2={10,9,1,8};
   cout<<findTheDistanceValue(arr1,arr2,2);

    

  return 0;
}