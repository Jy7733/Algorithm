#include <bits/stdc++.h> 

using namespace std;

int n;
int targetCnt; //바꿔야하는 문자 수 
vector<bool> needChange; 
int answer = 0;
string str; 

// 알파벳 변경횟수
void changeCnt(){
    for(int i=0; i<n; i++){
        if(needChange[i] == false) continue; 
        int seq = (int)(str[i]-'A'); 
        int rev = (int)('Z'-str[i]+1); 
        
        answer += min(seq, rev); 
    }
}

// 커서이동횟수 
void moveCursor(){
    if(targetCnt == 0) return; 
    int moveCnt = n-1; 
    
    for(int i=0; i<n; i++){
        int next = i+1;
        while(next < n && str[next]=='A') next++; //A연속 개수 
        int leftFirst = i*2 + (n-next);
        int rightFirst = (n-next)*2 + i; 
        moveCnt = min(moveCnt, min(leftFirst, rightFirst));
    }
    
    answer += moveCnt; 
}

int solution(string name) {
    
    str = name; 
    
    n = name.size(); 
    needChange.resize(n, false); 
    
    for(int i=0; i<name.size(); i++){
        if(name[i] != 'A') {
            needChange[i] = true; 
            targetCnt++; 
        }
    }
    
    changeCnt(); 
    moveCursor(); 
    
    return answer;
}