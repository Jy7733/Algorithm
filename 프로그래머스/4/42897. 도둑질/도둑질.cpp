#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    // dp[i] : i 번째까지 훔친 돈의 최댓값 
    int n = money.size(); // 집 개수 
    int dp1[n];  //0번 집 부터 시작 
    int dp2[n];  //1번 집 부터 시작 
    
    fill(dp1, dp1 + n, 0);
    fill(dp2, dp2 + n, 0); 
    
    dp1[0] = money[0]; 
    dp1[1] = money[0]; 
    
    dp2[1] = money[1]; 
    
    for(int i=2; i<n-1; i++){
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]); 
    }

    for(int i=2; i<n; i++){
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]); 
    }
    
    answer = max(dp1[n-2], dp2[n-1]); 
    return answer;
}