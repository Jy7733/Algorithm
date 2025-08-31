#include <bits/stdc++.h>

using namespace std;

int n,m;

int arr[100][100];
bool visited[100][100];
string board[100];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void BFS(int x,int y){
    queue<pair<int,int>> q;
    
    visited[x][y] = true;
    q.push({x,y});
    arr[x][y] = 1;
    
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny]== true || board[nx][ny] != '1' ) continue;
            
            visited[nx][ny] = true;
            q.push({nx,ny});
            arr[nx][ny] = arr[cur.first][cur.second] + 1;
        }
    }
    
}



int main(void){
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        cin>>board[i];
    }
    
    BFS(0,0);
    
    cout<<arr[n-1][m-1];
}
