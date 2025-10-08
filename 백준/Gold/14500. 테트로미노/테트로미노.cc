#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n, m;
vector<vector<int>> board;
vector<vector<bool>> visited;
int ans = 0, maxNum = 0;

void dfs(int k, int x, int y, int sum){
  if(sum + (4 - k) * maxNum <= ans) return; // 가지치기
  if(k == 4){
    ans = max(ans, sum);
    return;
  }

  for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if(visited[nx][ny]) continue;
    visited[nx][ny] = true;
    dfs(k+1, nx, ny, sum + board[nx][ny]);
    visited[nx][ny] = false;
  }
}

void checkExtra(int x, int y){
  // ㅗ
  if(x-1>=0 && y-1>=0 && y+1<m)
    ans = max(ans, board[x][y] + board[x-1][y] + board[x][y-1] + board[x][y+1]); 
  // ㅏ
  if(x-1>=0 && x+1<n && y+1<m)
    ans = max(ans, board[x][y]+board[x-1][y]+board[x+1][y]+board[x][y+1]); 
  // ㅜ
  if(y-1>=0 && y+1<m && x+1<n)
    ans = max(ans, board[x][y]+board[x][y-1]+board[x][y+1]+board[x+1][y]); 
  // ㅓ
  if(x-1>=0 && x+1<n && y-1>=0)
    ans = max(ans, board[x][y]+board[x-1][y]+board[x+1][y]+board[x][y-1]); 
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  board.resize(n, vector<int>(m));
  visited.resize(n, vector<bool>(m,false));

  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++){
      cin >> board[i][j];
      maxNum = max(maxNum, board[i][j]);
    }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      visited[i][j] = true;
      dfs(1, i, j, board[i][j]);
      visited[i][j] = false;
      checkExtra(i, j);
    }
  }

  cout << ans << "\n";
}
