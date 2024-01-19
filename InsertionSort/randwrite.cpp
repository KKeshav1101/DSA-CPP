#include<fstream>
#include<stdlib.h>
using namespace std;
int main(){
	ofstream fout("input.txt");
	//srand((long int)clock());
	for(int i=0;i<10000;i++)
		fout<<rand()%30000<<"\t";
	fout.close();
	return 0;
}
