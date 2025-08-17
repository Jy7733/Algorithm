#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;

// dp[i][0] = 문자열 길이가 i 일 때 (s&c)가 짝수 개인 문자열 수
// dp[i][1] = 문자열 길이가 i 일 때 (s&c)가 홀수 개인 문자열 수
ll dp[1000001][2];

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

int answer = 0;

int n; cin>>n;

dp[1][0] = 24;
dp[1][1] = 2;

for(int i=2; i<=n; i++){
dp[i][0] = (dp[i-1][0]*24 + dp[i-1][1]*2) % MOD;
dp[i][1] = (dp[i-1][0]*2 + dp[i-1][1]*24 % MOD);
}

cout<<dp[n][0]%MOD<<"\n";
return 0;
}
