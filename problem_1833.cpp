  #include<iostream>
  #include<vector>
  #include<algorithm>
  using namespace std;
    int maxIceCream(vector<int>& costs, int coins) {
        long long sum = 0;
        int ans = 0;
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++) {
            sum += costs[i];
            if (sum <= coins) {
                ans++;
                if (sum > coins)
                    break;
            }
        }
        return ans;

        // counting sort
        /*int mx = *max_element(costs.begin(), costs.end());
        vector<int>count(mx+1,0);
        //find frequency
        for(int cost:costs){
           count[cost]++;
        }

        int bars=0;
        int remainingcoin=coins;
        for(int cost=1;cost<=mx;++cost){
           if(count[cost]>0){
               int canBuy=min(count[cost],remainingcoin/cost);
               bars+=canBuy;
               remainingcoin-=canBuy*cost;
               if(canBuy==0){
                   break;
               }

           }
        }
        return bars;*/
    }
    int main(){
        return 0;

    }
