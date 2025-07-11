#include <bits/stdc++.h>
#define INF (~0U >> 2)

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int BFS(vector<vector<int>> board){
    int n = board.size();
    int cost[4][n][n]; 
    
    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++){
            for(int z=0; z<n; z++){
                cost[i][j][z] = INF;
            }
        }
    }
    
    queue<tuple<int,int,int,int>> q; 
    for(int dir = 0; dir<4; dir++){
        q.push({dir,0,0,0});
        cost[dir][0][0] = 0;
    }
    
    while(!q.empty()){
        auto [cdir, cx, cy, cprice] = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;  //보드 범위를 넘어가는 경우
            if(board[nx][ny] != 0) continue; //벽이 있어 이동하지 못하는 경우
            
            int nprice = 0;
            if(cdir == dir){
                nprice = 100;
            }
            else{
                nprice = 600;
            }
            
            if(cost[dir][nx][ny] >= cost[cdir][cx][cy] + nprice){
                cost[dir][nx][ny] = cost[cdir][cx][cy] + nprice;
                q.push({dir,nx,ny,cost[cdir][cx][cy] + nprice});
            }
        }
    }
    
    int tmp = INF;
    for(int i=0; i<4; i++){
        tmp = min(tmp, cost[i][n-1][n-1]);
    }

    return tmp;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    answer = BFS(board);
    return answer;
}
