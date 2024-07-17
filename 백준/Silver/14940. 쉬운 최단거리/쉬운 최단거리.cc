#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];
int result[1001][1001];
bool visited[1001][1001];

queue<pair<int,int>> q;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n,m;
int x,y;

void BFS(int x,int y){
    
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] == true) continue;
            if(arr[nx][ny] == 0) continue;
            
            
            visited[nx][ny] = true;
            q.push({nx,ny});
            result[nx][ny] = result[cur.first][cur.second] + 1;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j] == false) result[i][j] = -1;
        }
    }
    
}

int main(void){
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 2){
                x = i;
                y = j;
            }
            if(arr[i][j] == 0){
                result[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    
    q.push({x,y});
    visited[x][y] = true;
    result[x][y] = 0;
    BFS(x,y);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    
}

