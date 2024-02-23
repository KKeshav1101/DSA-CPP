//backtracking-sum of subset problem
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void getSet(int array[],int size){
	cout<<"Enter the elements";
	for(int i=0;i<size;i++){
		int k;
		bool flag=false;
		cin>>k;
		for(int j=0;j<i;j++){
			if(array[j]==k){
				flag=true;
			}
		}
		if(flag==false){
			array[i]=k;
		}
	}
	sort(array,array+size);
	/*for(int i=0;i<size;i++){
		cout<<array[i]<<"\t";
	}*/
}
void BACKTRACKING_SUBSET_SUM(int A[],int size,int t_sum,int Set[],int sum_now,int level,int size1){
	if(sum_now==t_sum){
		cout<<"[";
		for(int i=0;i<size1;i++){
			cout<<Set[i]<<",";
		}
		cout<<"]";
		cout<<endl;
	}
	for(int j=level;j<size;j++){
		if(sum_now+A[j]<=t_sum){
			Set[size1]=A[j];
			BACKTRACKING_SUBSET_SUM(A,size,t_sum,Set,sum_now+A[j],j+1,size1+1);
		}
	}
}
int main(){
	int size,t_sum,size1;
	size1=0;
	cout<<"Enter the size of the input set";
	cin>>size;
	cout<<"Enter target sum in subset";
	cin>>t_sum;
	int array[size],Set[size];
	getSet(array,size);
	BACKTRACKING_SUBSET_SUM(array,size,t_sum,Set,0,0,size1);
	return 0;
}
