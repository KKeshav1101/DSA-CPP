//recursivelinearsearch
#include<iostream>
using namespace std;
int RecursiveLinearSearch(int list[],int index,int last,int &locn,int target);
int main(){
	int n;
	cout<<"Enter number of elements in the array :";
	cin>>n;
	int array[n];
	cout<<"Enter the elements :";
	for(int i=0;i<n;i++){
		cin>>array[i];
		}
	int target;
	cout<<"enter target element :";
	cin>>target;
	int locn;
	int flag=RecursiveLinearSearch(array,array[0],n-1,locn,target);
	if(flag==1)
		cout<<"Element Present";
	else
		cout<<"Element Absent";	
	}
int RecursiveLinearSearch(int list[],int index,int last,int &locn,int target){
	if(index>last){
		locn=-1;
		return false;
		}
	if(target==list[index]){
		locn=index;
		return true;
		}
	return RecursiveLinearSearch(list,index+1,last,locn,target);		
	}