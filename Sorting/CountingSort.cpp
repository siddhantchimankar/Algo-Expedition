#include <iostream>
using namespace std;

int main(){

    int a;
    cin >> a;

    int freq[a] = { };

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for(int i = 0 ; i < a ; i++){
        if(freq[i] != 0){
            int k = freq[i];
            while(k > 0){
                cout << i << " ";
                k--;
            }
        }
    }

    return 0;
}