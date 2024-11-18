#include <bits/stdc++.h>
using namespace std;

int arr[5][5];
bool visited[5][5];

vector< pair<int, int> > shape[4];


int n,m;
int answer;

void backTrack(int x, int y, int score){

    if(y == m){
        y=0;
        x+=1;
    }

    if(x == n){
        answer = max(score,answer);
        return;
    }


    if(!visited[x][y]){
        for(int i=0; i<4; i++){
            int nx1 = x + shape[i][0].first;
            int ny1 = y + shape[i][0].second;

            int nx2 = x + shape[i][1].first;
            int ny2 = y + shape[i][1].second;

            if(nx1 < 0 || nx1 >= n || nx2 < 0 || nx2 >= n ||
                ny1 < 0 || ny1 >= m || ny2 < 0 || ny2 >= m ||
                visited[nx1][ny1] || visited[nx2][ny2]) continue;

            visited[x][y] = true;
            visited[nx1][ny1] = true;
            visited[nx2][ny2] = true;

            int tmpScore = arr[x][y]*2 + arr[nx1][ny1] + arr[nx2][ny2];

            backTrack(x,y+1,score + tmpScore);

            visited[x][y] = false;
            visited[nx1][ny1] = false;
            visited[nx2][ny2] = false;

        }
    }

    backTrack(x,y+1,score);
    

}


int main(void){
    
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    // ㄱ 자  
    shape[0].push_back({0,-1});
    shape[0].push_back({1,0});

    //  ㅁ
    //ㅁ ㅁ
    shape[1].push_back({-1,0});
    shape[1].push_back({0,-1});

    // ㄴ 
    shape[2].push_back({-1,0});
    shape[2].push_back({0,1});

    // ㅁ ㅁ 
    // ㅁ
    shape[3].push_back({1,0});
    shape[3].push_back({0,1});


    backTrack(0,0,0);
    cout<<answer;

}