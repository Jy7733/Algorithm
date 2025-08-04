#include <bits/stdc++.h> 

using namespace std;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0}; 

int target = 0; 
int tx = 0, ty = 0; 
int tn = 0, tm = 0; 

vector<string> pathList; 
bool found; 

char intToChar(int dir){
    char direction; 
    if(dir == 0) direction = 'd';
    else if(dir == 1) direction = 'l';
    else if(dir == 2) direction = 'r';
    else if(dir == 3) direction = 'u';
    return direction; 
}

void DFS(int x, int y, int cnt, string path){
    
    if(found) return; 
    
    int dist = abs(tx - x) + abs(ty - y); 
    int remain = target - cnt; 
    
    if(remain < dist) return; // 도달 불가능한 경우 
    if ((remain - dist) % 2 != 0) return; 
    
    if(cnt == target){
        if(x == tx && y == ty){
            pathList.push_back(path); 
            found = true; 
            return; 
        }
        return; 
    }
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= tn || ny < 0 || ny >= tm) continue; 
        char direction = intToChar(i); 
        
        path.push_back(direction); 
        DFS(nx, ny, cnt+1, path); 
        path.pop_back();
        if(found) return; 
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    target = k;
    tx = r-1; 
    ty = c-1; 
    tn = n; 
    tm = m; 
    
    string p; 
    DFS(x-1, y-1, 0, p); 
    
    if(pathList.empty()){
        answer = "impossible";
    }
    else{
        for(auto s : pathList[0]){
            answer += s;
        }
    }
    return answer;
}

