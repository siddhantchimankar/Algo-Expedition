#include <iostream>
using namespace std;

int partition(int arr[], int l, int r){

    int pivot = arr[r];
    int k = l;

    for(int i = l ; i < r ; i++){
        
        if(arr[i] < pivot){

            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            k++;
        }
    }

    arr[r] = arr[k];
    arr[k] = pivot;

    return k;
}

void quickSort(int arr[], int l, int r){

    if(l < r){

        int p = partition(arr, l, r);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}