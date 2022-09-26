#include <bits/stdc++.h>
#define Max 800001

using namespace std;

int arr[Max];

int main(void){
    int N, cards, idx = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        arr[i] = i + 1;
    }
    cards = N;
    for(int i = 1; arr[i] > 0; i += 2){
        arr[cards++] = arr[i];
    }
    cout << arr[--cards] << "\n";
    return 0; 
}