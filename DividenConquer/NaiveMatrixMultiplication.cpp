#include <iostream>
using namespace std;

int main(){

    int m1, n1, m2, n2;
    cin >> m1 >> n1 >> m2 >> n2;

    int mat1[m1][n1];
    
    for(int i = 0 ; i < m1 ; i++){
        for(int j = 0 ; j < n1 ; j++){
            cin >> mat1[i][j];
        }
    }

    for(int i = 0 ; i < m1 ; i++){
        for(int j = 0 ; j < n1 ; j++){
            cout << mat1[i][j] << " ";
        }
        cout << "\n";
    }

    int mat2[m2][n2];

    for(int i = 0 ; i < m2 ; i++){
        for(int j = 0 ; j < n2 ; j++){
            cin >> mat2[i][j];
        }
    }

    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << mat2[i][j] << " ";
        }
        cout << "\n";
    }

    int matpro[m1][n2];

    for(int i = 0 ; i < n1 ; i++){
        for(int j = 0 ; j < n1 ; j++){
            matpro[i][j] = 0;
            for(int k = 0 ; k < n1 ; k++){
                matpro[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for(int i = 0 ; i < n1 ; i++){
        for(int j = 0 ; j < n1 ; j++){
            cout << matpro[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}