#include <bits/stdc++.h>
#define INF (~0U >> 2)

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;

    // 목표 능력치
    int targetAlp = -1; int targetCop = -1;
    for(auto p : problems){
      targetAlp = max(targetAlp, p[0]);
      targetCop = max(targetCop, p[1]);
    }
    vector<vector<int>> dp(targetAlp+1, vector<int> (targetCop+1, INF)); // dp[i][j] = alp가 i, cop이 j가 되기까지의 최소 비용

     alp = min(alp, targetAlp);
     cop = min(cop, targetCop);
     dp[alp][cop] = 0;

    for(int i = alp; i<=targetAlp; i++){
      for(int j = cop; j <= targetCop; j++){
        // 1. 알고력 공부
        if(i<targetAlp) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);

        // 2. 코딩력 공부
        if(j<targetCop) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);

        // 3. 문제를 푸는 경우
        for(auto p : problems){
          // 현재 능력으로 문제를 풀 수 없는 경우 스킵
          if(i < p[0] || j < p[1]) continue;

          int alpRwd = p[2];
          int copRwd = p[3];
          int cost = p[4];
          int nxtAlp = min(targetAlp, i+alpRwd);
          int nxtCop = min(targetCop, j+copRwd);

          dp[nxtAlp][nxtCop] = min(dp[nxtAlp][nxtCop], dp[i][j] + cost);
        }
      }
    }

    return dp[targetAlp][targetCop];
}
