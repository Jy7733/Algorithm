#include <bits/stdc++.h>
using namespace std;

bool visited[11][11][4]; 

/*
0: U
1: D
2: L
3: R
*/

int solution(string dirs) {
    int answer = 0;
    
    //시작점 설정
    int sx = 5;
    int sy = 5; 
    
    //이동 
    for(auto dir : dirs){
        int nx=0, ny=0; //이동할 위치 
        int ndir =0; //이동한 방향 
        int cmpdir = 0; //비교할 방향 
        
        if(dir == 'U'){
            nx = sx-1;
            ny = sy; 
            ndir = 0; 
            cmpdir = 1;
        }
        else if(dir == 'D'){
            nx = sx+1;
            ny = sy;
            ndir = 1; 
            cmpdir = 0;
        }
        else if(dir == 'L'){
            nx = sx;
            ny = sy-1;
            ndir = 2;
            cmpdir = 3;
        }
        else if(dir == 'R'){
            nx = sx;
            ny = sy+1;
            ndir = 3;
            cmpdir = 2;
        }
        
        //범위 체크 
        if(nx < 0 || nx > 10 || ny < 0 || ny > 10) continue; //범위를 넘어갈 경우 무시
        
        if(!visited[nx][ny][ndir] && !visited[sx][sy][cmpdir]){
            visited[nx][ny][ndir] = true;
            answer++;
        }
        sx = nx;
        sy = ny;
    }
    return answer;
}