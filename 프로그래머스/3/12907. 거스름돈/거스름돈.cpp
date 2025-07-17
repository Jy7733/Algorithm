#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int solution(int n, vector<int> money) {
    int dp[n+1]; // dp[i] = i까지 만드는 경우의 수 
    fill(dp, dp+n+1, 0);
    
    dp[0] = 1; 
    for(int coin : money){
        for(int i=coin; i<=n; i++){
           dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }
    return dp[n];
}