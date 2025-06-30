#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, (int)gems.size()-1};
    
    // 보석 종류 
    set<string> gemTypes(gems.begin(), gems.end());
    int typeCnt = gemTypes.size();
    
    int minCnt = gems.size()-1;
    int start = 0, end = 0;
    map<string, int> m; 
    
    m[gems[0]]=1;
    
    while(start <= end && end < gems.size()){
        //현재 구간이 모든 종류 포함하는 경우 
        if(m.size() == typeCnt){
            //answer 배열 업데이트 
            if((end - start + 1) < minCnt){
                minCnt = end-start+1;
                answer = {start, end};
            }
            
            // start 한 칸 옮기기
            m[gems[start]]--;
            if(m[gems[start]] == 0){
                m.erase(gems[start]);
            }
            start++;
        }
        else{
            end++;
            if( end == gems.size()) break;
            m[gems[end]]++;
        }
    }
    
    answer[0]++;
    answer[1]++;
    return answer;
}        
