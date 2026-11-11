#include<iostream>
#include<cmath>
using namespace std;
int largestInteger(int n, int s) {
        if(s==0){
            return 0;
        }
        for(int i = pow(10, n)-1; i >= pow(10, n-1); i--) {
            int sum = 0;
            int temp = i;

            while(temp > 0) {
                int rev = temp % 10;
                sum += rev;
                temp = temp / 10;
            }

            if(sum == s) {
                return i;
            }
        }
        return -1;
    }

int main(){
  cout<<largestInteger(2,9);
  return 0;
}