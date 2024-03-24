//mcm_dc.cpp
#include<iostream>
#include<limits.h>
using namespace std;
int REC_MAT_CHAIN(int p[],int i,int j,int &count){
	if(i==j)
		return 0;
	int t=INT_MAX;
	for(int k=i;k<=j-1;k++){
		count=count+1;
		int q=REC_MAT_CHAIN(p,i,k,count)+REC_MAT_CHAIN(p,k+1,j,count)+p[i-1]*p[k]*p[j];
		if(q<t)
			t=q;
	}
	return t;
}
int main(){
	int p[5]={10,20,30,11,12};
	int count=0;
	cout<<REC_MAT_CHAIN(p,0,5,count);
}
