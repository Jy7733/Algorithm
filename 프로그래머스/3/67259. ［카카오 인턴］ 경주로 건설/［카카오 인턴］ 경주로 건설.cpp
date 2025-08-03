#include <bits/stdc++.h>
#define INF (~0U >> 2) 

using namespace std;

// 0: 상 / 1 : 하 / 2: 좌 / 3: 우 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int solution(vector<vector<int>> board) {
    int answer = INF;
    queue<tuple<int,int,int>> q; 
    
    int n = board.size(); 
    int price[n][n][4]; 
    // price[i][j][z] = (i,j) 까지 z 방향으로 갔을 때 가격 
    
    // 초기화 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int z=0; z<4; z++){
                price[i][j][z] = INF; 
            }
        }
    }
    
    for(int i=0; i<4; i++){
        q.push({0,0,i});
        price[0][0][i] = 0; 
    }
    
    while(!q.empty()){
        auto [cx, cy, cdir] = q.front(); q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i]; 
            int ny = cy + dy[i]; 
            int ndir = i; 
            int nprice =0; 
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; 
            if(board[nx][ny] == 1) continue;  //갈 수 없는 경우 
            
            if(i == cdir){
                nprice = price[cx][cy][cdir] + 100; 
            }
            else{
                nprice = price[cx][cy][cdir] + 600; 
            }
            if(nprice < price[nx][ny][ndir]) {
                price[nx][ny][ndir] = nprice; 
                q.push({nx,ny,ndir}); 
            }
        }
    }
    
    for(int i=0; i<4; i++){
        answer = min(price[n-1][n-1][i], answer); 
    }
    
    return answer;
}