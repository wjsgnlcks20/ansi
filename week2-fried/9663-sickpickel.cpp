#include <bits/stdc++.h>
#define Max 17

using namespace std;

int answer = 0;

int ispossible(int col, int N, int * row){
    for(int i = 0; i < col; i++){
        if(row[i] == row[col]) return 0;
        if(abs(i - col) == abs(row[i] - row[col]))return 0;
    }
    return 1;
}

void nqueen(int col, int N, int * row){
    if(col == N) {answer++; return;}

    for(int i = 0; i < N; i++){
        row[col] = i;
        if(ispossible(col, N, row)) nqueen(col + 1, N, row);
        else row[col] = -1;
    }
}

int main(void){
    int N, row[Max];
    cin >> N;
    for(int i = 0; i < N; i++) row[i] = -1;
    nqueen(0, N, row);
    cout << answer << "\n"; 
    return 0;
}