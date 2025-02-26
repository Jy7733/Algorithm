#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    
    int left = 0; //가장 가벼운 사람  
    int right = people.size()-1; //가장 무거운 사람 
    
    int answer = 0;
    sort(people.begin(), people.end());
    
    while(left <= right){
        int sum = people[right] + people[left];
        
        if(sum > limit){
            right--;
        }
        else{
            right--;
            left++;
        }
        answer++;
    }
    
    return answer;
}