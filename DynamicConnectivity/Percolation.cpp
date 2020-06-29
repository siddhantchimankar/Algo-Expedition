#include <iostream>
using namespace std;

int findRoot(int id[], int a, int f = 0)
{

    if(f){
        int k = a;
        while (id[k] != k)
        {
            if(id[k] == 0 || id[k] == 1 ){
                return k;
            }
            id[k] = id[id[k]];

            k = id[k];
        }
        return k;
    }else{
        int k = a;
        while (id[k] != k)
        {

            id[k] = id[id[k]];

            k = id[k];
        }
        return k;
    }
}

bool connected(int id[], int a, int b)
{

    if (findRoot(id, a) == findRoot(id, b))
    {
        // cout << "Connected\n";
        return true;
    }
    else
    {
        // cout << "Not connected\n";
        return false;
    }
}

void unionCommand(int id[], int size[], int a, int b)
{

    int p = findRoot(id, a, 1);
    int q = findRoot(id, b, 1);

    cout << p << " " << q << "\n";

    if (p == q)
    {
        return;
    }

    if (size[p] > size[q])
    {
        id[q] = p;
        size[p] += size[q];
    }
    else
    {
        id[p] = q;
        size[q] += size[p];
    }
}

void openSite(int id[], int size[], int a, int n){

    int c1, c2, c3, c4;
    c1 = 2;
    c2 = n + 1;
    c3 = n*n - n + 2;
    c4 = n*n + 1;

    if(a == c1){
        unionCommand(id, size, a, a + 1);
        unionCommand(id, size, a, a + n);
    }else if(a == c2){
        unionCommand(id, size, a, a - 1);
        unionCommand(id, size, a, a + n);
    }else if(a == c3){
        unionCommand(id, size, a, a - n);
        unionCommand(id, size, a, a + 1);
    }else if(a == c4){
        unionCommand(id, size, a, a - n);
        unionCommand(id, size, a, a - 1);
    }else if(a > c1 && a < c2){
        unionCommand(id, size, a, a + 1);
        unionCommand(id, size, a, a - 1);
        unionCommand(id, size, a, a + n);
    }else if(a > c3 && a < c4){
        unionCommand(id, size, a, a - n);
        unionCommand(id, size, a, a + 1);
        unionCommand(id, size, a, a - 1);
    }else if((a-c1)%n == 0 && a < c3){
        unionCommand(id, size, a, a + n);
        unionCommand(id, size, a, a - n);
        unionCommand(id, size, a, a + 1);
    }else if((a-c2)%n == 0 && a < c4){
        unionCommand(id, size, a, a + n);
        unionCommand(id, size, a, a - n);
        unionCommand(id, size, a, a - 1);
    }else{
        unionCommand(id, size, a, a + 1);
        unionCommand(id, size, a, a - 1);
        unionCommand(id, size, a, a + n);
        unionCommand(id, size, a, a - n);
    }

}

bool checkSite(int id[], int a, int n){

    int c1, c2, c3, c4;
    c1 = 2;
    c2 = n + 1;
    c3 = n * n - n + 2;
    c4 = n * n + 1;

    if (a == c1)
    {
        return (connected(id, a, a + 1) || connected(id, a, a + n));
    }
    else if (a == c2)
    {
        return (connected(id, a, a - 1) || connected(id, a, a + n));
    }
    else if (a == c3)
    {
        return (connected(id, a, a - n) || connected(id, a, a + 1));
    }
    else if (a == c4)
    {
        return (connected(id, a, a - 1) || connected(id, a, a - n));
    }
    else if (a > c1 && a < c2)
    {
        return (connected(id, a, a + 1) || connected(id, a, a - 1) || connected(id, a, a + n));
    }
    else if (a > c3 && a < c4)
    {
        return (connected(id, a, a - n) || connected(id, a, a - 1) || connected(id, a, a + 1));
    }
    else if ((a - c1) % n == 0 && a < c3)
    {
        return (connected(id, a, a + 1) || connected(id, a, a - n) || connected(id, a, a + n));
    }
    else if ((a - c2) % n == 0 && a < c4)
    {
        return (connected(id, a, a - 1) || connected(id, a, a - n) || connected(id, a, a + n));
    }
    else
    {
        return (connected(id, a, a + 1) || connected(id, a, a - 1) || connected(id, a, a + n) || connected(id, a, a - n));
    }
}

float thresholdCalc(int id[], int n){

    float percolates = 0;

    for(int i = 2 ; i < n*n + 2 ; i++){
        if(checkSite(id, i, n)){
            // cout << i << " : " << checkSite(id, i, n) << "\n";
            percolates++;
        }
    }

    cout << "Threshold : " << percolates/(n*n + 2) << "\n";
    return percolates/(n*n + 2);
}

int main(){

    int n;
    cin >> n;

    int id[n*n + 2] = { };
    int size[n*n + 2] = { };

    for(int i = 0 ; i < n*n + 2 ; i++){
        id[i] = i;
    }

    for(int i = 2 ; i < n+2 ; i++){
        id[i] = 0;
    }

    for(int i = n*n + 1 ; i >= n*n - n + 2 ; i--){
        id[i] = 1;
    }

    // unionCommand(id, size, 2, 3);
    // unionCommand(id, size, 5, 10);
    // unionCommand(id, size, 10, 15);
    // unionCommand(id, size, 15, 16);
    // unionCommand(id, size, 17, 22);
    // unionCommand(id, size, 22, 23);
    // unionCommand(id, size, 25, 26);

    while(connected(id, 0, 1) == 0){
        int r = 2 + rand() % (n * n);
        // cout << r << "\n";
        openSite(id, size, r, n);
    }

    // openSite(id, size, 11, n);
    // openSite(id, size, 5, n);
    // openSite(id, size, 16, n);
    // openSite(id, size, 6, n);

    // for(int i = 0 ; i < n*n + 2 ; i++){
    //     cout << id[i] << " ";
    // }


    thresholdCalc(id, n);
}