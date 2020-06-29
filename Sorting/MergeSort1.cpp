#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    
    int i = l;
    int j = m + 1;
    int k = 0;

    int *temp = new int[r - l + 1];

    while(i <= m && j <= r){

        if(arr[i] > arr[j]){

            temp[k] = arr[j];
            j++;
            k++;

        }
        else if(arr[i] < arr[j]){

            temp[k] = arr[i];
            i++;
            k++;

        }else{

            temp[k] = arr[i];
            i++;
            k++;
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    if(i <= m){

        while(i <= m){

            temp[k] = arr[i];
            k++;
            i++;
        }

    }else if(j <= r){

        while (j <= r)
        {

            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    int c = 0;

    for(int i = l ; i <= r ; i++){
        arr[i] = temp[c];
        c++;
    }
}

void mergeSort(int arr[], int l, int r){

    if(l < r){

        int mid = (l + r)/2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}