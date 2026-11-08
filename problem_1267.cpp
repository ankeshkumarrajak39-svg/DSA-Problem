
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int Countserver(vector<vector<int>> servers){

    unordered_map<int, int> rowCount;
    unordered_map<int, int> colCount;

    // Count servers in each row and column
    for(int i = 0; i < servers.size(); i++){
        for(int j = 0; j < servers[i].size(); j++){
            if(servers[i][j] == 1){
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }

    int ans = 0;

    // Count communicating servers
    for(int i = 0; i < servers.size(); i++){
        for(int j = 0; j < servers[i].size(); j++){
            if(servers[i][j] == 1 &&
               (rowCount[i] > 1 || colCount[j] > 1)){
                ans++;
            }
        }
    }

    return ans;
}

int main(){

    vector<vector<int>> severs = {
        {1,1,0,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,1}
    };

    int ans = Countserver(severs);
    cout << ans;

    return 0;
}
