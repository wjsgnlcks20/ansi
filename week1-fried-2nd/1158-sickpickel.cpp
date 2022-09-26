#include <bits/stdc++.h>

using namespace std;

int main(void){
    int N, K;
    queue<int> q;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        q.push(i);
    }
    cout << "<";
    int limit = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(++limit == K) {
            limit = 0;
            cout << now + 1;
            if(q.empty()) cout << ">";
            else cout << ", ";
        }
        else {
            q.push(now);
        }
    }
    return 0;
}