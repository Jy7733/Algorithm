#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int cover = w*2+1;
    int curPos = 1;
    int idx = 0; 
    
    while(curPos <= n){
        if(idx < stations.size() && curPos >= stations[idx]-w){
            curPos = stations[idx]+w+1;
            idx++;
        }else{
            answer++;
            curPos += cover; 
        }
    }
    return answer;
}




