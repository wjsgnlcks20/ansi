#include <bits/stdc++.h>

using namespace std;

void solve(){
    stack<char> s;
    string input;
    cin >> input;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == ')'){
            if(s.size() && s.top() == '(')
                s.pop();
            else {
                cout << "NO\n";
                return;
            }
        }
        else{
            s.push(input[i]);
        }
    }
    if(s.empty()) cout << "YES\n";
    else cout << "NO\n";
}

int main(void){
    int T; cin >> T;
    while(T--) solve();
    return 0;
}