#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int stack_func(string cmd, int input){
    if(cmd == "push"){
        s.push(input);
        return 0;
    }
    else if(cmd == "top"){
        if(s.size() != 0) return s.top();
        return -1;
    }
    else if(cmd == "empty"){
        if(s.empty()) return 1;
        return 0;
    }
    else if(cmd == "size"){
        return s.size();
    }
    else{
        if(s.empty()) return -1;
        else {
            int ret = s.top(); s.pop();
            return ret;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, input;
    cin >> N;
    string cmd;

    for(int i = 0; i < N; i++){
        cin >> cmd;
        if(cmd == "push") {
            cin >> input;
            stack_func(cmd, input);
        }
        else cout << stack_func(cmd, input) << "\n";
    }
    return 0;
}