#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int divN = n;
    
    if(s == 1 || n > s){
        answer.push_back(-1);
        return answer;
    }
    
    for(int i=0; i<n; i++){
        int div = s/divN; 
        answer.push_back(div);
        
        s-=div;
        divN-=1;
        
    }
    
    
    return answer;
}