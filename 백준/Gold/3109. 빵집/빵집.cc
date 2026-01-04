#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1}; 
int cnt=0;
vector<vector<int>> board;
int r,c;

bool dfs(int x, int y){

    if(y == c-1){
        cnt++;
        return true;
    }

    board[x][y] = 1;

    for(int i=0; i<3; i++){
        int nx = x+dx[i];
        int ny = y+1;
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if(board[nx][ny] == 1) continue;
        if(dfs(nx,ny)) return true; 
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>r>>c;
    board.resize(r, vector<int>(c,0));


    for(int i=0; i<r; i++){
        string str; cin>>str;
        for(int j=0; j<c; j++){
            if(str[j] == '.') board[i][j] = 0;
            else if(str[j] == 'x') board[i][j] = 1;
        }
    }

    for(int i=0; i<r; i++){
        dfs(i,0);
    }

    cout<<cnt<<"\n";
}

