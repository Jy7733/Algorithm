#include <bits/stdc++.h>

using namespace std;




vector<int> solution(vector<string> operations) {
    vector<int> answer;    
    
    multiset<int> ms;
    
    int cnt = 0; //큐에 남아있는 원소의 개수 
    
    for(auto op : operations){
        
        //I -> 삽입 
        if(op[0] == 'I'){
            int num = stoi(op.substr(2));
            ms.insert(num);
            cnt++;
        }
        
        //D -> 최댓값 or 최솟갑 삭제 
        else if(!ms.empty() && op[0] == 'D'){
            
            //D 1 -> 최댓값 삭제 
            if(op[2] == '1'){
                ms.erase(prev(ms.end()));
            }
                
            //D -1 -> 최솟값 삭제 
            else{
                ms.erase(ms.begin());
            }
        }   
    }
    
    return ms.empty() ? vector<int>{0, 0} : vector<int>{*prev(ms.end()), *ms.begin()};
}

