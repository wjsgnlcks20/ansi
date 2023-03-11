#include <bits/stdc++.h>
#define Max 11
#define INF 987654321

using namespace std;

typedef int(*parr)[Max];

int N, M, land[Max][Max];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int root[Max * Max];

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

void dfs(int y, int x, parr visited){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx] || land[ny][nx] == 0) continue;

        int now_root_idx = y * M + x;
        int next_root_idx = ny * M + nx;
        unify(next_root_idx, now_root_idx);
        dfs(ny, nx, visited);
    }
}

void printRoot(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << find(i * M + j) << " ";
        }
        cout << "\n";
    }
}

int get_mindist(int u, int v, int * islands, vector<pair<int, pair<int, int>>>& edges){
    int ret = INF;
    int v_head = islands[v];
    int u_head = islands[u];

    for(int i = 0; i < N; i++){
        int u_dist = 0, v_dist = 0;
        // flag에는 가장 마지막 방문 땅의 그룹(find(id))를 저장한다.
        // -1은 u, v 이외의 다른 섬
        int flag = -1;
        for(int j = 0; j < M; j++){
            int id = i * M + j;
            if(land[i][j] == 0){
                if(flag == v_head) v_dist++; 
                else if(flag == u_head) u_dist++;
            }
            else {
                if(find(id) == u_head){
                    if(v_dist >= 2) {
                        if(v_dist == 4) cout << i << " " << j << "\n";
                        edges.push_back({v_dist, {u_head, v_head}});
                        v_dist = 0;
                    }
                    flag = u_head;
                } 
                else if(find(id) == v_head){
                    if(u_dist >= 2) {
                        if(u_dist == 4) cout << i << " " << j << "\n";
                        edges.push_back({u_dist, {u_head, v_head}});
                        u_dist = 0;
                    }
                    flag = v_head;
                }
                else flag = -1;
                v_dist = u_dist = 0;
            }
        }
    }

    for(int j = 0; j < M; j++){
        int u_dist = 0, v_dist = 0;
        // flag에는 가장 마지막 방문 땅의 그룹(find(id))를 저장한다.
        // -1은 u, v 이외의 다른 섬
        int flag = -1;
        for(int i = 0; i < N; i++){
            int id = i * M + j;
            if(land[i][j] == 0){
                if(flag == v_head) v_dist++; 
                else if(flag == u_head) u_dist++;
            }
            else {
                if(find(id) == u_head){
                    if(v_dist >= 2) {
                        edges.push_back({v_dist, {u_head, v_head}});
                        v_dist = 0;
                    }
                    flag = u_head;
                } 
                else if(find(id) == v_head){
                    if(u_dist >= 2) {
                        edges.push_back({u_dist, {u_head, v_head}});
                        u_dist = 0;
                    }
                    flag = v_head;
                }
                else flag = -1;
                v_dist = u_dist = 0;
            }
        }
    }

    return ret;
}

int get_island_idx(int id, int * island, int island_size){
    for(int i = 0; i < island_size; i++){
        if(island[i] == id){
            return i;
        }
    }
    return -1;
}

int main(void){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            root[i * M + j] = i * M + j;
            cin >> land[i][j];
        }
    }
    int visited[Max][Max] = {}, island_idx = 0;
    int islands[Max];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] || land[i][j] == 0)continue;
            dfs(i,j, visited);
            islands[island_idx++] = find(i * M + j);
        }
    }

    vector<pair<int, pair<int, int>>> edges;

    for(int i = 0; i < island_idx - 1; i++){
        for(int j = i + 1; j < island_idx; j++){
            // 상호간 놓을 수 있는 다리 중에 가장 짧은 다리(2이상)을 둔다고 가정하고 edge에 그 정보를 저장한다.
            get_mindist(i, j, islands, edges);
        }
    }

    sort(edges.begin(), edges.end(), less<pair<int, pair<int, int>>>());

    int answer = 0;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int c = edges[i].first;
        // cout << "(" << get_island_idx(u, islands, island_idx) << " ";
        // cout << get_island_idx(v, islands, island_idx) << ") : " << c << "\n";
        if(find(u) != find(v)){
            unify(u, v);
            answer += c;
        }
    }
    int flag = 1; 
    for(int i = 1; i < island_idx; i++){
        if(find(islands[0]) != find(islands[i])) {flag = 0; break; }
    }

    if(flag) cout << answer << "\n";
    else cout << "-1\n";

    return 0;
}