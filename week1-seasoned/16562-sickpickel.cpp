#include <bits/stdc++.h>
#define Max 10002

using namespace std;

int root[Max], friend_fee[Max]; 

int find(int x){
    if(x == root[x]) return x;
    return root[x] = find(root[x]);
}

void unify(int x, int y){
    x = find(x);
    y = find(y);

    if(friend_fee[x] < friend_fee[y]) root[y] = x;
    else root[x] = y;
}

int main(void){
    int N, M, K, u, v, joonseok = 0;
    cin >> N >> M >> K;
    vector<pair<int, pair<int, int>>> edge;

    for(int i = 1; i <= N; i++){
        cin >> friend_fee[i];
        root[i] = i;
    }
    
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        if(find(u) != find(v)){
            unify(u, v);
        }
    }

    int price_sum = 0;
    for(int i = 1; i <= N; i++){
        if(find(i) != find(joonseok)){
            price_sum += friend_fee[find(i)];
            unify(i, joonseok);
        }
    }

    if(price_sum > K){ cout << "Oh no\n"; return 0;};
    cout << price_sum << "\n";
    return 0;
}