#include <bits/stdc++.h>

using namespace std;

struct Job {
    int num;
    int requestTime;
    int runningTime; 
};

struct cmp {
    bool operator()(const Job &a, const Job &b){
        if(a.runningTime != b.runningTime){
            return a.runningTime > b.runningTime;
        }
        if(a.requestTime != b.requestTime){
            return a.requestTime > b.requestTime;
        }
        else return a.num > b.num;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<Job, vector<Job>, cmp> pq; 
    int n = jobs.size(); 
    
    int end = 0;
    int sum = 0;
    int time = 0;
    int cnt = 0; 
    int idx = 0; 
    
    sort(jobs.begin(), jobs.end()); // 요청시간 순서대로 정렬 
    
    while(cnt < n){
        //현재까지 들어온 요청 큐에 삽입
        while(idx < n && jobs[idx][0] <= time){
            pq.push({idx, jobs[idx][0], jobs[idx][1]});
            idx++;
        }
        
        // 실행가능한 작업이 있는 경우 
        if(!pq.empty()){
            auto current = pq.top(); pq.pop(); 
            time += current.runningTime;
            sum += (time - current.requestTime);
            cnt++;
        } else{
            //다음 작업 시작 시간으로 이동 
            time = jobs[idx][0];
        }
    }

    answer = (sum / n); 
    return answer;
}

// 우선순위
// 1. 작업 소요시간이 짧은 것
// 2. 요청 시각이 빠른 것
// 3. 번호가 작은 것

// pq: (1,2,3) (2,5,7) (3,7,8)
