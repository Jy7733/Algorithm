#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool visited[3][3];
int answer = 0;

void DFS(int x, int y, int cnt){
  if(cnt == 9){
    answer++;
    return;
  }

  for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
    if(visited[nx][ny]) continue;
    visited[nx][ny] = true;
    DFS(nx,ny,cnt+1);
    visited[nx][ny] = false;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k;
  cin>>k;
  
  int x = (k-1)/3; 
  int y = (k-1)%3; 
  visited[x][y] = true;
  DFS(x,y,1);

  cout<<answer<<"\n";
}
