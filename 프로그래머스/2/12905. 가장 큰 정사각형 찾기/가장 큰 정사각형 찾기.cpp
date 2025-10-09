#include <bits/stdc++.h>
using namespace std;


int solution(vector<vector<int>> board)
{
    int n = board.size(); 
    int m = board[0].size(); 
    int answer = board[0][0];
    
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(board[i][j]==1){
                board[i][j] = 1 + min({board[i-1][j], board[i-1][j-1], board[i][j-1]});
                answer = max(answer, board[i][j]); 
            }
        }
    }

    return answer*answer;
}


