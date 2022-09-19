#include <bits/stdc++.h>

using namespace std;

int main(void){
    string input;
    cin >> input;
    int answer = 0, razer = 0;
    int times = 0;

    for(int i = 0; i < input.size(); i++){
        char tok = input[i];
        if(tok == '('){
            times++;
        }
        else{
            times--;
            if(i > 0 && input[i - 1] == '('){
                answer += (times);
            }
            else answer += 1;
        }
    }
    cout << answer << "\n";
    return 0;
}