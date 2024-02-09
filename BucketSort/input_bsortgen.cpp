#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
    ofstream fout("input_bsort.txt");
    srand((long int)clock());
    for(int i=0;i<10000;i++)
        fout<<(float)rand()/RAND_MAX<<"\t";
    fout.close();
    return 0;
}