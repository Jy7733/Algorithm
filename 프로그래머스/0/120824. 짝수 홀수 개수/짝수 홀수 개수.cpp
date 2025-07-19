#include <string>
#include <vector>
 
using namespace std;
 
vector<int> solution(vector<int> num_list) {
    
    int even = 0, odd = 0;
    for(int i = 0; i < num_list.size(); i++)
    {
        if (num_list[i] % 2 == 0) even++;
        else odd++;
    }
    
    vector<int> answer {even, odd};
    
    return answer;
}
