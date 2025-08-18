#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X, Y; 
    cin>>X>>Y; 

    int answer = 0;
    vector<vector<ll>> dp(X+1, vector<ll>(Y+1, 0));
  
    dp[0][0] = 1; 
    for (int i=0; i<=X; i++) {
        for (int j=0; j<=Y; j++) {
            if (i % 2 == 0) {
                if (i >= 2 && j >= 1) {
                    dp[i][j] = (dp[i][j] +  dp[i-2][j-1] * 3) % MOD;
                }
                if (j >= 3) {
                    dp[i][j] = (dp[i][j] + dp[i][j-3]) % MOD;
                }
            }
        }
    }
    cout<<dp[X][Y]<<"\n";
}
