#include <bits/stdc++.h>
#define Max 1001

using namespace std;

typedef long long ll;

int root[Max];

int find(int x){
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void unify(int x, int y){
    x = find(x);
    y = find(y);

    if(y < x) root[y] = x;
    else root[x] = y;
}

double get_dist(pair<double, double>a, pair<double, double>b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main(void){
    int N, M, u, v;
    double x, y;
    cin >> N >> M;
    vector<pair<double, pair<double, double>>> edge;
    vector<pair<int, int>> pos(N);

    for(int i = 0; i < N; i++){
        root[i] = i;
        cin >> x >> y;
        pos[i] = {x, y}; 
    }
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        unify(u - 1, v - 1);
    }

    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(find(i) == find(j)) continue;
            edge.push_back({get_dist(pos[i], pos[j]), {i, j}});
        }    
    }

    sort(edge.begin(), edge.end(), less<pair<double, pair<double, double>>>());

    double answer = 0;

    for(int i = 0; i < edge.size(); i++){
        double c = edge[i].first;
        u = edge[i].second.first;
        v = edge[i].second.second;

        if(find(u) != find(v)){
            unify(u, v);
            answer += c;
        }
    } 
    printf("%.2lf\n", answer);
    return 0;
}