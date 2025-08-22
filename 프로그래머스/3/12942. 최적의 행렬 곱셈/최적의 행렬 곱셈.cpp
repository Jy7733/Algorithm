#include <bits/stdc++.h>
#define INF (~0U>>2) 
using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;

    int n = matrix_sizes.size();
    vector<vector<int>> dp(n, vector<int>(n,0)); //dp[i][j] = i번~j번까지의 행렬 곱

    for(int len=1; len<n; len++){
      for(int i=0; i+len<n; i++){
        int j=i+len; 
        dp[i][j] = INF; 

        for(int k=i; k<j; k++){
            int cost = dp[i][k] + dp[k+1][j] + matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1]; 
            dp[i][j] = min(cost, dp[i][j]); 
        }
      }
    }

    return dp[0][n-1];
}


