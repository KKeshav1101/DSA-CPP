#include<fstream>
#include<iostream>
#include<stdlib.h>
using namespace std;
void insertionsortasc(int array[10000]);
void insertionsortdesc(int array[10000]);
int main(){
	int array[100000],i=0;
	ifstream fin("input.txt");
	while(!fin.eof()){
		fin>>array[i];
		i=i+1;
	}
	fin.close();
	/*for(int j=0;j<10000;j++){
		cout<<array[j]<<"\t";
	}*/
	insertionsortasc(array);
	insertionsortdesc(array);
	return 0;
}
void insertionsortasc(int array[10000]){
	int i,j,key;
	for(j=1;j<10000-1;j++){
		key=array[j];
		i=j-1;
		while(i>=0 && array[i]>key){
			array[i+1]=array[i];
			i=i-1;
		}
		array[i+1]=key;
	}
	ofstream fout("ascending1.txt");
	for(int i=0;i<10000;i++){
		fout<<array[i]<<"\t";
	}
	fout.close();
}
void insertionsortdesc(int array[10000]){
	int i,j,key;
	for(j=1;j<10000-1;j++){
		key=array[j];
		i=j-1;
		while(i>=0 && array[i]<key){
			array[i+1]=array[i];
			i=i-1;
		}
		array[i+1]=key;
	}
	ofstream fout("descending1.txt");
	for(int i=0;i<10000;i++){
		fout<<array[i]<<"\t";
	}
	fout.close();
}
