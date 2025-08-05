#include <bits/stdc++.h> 

using namespace std;

vector<vector<int>> pillar; 
vector<vector<int>> beam; 
int sz = 0;

void buildPillar(int x, int y){
    
    bool able = false; 
    // 바닥 위에 있는 경우
    if(y == 0) able = true; 
    
    // 보의 한쪽 끝 부분 위
    else if(beam[x][y] != 0 || (x-1 >= 0 && beam[x-1][y] != 0)) able = true; 
    
    // 다른 기둥 위
    else if(y - 1 >= 0 && pillar[x][y - 1] != 0) able = true;
     
    if(able){
        pillar[x][y] = 1;
    }
}

void buildBeam(int x, int y){
    bool able = false; 
    
    // 한쪽 끝이 기둥 위
    if ((y - 1 >= 0 && pillar[x][y - 1] != 0) || (x + 1 < sz && y - 1 >= 0 && pillar[x + 1][y - 1] != 0))
        able = true; 
    
    // 양쪽 끝이 연결되어 있는 경우
    else if((x-1>=0 && beam[x-1][y] != 0) && (x+1 <sz && beam[x+1][y] != 0)) able = true; 
    
    if(able){
        beam[x][y] = 1;
    }
}

bool isValidate(){
    for(int x=0; x<sz; x++){
        for(int y=0; y<sz; y++){
            if(pillar[x][y]){
                if(!((y==0) || (beam[x][y] != 0 || (x-1 >= 0 && beam[x-1][y] != 0)) || y - 1 >= 0 && pillar[x][y - 1] != 0)) 
                    return false; 
            }
            if(beam[x][y]){
                if(!((y - 1 >= 0 && pillar[x][y - 1] != 0) || (x + 1 < sz && y - 1 >= 0 && pillar[x + 1][y - 1] != 0)
                   || (x-1>=0 && beam[x-1][y] != 0) && (x+1 <sz && beam[x+1][y] != 0)))
                    return false;
            }
        }
    }
    return true;
}

vector<vector<int>> findAnswer(vector<vector<int>> answer){
    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            if(pillar[i][j] != 0){
                answer.push_back({i,j,0});
            }
            if(beam[i][j] != 0){
                answer.push_back({i,j,1});
            }
        }
    }
    
    sort(answer.begin(), answer.end()); 
    return answer; 
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    pillar.resize(n+1); 
    beam.resize(n+1); 
    
    sz = n+1; 
    
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            pillar[i].push_back(0);
            beam[i].push_back(0); 
        }
    }
    
    for(auto frame : build_frame){
        int x = frame[0];
        int y = frame[1]; 
        int type = frame[2];
        int cmd = frame[3]; 
        if(cmd == 1){
            if(type == 0) buildPillar(x,y);
            else buildBeam(x,y); 
        }
        else{
            if(type == 0){
                pillar[x][y] = 0;
                if(!isValidate()) pillar[x][y] = 1;
            }
            else {
                beam[x][y] = 0;
                if(!isValidate()) beam[x][y] = 1; 
            }
        }
    }


    return findAnswer(answer);
}