#include <bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

bool vecCmp(pair<string,int> &a, pair<string, int> &b){
    return a.second > b.second;
}


using pq = priority_queue< pair<int,int>, vector<pair<int,int>>, cmp>;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
   
    map<string, int> m; //장르별 재생횟수 합계 저장 
    map<string, pq> pm; //장르별 (재생횟수, 노래 인덱스) 저장    
    
    for(int i=0; i<genres.size(); i++){
        m[genres[i]] += plays[i];
        pm[genres[i]].push({plays[i], i});
    }
    
    // 재생횟수 합계 순으로 정렬 
    vector< pair<string,int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), vecCmp);
    
    for(auto v : vec){
        string genre = v.first;
        for(int i=0; i<2 && !pm[genre].empty(); i++){
            int musicIdx = pm[genre].top().second;
            answer.push_back(musicIdx);
            pm[genre].pop();
        }
    }
    
    return answer;
}