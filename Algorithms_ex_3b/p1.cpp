#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

string fileNameInput();
int getNumOfVertices(ifstream &myfile);
void getEdges(ifstream &myfile, string fname);


//// This class represents a directed graph using
//// adjacency list representation
//class Graph
//{
//	int V;    // No. of vertices
//
//			  // Pointer to an array containing adjacency
//			  // lists
//	list<int> *adj;
//public:
//	Graph(int V);  // Constructor
//
//				   // function to add an edge to graph
//	void addEdge(int v, int w);
//
//	// prints BFS traversal from a given source s
//	void BFS(int s);
//};
//
//Graph::Graph(int V)
//{
//	this->V = V;
//	adj = new list<int>[V];
//}
//
//void Graph::addEdge(int v, int w)
//{
//	adj[v].push_back(w); // Add w to v’s list.
//}
//
//
//void Graph::BFS(int s)
//{
//	// Mark all the vertices as not visited
//	bool *visited = new bool[V];
//	for (int i = 0; i < V; i++)
//		visited[i] = false;
//
//	// Create a queue for BFS
//	list<int> queue;
//
//	// Mark the current node as visited and enqueue it
//	visited[s] = true;
//	queue.push_back(s);
//
//	// 'i' will be used to get all adjacent
//	// vertices of a vertex
//	list<int>::iterator i;
//
//	while (!queue.empty())
//	{
//		// Dequeue a vertex from queue and print it
//		s = queue.front();
//		cout << s << " ";
//		queue.pop_front();
//
//		// Get all adjacent vertices of the dequeued
//		// vertex s. If a adjacent has not been visited, 
//		// then mark it visited and enqueue it
//		for (i = adj[s].begin(); i != adj[s].end(); ++i)
//		{
//			if (!visited[*i])
//			{
//				visited[*i] = true;
//				queue.push_back(*i);
//			}
//		}
//	}
//}

int getNumOfVertices(ifstream &myfile) {
	int numberOfVertices;
	string line;
	bool firstLine = true;
	if (!myfile.is_open()) {
		exit(EXIT_FAILURE);
	}
	else {
		while (getline(myfile, line)) {

			stringstream iss(line);
			if (firstLine == true) {
				iss >> numberOfVertices;
				firstLine = false;
			}
			else {
				return numberOfVertices;
			}

		}

	}
	myfile.close();

}

//void fillGraphWithData(Graph graph) {
//
//
//}
string fileNameInput() {
	string fname;
	cout << "Please enter a name of an input file: " << endl;
	cin >> fname;
	return fname;
}

void getEdges(ifstream &myfile,string fname) {
	myfile.open(fname, ios::in);
	char my_character;
	int number_of_lines = 0;
	vector<int> myEdge;

	while (!myfile.eof()) {

		myfile.get(my_character);
		cout << my_character;
		myfile.get(my_character);
		cout << my_character;
		myfile.get(my_character);
		cout << my_character;
		myfile.get(my_character);
		cout << my_character;
		myfile.get(my_character);
		cout << my_character;
		myfile.get(my_character);
		cout << my_character;
		//if (my_character == '\n') {
		//	++number_of_lines;
		//}
		//if (my_character == '{') { // detects Edge
		//	
		//	while (!my_character == '}') {
		//		myfile.get(my_character);
		//		if (my_character != ',') {
		//			cout << my_character << endl;
		//		}
		//		else {
		//			cout << my_character << endl;
		//		}
		//	}
		//}
	}
	cout << "NUMBER OF LINES: " << number_of_lines << endl;

}

void main() {
	
	int startVertex;
	string fname;
	ifstream myfile;

	fname = fileNameInput();
	myfile.open(fname);
	
	getNumOfVertices(myfile);
	myfile.clear();
	getEdges(myfile, fname);
	//getVertices();


	//fillGraphWithData();
	cout << "Please enter the source node : " << endl;
	cin >> startVertex;
	cout << "The output for " << startVertex << " is : " << endl;
	//printAnswer();


	/*Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);*/

	system("pause");


}