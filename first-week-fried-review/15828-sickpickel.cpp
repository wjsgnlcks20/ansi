#include <bits/stdc++.h>

using namespace std;

int main(void){
    int N, input;
    queue <int> q;
    cin >> N;
    cin >> input;

    while(input != -1){
        if(input != 0){
            if(q.size() == N) continue;
            else q.push(input);
        }
        else{
            q.pop();
        }
        cin >> input;
    }
    if(q.empty()) {cout << "empty\n"; return 0;}
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}