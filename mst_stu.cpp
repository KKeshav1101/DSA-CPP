//IMPLEMENTATION OF PRIM'S ALGORITHM ON AN UNDIRECTED WEIGHTED GRAPH - DETERMINE THE COST OF MINIMUM SPANNING TREE

#include<iostream>
using namespace std;

class Arc;

class Vertex {

public :

	char data;
	bool intree;
	Arc *first_arc, *rear_arc;
	Vertex *next_vertex;
	
	Vertex(char data = '\0') : data(data), intree(false) {
		first_arc = rear_arc = NULL; next_vertex = NULL;
	}
	
};

class Arc {

public :

	int weight;
	Vertex* vertex;
	Arc* link;
	
	Arc(int weight = 0, Vertex* vertex = NULL) : weight(weight), vertex(vertex), link(NULL){}
	
	
};

class Graph {

	Vertex *first, *rear;
	int count;
	
public:

	Graph() : first(NULL), rear(NULL), count(0) {}
	
	void addVertex(char data){
	
		Vertex *temp = new Vertex(data);
		
		if(first) rear = rear->next_vertex = temp;
		else first =  rear = temp;
		count++;
		
		cout << "VERTEX ADDED SUCCESSFULLY\n\n";
		
	}
	
	void addArc(char data1, char data2, int weight){
	
		if(!first) {
			cout << "GRAPH IS EMPTY\n\n";
			return;
		}
	
		Vertex *d1, *d2;
		d1 = d2 = first;
		
		for(; d1 and d1->data != data1; d1 = d1->next_vertex);
		for(; d2 and d2->data != data2; d2 = d2->next_vertex);
		
		if(!d1 or !d2) {
			cout << "INVALID INPUT - CAN'T ADD EDGE\n\n";
			return;
		}
		
		Arc* temp = new Arc(weight, d1);
		if(d2->first_arc) d2->rear_arc = d2->rear_arc->link = temp;
		else d2->first_arc = d2->rear_arc = temp;
		
		temp = new Arc(weight, d2);
		if(d1->first_arc) d1->rear_arc = d1->rear_arc->link = temp;
		else d1->first_arc = d1->rear_arc = temp;
		
		cout << "EDGE ADDED SUCCESSFULLY\n\n";
		
	}
	
	void display() {
		for(Vertex *temp = first; temp; temp = temp->next_vertex){
			cout << temp->data << " --- ";
			for(Arc *arc = temp->first_arc; arc; arc = arc->link)
				cout << arc->vertex->data <<" --> ";
			cout<<"NULL\n";
		}
		cout<<"\n\n";
	}
	
	void prims_mst() {
	
		if(!first) {
			cout << "GRAPH IS EMPTY\n\n";
			return;
		}
	
		cout << "MINIMUM SPANNING TREE\n\n";
		
		Vertex *vertex = first, *suc = NULL;
		for(Vertex *temp = first; temp; temp = temp->next_vertex) temp->intree = false;
		
		int min = 9999, sum = 0;
		bool tree_complete = false;
		Vertex *minedge = NULL;
		
		vertex = first;
		vertex->intree = true;
		
		while(!tree_complete){
			min  = 9999;
			tree_complete = true;
			
			for(vertex = first; vertex; vertex = vertex->next_vertex){
			
				if(vertex->intree and vertex->first_arc){
				
					for(Arc* arc = vertex->first_arc; arc; arc = arc->link){
					
						if(! arc->vertex->intree) {
						
							tree_complete = false;
							
							if(min > arc->weight) {
								min = arc->weight;
								minedge = arc->vertex;
								suc = vertex;
							}
							
						}	
						
					}
				
				}	
			} 
			
			if(minedge != NULL and !tree_complete) {
				sum += min;
				minedge->intree = true;
				cout << suc->data << " ---( " << min << " )---> " << minedge->data << endl;
			}
			
		}
		
		cout << "COST = " << sum;
		cout << "\n\n";
		
	}
};

int main() {

	cout << "DETERMINATION OF MINIMUM SPANNING TREE USING PRIM'S ALGORITHM\n\n";
	
	int weight = 0, opt = 0;	
	char data1 = '\0', data2 = '\0';
	bool exit = false;
	Graph g;
	
	do {
		cout << "MENU\n----\n\n1. INSERT VERTEX\n2. INSERT EDGE\n3. DISPLAY\n4. MINIMUM SPANNING TREE\n5. EXIT\n\nENTER OPTION : ";
		cin >> opt; cout<<endl;
		switch(opt){
			case 1 :
					cout << "DATA : "; cin>>data1; cout<<endl;
					g.addVertex(data1);
					break;
			case 2 :
					cout << "DATA 1 : "; cin>>data1; 
					cout << "DATA 2 : "; cin>>data2; 
					cout << "WEIGHT : "; cin>>weight; cout<<endl;
					g.addArc(data1, data2, weight);
					break;
			case 3 :
					g.display();
					break;
			case 4 :
					g.prims_mst();
					break;
			case 5 :
					exit = true;
					cout << "EXIT\n\n";
					break;
			default :
					cout << "INVALID OPTION\n\n";
		}
	} while(! exit);

}

