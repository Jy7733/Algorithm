#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

int cost[10001][4] = {};
int dp[10001][4] = {}; 

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n; //집 개수 

    for(int i=1; i<=n; i++){
        cin>>cost[i][1]>>cost[i][2]>>cost[i][3];
    }

    //초기 세팅
    for(int i=1; i<=3; i++){
        dp[1][i] = cost[1][i];
    }

    for(int i=2; i<=n; i++){
        dp[i][1] = min(cost[i][1]+dp[i-1][2], cost[i][1]+dp[i-1][3]);
        dp[i][2] = min(cost[i][2]+dp[i-1][1], cost[i][2]+dp[i-1][3]);
        dp[i][3] = min(cost[i][3]+dp[i-1][1], cost[i][3]+dp[i-1][2]);
    }

    int result = min({dp[n][1], dp[n][2], dp[n][3]});
    cout<<result<<"\n";
}