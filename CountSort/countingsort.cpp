//countingsort.cpp
#include<fstream>
#include<iostream>
#include<cstring>
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
int main(){
	int size[]={10,50,100,500,1000,5000,10000};
	int arr[10000];
	int b[100000];
	for(int i=0;i<7;i++){
		char fname[25]="input_csort_";
		char ext[2];
		ext[0]='1'+i;
		ext[1]='\0';
		int n=size[i];
		strcat(fname,ext);
		strcat(fname,".txt");
		ifstream fin(fname);
		for(int j=0;j<size[i];j++)
			fin>>arr[j];
		COUNTSORT(arr,b,n,findMax(arr,n),count);
		cout<<count<<endl;
		char ofname[25]="output_csort_";
		ext[0]='1'+i;
		ext[1]='\0';
		strcat(ofname,ext);
		strcat(ofname,".txt");
		ofstream fout(ofname);
		for(int k=0;k<size[i];k++)
			fout<<b[k]<<"\t";
	}
}
/*
41
201
401
2001
4001
20001
40001
*/
