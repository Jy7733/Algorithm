#include <bits/stdc++.h> 

using namespace std;

int timeToSecond(string str) {
    int h = stoi(str.substr(0, 2)) * 3600; 
    int m = stoi(str.substr(3, 2)) * 60; 
    int s = stoi(str.substr(6, 2)); 
    return h + m + s; 
}

string secToTime(int t) {
    char buf[10];
    sprintf(buf, "%02d:%02d:%02d", t/3600, (t%3600)/60, t%60);
    return string(buf);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int playTime = timeToSecond(play_time); 
    int advTime = timeToSecond(adv_time); 
    vector<long long> sum(playTime + 1, 0); 
    
    for (auto &log : logs) {
        int startTime = timeToSecond(log.substr(0, 8));
        int endTime = timeToSecond(log.substr(9, 8));
        sum[startTime] += 1; 
        sum[endTime] -= 1; 
    }    
    
    // 1차 누적합: 초별 시청자 수
    for (int i = 1; i <= playTime; i++) {
        sum[i] += sum[i-1]; 
    }
    // 2차 누적합: 누적 시청 시간
    for (int i = 1; i <= playTime; i++) {
        sum[i] += sum[i-1]; 
    }
    
    long long maxTime = sum[advTime - 1];
    int bestStart = 0;
    for (int i = advTime; i <= playTime; i++) {
        long long watchTime = sum[i] - sum[i - advTime];
        if (watchTime > maxTime) {
            maxTime = watchTime;
            bestStart = i - advTime + 1;
        }
    }
    return secToTime(bestStart);
}


