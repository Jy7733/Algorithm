![image](https://github.com/user-attachments/assets/705d95f1-bffb-42c8-b49f-c78909bc1e2d)## 💡 알고리즘 분류

- 다이나믹 프로그래밍

**…으로 분류되어 있지만 나는 그냥 재귀로 풀었다..! 🔥** 

## 🔎 접근 방법

- **조건 확인하기**
    - 입력 ≤ 40자
    - 1 ≤ 각 카드에 적힌 숫자 ≤ 34 ⇒ **숫자 2개 까지밖에 못 묶는다.**
    - 위치는 변경하지 않음
- **경우의 수를 표로 그려보면 ⬇️**
![image](https://github.com/user-attachments/assets/23085590-c1bf-4732-b666-99e6054fd3bb)



- 각 단계에서 뒤에 오는 숫자랑 묶는 경우 vs 아닌 경우, 2개로 나뉘어진다.
    - `27` vs `2`  `7`
        
        → `27` | `1` | `2`  | vs `27` | `12` 
        
- 어떤 조합인지 기록할 필요 없이 **개수만** 카운트하면 됨 → **가능 vs 불가능만 확인**할 수 있으면 된다.

### 🚨 주의할 점 : `01` 은 `1` 이 아니다. & `0` 인 카드는 없다.

→ 이 부분에 대하여 예외처리를 해주어야 한다. 

→ 따라서 

- **묶지 않고 숫자 하나를 단독으로 쓰는 경우 :** 0이 아니라는 조건을 추가해주어야 한다.
    
    **`if(input[k] != 0)** countCombination(k+1);`
    
- **숫자 두 개를 묶는 경우 :** 앞에 숫자 (`input[k]` 가 0이 아니라는 조건을 추가해주어야 한다.)
    
    ```cpp
    if(k + 1 < input.size() && input[k] != 0){
    		int num = input[k] * 10 + input[k+1];
    		if(num >= 1 && num <= 34) countCombination(k+2);
    	}
    ```
    

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> input;

stack<int> s;

int cnt;

void countCombination(int k){

	if(k >= input.size()){
		cnt+=1;
		return;
	}

	if(input[k] != 0) countCombination(k+1);

	//묶을 수 있다면 ( 1이상, 34이하 )
	if(k + 1 < input.size() && input[k] != 0){
		int num = input[k] * 10 + input[k+1];
		if(num >= 1 && num <= 34) countCombination(k+2);
	}
}

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	string str; 
	cin>>str;

	//숫자로 변환 
	for(int i=0; i<str.size(); i++){
		input.push_back(str[i] - '0');
	}

	countCombination(0);
	cout<<cnt<<"\n";
}
```
