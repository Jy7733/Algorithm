#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;

    int cover = m; // 현재 커버 가능한 사용자 수
    vector<int> servers(24+k,0); // 해당 시간 대의 서버 개수 조절용
    int serverCnt = 0; // 현재 서버 개수

    for(int i=0; i<24; i++){
      serverCnt += servers[i];
      if(players[i] >= serverCnt*m && players[i] >= m){
        int newServer = (players[i]/m) - serverCnt; // 새로 증설해야하는 서버 개수
        answer += newServer;
        serverCnt += newServer;
        servers[i+k] = (-1)*newServer;
      }
    }
    return answer;
}
