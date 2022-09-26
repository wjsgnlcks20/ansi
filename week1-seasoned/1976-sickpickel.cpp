#include <bits/stdc++.h>
#define Max 201

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
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, input;
    cin >> N >> M;   

    for(int i = 0; i < N; i++) root[i] = i;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> input;
            if(input) unify(i, j);
        }
    }
    int travel_from, travel_to;
    for(int i = 0; i < M; i++){
        if(i==0) { cin >> travel_from; travel_from--; continue;}
        else { cin >> travel_to; travel_to--;}
        
        if(find(travel_from) != find(travel_to)) {
            cout << "NO\n"; return 0;
        }
    }
    cout << "YES\n";
    return 0;
}