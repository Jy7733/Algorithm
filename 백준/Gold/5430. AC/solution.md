## 💡 알고리즘 분류

- 구현
- 자료 구조
- 문자열
- 파싱
- 덱

## 🔎 접근 방식

- R → 뒤집기
- D → 첫 번째 수 버리기 → 큐 를 사용할 수 있지 않을까?
- 만약 R 동작 수행을 위해서 :
    
    → **reverse함수를 사용한다면? :**  p 10만개가 모두 R이면 → 10만 x 10만 ⇒ 시간초과가 날듯
    
    → **stack 에 옮긴다면? :** 이것도 어쨋든 반복이다. 
    
    →  **R 에 대해서 아예 아무 동작을 하지 않는 방법을 생각해보자!** 
    
- **구현 :**
    - `Deque`를 사용하면서, R이 나오면 flag만 바꿔주는 방법을 사용한다.
    - flag = true면 D를 수행할 때 / 출력할 때 - front 삭제 / 출력
    - flag = false면 D를 수행할 때 / 출력할 때 - back 삭제 / 출력

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n = 0;
	string p = ""; //함수 
	string input = "";
	deque<int> dq;
	vector<string> result;
	
	cin>>t;
	
	for(int i=0; i<t; i++){
		cin>>p;
		cin>>n;
		cin>>input;

		bool flag = true; 
		bool error = false;

		//문자열 파싱 
		input = input.substr(1,input.size()-2);
		if (!input.empty()) { // 빈 배열이 아닌 경우만 파싱
            istringstream ss(input);
            string str;
            while (getline(ss, str, ',')) {
                dq.push_back(stoi(str));
            }
        }

		for(auto func : p){

			//R이면 flag만 바꿔줌
			if(func == 'R'){
				flag = !flag; //true면 false, false면 true로 변경
			}

			else if(func == 'D'){
				if(dq.empty()){
					error = true;
					break;
				}
				else if(flag == true){ 
					dq.pop_front();
				}
				else if(flag == false){
					dq.pop_back();
				}
			}
		}

		if(error) result.push_back("error");

		else {
            string tmp = "[";
            if (!flag) {
                while (!dq.empty()) {
                    tmp += to_string(dq.back());
                    dq.pop_back();
                    if (!dq.empty()) tmp += ",";
                }
            } else {
                while (!dq.empty()) {
                    tmp += to_string(dq.front());
                    dq.pop_front();
                    if (!dq.empty()) tmp += ",";
                }
            }
            tmp += "]";
            result.push_back(tmp);
        }
	}

	for(auto answer : result){
		cout<<answer<<"\n";
	}
}
```
