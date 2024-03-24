#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

void PRINT_LCS(string X, int i, int j, string **b);
void LCS_LENGTH_BU(string X, string Y, int m, int n, int &count){
    int c[m+1][n+1];
    string **b = new string*[m+1];
    for(int i = 0; i <= m; i++)
        b[i] = new string[n+1];
    for(int j = 0; j <= n; j++)
        c[0][j] = 0;
    for(int i = 1; i <= m; i++)
        c[i][0] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            count++;
            if(X[i-1] == Y[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = "0";
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = "1";
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = "2";
            }
        }
    }
    PRINT_LCS(X, m, n, b);
    for(int i = 0; i <= m; i++)
        delete[] b[i];
    delete[] b;
}

void PRINT_LCS(string X, int i, int j, string **b){
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == "0") {
        PRINT_LCS(X, i - 1, j - 1, b);
        cout << X[i-1];
    } 
    else if (b[i][j] == "1")
        PRINT_LCS(X, i - 1, j, b);
    else
        PRINT_LCS(X, i, j - 1, b);
}

int main(){
    int count = 0;
    LCS_LENGTH_BU("ABCABC", "ACAB", 6, 4, count); //m is size of string1 and n is size of string 2
    cout << endl;
    cout << "Count=" << count << endl;
}

