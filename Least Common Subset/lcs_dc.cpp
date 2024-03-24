#include<iostream>
using namespace std;

void print_lcs(char x[],char b[][20],int i,int j){
	if(i==0 || j==0)
		return;
	if(b[i][j]=='c'){
		print_lcs(x,b,i-1,j-1);
		cout<<x[i];
	}
	else if(b[i][j]=='t'){
		print_lcs(x,b,i-1,j);
	}
	else{
		print_lcs(x,b,i,j-1);
	}
}
int lcs_dc(char x[],char y[],int i,int j, int &count){
	count++;
	if(i==0 || j==0){
		return 0;
	}
	if(x[i]==y[j]){
		return 1+lcs_dc(x,y,i-1,j-1,count);
	}
	else{
		int t1=lcs_dc(x,y,i-1,j,count);
		int t2=lcs_dc(x,y,i,j-1,count);
		if(t1>=t2)
			return t1;
		else
			return t2;
	}
}
int main(){
	int m,n;
	cout<<"Enter m :";
	cin>>m;
	cout<<"Enter n :";
	cin>>n;
	char x[m+1],y[n+1];
	for(int i=1;i<=m;i++){
		cout<<"Enter string 1 :";
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		cout<<"Enter string 2 :";
		cin>>y[i];
	}
	int count=0;
	cout<<"Length :"<<lcs_dc(x,y,m,n,count)<<endl;
	cout<<"\n\nCOUNT :"<<count<<endl;
}
