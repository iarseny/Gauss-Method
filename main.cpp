#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
 
string gauss(float **matrix,int n,int m)
{
   int i, j;
 
//Метод Гаусса
//Прямой ход, приведение к верхнетреугольному виду
    float  tmp, xx[m];
    int k;
 
    for (i=0; i<n; i++)
     {
       tmp=matrix[i][i];
         for (j=n;j>=i;j--)
             matrix[i][j]/=tmp;
           for (j=i+1;j<n;j++)
          {
             tmp=matrix[j][i];
               for (k=n;k>=i;k--)
             matrix[j][k]-=tmp*matrix[i][k];
          }
      }

    xx[n-1] = matrix[n-1][n];
     for (i=n-2; i>=0; i--)
       {
           xx[i] = matrix[i][n];
           for (j=i+1;j<n;j++) xx[i]-=matrix[i][j]*xx[j];
       }

        bool correct = true;
        for (i=0; i<n; i++) {
            if (to_string(xx[i]) == "-nan") {
                correct = false;
            }
        }

        string ret = "";
        if (correct) {
            for (i=0; i<n; i++) {
                ret += ("X" + to_string(i + 1)  + " = " + to_string(xx[i]));
                ret += "\n";
            }
            cout << endl;
        } else {
            ret += "Нет решений!";
        }
 
   return ret;
}


int main() {

    int n = 3;
    int m = 4;

    float **matrix = new float*[n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new float[m];
    }

    matrix[0][0] = 6;
    matrix[0][1] = 8;
    matrix[0][2] = 12;
    matrix[0][3] = 3;

    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 7;
    matrix[1][3] = 15;

    matrix[2][0] = 16;
    matrix[2][1] = 3;
    matrix[2][2] = 6;
    matrix[2][3] = 62;


    cout << gauss(matrix,n,m);

    for (int i = 0; i < n; i++) {
        delete [] matrix[i];
    }

    delete [] matrix;

    return 0;
};