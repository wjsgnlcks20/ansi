#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    stack<char> s;
    stack<int> depth_sum;

    string input;
    cin >> input;
    depth_sum.push(0);

    for(int i = 0; i < input.size(); i++){
        char tok = input[i];
        if(tok == '(' || tok == '['){
            s.push(tok);
            depth_sum.push(0);
        }
        else{
            if(s.empty()) {cout << "0\n"; return 0;}
            char expect;
            if(tok == ')') expect = '(';
            else expect = '[';

            if(s.top() != expect) { cout << "0\n"; return 0; }
            else {
                int val = depth_sum.top();
                depth_sum.pop();

                if(val == 0) val = 1;
                if(s.top() == '[') val *= 3;
                else val *= 2;

                int tmp = depth_sum.top();
                depth_sum.pop();
                depth_sum.push(tmp + val);

                s.pop();
            }
        }
    }
    if(!s.empty()) cout << "0\n";
    else cout << depth_sum.top() << "\n";
    return 0;
}