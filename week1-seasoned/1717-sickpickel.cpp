#include <bits/stdc++.h>
#define Max 1000010

using namespace std;

int root[Max];

int find(int x){
    if(x == root[x]) return x;
    return root[x] = find(root[x]);
}

void unify(int x, int y){
    x = find(x);
    y = find(y);
    if(x < y) root[x] = y;
    else root[y] = x;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, u, v, cmd;
    cin >> N >> M;
    for(int i = 0; i <= N; i++){
        root[i] = i;
    }
    for(int i = 0; i < M; i++){
        cin >> cmd >> u >> v;
        if(cmd == 0){
            unify(u, v);
        }
        else{
            int flag = (find(u) == find(v));
            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}