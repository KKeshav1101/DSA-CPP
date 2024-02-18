#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main(){
	ofstream fout("input_maxSubarray.txt");
	for(int i=0;i<10000;i++){
		int num=rand()%30;
		if(rand()%2==0)
			fout<<-1*num<<"\t";
		else
			fout<<num<<"t";
	}
	fout.close();
	return 0;
}

