#include <iostream>
using namespace std;   

int maxCross(int arr[], int l, int m, int r){

    int lsum = -10000;
    int rsum = -10000;
    int sum = 0;

    for(int i = m ; i >= l ; i--){
        sum = sum + arr[i];
        lsum = max(lsum, sum);
    }

    sum = 0;

    for(int i = m + 1 ; i <= r ; i++){
        sum = sum + arr[i];
        rsum = max(rsum, sum);
    }

    return lsum + rsum;
}

int maxSub(int arr[], int l, int r){

    if(l == r){
        return arr[l];
    }else{

        int mid = (l + r)/2;
        return max(max(maxSub(arr, l, mid), maxSub(arr, mid + 1, r)), maxCross(arr, l, mid, r));
    }
}

int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    cout << maxSub(arr, 0, n-1);

    return 0;
}