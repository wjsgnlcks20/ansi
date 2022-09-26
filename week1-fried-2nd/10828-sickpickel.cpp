#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, input;
    string cmd;
    stack<int> s;
    cin >> N;
    while(N--){
        cin >> cmd;
        if(cmd == "push") {
            cin >> input;
            s.push(input);
        }
        else if(cmd == "pop"){
            if(s.empty()) {cout << "-1\n"; continue;}
            cout << s.top() << "\n";
            s.pop();
        }
        else if(cmd == "size"){
            cout << s.size() << "\n";
        }
        else if(cmd == "empty"){
            cout << (s.empty() ? 1 : 0) << "\n";
        }
        else {
            if(s.empty()) {cout << "-1\n"; continue;}
            cout << s.top() << "\n";
        }
    }
    return 0;
}