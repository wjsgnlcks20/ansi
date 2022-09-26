#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, input;
    string cmd;
    queue<int> q;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> cmd;
        if(cmd == "push") {
            cin >> input;
            q.push(input);
        }
        else if(cmd == "front"){
            if(q.empty()) {cout << "-1\n"; continue;}
            cout << q.front() << "\n";
        }
        else if(cmd == "back"){
            if(q.empty()) {cout << "-1\n"; continue;}
            cout << q.back() << "\n";
        }
        else if(cmd == "size"){
            cout << q.size() << "\n";
        }
        else if(cmd == "empty"){
            cout << (q.empty() ? 1 : 0) << "\n";
        }
        else{
            if(q.empty()) {cout << "-1\n"; continue;}
            cout << q.front() << "\n";
            q.pop();
        } 
    }
    return 0;
}