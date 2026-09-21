#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
           /* int maxProfit = 0;
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] > prices[i]) {
                    maxProfit = max(maxProfit, prices[j] - prices[i]);
                }
            }
            profit += maxProfit;*/
             if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
             }
        }
        return profit;
    }


int main(){
  vector<int>prices={7,5,7,4,3,5,9};
  cout<<maxProfit(prices);
  
  return 0;
}
    