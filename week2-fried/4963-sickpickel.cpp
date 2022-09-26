#include <bits/stdc++.h>
#define Max 51

using namespace std;

typedef int(*parr)[Max];

int dy[8] = { 1, -1, 0, 0, -1, -1, 1, 1}; 
int dx[8] = { 0, 0, 1, -1, -1, 1, -1, 1}; 

void dfs(int y, int x, int H, int W, parr visited, parr arr){
    visited[y][x] = 1;
    for(int i = 0; i < 8; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        
        if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
        
        if(visited[ny][nx] || arr[ny][nx] == 0) continue;
        
        dfs(ny, nx, H, W, visited, arr);
    }
}

void solve(int W, int H){
    int arr[Max][Max] = {}, visited[Max][Max] = {};
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(visited[i][j] || arr[i][j] == 0) continue;
            dfs(i, j, H, W, visited, arr);
            ans++;
        }
    }
    cout << ans << "\n";
}

int main(void){
    int W, H;
    while(1){
        cin >> W >> H;
        if(W == 0 && H == 0) break;
        solve(W, H);
    }
    return 0;
}