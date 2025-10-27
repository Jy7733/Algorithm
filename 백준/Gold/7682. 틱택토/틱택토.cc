#include <bits/stdc++.h>
using namespace std;

bool checkValid(string str){
    int xCnt = 0;
    int oCnt = 0; 
    for(int i=0; i<9; i++){
        if(str[i] == 'X') xCnt++;
        else if(str[i] == 'O') oCnt++; 
    }

    // 가로 체크 
    bool oDone = false; 
    bool xDone = false; 
    for(int i=0; i<=6; i+=3){
        if(str[i]=='.') continue;
        else if((str[i]==str[i+1]) && (str[i+1]==str[i+2])){
            if(str[i] == 'O') oDone=true; 
            else if(str[i] == 'X') xDone=true;  
        }
    }

    // 세로 체크
    for(int i=0; i<3; i++){
        if(str[i] == '.') continue;
        else if((str[i]==str[i+3]) && (str[i+3]==str[i+6])){
            if(str[i] == 'O') oDone=true; 
            else if(str[i] == 'X') xDone=true;
        }
    }
    // 대각선 체크
    if(((str[0] == str[4]) && (str[4] == str[8]))
        || ((str[2] == str[4])&&(str[4] == str[6]))){
            if(str[4] == 'O') oDone = true; 
            else if(str[4] == 'X') xDone = true; 
        }

   // X가 승리하는 경우
   if(xDone && !oDone && (xCnt == oCnt+1)) return true; 
   
   // O가 승리하는 경우
   else if(!xDone && oDone && (xCnt == oCnt)) return true;

   // 비기는 경우
   else if(!xDone && !oDone && (xCnt==5 && oCnt==4)) return true;

   else if(xDone && oDone) return false; 

   else return false; 
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    
    while(true){
        string str; 
        cin>>str;
        if(str == "end") break;
        if(checkValid(str)) cout<<"valid\n";
        
        else cout<<"invalid\n";
    }
}