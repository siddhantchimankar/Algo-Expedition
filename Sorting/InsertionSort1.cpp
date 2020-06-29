#include <iostream>
using namespace std;


void inSort(int arr[], int n){

    for(int i = 0 ; i < n ; i++){
        
        int j = i;

        while(j > 0 && arr[j-1] > arr[i]){
            j--;
        }

        int temp = arr[i];

        for(int k = i-1 ; k >= j ; k--){
            arr[k+1] = arr[k];
        }

        arr[j] = temp;
  
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    inSort(arr, n);

    return 0;
}