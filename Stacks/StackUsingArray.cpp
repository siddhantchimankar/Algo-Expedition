#include <iostream>
#include <sstream>
using namespace std;

int top = -1;

void push(string s[], string a){
    top++;
    s[top] = a;
}

void pop(string s[]){
    cout << s[top] << " ";
    top--;
}

void peek(string s[]){
    cout << s[top] << " ";
}

int main(){

    string stack[100];

    string t;
    getline(cin, t);

    istringstream iss(t);
    string word;
    while (iss >> word)
    {
        if (word == "-")
        {
            pop(stack);
        }
        else
        {
            push(stack, word);
        }
    }
}