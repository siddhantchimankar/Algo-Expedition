#include <iostream>
using namespace std;

void bsearch(int arr[], int l, int r, int k){

    while(l <= r){

        int mid = (l + r)/2;

        if(arr[mid] > k){

            r = mid - 1;

        }else if(arr[mid] < k){

            l = mid + 1;

        }else{
            
            cout << k << " found at : " << mid;
            return;
        }
    }

    cout << "Element not found";
    
}

int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;

    bsearch(arr, 0, n-1, k);

    return 0;
}