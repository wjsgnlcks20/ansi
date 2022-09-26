#include <bits/stdc++.h>
#define Max 1001

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
    int N, M, u, v;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        root[i] = i;
    }
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        u--; v--;
        if(find(u) != find(v)) {
            unify(u, v);
        }
    }
    int group_leader[Max] = {}, answer = 0;
    for(int i = 0; i < N; i++){
        group_leader[find(i)] = 1;
    }
    for(int i = 0; i < N; i++){
        if(group_leader[i]) answer++;
    }
    cout << answer << "\n";
    return 0;
}