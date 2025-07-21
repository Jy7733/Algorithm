#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool arr[n+1][n+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            arr[i][j] = false;
        }
    }
    
    for(auto result : results){
        arr[result[0]][result[1]] = true;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int z=1; z<=n; z++){
                if(arr[j][i] && arr[i][z]) arr[j][z] = true;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(arr[i][j] || arr[j][i]) cnt++;
        }
        if(cnt == (n-1)){
            answer++;
        }
    }
    
    return answer;
}
