#include <bits/stdc++.h>
#define Max 100000

using namespace std;

typedef long long ll;

typedef struct _pos{
    int x;
    int y;
    int z;
    int node;
}Pos;

int n, root[Max];
ll ans = 0;

int getabs(int a){
    return (a < 0) ? (a * -1) : a;
}

int sortbyX(Pos a, Pos b){
    return a.x < b.x;
}
int sortbyY(Pos a, Pos b) {
    return a.y < b.y;
}
int sortbyZ(Pos a, Pos b) {
    return a.z < b.z;
}

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
    ios::sync_with_stdio(false); cin.tie(NULL);
    int limit, cnt = 0;
    Pos dots[Max]; 
    vector<pair<int, pair<int, int>>> edges;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> dots[i].x >> dots[i].y >> dots[i].z;
        dots[i].node = i + 1;
    }
    for(int i = 1; i <= n; i++){
        root[i] = i;
    }
    
    sort(dots, dots + n, sortbyX);
    for(int i = 0; i < n - 1; i++){
        edges.push_back({getabs(dots[i + 1].x - dots[i].x), {dots[i].node, dots[i+1].node}});
    }

    sort(dots, dots + n, sortbyY);
    for(int i = 0; i < n - 1; i++){
        edges.push_back({getabs(dots[i + 1].y - dots[i].y), {dots[i].node, dots[i+1].node}});
    }

    sort(dots, dots + n, sortbyZ);
    for(int i = 0; i < n - 1; i++){
        edges.push_back({getabs(dots[i + 1].z - dots[i].z), {dots[i].node, dots[i+1].node}});
    }
    sort(edges.begin(), edges.end());

    limit = edges.size();
    for(int i = 0; i < limit && cnt < n - 1; i++){
        int s = edges[i].second.first;
        int e = edges[i].second.second;
        int c = edges[i].first;

        if(find(s) != find(e)){
            unify(s, e);
            ans += c;
            cnt++;
        }
    }
    cout << ans;
    return 0;
}