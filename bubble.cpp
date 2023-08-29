/* program to implement bubble sort
bubble.cpp*/
#include<iostream>
using namespace std;
void bubbleSort(int list[],int last);
int main(){
int n,walker;
cout<<"Enter the number of elements :";
cin>>n;
int array[n];
cout<<"Enter array elements :";
for(int index=0;index<n;index++)
cin>>array[index];
bubbleSort(array,n-1);
cout<<"The sorted array is :";
for(int index=0;index<n;index++)
cout<<array[index]<<" ";
}


void bubbleSort(int list[],int last){
int current=0;
bool sorted=false;
while(current<=last && sorted==false){
	int walker=last;
	sorted=true;
	while(walker>current){
		if(list[walker]<list[walker-1]){
		sorted=false;
		swap(list[walker],list[walker-1]);
		}
	walker--;
	}
current++;
}
}

void swap(int a,int b){
int temp;
temp=a;
a=b;
b=temp;
}