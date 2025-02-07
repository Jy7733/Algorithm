#include <bits/stdc++.h>
#define INF (~0U >> 2)

using namespace std;

int board[1001][1001];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool visited[1001][1001][2]; //[x][y][x,y에 오기까지 벽을 부쉈는지 여부]
queue<tuple<int, int, int, bool>> q;
int result = INF;
int n,m;


void move(){

	while(!q.empty()){
		auto [cx, cy, cost, breakWall] = q.front(); q.pop();

		//도착지인 경우 -> result 비교 
		if(cx == n && cy == m){
			result = min(result, cost);
			return;
		}

		for(int i=0; i<4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if(nx<= 0 || nx > n || ny <= 0 || ny > m) continue;

			//벽이 아닌 경우 
			if(board[nx][ny] == 0 && !visited[nx][ny][breakWall]){
				visited[nx][ny][breakWall] = true;
				q.push({nx, ny, cost+1, breakWall});
			}
			
			//벽을 만난 경우  + breakWall = false 인 경우(즉, 부술 기회가 남아있는 경우) 
			else if(board[nx][ny] == 1 && !breakWall && !visited[nx][ny][1]){
				visited[nx][ny][1] = true;
				q.push({nx, ny, cost+1, true});
			}
		}
	}
}

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			char x;
			cin>>x;
			board[i][j] = x - '0';
		}
	}
	
	visited[1][1][0] = true;
	q.push({1, 1, 1, false});

	move();

	if(result == INF) cout<<"-1\n";
	else cout<<result<<"\n";
}