#include <bits/stdc++.h>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<int> prev(n);
    vector<int> next(n);
    stack<int> deleted;
    int cur = k;
    
    //초기화 
    for(int i=0; i<n; i++){
        prev[i] = i-1;
        next[i] = i+1;
    }
    next[n-1] = -1; 

    string command; 
    for(string c : cmd){
        if(c[0] == 'U' || c[0] == 'D'){
            int cnt = stoi(c.substr(2));
            if(c[0] == 'U'){
                while(cnt > 0){
                    cur = prev[cur];
                    cnt--;
                }
            }
            else{
                while(cnt > 0){
                    cur = next[cur];
                    cnt--;
                }
            }
        }
        else if(c[0] == 'C'){
            int prevNode = prev[cur];
            int nextNode = next[cur];

            if(nextNode != -1) prev[nextNode] = prevNode;
            if(prevNode != -1) next[prevNode] = nextNode;
            deleted.push(cur);
            
            // 커서 이동
            if(nextNode != -1) cur = nextNode;
            else cur = prevNode;
        }
        else{
            int latestDeleted = deleted.top(); deleted.pop();
            if(prev[latestDeleted] != -1) next[prev[latestDeleted]] = latestDeleted;
            if(next[latestDeleted] != -1) prev[next[latestDeleted]] = latestDeleted;
        }
    }

    string answer(n, 'O');
    while(!deleted.empty()){
        answer[deleted.top()] = 'X';
        deleted.pop();
    }

    return answer;
}