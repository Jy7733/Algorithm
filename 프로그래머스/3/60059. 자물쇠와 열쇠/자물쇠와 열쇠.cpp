#include <bits/stdc++.h>
using namespace std;

int point = 0; //자물쇠 홈 갯수 
vector<vector<int>> board;
int m = 0;
int n = 0;

//회전
void rotate(vector<vector<int>> &key) {
    vector<vector<int>> tmp = key;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            tmp[i][j] = key[j][m-1-i];
        }
    }
    
    key = tmp;
}

// unlock 가능한지 확인
int checkUnlock(vector<vector<int>> &key, int sx, int sy){
    int kx = 0;
    int ky = 0;
    int check = 0;
    
    for(int bx=sx; bx < sx + m; bx++, kx++){
        for(int by=sy,ky=0; by < sy+m; by++, ky++){
            if(board[bx][by] == 1 && key[kx][ky] == 1) return -1;
            if(board[bx][by] == 0 && key[kx][ky] == 0) return -1;
            if(board[bx][by] == 0 && key[kx][ky] == 1) check++;
        }
    }
    return check;
}

// 키 회전  이동 
bool moveKey(vector<vector<int>> &key){
    int check = 0;
    for(int R=0; R<4; R++){
        for(int i=0; i<m+n-1; i++){
            for(int j=0; j<m+n-1; j++){
                int result = checkUnlock(key,i,j);
                if(result == point) return true;
            }
        }
        rotate(key);
    }
    return false;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    n = lock.size();
    m = key.size(); 
    int sz = n + (m-1)*2;
    
    // 보드 확장 
    board.resize(sz, vector<int>(sz,2));
    
    for(int i=m-1, lockx=0; i< sz - (m-1); i++, lockx++){
        for(int j=m-1, locky=0; j<sz-(m-1); j++,locky++){
            board[i][j] = lock[lockx][locky];
            if(lock[lockx][locky] == 0) point++;
        }
    }
    
    // 회전 후 체크 
    answer = moveKey(key);
    
    return answer;
}


