#include <bits/stdc++.h>

using namespace std;

typedef int(*parr)[9];

int board[9][9], flag = 0;
int box[9][10], row[9][10], col[9][10];

void printArr(parr arr){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int getboxNum(int y, int x){
    int idx = 0;
    for(int i = 3; i <= 9; i += 3){
        for(int j = 3; j <= 9; j += 3){
            if(y < i && x < j) return idx;
            idx++;
        }
    }
    return -1;
}

int ispossible(int y, int x, int idx){
    if(row[y][idx] || col[x][idx] || box[getboxNum(y, x)][idx]) return 0;
    return 1;
}

void play(int idx, parr board, vector<pair<int, int>> & zeros){
    if(flag) return;
    if(idx == zeros.size()){
        printArr(board); 
        flag = 1;
        return;
    }
    int y = zeros[idx].first;
    int x = zeros[idx].second;

    for(int j = 1; j <= 9; j++){
        if(!ispossible(y, x, j)) continue;
        board[y][x] = j;
        row[y][j] = col[x][j] = box[getboxNum(y, x)][j] = 1;
        play(idx + 1, board, zeros);
        if(flag) return;
        board[y][x] = row[y][j] = col[x][j] = box[getboxNum(y, x)][j] = 0;
    }
}

int main(void){
    vector<pair<int, int>> zeros;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) {zeros.push_back({i, j}); continue;}
            row[i][board[i][j]] = col[j][board[i][j]] = box[getboxNum(i, j)][board[i][j]] = 1;
        }
    } 
    cout << "\n";
    play(0, board, zeros);
    return 0;
}