#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> st;
    
    for(auto c : s){
        if(!st.empty() && c == ')'){
            if(st.top() == '('){
                st.pop();
            }
        }
        else if(c == '('){
            st.push(c);
        }
        else if(st.empty() && c == ')'){
            answer = false;
            break;
        }
    }
    
    if(!st.empty()) answer = false;

    return answer;
}


