#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    ll left = 0;
    ll right = *max_element(times.begin(), times.end()) * n; 
    
    while(left <= right){
        ll mid = (left + right)/2;
        ll people =0; 
        
        for(auto time : times){
            people += mid/time; 
        }
        
        if(people >= n){
            answer = mid; 
            right = mid-1;
        }
        else{
            left = mid+1; 
        }
    }
    return answer;
}