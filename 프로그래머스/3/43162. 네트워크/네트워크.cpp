#include <string>
#include <vector>

using namespace std;
bool visited[201];
int answer = 0;

void DFS(int dest, int n, vector<vector<int>> computers){
    visited[dest] = true;
    
    for(int i=0; i<n; i++){
        if(computers[dest][i] == 1 && !visited[i]){
            DFS(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(computers[i][j] == 1 && !visited[j]){
                DFS(j, n, computers);
                answer++;
            }
        }
    }
    return answer;
}