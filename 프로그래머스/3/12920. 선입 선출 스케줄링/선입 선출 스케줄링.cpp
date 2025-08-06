#include <bits/stdc++.h>

using namespace std;

int cntJobs(int mid, vector<int> cores){
    int jobs = 0;
    for(auto core : cores){
        jobs += mid / core; 
    }
    return jobs; 
}

int solution(int n, vector<int> cores) {
    int answer = 0;
    if(n <= cores.size()) return n;

    int max_time = *max_element(cores.begin(), cores.end()); 

    int left = 0; 
    int right = n * max_time; // 최대로 걸릴 수 있는 시간 
    int time =0; // n번째 작업이 처리되기 까지 걸리는 최소 시간 

    while(left < right){
        int mid = (left + right) / 2; 
        int jobs = 0; 
        //처리 가능한 작업 수 계산 
        jobs = cntJobs(mid, cores) + cores.size(); 
        if(jobs < n) left = mid+1; 
        else right = mid; 
    }
    time = left;  

    // time - 1 까지 처리된 작업 수 계산 
    int jobs = cntJobs(time-1, cores) + cores.size(); 

    for(int i=0; i<cores.size(); i++){
        if(time % cores[i] == 0){
            jobs++;
            if(jobs == n){
                return i+1; 
            }
        }
    }
    return -1; 
}
