#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int maxScore = 0;
    
    pair<int,int> target = {scores[0][0], scores[0][1]};
    
    sort(scores.begin(), scores.end(), [](vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });
    
    for(auto s : scores){
        if (s[1] < maxScore){
            if(s[0] == target.first && s[1] == target.second) return -1;
            continue;
        }
        if (s[0] + s[1] > target.first + target.second) answer++;
        maxScore = max(maxScore, s[1]);
    }
    
    return answer;
}

