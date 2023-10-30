#include<iostream>
using namespace std;
struct ga;
struct gv{
	gv* nextv;
	char name;
	bool proc;
	ga* firstarc;
};
struct ga{
	gv* adj;
	ga* link;
};
struct node{
	gv *data;
	node *link;
};
class Stack{
	node *top;
	public:
		Stack(){
			top=NULL;
		}
		void push(gv* d){
			node *nn=new node;
			nn->data=d;
			nn->link=top;
			top=nn;
		}
		gv* pop(){
			gv* n=top->data;
			top=top->link;
			return n;
		}
		gv* stackTop(){
			if(top==NULL)
				return NULL;
			else
				return top->data;
		}
};
class DFS{
	public:
	gv* first;
	int count;
	DFS(){
		first=NULL;
		count=0;
	}
	void insertvertex(){
		char d;
		cout<<"enter node name :";
		cin>>d;
		gv* nn=new gv;
		nn->nextv=NULL;
		nn->name=d;
		nn->proc=false;
		nn->firstarc=NULL;
		if(first==NULL)
			first=nn;
		else{
			gv* temp=first;
			while(temp->nextv!=NULL)
				temp=temp->nextv;
			temp->nextv=nn;
		}
		count++;
	}
	void insertarc(char x,char y){
		gv* temp1=first;
		while(temp1!=NULL && temp1->name!=x)
			temp1=temp1->nextv;
		gv* temp2=first;
		while(temp2!=NULL && temp2->name!=y)
			temp2=temp2->nextv;
		ga* nn=new ga;
		nn->adj=temp2;
		nn->link=temp1->firstarc;
		temp1->firstarc=nn;
		ga* nn1=new ga;
		nn1->adj=temp1;
		nn1->link=temp2->firstarc;
		temp2->firstarc=nn1;
	}
	void DFT(){
		Stack s;
		int nov=0;
		gv* temp=first;
		s.push(temp);
		temp->proc=true;
		nov++;
		cout<<temp->name;
		while(nov!=count){
			gv* n=s.stackTop();
			ga* t=n->firstarc;
			while(t!=NULL && t->adj->proc)
				t=t->link;
			if(t!=NULL){
				s.push(t->adj);
				t->adj->proc=true;
				nov++;
				cout<<t->adj->name;
			}
			else{
				gv* n1=s.pop();
				if(s.stackTop()==NULL){
					gv* t=first;
					while(t!=NULL && t->proc==true)
						t=t->nextv;
					if(t!=NULL){
						s.push(t);
						t->proc=true;
						nov++;
						cout<<t->name;
					} 
				}
			}
		}
	}
};
int main(){
	DFS d;
	int opt;
	char d1,d2;
	do{
		cout<<"1.INSERT VERTEX\n2.INSERT ARC\n3.DFS\nEnter option :";
		cin>>opt;
		switch(opt){
			case 1:
					d.insertvertex();
					break;
			case 2:
					cout<<"Enter end vertices";
					cin>>d1>>d2;
					d.insertarc(d1,d2);
					break;
			case 3: d.DFT();
					break;
			default:
					cout<<"INVALID OPTION ENTERED";
		}
		cout<<"\npress 1 to continue :";
		cin>>opt;
	}while(opt==1);
	return 0;
}
