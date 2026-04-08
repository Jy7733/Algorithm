#include <bits/stdc++.h>
using namespace std;

bool visited[4][501][501];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int solution(string dirs) {
    int answer = 0;
    
    int cx=5, cy=5;
    int nx=0, ny=0, nd=0, pd=0;
    for(auto d:dirs){
        if(d == 'U'){
            nx = cx-1;
            ny = cy;
            nd=0;
            pd=1;
        }
        else if(d=='D'){
            nx = cx+1;
            ny = cy;
            nd=1;
            pd=0;
        }
        else if(d=='L'){
            nx = cx;
            ny = cy-1;
            nd=2;
            pd=3;
        }
        else if(d=='R'){
            nx = cx;
            ny = cy+1;
            nd=3;
            pd=2;
        }
        
        if(nx<0 || nx > 10 || ny<0 || ny>10) continue;
        
        if(!visited[nd][nx][ny] && !visited[pd][cx][cy]){
            answer++;
        }
        visited[nd][nx][ny] = true;
        
        cx=nx;
        cy=ny;
    }
    
    return answer;
}