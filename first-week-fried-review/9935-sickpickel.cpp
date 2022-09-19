#include <bits/stdc++.h>

using namespace std;

/**
 * 처음에 잘못 풀었던 부분:
 * cur - j >= 0 또한 탈출조건이기에 flag == 1 일 경우에만 cur 값 변경을 하려했다면
 * 그 경우 또한 flag = 0 에 포함시켜야 했음. 
 * 따라서 flag == bomb.size() 에 일치하는 경우에 한해서 cur 변경으로 구현.
 */

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s, input, bomb;
    cin >> input >> bomb;
    s = input;

    int cur = 0;
    for(int i = 0; i < input.length(); i++, cur++){
        s[cur] = input[i];
        if(s[cur] != bomb.back()) continue;
        int flag = 0;
        for(int j = bomb.size() - 1; cur - j >= 0 && j >= 0; j--){
            if(s[cur - (bomb.size() - 1 - j)] == bomb[j]) flag++;
        }
        if(flag == bomb.size()) cur -= flag;
    }

    s = s.substr(0, cur);
    if(cur == 0) cout << "FRULA\n";
    else cout << s << "\n";
    return 0;
}