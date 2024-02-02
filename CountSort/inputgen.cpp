#include<fstream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main(){
	int size[]={10,50,100,500,1000,5000,10000};
	for(int i=0;i<7;i++){
		char fname[25]="input_csort_";
		char ext[2];
		ext[0]='1'+i;
		ext[1]='\0';
		int n=size[i];
		strcat(fname,ext);
		strcat(fname,".txt");
		ofstream fout(fname);
		for(int i=0;i<n;i++)
			fout<<rand()%(n/2)<<"\t";
		fout.close();
	}
	return 0;
}
