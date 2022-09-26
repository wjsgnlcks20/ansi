#include <bits/stdc++.h>
#define Max 21

using namespace std;

typedef int(*parr)[Max];

int R, C, ans = 0;
char board[Max][Max];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

vector<pair<int, int>> save_path;

void dfs(int y, int x, int depth, int visited){

    ans = max(ans, depth);

    visited |= (1 << (board[y][x] - 'A'));

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if((visited & (1 << (board[ny][nx] - 'A')))) continue;
        save_path.push_back({ny, nx});
        dfs(ny, nx, depth + 1, visited); 
        save_path.pop_back();
    }
    visited &= (1 << (board[y][x] - 'A'));
}

int main(void){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }
    // 매 dfs 마다 값을 새로 구하기보다 메모이제이션을 통해 탐색시간을 줄일 수 있지 않을까
    // bitmasking 사용해서 방문 경로 비교 통해서 아예 다른 경로를 가진 경우에만 캐시 가져옴
    dfs(0, 0, 1, 0);
    
    cout << ans << "\n";
    return 0;
}