#include <bits/stdc++.h>
#define Max 1001

using namespace std;

typedef int(*parr)[Max];
int N;

void dfs(int now, int * visited, parr arr){

    visited[now] = 1;

    for(int i = 0; i < N; i++){
        if(visited[i] || arr[now][i] == 0) continue;
        dfs(i, visited, arr);
    }
}

int main(void){
    int M, u, v;
    int connection[Max][Max] = {};
    int visited[Max] = {};
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        --u; --v;
        connection[u][v] = 1;
        connection[v][u] = 1;
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        dfs(i, visited, connection);
        ans++;
    }
    cout << ans << "\n";
    return 0;
}