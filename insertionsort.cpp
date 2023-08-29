//insertionsort.cpp
#include<iostream>
using namespace std;
void InsertionSort(int list[],int last);
int main(){
	int n;
	cout<<"Enter the number of elements :";
	cin>>n;
	int array[n];
	cout<<"Enter the elements :";
	for(int index=0;index<n;index++)
		cin>>array[index];
	InsertionSort(array,n-1);
	for(int index=0;index<n;index++)
		cout<<array[index]<<"\t";
	}
void InsertionSort(int list[],int last){
	int current,walker;
	current=1;
	while(current<=last){
		walker=current-1;
		int hold=list[current];
		while(walker>=0 && hold<list[walker]){
			list[walker+1]=list[walker];
			walker--;
			}
		list[walker+1]=hold;
		current++;
		}
	}
