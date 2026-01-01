#include <bits/stdc++.h>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    int st=1, en=distance;
    int rockCnt=rocks.size(); 
    sort(rocks.begin(), rocks.end());
    
    while(st <= en){
        int cur=0; 
        int cnt=0; 
        int mid=(st+en)/2; 
        
        for(int i=0; i<rockCnt; i++){
            if(rocks[i] >= cur+mid){
                cnt++; 
                cur = rocks[i]; 
            }
        }
        if(distance >= cur+mid) cnt++;
        
        if(cnt >= rockCnt-n+1){
            answer = mid; 
            st=mid+1;
        }
        else{
            en=mid-1; 
        }
    }
    
    return answer;
}