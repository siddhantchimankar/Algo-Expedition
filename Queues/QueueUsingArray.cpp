#include <iostream>
#include <sstream>
using namespace std;

int top = -1;
int bottom = 0;

void enqueue(string s[], string a)
{
    top++;

    s[top] = a;
}

void dequeue(string s[])
{
    cout << s[bottom] << " ";
    bottom++;
}


int main()
{

    string stack[100];

    string t;
    getline(cin, t);

    istringstream iss(t);
    string word;
    while (iss >> word)
    {
        if (word == "-")
        {
            dequeue(stack);
        }
        else
        {
            enqueue(stack, word);
        }
    }
}