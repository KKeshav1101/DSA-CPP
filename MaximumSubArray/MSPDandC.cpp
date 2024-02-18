//MSPDandC.cpp
#include<iostream>
#include<fstream>
#include<limits.h>
#include<cmath>
using namespace std;

class Solution{
	public:
		int low;
		int high;
		int max_sum;
		Solution(int l,int h,int max){
			low=l;
			high=h;
			max_sum=max;
		}
		void display(){
			cout<<"Starting index ="<<low<<endl;
			cout<<"Ending index ="<<high<<endl;
			cout<<"SUM ="<<max_sum<<endl;
		}
};

Solution FIND_MAX_CROSS_SUBARRAY(int A[],int low,int mid,int high,int &count);
Solution FIND_MAX_SUBARRAY(int A[],int low,int high,int &count){
	if(low==high)
		return Solution(low,high,A[low]);
	else{
		int mid=(low+high)/2;
		Solution left=FIND_MAX_SUBARRAY(A,low,mid,count);
		Solution right=FIND_MAX_SUBARRAY(A,mid+1,high,count);
		Solution cross=FIND_MAX_CROSS_SUBARRAY(A,low,mid,high,count);
		if(left.max_sum>=right.max_sum && left.max_sum>=cross.max_sum)
			return left;
		else if(right.max_sum>=left.max_sum && right.max_sum>=cross.max_sum)
			return right;
		else
			return cross;
	}	
}

Solution FIND_MAX_CROSS_SUBARRAY(int A[],int low,int mid,int high,int &count){
	int cleftmax=-(INT_MAX);
	int cleftlow;
	int sum=0;
	for(int i=mid;i>=low;i--){
		count=count+1;
		sum=sum+A[i];
		if(sum>cleftmax){
			cleftmax=sum;
			cleftlow=i;
		}
	}
	int crightmax=-(INT_MAX);
	sum=0;
	int crighthigh;
	for(int j=mid+1;j<=high;j++){
		count=count+1;
		sum=sum+A[j];
		if(sum>crightmax){
			crightmax=sum;
			crighthigh=j;
		}
	}
	return Solution(cleftlow,crighthigh,cleftmax+crightmax);
}
int main(){
	int arr[10000];
	int count=0;
	ifstream fin("input_maxSubarray.txt");
	for(int i=0;i<10;i++){
		fin>>arr[i];
	}
	FIND_MAX_SUBARRAY(arr,0,9999,count).display();
	return 0;
}

