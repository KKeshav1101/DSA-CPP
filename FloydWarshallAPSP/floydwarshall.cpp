#include<iostream>
#include<limits.h>
using namespace std;

void init(int w[][10], int d[][10],int pi[][10],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d[i][j]=w[i][j];
			if(i==j or w[i][j]==9999)
				pi[i][j]=INT_MIN;
			else
				pi[i][j]=i;
		}
	}
}

void FLOYD_WARSHALL(int d[][10],int pi[][10],int n){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(pi[i][k]!=INT_MIN and pi[k][j]!=INT_MIN and d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					pi[i][j]=pi[k][j];
				}
			}
		}
	}
}
int main(){
	int n;
	cout<<"ENTER SIZE OF MATRIX :";
	cin>>n;
	int w[10][10];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<"Enter :";
			cin>>w[i][j];
		}
	}
	int d[10][10];
	int pi[10][10];
	init(w,d,pi,n);
	fw(d,pi,n);
	cout<<"D matrix:\n";
	for(int i=0;i<n;i++){

		for(int j=0;j<n;j++){
			cout<<d[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"pi matrix :\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<pi[i][j]<<"\t";
		}
		cout<<endl;
	}
}
