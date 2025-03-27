#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> task; 
    for(int work : works){
        task.push(work);
    }
    
    for(int i=0; i<n; i++){
        int curTask = task.top();
        if(curTask == 0) continue;
        task.pop();
        task.push(curTask-1);
    }
    
    while(!task.empty()){
        answer+=( task.top() * task.top());
        task.pop();
    }
    return answer;
}