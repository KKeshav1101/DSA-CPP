//iterativelinearsearch
#include<iostream>
using namespace std;
int Search(int list[],int last,int target,int &locn);
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
	int flag=Search(array,n-1,target,locn);
	if(flag==1)
		cout<<"Element Present";
	else
		cout<<"Element Absent";	
	}
int Search(int list[],int last,int target,int &locn){
	int looker=0,found;
	while(looker<last && target!=list[looker]){
		looker++;
		}
	locn=looker;
	if(target==list[looker])
		found=true;
	else
		found=false;	
	return found;
	}
