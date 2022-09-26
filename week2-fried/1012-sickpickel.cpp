#include <bits/stdc++.h>
#define Max 51

using namespace std;

typedef int(*parr)[Max];

int N, M;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void dfs(int y, int x, parr visited, parr arr){
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx] || arr[ny][nx] == 0) continue;
        dfs(ny, nx, visited, arr);
    }
}

void solve(){
    int K, X, Y;
    cin >> M >> N >> K;
    int arr[Max][Max] = {};

    for(int i = 0; i < K; i++){
        cin >> X >> Y;
        arr[Y][X] = 1;
    }

    int visited[Max][Max] = {}, answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] || arr[i][j] == 0) continue;
            dfs(i, j, visited, arr);
            answer++;
        }
    }
    cout << answer << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}