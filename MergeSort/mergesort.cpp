#include<iostream>
#include<fstream>
#include<limits.h>
#include<stdlib.h>
using namespace std;
void mergeasc(int array[10000],int p,int q,int r){
	int n1,n2;
	n1=q-p+1;
	n2=r-q;
	int L[n1],R[n2];
	for(int i=0;i<=n1;i++)
		L[i]=array[p+i-1];
	for(int j=0;j<=n2;j++)
		R[j]=array[q+j];
	L[n1+1]=INT_MAX;
	R[n2+1]=INT_MAX;
	int i=1,j=1,k=p;
	for(k=p;k<=r;k++){
		if(L[i]<=R[j]){
			array[k]=L[i];
			i=i+1;
		}
		else{
			array[k]=R[j];
			j=j+1;
		}
	}
}
void mergesortasc(int array[10000],int p,int r){
	if(p<r){
		int q;
		q=(p+r)/2;
		mergesortasc(array,p,q);
		mergesortasc(array,q+1,r);
		mergeasc(array,p,q,r);
	}
	ofstream fout("ascending.txt");
	for(int i=0;i<10000;i++)
		fout<<array[i]<<"\t";
	fout.close();
}
void mergedesc(int array[10000],int p,int q,int r){
	int n1,n2;
	n1=q-p+1;
	n2=r-q;
	int L[n1],R[n2];
	for(int i=0;i<=n1;i++)
		L[i]=array[p+i-1];
	for(int j=0;j<=n2;j++)
		R[j]=array[q+j];
	L[n1+1]=INT_MIN;
	R[n2+1]=INT_MIN;
	int i=1,j=1,k=p;
	for(k=p;k<=r;k++){
		if(L[i]>=R[j]){
			array[k]=L[i];
			i=i+1;
		}
		else{
			array[k]=R[j];
			j=j+1;
		}
	}
}
void mergesortdesc(int array[10000],int p,int r){
	if(p<r){
		int q;
		q=(p+r)/2;
		mergesortdesc(array,p,q);
		mergesortdesc(array,q+1,r);
		mergedesc(array,p,q,r);
	}
	ofstream fout("descending.txt");
	for(int i=0;i<10000;i++)
		fout<<array[i]<<"\t";
	fout.close();
}
int main(){
	ifstream fin("input.txt");
	int array[10000];
	int i=0;
	while(!fin.eof()){
		fin>>array[i];
		i++;
	}
	mergesortasc(array,0,9999);
	mergesortdesc(array,0,9999);
	return 0;
}
