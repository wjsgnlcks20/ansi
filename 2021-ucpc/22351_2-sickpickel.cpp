#include <bits/stdc++.h>

using namespace std;

int main(void){
    string input;
    cin >> input;

    for(int len = 1; len <= 3; len++){
        string start = input.substr(0, len);
        string ans = "";
        for(int j = stoi(start); ;j++){
            ans += to_string(j);
            if(ans.size() == input.size()){
                if(ans == input){
                    cout << start << " " << j << "\n";
                    return 0;
                }
            }
            else if(ans.size() > input.size()) break;
        }
    }
    cout << input << " " << input << "\n";
    return 0;
}