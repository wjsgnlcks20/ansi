#include <bits/stdc++.h>
#define Max 1001

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
    int N, M, u, v, c;
    cin >> N >> M;
    vector<pair<int, pair<int, int>>> edge;
    for(int i = 0; i < N; i++){
        root[i] = i;
    }

    for(int i = 0; i < M; i++){
        cin >> u >> v >> c;
        edge.push_back({c, {u - 1, v - 1}});
    }
    sort(edge.begin(), edge.end());
    int answer = 0;
    for(int i = 0; i < edge.size(); i++){
        int cost = edge[i].first;
        pair<int, int> now = edge[i].second;
        if(find(now.first) != find(now.second)){
            unify(now.first, now.second);
            answer += cost;
        }
    }
    cout << answer << "\n";
    return 0;
}