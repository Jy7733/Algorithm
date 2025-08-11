#include <bits/stdc++.h>

using namespace std;

int solution(int N, int number) {
    int answer = 0;

    //dp[i] = N을 i번 사용해서 만들 수 있는 숫자들의 집합
    vector<set<int>> dp(9);
    dp[1].insert(N);

    if(N == number) return 1;

    for(int i=2; i<9; i++){
      int repeated = 0;
      for(int k=0; k<i; k++){
        repeated = repeated * 10 + N;
      }
      dp[i].insert(repeated);

      for(int j=1; j < i; j++){
        // N을 j번 사용한 연산 결과와 (i-j)번 사용한 연산결과를 활용하여 i번 사용한 연산결과 만들기
        for(int a : dp[j]){
          for(int b : dp[i-j]){
            dp[i].insert(a + b);
            dp[i].insert(a - b);
            dp[i].insert(a * b);
            if(b != 0) dp[i].insert(a / b);
          }
        }
      }

      if(dp[i].count(number)) return i; 
    }

    return -1; // N 사용횟수의 최솟값
}
