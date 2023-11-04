#include<iostream>
using namespace std;

class Arc;

class Vertex {
public:
	bool processed;
	bool inQueue;
	char data;
	Vertex* next_vertex;
	Arc* first_arc, * rear_arc;
	Vertex(char data = '\0') : inQueue(false), processed(false), data(data), next_vertex(NULL), first_arc(NULL), rear_arc(NULL) {}
};

class Arc {
public:
	Vertex* vertex;
	Arc* link;
	Arc(Vertex* vertex = NULL) : vertex(vertex), link(NULL) {}
};

class Node {
public:
	Vertex* data;
	Node* link;
	Node(Vertex* data = NULL) : data(data), link(NULL) {}
};

class Queue {
	Node* front, * rear;
public:
	Queue() : front(NULL), rear(NULL) {}
	bool empty() { return front ? false : true; }
	void enqueue (Vertex* vertex) {
		Node* temp = new Node(vertex);
		if(front) rear->link = temp;
		else front = temp;
		rear = temp;
	}
	Vertex* dequeue() {
		if (empty()) return NULL;
		else {
			Vertex* temp = front->data;
			front = front->link;
			return temp;
		}
	}
};

class Graph {
	Vertex* first, *rear;
	int count;
public:
	Graph() : first(NULL), rear(NULL), count(0) {}
	void addVertex(char data) {
		Vertex* temp = new Vertex(data);
		if (first) rear = rear->next_vertex = temp;
		else first = rear = temp;
		count++;
		cout << "VERTEX ADDED SUCCESSFULLY\n\n";
	}
	void addArc(char data1, char data2) {
		Vertex* d1, * d2;
		d1 = d2 = first;
		for (; d1 && d1->data != data1; d1 = d1->next_vertex);
		for (; d2 && d2->data != data2; d2 = d2->next_vertex);
		if (!d1 || !d2) {
			cout << "INVALID EDGE ADDITON";
			return;
		}
		Arc* temp = new Arc(d1);
		if (d2->first_arc) d2->rear_arc = d2->rear_arc->link = temp;
		else d2->first_arc = d2->rear_arc = temp;
		temp = new Arc(d2);
		if(d1->first_arc) d1->rear_arc = d1->rear_arc->link = temp;
		else d1->first_arc = d1->rear_arc = temp;
		cout << "EDGE ADDED SUCCESSFULLY\n\n";
	}
	void display() {
		Vertex* trav = first;
		Arc* temp = NULL;
		for (; trav; trav = trav->next_vertex) {
			cout << trav->data << " <---> ";
			temp = trav->first_arc;
			for (; temp; temp = temp->link) {
				cout << temp->vertex->data << " ---> ";
			}
			cout << "NULL\n";
			cout << "|\n|\n";
		}
		cout << "NULL\n\n";
	}
	void BFT() {
		if (!first) {
			cout << "Graph is empty\n\n";
			return;
		}
		Queue q;
		int nov = 0;
		Vertex* vertex = first;
		while (count != nov) {
			for (vertex = first; vertex->processed; vertex = vertex->next_vertex);
			if (!vertex->inQueue) {
				q.enqueue(vertex);
				vertex->inQueue = true;
			}
			while (!q.empty()) {
				vertex = q.dequeue();
				vertex->inQueue = false;
				vertex->processed = true;
				cout << vertex->data << " ";
				nov++;
				for (Arc* arc = vertex->first_arc; arc; arc = arc->link) {
					if (!arc->vertex->processed && !arc->vertex->inQueue) {
						q.enqueue(arc->vertex);
						arc->vertex->inQueue = true;
					}
				}
			}
		}
		cout<<"\n\n";
	}
};

int main() {
	char data1 = '\0', data2 = '\0';
	int opt = 0;
	bool exit = false;
	Graph g;
	cout << "IMPLEMENTATION OF DEAPTH FIRST SEARCH IN A UNDIRECTED GRAPH\n";
	cout << "-----------------------------------------------------------\n\n";
	do {
		cout << "MENU\n----\n\n1. INSERT VERTEX\n2. INSERT ARC\n3. DISPLAY ADJACENCY LIST\n4. BREADTH FIRST SEARCH\n5. EXIT\n\n";
		cout << "ENTER OPTION : "; cin >> opt; cout << endl;
		switch (opt) {
		case 1:
			cout << "ENTER DATA : "; cin >> data1; cout << endl;
			g.addVertex(data1);
			break;
		case 2:
			cout << "ENTER VERTEX 1 : "; cin >> data1;
			cout << "ENTER VERTEX 2 : "; cin >> data2; cout << endl;
			g.addArc(data1, data2);
			break;
		case 3:
			cout << "ADJACENCY LIST REPRESENTATION OF THE GRAPH\n";
			cout << "------------------------------------------\n\n";
			g.display();
			break;
		case 4:
			cout << "DEAPTH FIRST SEARCH RESULT\n";
			cout << "--------------------------\n\n";
			g.BFT();
			break;
		case 5:
			exit = true;
			cout << "EXIT\n\n";
			break;
		default:
			cout << "INVALID OPTION\n\n";
		}
	} while (!exit);
}


