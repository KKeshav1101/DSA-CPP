#include <iostream>
#include <time.h>
#include<fstream>
#include <stdlib.h>
using namespace std;
int partition(int arr[], int p, int r, int &count) {
    int x = arr[r];
    int i = p - 1;
    int temp;
    for (int j = p; j < r; j ++) {
        count ++;
        if (arr[j] <= x) {
            i ++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}
int randomizedPartition(int arr[], int p, int r, int &count) {
    int i = (rand() % (r - p + 1)) + p;
    int temp = arr[r];
    arr[r] = arr[i];
    arr[i] = temp;
    return partition(arr, p, r, count);
}
void randomizedQuickSort(int arr[], int p, int r, int &count) {
    if (p < r) {
        int q = randomizedPartition(arr, p, r, count);
        randomizedQuickSort(arr, p, q - 1, count);
        randomizedQuickSort(arr, q + 1, r, count);
    }
}
int count_rate(int arr[], int size) {
    int count = 0;
    randomizedQuickSort(arr, 0, size - 1, count);
    return count;
}
int main() {
    int size[7] = {10, 50, 100, 500, 1000, 5000, 10000};
    int a[10000];
    /*cout << "Ascending: \n";
    for (int i = 0; i < 7; i ++) {
        cout << size[i] << ": ";
        for (int j = 0; j < size[i]; j ++)
            a[j] = j;
        cout << count_rate(a, size[i]) << endl;
    }
    cout << "\nDescending: \n";
    for (int i = 0; i < 7; i ++) {
        cout << size[i] << ": ";
        for (int j = size[i]; j > 0; j --)
            a[size[i] - j] = j;
        cout << count_rate(a, size[i]) << endl;
    }
    cout << "\nEqual values: \n";
    for (int i = 0; i < 7; i ++) {
        cout << size[i] << ": ";
    for (int j = 0; j < size[i]; j ++)
        a[j] = 10;
    cout << count_rate(a, size[i]) << endl;
    }*/
    ofstream fout("quickinput.txt");
    srand ((long int) clock());
    for (int j = 0; j < 10000; j ++){
        a[j] = rand() % 30000;
        fout<<a[j]<<"\t";
    }
    fout.close();
    cout << count_rate(a, 10000) << endl;
    ofstream fout1("qs_output.txt");
    for(int i=0;i<10000;i++){
        fout1<<a[i]<<"\t";
    }
    fout1.close();
}