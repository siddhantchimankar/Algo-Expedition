#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* head = NULL;

class LinkedList {

    private :
        node *head;
        node *tail;

    public :
        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        void insertNode(int a)
        {

            node *temp = new node();
            temp->data = a;
            temp->next = NULL;

            if (head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
            }
        }

        void printList(){

            node* t = head;

            while(t != NULL){
                cout << t->data << " ";
                t = t->next;
            }

            cout << "\n";
        }

        void deleteNode(int n){

            if(n == 0){

                node* t = head;
                head = head->next;
                free(t);

            }else{

                node *t = head;
                node *p = head;

                for (int i = 0; i < n - 1; i++)
                {
                    t = t->next;
                    p = p->next;
                }

                t = t->next;
                p->next = t->next;
                free(t);
            }

        }

        void searchNode(int a){

            node* t = head;
            int index = 0;

            while(t != NULL){

                if(t->data == a){
                    cout << index << "\n";
                    return;
                }

                t = t->next;
                index++;

            }

            cout << "Not found\n";
        }
            
    };



int main(){

    int n;
    cin >> n;

    LinkedList ll;

    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        ll.insertNode(a);
    }

    ll.printList();

    return 0;
}