#include<iostream>
#include<fstream>
#include<limits.h>
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

Solution MAX_SUBARRAY_BF(int array[],int size,int &count){
	int l,h;
	int max_sum=-(INT_MAX);
	for(int i=0;i<size;i++){
		int sum=0;
		for(int j=i;j<size;j++){
			count=count+1;
			sum=sum+array[j];
			if(sum>max_sum){
				max_sum=sum;
				l=i;
				h=j;
			}
		}
	}
	return Solution(l,h,max_sum);
}
int main(){
	ifstream fin("input_maxSubarray.txt");
	int array[10000];
	for(int i=0;i<10000;i++)
		fin>>array[i];
	int count=0;
	MAX_SUBARRAY_BF(array,10000,count).display();
	cout<<count;
}
