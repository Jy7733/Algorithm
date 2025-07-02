#include <bits/stdc++.h>

using namespace std;

bool able(vector<int> stones, int k, int people){
    int cnt = 0;
    for(int stone : stones){
        if((stone - people) < 0) cnt++;
        else cnt = 0;
        
        if(cnt >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());
    
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(able(stones, k, mid)){
            answer = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    
    return answer;
}