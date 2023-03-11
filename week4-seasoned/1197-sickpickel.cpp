#include <bits/stdc++.h>
#define Max 10001

using namespace std;

int root[Max];

int find(int x){
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void unify(int x, int y){
    x = find(x);
    y = find(y);

    if(x < y) root[x] = y;
    else root[x] = y;
}

int main(void){

    int V, E, A, B, C;
    cin >> V >> E;

    for(int i = 0; i < V; i++) root[i] = i;
    vector<pair<int, pair<int, int>>> edge;

    for(int i = 0; i < E; i++){
        cin >> A >> B >> C;
        A--; B--;
        edge.push_back({C, {A, B}});
    }
    int answer = 0;
    sort(edge.begin(), edge.end(), less<pair<int, pair<int, int>>>());
    for(int i = 0; i < edge.size(); i++){
        int c = edge[i].first;
        int u = edge[i].second.first;
        int v = edge[i].second.second;

        if(find(u) != find(v)){
            unify(u, v);
            answer += c;
        }
    }

    cout << answer << "\n";

    return 0;
}