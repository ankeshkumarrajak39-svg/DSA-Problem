#include<iostream>
#include<string>
using namespace std;
string trafficSignal(int timer) {
        
        if(timer==0){
            return "Green";
        }else if(timer==30){
            return "Orange";
        } else if(timer>30 && timer<=90){
            return "Red";
        } else{
            return "Invalid";
        }
        
    }
int main(){
  string ans = trafficSignal(60);
  cout<<ans;
  
  return 0;
}