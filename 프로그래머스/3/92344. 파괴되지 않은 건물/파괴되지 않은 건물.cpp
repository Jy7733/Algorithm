#include <bits/stdc++.h>

const int TYPE = 0, R1 = 1, C1 = 2, R2 = 3, C2 = 4, DEGREE = 5;


using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int n = board.size();
    int m = board[0].size();
    
    int sum[n+1][m+1];
    
    for(int i=0; i<n+1; i++){
        fill(sum[i], sum[i] + m+1, 0);
    }
    
    // 누적합 기록 
    for(auto s : skill){
        int type = s[TYPE];
        int r1 = s[R1];
        int r2 = s[R2];
        int c1 = s[C1];
        int c2 = s[C2];
        int degree = s[DEGREE];
        
        if(type == 1) degree = (-1)*degree;
        
        sum[r1][c1] += degree;
        sum[r2+1][c1] -= degree;
        sum[r1][c2+1] -= degree;
        sum[r2+1][c2+1] += degree;
    }
    
    // 행 기준 누적합 계산 
    for(int i=0; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            sum[i][j] += sum[i][j-1];
        }
    }
    
    // 열 기준 누적합 계산
    for(int i=0; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            sum[j][i] += sum[j-1][i];
        }
    }
    
    // board 값과 병합 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] + sum[i][j] > 0) answer++;
        }
    }
    return answer;
}

