#include <bits/stdc++.h> 

#define INF (~0U >> 2)

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INF; 
    int m = weak.size(); 
    // 배열 확장 
    for(int i=0; i<m; i++){
        weak.push_back(weak[i] + n); 
    }
    
    sort(dist.begin(), dist.end()); 
    
    do{
        for(int i=0; i<m; i++){
            int cnt = 1; 
            int cover = weak[i] + dist[cnt-1]; // 0번 친구가 커버하는 범위의 끝 지점 
            
            for(int j=i; j<i+m; j++){
                if(weak[j] > cover){ // 다음 취약지점이 이전 친구가 커버하는 범위 밖인 경우 
                    cnt++;
                    if(cnt > dist.size()) break; // 더 이상 투입할 친구가 없는 경우 종료 
                    cover = weak[j] + dist[cnt-1]; 
                }
            }
            
            answer = min(answer, cnt); 
        }
        
    }
    while(next_permutation(dist.begin(), dist.end())); 
    
    if(answer > dist.size()) return -1; 
    return answer;
}

