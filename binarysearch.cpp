//iterativebinarysearch
#include<iostream>
using namespace std;
int BinarySearch(int list[],int last,int target,int &locn);
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
	int flag=BinarySearch(array,n-1,target,locn);
	if(flag==1)
		cout<<"Element Present";
	else
		cout<<"Element Absent";	
	}
int BinarySearch(int list[],int last,int target,int &locn){
	int mid,begin=0;
	int end=last;
	while(begin<=end){
		mid=(begin+end)/2;
		if (target>list[mid+1])
			begin=mid+1;
		else if(target<list[mid])
			end=mid-1;
		else
			begin=end+1;
		}
	locn=mid;
	int found;
	if(target==list[mid])
		found=true;
	else
		found=false;
	return found;
	}