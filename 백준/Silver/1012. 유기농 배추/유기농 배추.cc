#include <bits/stdc++.h>

using namespace std;

int t,m,n,k;
int cnt = 0;


int veg[51][51];
bool visited[51][51]={false};

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void BFS(int x,int y){
    queue<pair<int,int>> q;
    
    visited[x][y] = true;
    q.push({x,y});
    
    while(!q.empty()){
        
        pair<int, int> cur = q.front();
        q.pop();
        
        
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] == true || veg[nx][ny] == 0) continue;
            
            visited[nx][ny] = true;
            q.push({nx,ny});
            
        }
        
    }
  
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin>>t;
    
    for(int i=0; i<t; i++){
        memset(veg, 0, sizeof(veg));
        memset(visited,false,sizeof(visited));
        cnt = 0;
        
        cin>>m>>n>>k;
        
        for(int i=0; i<k; i++){
            int a,b;
            cin>>a>>b;
            veg[a][b] = 1;
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(veg[i][j] == 1 && !visited[i][j]){
                    BFS(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    
}

