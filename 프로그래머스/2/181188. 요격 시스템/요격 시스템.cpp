#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end()); 
    
    int start = 0, end = 0; 
    
    for(auto target : targets){
        // 겹치는 구간
        if(target[0] < end){
            start = max(start, target[0]); 
            end = min(end, target[1]); 
        }
        else if(target[0] >= end){
            start = target[0]; 
            end = target[1]; 
            answer++;
        }
    }
    return answer;
}

/*
[4,5],[4,8],[10,14],[11,13],[5,12],[3,7],[1,4]
-> sort
[1,4]
[3,7]
[4,5]
[4,8]
[5,12]
[10,14]
[11,13]

*/

