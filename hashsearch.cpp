//hash search//keshav
#define hsize 7
#include<iostream>
using namespace std;
struct node{
	int data;
	node *link;
};
class HSearch{
	node *first[hsize];
	public:
		HSearch(){
			for(int i=0;i<hsize;i++)
				first[i]=NULL;
		}
		void insert(int rem,int d){
			node *t=new node;
			t->data=d;
			t->link=first[rem];
			first[rem]=t;
		}
		void search(int data){
			int x=data%hsize;
			node *t=first[x];
			while(t!=NULL){
				if(t->data==data){
					cout<<"Element found\n";
					return;
				}
				t=t->link;
			}
			cout<<"Element not found\n";
		}
		void display(){
			for(int i=0;i<hsize;i++){
				node *t=first[i];
				while(t!=NULL){
					cout<<t->data<<"=>";
					t=t->link;
				}
			}
		}
};
int main(){
	HSearch h;
	int opt,data,rem;
	do{
		cout<<"1.Insert\n2.Search\n3.Display\n";
		cout<<"Enter option";
		cin>>opt;
		switch(opt){
			case 1: cout<<"Enter data";
					cin>>data;
					rem=data%hsize;
					h.insert(rem,data);
					break;
			case 2: cout<<"Enter element to be searched";
					cin>>data;
					h.search(data);
					break;
			case 3:	h.display();
					break;
			default:cout<<"Enter valid option.";
		}
		cout<<"Want to continue?";
		cin>>opt;
	}while(opt==1);
}

