#include <iostream>
using namespace std;

void connected(int id[], int a, int b){

    if(id[a] == id[b]){
        cout << "Connected\n";
    }else{
        cout << "Not connected\n";
    }
}

void unionCommand(int id[], int a, int b, int n){

    if(id[a] != id[b]){

        int ida = id[a];
        int idb = id[b];

        for(int i = 0 ; i < n ; i++){
            if(id[i] == ida){
                id[i] = idb;
            }
        }
    }
}

int main(){

    int n;
    cin >> n;

    int id[n];

    for(int i = 0 ; i < n ; i++){
        id[i] = i;
    }

    unionCommand(id, 4, 3, n);
    unionCommand(id, 3, 8, n);
    unionCommand(id, 6, 5, n);
    unionCommand(id, 9, 4, n);
    unionCommand(id, 2, 1, n);
    connected(id, 8, 9);
    connected(id, 5, 0);
    unionCommand(id, 5, 0, n);
    unionCommand(id, 7, 2, n);
    unionCommand(id, 6, 1, n);
}