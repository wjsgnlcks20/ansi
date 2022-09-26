#include <bits/stdc++.h>
#define Max 200010

using namespace std;

int find(int x, int * root){
    if(x == root[x]) return x;
    return root[x] = find(root[x], root);
}

void unify(int x, int y, int * root, int * network_cnt){
    x = find(x, root);
    y = find(y, root);
    int newhead, deadhead;
    newhead = (x < y ? x : y);
    deadhead = (x < y ? y : x);

    network_cnt[newhead] += network_cnt[deadhead];
    root[deadhead] = newhead;
}

void solve(){
    int N, root[Max], network_cnt[Max];
    cin >> N;
    for(int i = 0; i < 2 * N; i++){
        root[i] = i;
        network_cnt[i] = 1;
    }
    string person1, person2;
    int data_idx = 0;
    map<string, int> mp;
    for(int i = 0; i < N; i++){
        cin >> person1 >> person2;
        if(mp.find(person1) == mp.end()) mp.insert({person1, data_idx++});
        if(mp.find(person2) == mp.end()) mp.insert({person2, data_idx++});
        if(find(mp[person1], root) != find(mp[person2], root)){
            unify(mp[person1], mp[person2], root, network_cnt);
        }
        cout << network_cnt[find(mp[person1], root)] << "\n";
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T; 
    while(T--) solve();
    return 0;
}