#include <bits/stdc++.h>

using namespace std;



int main(void){
    int t;
    cin>>t;


    for(int i=0; i<t; i++){
        vector<string> str;

        int n; cin>>n;
        for(int i=0; i<n; i++){
            string input;
            cin>>input;
            str.push_back(input);
        }

        sort(str.begin(), str.end());

        int flag = 0;
        for(int i=0; i<str.size()-1; i++){
            string cur = str[i];
            string next = str[i+1];

            // 다음 문자열 길이가 더 작거나 같으면(-> 똑같은 번호는 안나오므로!) 비교할 필요 X 
            if(cur.length() >= next.length()) continue;

            if(next.substr(0,cur.length()) == cur){
                flag = 1;
                break;
            }

        }
        if(flag == 0) cout<<"YES\n";
        else cout<<"NO\n";
    }

}