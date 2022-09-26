#include <bits/stdc++.h>

using namespace std;

int main(void){
    string input;
    cin >> input;
    for(int len_s = 1; len_s <= 3; len_s++) {
        int len = len_s;
        string start = input.substr(0, len);
        if(to_string(stoi(start) + 1).length() > start.length()) len++;
        string next = input.substr(start.length(), len);
        pair<string, string> answer = {start, ""};
        if(next == ""){ cout << input << " " << input; return 0; }
        if(stoi(next) - stoi(start) == 1){
            int flag = 1; 
            for(int i = start.length() + next.length(); i < input.size(); i += len){
                start = next;
                if(to_string(stoi(next) + 1).length() > next.length()) len++;
                next = input.substr(i, len);
                if(stoi(next) - stoi(start) != 1) flag = 0;
            }
            // if(!flag) { cout << input << " " << input << "\n"; return 0;}
            if(stoi(next) <= stoi(start)) { cout << input << " " << input << "\n"; return 0;}
            answer.second = next;
            cout << answer.first << " " << answer.second << "\n";
            return 0;
        }
    }
    return 0;
}