#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;

    for(auto work : works) pq.push(work);
    
    for(int i=0; i<n; i++){
        int curTop = pq.top();
        if(curTop - 1 >= 0){
            pq.pop();
            pq.push(curTop - 1);
        }
    }
    
    while(!pq.empty()){
        answer += (pq.top() * pq.top());
        pq.pop();  
    }
    
    return answer;
}