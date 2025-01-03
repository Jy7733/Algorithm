#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

long long dp[100001][4]; // [만들 수 있는 숫자][직전 숫자]

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1; //배열 초기 세팅

    for(int i=4; i<100001; i++){
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD; // 1 이전에 올 수 있는 숫자는 2, 3
        dp[i][2] =(dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
    }

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        cout<<(dp[x][1] + dp[x][2] + dp[x][3]) % MOD<<"\n";
    }

}