#include<iostream>
using namespace std;

struct node{
	int from;
	int to;
	int weight;
	node* next;
};

struct vnode{
	string name;
	int d;
	int pi;
}

class graph{
	int n,m;
	vnode vertex[10];
	node *elist;

	public:
		void createGraph(){
			cout<<"Enter n:";
			cin>>n;
			for(int i=1;i<=n;i++){
				cout<<"Enter name :";
				cin>>vertex[i].name;
			}
			cout<<"Enter m";
			cin>>m;
			elist=NULL;
			node* last=NULL;
			for(int j=1;j<=m;j++){
				node *t=new node;
				cout<<"Enter from :";
				cin>>t->from;
				cout<<"Enter to :";
				cin>>t->to;
				cout<<"Enter weight :";
				cin>>t->weight;
				t->next=NULL;
				if(last==NULL)
					elist=t;
				else
					last->next=t;
				last=t;
			}
		}
		void init(int s){
			for(int i=1;i<=n;i++){
				vertex[i].d=1e9;
				vertex[i].pi=-1;
			}
			vertex[s].d=0;
		}
		void relax(int u,int v,int w){
			if(vertex[v].d>vertex[u].d+w){
				vertex[v].d=vertex[u].d+w;
				vertex[v].pi=u;
			}
		}
		bool BELLMAN_FORD(int s){
			init(s);
			for(int i=1;i<n;i++){
				node*t=elist;
				while(t!=NULL){
					relax(t->from,t->to,t->weight);
					t=t->next;
				}
				node* t=elist;
				while(t!=NULL){
					if(vertex[t->to].d>vertex[t->from].d+t->weight){
						return false;
					}
					t=t->next;
				}
				return true;
			}
		}
		void disp(){
			for(int i=1;i<=n;i++){
				cout<<vertex[i].d<<"\t";
			}
			cout<<endl;
		}
};


int main(){
	graph g;
	g.createGraph();
	bool flag=g.BELLMAN_FORD(1);
	if(flag){
		cout<<"Done"<<endl;
		g.disp();
	}
	else
		cout<<"Nope"<<endl;
}
