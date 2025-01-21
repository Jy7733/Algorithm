### 💡알고리즘 분류

---

- Divide and Conquer

### 🔎 알아야했던 것 !

---

- **최대 공약수 구하기 (유클리드 호제법)**
    
    함수 안에서 b가 0이 될 때 까지 a를 b로 나눈 나머지를 b에 대입하면서 최대 공약수를 구한다.
    
    ```cpp
    int gcd(int a, int b){
    	if(b == 0) return a;
    	return gcd(b, a%b);
    }
    ```
    
    ex) a = 24, b = 36 이라면, 
    
    gcd( 24, 36 ) → gcd( 36, 24 % 36 = 24) → gcd (24, 36 % 24 = 12) → gcd( 12, 24 % 12 = 0) ⇒ 최대공약수: 12
    

### ✅ 풀이

---

🔑 처음에 왼쪽 선택 / 오른쪽 선택. 이렇게 두 가지의 경우로 나뉘는데 → 이 두가지 경우에서의 최종 최대공약수 합을 비교한다.

```cpp
#include <bits/stdc++.h>

using namespace std;
vector<int> home;

//유클리드 호제를 이용한 최대공약수 구하기 
int gdb(int a, int b){
    if(b ==0){
        return a;
    }
    return gdb(b, a%b);
}

//선택 구간의 최대공약수 구하기 
int findGdb(int start, int end){

    int val = 0;

    for(int i=start; i<=end; i++){
        val = gcd(val, home[i]);
    }

    return val;
}

int divide(int start, int end){

    if(start == end) return home[start]; // 원소가 하나인 경우 그대로 반환 

    int mid = (start + end - 1)/2;
    
    int selectLeft = findGdb(start, mid) + divide(mid+1, end); //왼쪽을 선택했을 때 최대 공약수 구하기 + 나머지 부분 재귀로 다시 나누기 
    int selectRight = divide(start, mid) + findGdb(mid+1, end); //오른쪽 선택했을 때 최대 공약수 구하기 + 나머지 부분 재귀로 다시 나누기

    return max(selectLeft, selectRight); //최대공약수의 최대합
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        home.push_back(x);
    }

    cout<<divide(0,n-1);
}
```

### **📌 어려웠던 이유**

---

- Divide and Conquer 를 써야겠다고 생각해내지 못했다.
- 유클리드 호제법을 이용한 최대 공약수를 구하는 방법을 숙지하지 못했다.
- 재귀는 어렵다 ㅜ ㅅ ㅜ
