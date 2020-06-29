#include <iostream>
#include <random>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cout << rand() % (50) << " ";
    }

    return 0;
}