#include <bits/stdc++.h>

using namespace std;
int solution(string s)
{
    int answer=1;
    int center = 0;
    int n = s.size();
    
    for(int center=0; center<n; center++){
        int left = center; int right = center;
        
        while(left >= 0 && right < n && (s[left] == s[right])){
            answer = max(answer, (right - left) + 1);
            left--;
            right++;
        }
        
        left = center; right = center+1;
        while(left >= 0 && right < n && (s[left] == s[right])){
            answer = max(answer, (right - left) + 1);
            left--;
            right++;
        }
    }
    return answer;
}