#include <iostream>
using namespace std;

int bsearch(int arr[], int l, int r, int k){

    if(l <= r){

        int mid = (l + r) / 2;

        if (arr[mid] > k)
        {
            return bsearch(arr, l, mid - 1, k);
        }
        else if (arr[mid] < k)
        {
            return bsearch(arr, mid + 1, r, k);
        }
        else
        {
            return mid;
        }
    }

    return -1;
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

    int a = bsearch(arr, 0, n - 1, k);

        if (a== -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << k << " found at : " << a;
    }

    return 0;
}
