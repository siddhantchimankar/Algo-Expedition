#include <iostream>
using namespace std;

int findRoot(int id[], int a){

    int k = a;
    while(id[k] != k){
        id[k] = id[id[k]];
        k = id[k];
    }
    return k;
}

void connected(int id[], int a, int b){

    if(findRoot(id, a) == findRoot(id, b)){
        cout << "Connected\n";
    }else{
        cout << "Not connected\n";
    }
}

void unionCommand(int id[], int size[], int a, int b){

    int p = findRoot(id, a);
    int q = findRoot(id, b);

    if(p == q){
        return;
    }
    
    if(size[p] > size[q]){
        id[q] = p;
        size[p] += size[q];
    }else{
        id[p] = q;
        size[q] += size[p];
    }
}

int main(){

    int n;
    cin >> n ;

    int id[n];
    int size[n];

    for(int i = 0 ; i < n ; i++){
        id[i] = i;
    }

    unionCommand(id,size, 4, 3);
    unionCommand(id, size, 3, 8);
    unionCommand(id, size, 6, 5);
    unionCommand(id, size, 9, 4);
    unionCommand(id, size, 2, 1);
    connected(id, 8, 9);
    connected(id, 5, 4);
    unionCommand(id, size, 5, 0);
    unionCommand(id, size, 7, 2);
    unionCommand(id,size, 6, 1);
    unionCommand(id, size,7, 3);
    connected(id, 3, 9);
}