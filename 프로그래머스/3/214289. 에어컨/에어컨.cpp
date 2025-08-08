#include <bits/stdc++.h>
#define INF (~0U >> 2)

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = INF;
    // 온도 범위 조정 (+10)
    temperature += 10;
    t1 += 10;
    t2 += 10;
    int n = onboard.size();

    int dp[n][51];
    for(int i=0; i<n; i++){
      fill(dp[i], dp[i] + 51, INF);
    }

    int dir = 0;
    int start = 0, end = 0;
    if(temperature > t2){
      dir = -1;
      start = t1;
      end = temperature;
    }
    else if(temperature < t1){
      dir = 1;
      start = temperature;
      end = t2;
    }
    else {
      // 외부온도가 적정범위 내인 경우, 범위 설정은 t1~t2
      dir = 0;
      start = t1;
      end = t2;
    }

    dp[0][temperature] = 0;
    if (dir != 0) {
      int nextTemp = temperature + dir;
      if(nextTemp >= 0 && nextTemp <= 50)
        dp[0][nextTemp] = a;
    }

    for(int i=1; i<n; i++){
      for(int j=start; j<=end; j++){
        if(onboard[i] == 1 && (j < t1 || j > t2)) continue;

        if(j == temperature){
          // 꺼진 상태 유지
          if(dp[i-1][j] != INF)
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
          // 자연 온도 변화
          if(dir != 0) {
            int nxt = j + dir;
            if(nxt >= start && nxt <= end && dp[i-1][nxt] != INF)
              dp[i][j] = min(dp[i][j], dp[i-1][nxt]);
          }
        }
        else {
          // 켠 상태 유지
          if(dp[i-1][j] != INF)
            dp[i][j] = min(dp[i][j], dp[i-1][j] + b);

          // 다른 온도에서 켜서 맞춤
          if(dir != 0) {
            int prev = j - dir;
            if(prev >= start && prev <= end && dp[i-1][prev] != INF)
              dp[i][j] = min(dp[i][j], dp[i-1][prev] + a);

            // 꺼져서 자연 변화
            int nxt = j + dir;
            if(nxt >= start && nxt <= end && dp[i-1][nxt] != INF)
              dp[i][j] = min(dp[i][j], dp[i-1][nxt]);
          }
        }

        if(i == n-1) answer = min(answer, dp[i][j]);
      }
    }

    return answer;
}
