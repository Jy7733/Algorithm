#include <bits/stdc++.h>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    const int INF = 100001 * n; 
    int answer = INF;

    int dist[n+1][n+1];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(auto fare : fares){
        dist[fare[0]][fare[1]] = fare[2]; 
        dist[fare[1]][fare[0]] = fare[2];
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }

    return answer;
}
