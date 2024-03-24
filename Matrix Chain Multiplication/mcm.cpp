#include<iostream>
#include<limits.h>
using namespace std;

void PRINT_OPT_ORDER(int s[10][10],int i,int j);
void MATRIX_CHAIN_ORDER(int p[],int n,int &count){
	int m[n][n],s[10][10];
	for(int i=1;i<n;i++)
		m[i][i]=0;
	for(int l=2;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1;
			m[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++){
				count=count+1;
				int q=m[i][k]+m[k][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	PRINT_OPT_ORDER(s,1,n-1);
}

void PRINT_OPT_ORDER(int s[10][10],int i,int j){
	if(i==j)
		cout<<"A"<<i;
	else{
		cout<<"(";
		PRINT_OPT_ORDER(s,i,s[i][j]);
		PRINT_OPT_ORDER(s,s[i][j]+1,j);
		cout<<")";
	} 
}

int main(){
	int p[5]={10,30,20,25,10};
	int count=0;
	MATRIX_CHAIN_ORDER(p,5,count);	
	cout<<"Number of scalar operations :"<<count;
}
