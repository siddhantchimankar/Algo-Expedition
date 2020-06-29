#include <iostream>
#include <sstream>
using namespace std;

struct node
{
    string text;
    node* next;
};

class LinkedList{

    private :
        node *head;
        node *tail;

    public :

        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        void push(string a){

            if(head == NULL){
                head = new node();
                head->text = a;
                head->next = NULL;
            }else{
                node* t = new node();
                t->text = a;
                t->next = head;
                head = t;
            }
        }

        void pop(){

            if(head == NULL){
                cout << "Stack is Empty\n";
            }else{
                node* t = head;
                head = head->next;
                cout << t->text << " ";
                free(t);
            }
        }

        void top(){

            if (head == NULL)
            {
                cout << "Stack is Empty\n";
            }
            else{
                cout << head->text << "\n";
            }
        }


};



int main(){

    LinkedList ll;

    string t;
    getline(cin, t);

    istringstream iss(t);
    string word;
    while (iss >> word)
    {
        if(word == "-"){
            ll.pop();
        }else{
            ll.push(word);
        }
    }

}