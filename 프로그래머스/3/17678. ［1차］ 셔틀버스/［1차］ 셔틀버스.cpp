#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> shuttleTime;
vector<pair<int, int>> crewArrive; 
vector<priority_queue<pair<int,int>>> boarded;

void splitString(vector<string> timetable){
    for(auto time : timetable){
        int h = stoi(time.substr(0,2));
        int m = stoi(time.substr(3,2));   
    
        crewArrive.push_back({h,m});
    }
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    boarded.resize(n);
    
    // timestring -> (int,int 로 변환)
    splitString(timetable); 
    sort(crewArrive.begin(), crewArrive.end());
    
    //shuttleTime 초기화 
    shuttleTime.push_back({9,0});
    int hour = 9;
    int minute = 0;
    for(int i=1; i<n; i++){
        minute += t;
        if(minute >= 60){
            hour+=1;
            minute-=60;
        }
        shuttleTime.push_back({hour,minute});
    }
    
    int i=0,j=0,size=0;
    
    while((i < n) && (j < timetable.size())){
                      
        int sH = shuttleTime[i].first; 
        int sM = shuttleTime[i].second;
        
        int cH = crewArrive[j].first;
        int cM = crewArrive[j].second; 
        
        // 탑승 가능한 경우 
        if((sH > cH) || ((sH == cH) && (sM >= cM ))){
            boarded[i].push({cH, cM});
            
            size++;
            j++;

            if (size == m) {
                i++;
                size = 0;
            }
        }
        
        // 현재 시간에 탑승 불가인 경우 
        else if((sH < cH) || ((sH == cH) && (sM < cM))){
            size = 0; 
            i++;  // 다음 시간으로 
        }
    }
    
    int connH = 0;
    int connM = 0;
    
    // 인원수 가 다찼으면 -> 가장 뒤 크루보다 1분 빠르게 
    if(boarded[n-1].size() == m){
        // 가장 뒤 크루 도착 시간 
        
        auto time = boarded[n-1].top(); 
        
        if(time.second == 0){
            connH = time.first-1;
            connM = 59;
        }
        else{
            connH = time.first;
            connM = time.second-1;
        }
    }
    
    // 인원수 미달 -> 가장 늦은 셔틀 시간
    else if(boarded[n-1].size() < m){
        auto time = shuttleTime[n-1];
        connH = time.first;
        connM = time.second;
    }
    
    char buffer[6];
    sprintf(buffer, "%02d:%02d", connH, connM);
    answer = string(buffer);
    return answer;
}


