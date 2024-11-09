#include <bits/stdc++.h>
using namespace std;

int arr[26]; 
int result[21];
int wordSize;
set<string> uniquePermutations; 

void func(int k) {
    if (k == wordSize) {
        string permutation;
        for (int i = 0; i < k; i++) {
            permutation += (char)(result[i] + 'a');
        }
        
        if (uniquePermutations.find(permutation) == uniquePermutations.end()) {
            uniquePermutations.insert(permutation); // 새로운 순열 추가
            cout << permutation << "\n"; // 중복되지 않는 경우에만 출력
        }
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (arr[i] > 0) {
            arr[i] -= 1;
            result[k] = i;
            func(k + 1);
            arr[i] += 1;
        }
    }
}

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        // 배열과 집합 초기화
        fill(begin(arr), end(arr), 0);
        uniquePermutations.clear();

        for (char c : word) {
            arr[c - 'a'] += 1;
        }

        wordSize = word.size();
        func(0);
    }
}
