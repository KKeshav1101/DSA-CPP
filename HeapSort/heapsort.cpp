#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
void swap(int *m, int *n) {
    int p;
    p = *m;
    *m = *n;
    *n = p;
}
void maxheap(int a[], int i, int n, int &count){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    count++;
    if(l<n && a[l] > a[largest]){
        largest = l;
    }
    if(r<n && a[r] > a[largest]){
        largest = r;
    }
    if(i!=largest){
        swap(&a[i], &a[largest]);
        maxheap(a, largest, n, count);
    }
}
void buildheap(int a[], int n, int &count){
    for(int i=n/2-1;i>=0;i--){
        maxheap(a, i, n, count);
    }
}
void heapsort(int a[], int n, int &count){
    buildheap(a, n, count);
    int heapsize = n;
    for(int i = n-1;i>=0;i--){
        swap(&a[i], &a[0]);
        heapsize = heapsize-1;
        maxheap(a, 0, heapsize, count); 
    }
}
int main(){
    int n;
    int count = 0;
    cout<<"Enter the number of elements:";
    cin>>n;
    int ar[n];
    ofstream fout("input.txt");
	for(int i=0;i<n;i++)
		fout<<rand()%30000<<"\t";
	fout.close();
    ifstream myfile("input.txt");
    int i1 = 0;
    while(!myfile.eof()) {
        myfile>>ar[i1];
        i1++;
    }
    myfile.close();
    heapsort(ar, n, count);
    ofstream fout1("ascending_heap.txt");
    for(int i=0;i<n;i++){
        fout1<<ar[i]<<"\t";
    }
    cout<<"\ncount = "<<count;
    return 0;
}
