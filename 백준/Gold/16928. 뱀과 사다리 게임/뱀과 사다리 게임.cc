#include <bits/stdc++.h>

using namespace std;

queue<pair<int,int>> q;
bool visited[101];
int LadderOrSnake[101];

int main(void){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n+m; i++){
        int x,y;
        cin>>x>>y;

        LadderOrSnake[x] = y;
    }

    q.push({1,0}); // 시작점 세팅 
    visited[1] = true;
    int result = 0;

    while(!q.empty()){
        int cur = q.front().first; //현재 위치  
        int cnt = q.front().second;  //현재 위치까지 주사위를 굴린 횟수 
        q.pop();

        for(int i=1; i<=6; i++){
            int nx = cur + i; //이동할 위치 

            if(nx > 100) break;

            //이동할 위치에 사다리나 뱀이 있다면 
            if(LadderOrSnake[nx] != 0){
                nx = LadderOrSnake[nx]; 
            }

            if(visited[nx] == false){
                q.push({nx, cnt+1});
                visited[nx] = true;
            }

            if(nx == 100){
                cout<<cnt+1<<"\n";
                return 0;
            }

        }

    }
    
    cout<<result<<"\n";

}