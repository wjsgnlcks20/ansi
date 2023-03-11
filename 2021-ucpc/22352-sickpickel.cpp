#include <bits/stdc++.h>
#define Max 31

using namespace std;


int N, M, flag = 1;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

typedef int(*parr)[Max];

void dfs(int y, int x, parr travel, parr check, parr visited, int id){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx] || check[ny][nx] != check[y][x]) continue;

        dfs(ny, nx, travel, check, visited, id);
    }
    check[y][x] = id;
}

void printArr(parr arr){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int before[Max][Max], after[Max][Max];
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> before[i][j];
        }
    } 

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> after[i][j];
        }
    } 

    int visited[Max][Max] = {}, flag = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(before[i][j] == after[i][j]) continue;
            dfs(i, j, after, before, visited, after[i][j]);
            flag = 1; break; 
        }
        if(flag) break;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(before[i][j] != after[i][j]) {cout << "NO\n"; return 0;}
        }
    }
    cout << "YES\n";
    return 0;
}