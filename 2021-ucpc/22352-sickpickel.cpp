#include <bits/stdc++.h>
#define Max 31

using namespace std;


int N, M;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

typedef int(*parr)[Max];

void dfs(int y, int x, parr travel, parr mark, int id){
    mark[y][x] = id;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(mark[ny][nx]) continue;
        if(travel[y][x] != travel[ny][nx]) continue;
        dfs(ny, nx, travel, mark, id);
    }    
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

    int before_mem[Max][Max] = {}, after_mem[Max][Max] = {};
    int id = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(before_mem[i][j]) continue;
            dfs(i, j, before, before_mem, id++);
        }
    }
    id = 1;
    cout << "\n";
    printArr(before_mem);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(after_mem[i][j]) continue;
            dfs(i, j, after, after_mem, id++);
        }
    }
    printArr(after_mem);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(before_mem[i][j] != after_mem[i][j]) {cout << "NO\n"; return 0;}
        }
    }

    cout << "YES\n";
    return 0;
}