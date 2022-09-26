#include <bits/stdc++.h>

using namespace std;

void dfs(int now, int N, int M, vector<int>& arr){

    if(arr.size() == M){
        for(auto elem : arr){
            cout << elem << " ";
        }
        cout << "\n";
        return;
    }
    else if(arr.size() > M) return;

    for(int i = now; i <= N; i++){
        arr.push_back(i);
        dfs(i + 1, N, M, arr);
        arr.pop_back();
    }
}

int main(void){
    int N, M;
    cin >> N >> M;
    vector<int> arr;
    dfs(1, N, M, arr);

    return 0;
}