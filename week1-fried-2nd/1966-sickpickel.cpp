#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N, M, input;
    double ave = 0;
    pair<int, int> save;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        if(i == M) save = {input, i};
        q.push({input, i});
        pq.push(input);
    } 
    int clock = 0;
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        if(now.first == pq.top()){
            pq.pop();
            ++clock;
            if(now == save) break;
        }
        else q.push(now);
    }
    while(!q.empty()) q.pop();
    
    cout << clock << "\n";
}

int main(void){
    int T; cin >> T;
    while(T--) solve();
    return 0;
}