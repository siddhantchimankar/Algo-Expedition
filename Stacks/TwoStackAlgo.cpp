#include <iostream>
#include <sstream>
using namespace std;

struct node
{
    char text;
    int n;
    node *next;
};

class LinkedList
{

private:
    node *head;
    node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void push(char a)
    {

        if (head == NULL)
        {
            head = new node();
            head->text = a;
            head->next = NULL;
        }
        else
        {
            node *t = new node();
            t->text = a;
            t->next = head;
            head = t;
        }
    }

    void push(int a)
    {

        if (head == NULL)
        {
            head = new node();
            head->n = a;
            head->next = NULL;
        }
        else
        {
            node *t = new node();
            t->n = a;
            t->next = head;
            head = t;
        }
    }

    char pop()
    {

        if (head == NULL)
        {
            cout << "Stack is Empty\n";
            return '\0';
        }
        else
        {
            node *t = head;
            head = head->next;
            return t->text;
            free(t);
        }
    }

    int pop(int a)
    {

        if (head == NULL)
        {
            cout << "Stack is Empty\n";
            return '\0';
        }
        else
        {
            node *t = head;
            head = head->next;
            return t->n;
            free(t);
        }
    }
};

int main()
{

    LinkedList value;
    LinkedList op;

    string s;
    getline(cin, s);

    for(char c : s){

        if(c == '+' || c == '-' || c == '/' || c == '*'){
            op.push(c);
        }
        else if(c == ')'){
            int a = value.pop(1);
            int b = value.pop(1);
            
            char o = op.pop();

            int sum;
            if(o == '+'){
                sum = a + b ;
            }else if(o == '-'){
                sum = b - a;
            }else if(o == '*'){
                sum = (a )*(b );
            }else if(o == '/'){
                sum = (b )/(a);
            }
            
            value.push(sum);

        }else if(c != '(' && c != ' '){
            value.push(int(c) - 48);
            // cout << int(c) << "\n";
        }
    }

    cout << value.pop(1);
}