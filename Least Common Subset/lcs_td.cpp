#include<iostream>
using namespace std;

void print_lcs(char x[],char b[][20],int i,int j){
	if(i==0 || j==0)
		return;
	if(b[i][j]=='c'){
		print_lcs(x,b,i-1,j-1);
		cout<<x[i];
	}
	else if(b[i][j]='t')
		print_lcs(x,b,i-1,j);
	else
		print_lcs(x,b,i,j-1);
}
int lcs_td(char x[],char y[],int c[][20],char b[][20],int i,int j,int &count){
	if(c[i][j]>=0){
		return c[i][j];
	}
	count++;
	if(i==0 || j==0){
		c[i][j]=0;
		return c[i][j];
	}
	if(x[i]==y[j]){
		c[i][j]=1+lcs_td(x,y,c,b,i-1,j-1,count);
		b[i][j]='c';
	}
	else{
		int t1=lcs_td(x,y,c,b,i-1,j,count);
		int t2=lcs_td(x,y,c,b,i,j-1,count);
		if(t1>=t2){
			c[i][j]=t1;
			b[i][j]='t';
		}
		else{
			c[i][j]=t2;
			b[i][j]='r';
		}
	}
	return c[i][j];
}
int main(){
	int m,n;
	cout<<"Enter m :";
	cin>>m;
	cout<<"Enter n :";
	cin>>n;
	char x[m+1],y[n+1];
	for(int i=1;i<=n;i++){
		cout<<"Enter :";
		cin>>x[i];
	}
	for(int i=0;i<=n;i++){
		cout<<"Enter :";
		cin>>y[i];
	}
	int c[20][20];
	char b[20][20];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++)
			c[i][j]=-99999;
	}
	int count=0;
	lcs_td(x,y,c,b,m,n,count);
	print_lcs(x,b,m,n);
	cout<<"\n\nCount :"<<count<<endl;
}
