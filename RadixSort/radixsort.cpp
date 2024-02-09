//radixsort.cpp
#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;
int count;
void COUNTSORT(int A[],int B[],int n,int k,int &count){
	count=0;
	int C[k+1];
	for(int i=0;i<=k;i++){
		count=count+1;
		C[i]=0;
	}
	for(int j=0;j<n;j++){
		count=count+1;
		C[A[j]]=C[A[j]]+1;
	}
	for(int i=1;i<=k;i++){
		count=count+1;
		C[i]=C[i-1]+C[i];
	}
	for(int j=n-1;j>=0;j--){
		count=count+1;
		B[C[A[j]]-1]=A[j];
		C[A[j]]=C[A[j]]-1;
	}
}
int findMax(int array[],int size){
	int max=0;
	for(int i=0;i<size;i++){
		if(array[i]>max)
			max=array[i];
	}
}
void RADIXSORT(int array[],int B[],int size,int &count){
	int m=findMax(array,size);
	for(int exp=1;m/exp>0;exp=exp*10)
		count=count+1;
		COUNTSORT(array,B,size,m,count);
}
int count_rate(int arr[],int b[], int size) {
    int count = 0;
    RADIXSORT(arr, b, size - 1, count);
    return count;
}
int main(){
	int a[10000];	
	int b[10000];
	int size[7] = {10, 50, 100, 500, 1000, 5000, 10000};
    /*cout << "Ascending: \n";
    for (int i = 0; i < 7; i ++) {
        cout << size[i] << ": ";
        for (int j = 0; j < size[i]; j ++)
            a[j] = j;
        cout << count_rate(a,b, size[i]) << endl;
    }
    cout << "\nDescending: \n";
    for (int i = 0; i < 7; i ++) {
        cout << size[i] << ": ";
        for (int j = size[i]; j > 0; j --)
            a[size[i] - j] = j;
        cout << count_rate(a,b, size[i]) << endl;
    }
    cout << "\nEqual values: \n";
    for (int i = 0; i < 7; i ++) {
        cout << size[i] << ": ";
    for (int j = 0; j < size[i]; j ++)
        a[j] = 10;
    cout << count_rate(a,b, size[i]) << endl;
    }
    cout << "\nRandom values: \n";
    for (int i = 0; i < 7; i ++) {
        cout << size[i] << ": ";
        srand ((long int) clock());
        for (int j = 0; j < size[i]; j ++)
            a[j] = rand() % 30000;
        cout << count_rate(a,b, size[i]) << endl;
	}*/
	ifstream fin("input_rsort.txt");
	for(int i=0;i<10000;i++){
		fin>>a[i];
	}
	RADIXSORT(a,b,10000,count);
	ofstream fout("output_rsort.txt");
	for(int i=0;i<10000;i++)
		fout<<b[i]<<"\t";
	cout<<count;
	return 0;
}
