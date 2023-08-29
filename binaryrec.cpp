//recursiveapproach to binary search
#include<iostream>
using namespace std;
int BinarySearch_Recursion(int List[],int first,int last,int target,int &Loc);
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
	int Loc;
	int flag=BinarySearch_Recursion(array,0,n-1,target,Loc);
	if(flag==1)
		cout<<"Element Present";
	else
		cout<<"Element Absent";	
}
int BinarySearch_Recursion(int List[],int first,int last,int target,int &Loc){
    if (last<first){
        Loc=-1;
        return false;
    }
    else{
        int Mid=(first+last)/2;
        if(target<List[Mid])
            return BinarySearch_Recursion(List,first,Mid-1,target,Loc);
        else if(target>List[Mid])
            return BinarySearch_Recursion(List,Mid+1,last,target,Loc);
        else{
            Loc=Mid;
            return true;
        }

    }
}