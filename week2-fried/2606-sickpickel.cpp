#include <bits/stdc++.h>
#define Max 101

using namespace std;

typedef int(*parr)[Max];

int N;

int connected(int now, parr arr, int * visited){
    int ret = 1;
    for(int i = 0; i < N; i++){
        if(visited[i] || arr[now][i] == 0) continue;
        visited[i] = 1;
        ret += connected(i, arr, visited);
    }
    return ret;
}

int main(void){
    int M, u, v;
    cin >> N >> M;

    int connection[Max][Max] = {};
    int visited[Max] = {};
    visited[0] = 1;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        connection[--u][--v] = 1;
        connection[v][u] = 1;
    }
    
    cout << connected(0, connection, visited) - 1 << "\n";
    return 0;
}