#include <bits/stdc++.h>
#define Max 1001

using namespace std;

int pop(int * stack, int * top){
    if(*top == 0) {
        cout << "error!\n";
        return NULL;
    }
    return stack[(*top)--];
}

int push(int * stack, int top, int value){
    stack[top++] = value;
}

int peek(int * stack, int top){
    if(top == 0) {
        cout << "error\n";
        return NULL;
    }
    return stack[top - 1];
}

int main(void){
    int stack[Max];
    int top = 0;





    return 0;
}