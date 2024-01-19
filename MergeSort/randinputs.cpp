#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
	ofstream fout("input.txt");
	for(int i=0;i<10000;i++)
		fout<<rand()%30000<<"\t";
	fout.close();
	return 0;
}
