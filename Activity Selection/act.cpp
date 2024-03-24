#include<iostream>
using namespace std;

struct activity{
	int no;
	int start;
	int finish;
};

void sort(activity a[], int n){
	for(int j=1;j<n;j++){
		activity key=a[j];
		int i=j-1;
		while(i>=0 && a[i].finish>key.finish){
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
}
int main(){
	int n;
	cout<<"Enter number of activities";
	cin>>n;
	activity a[n];
	for(int i=0;i<n;i++){
		activity j;
		j.no=i+1;
		cout<<"Enter starting time :";
		cin>>j.start;
		cout<<"Enter finishing time :";
		cin>>j.finish;
		a[i]=j;
	}
	sort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i].no<<"\t"<<a[i].start<<"\t"<<a[i].finish<<"\n";
	}

	cout<<"Selected"<<cout;

	activity final[n];
	int k=0;
	final[k]=a[0];

	for(int i=1;i<n;i++){
		if(a[i].start>=final[k].finish){
			final[++k]=a[i];
		}
	}
	for(int i=0;i<=k;i++){
		cout<<final[i].no<<"\t"<<final[i].start<<"\t"<<final[i].finish<<"\n";
	}
	return 0;
}
