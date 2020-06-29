#include <iostream>
using namespace std;

template<typename T>

struct node{

    T data;
    node* left;
    node* right;
};

template <class T>
class LinkedList
{

private:
    node<T>* head;
    node<T>* tail;
    int s;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        s = 0;
    }

    void addFront(T a)
    {

        if(head == NULL){

            node<T> *t = new node<T>;
            head = t;
            tail = t;
            head->data = a;
            head->right = NULL;
            head->left = NULL;
        }else{

            node<T>* t = new node<T>;
            t->data = a;
            t->right = head;
            head->left = t;
            t->left = NULL;
            head = t;

        }
        s++;
    }

    void removeFront(){

        if(head == NULL){
            cout << "Deque is empty\n";
        }else{
            node<T>* t = head;
            head = head->right;
            free(t);
            s--;
        }
    }

    void addEnd(T a){

        if(head == NULL){

            head = new node<T>;
            tail = head;
            head->data = a;
            head->right = NULL;
            head->left = NULL;

        }else{

            node<T>* t = new node<T>;
            t->data = a;
            t->right = NULL;
            t->left = tail;
            tail->right = t;
            tail = t;
        }
        s++;
    }

    void removeEnd(){

        if (head == NULL)
        {
            cout << "Deque is empty\n";
        }
        else{
            node<T>* t = tail;
            tail = tail->left;
            free(t);
            s--;
        }
    }

    void display(){

        node<T>* t = head;

        while(t != NULL){
            cout << t->data << " ";
            t = t->right;
        }
    }

    void checkSize(){
        cout << "Size : "<< s << "\n";
    }


};

int main(){

    LinkedList<int> ll;
    ll.addFront(5);
    ll.addFront(7); 
    ll.addEnd(2);
    ll.removeFront();
    ll.display();
    ll.checkSize();

    LinkedList<string> ll2;
    ll2.addFront("hi");
    ll2.addEnd("my");
    ll2.addEnd("name");
    ll2.removeEnd();
    ll2.display();
    
}