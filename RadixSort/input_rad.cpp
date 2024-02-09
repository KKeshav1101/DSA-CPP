#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main(){
	ofstream fout("input_rsort.txt");
	for(int i=0;i<10000;i++)
		fout<<1000+rand()%9000<<"\t";
	fout.close();
	return 0;
}
