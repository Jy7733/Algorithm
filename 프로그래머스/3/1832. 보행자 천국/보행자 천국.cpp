#include <vector>

using namespace std;

int MOD = 20170805;

int dx[] = {-1,0};
int dy[] = {0,-1};

typedef long long ll;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    ll dp[m][n][2]; //dp[x][y][dir] = (x,y) 까지 dir 방향으로 온 경우의 수
    fill(&dp[0][0][0], &dp[0][0][0] + m*n*2, 0);

    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    city_map[0][0] = 2;

    for(int x=0; x<m; x++){
      for(int y=0; y<n; y++){
        if(city_map[x][y] == 1) continue;
        for(int i=0; i<2; i++){

          // 이전 칸
          int nx = x + dx[i];
          int ny = y + dy[i];

          if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
          if(city_map[nx][ny] == 1) continue;

          if(city_map[nx][ny] == 2){
            dp[x][y][i] += dp[nx][ny][i];
          }
          else{
            dp[x][y][i] += (dp[nx][ny][0] + dp[nx][ny][1]);
          }
          dp[x][y][i] %= MOD;
        }
      }
    }

    answer = (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
    return answer;
}