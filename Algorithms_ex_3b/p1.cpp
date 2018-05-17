#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <list>



using namespace std;

typedef struct Vertex {

	int currentVertex;
	vector<int> myEdges;

} Vertex;



// This class represents a directed graph using
// adjacency list representation
class Graph
{
	int V;    // No. of vertices

			  // Pointer to an array containing adjacency
			  // lists
	list<int> *adj;
public:
	Graph(int V);  // Constructor

				   // function to add an edge to graph
	void addEdge(int v, int w);

	// prints BFS traversal from a given source s
	void BFS(int s);
};


string fileNameInput();
int getNumOfVertices(ifstream &myfile);
Vertex* getEdges(ifstream &myfile, string fname, int numOfVertices);
Graph createAndFillGraph(Vertex *arrayOfEdges, int numOfVertices);
void getNumOfShortestPaths(Graph g);






Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}


void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// 'i' will be used to get all adjacent
	// vertices of a vertex
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited, 
		// then mark it visited and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}








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
	//myfile.close();

}


string fileNameInput() {
	string fname;
	cout << "Please enter a name of an input file: " << endl;
	cin >> fname;
	return fname;
}

Vertex* getEdges(ifstream &myfile,string fname,int numOfVertices) {
	myfile.open(fname);
	char my_character;
	int number_of_lines = 0;
	vector<int> myEdge;
	int i = 0;
	string numToParse;
	int vertexToInsert;
	Vertex *arrayOfEdges = new Vertex[numOfVertices];
	vector<int>::const_iterator j;
	

		if (!myfile.is_open()) {
		exit(EXIT_FAILURE);
			}
		else {
			while (!myfile.eof()) {

				myfile >> my_character;

				if (my_character == '{') { // detects new set of Edges
					myfile >> my_character;
					
					while (my_character != '}') {
						if (my_character != ',' ) {
							stringstream iss;
							arrayOfEdges[i].myEdges.reserve(numOfVertices - 1);
							arrayOfEdges[i].currentVertex = i + 1;
							iss << my_character;
							iss >> vertexToInsert;
							arrayOfEdges[i].myEdges.push_back(vertexToInsert);
							//	cout << "this is a num :";
							//cout << "the index is : " << i + 1 << endl;
							//cout << vertexToInsert << endl;
							
						}
						myfile >> my_character;
						
					}
					i++;
				}
			}

		}

	
	for (int i = 0; i < numOfVertices; i++) {
		
		if (arrayOfEdges[i].currentVertex > 0) {  // otherwise the system shows the currentVertex as a negative number( memory not allocated)
			cout << "current vertex is : " << arrayOfEdges[i].currentVertex << endl; ;
			for (j = arrayOfEdges[i].myEdges.begin(); j != arrayOfEdges[i].myEdges.end(); ++j) {

				cout << (*j) << ",";
			}
			cout << endl;
		}
	}

	return arrayOfEdges;

}

Graph createAndFillGraph(Vertex *arrayOfEdges, int numOfVertices) {
	
	Graph g(numOfVertices);
	vector<int>::const_iterator j;
	int k = 0;
	int v1, v2;
	for (int i = 0; i < numOfVertices; i++) {
		if (arrayOfEdges[k].myEdges.size() > 0) {
			v1 = arrayOfEdges[k].currentVertex;
			for (j = arrayOfEdges[i].myEdges.begin(); j != arrayOfEdges[i].myEdges.end(); ++j) {
				
				v2 = (*j);
				g.addEdge(v1, v2);
			}
		}
		k++;
	}


	
	return g;
}
void getNumOfShortestPaths(Graph g) {
	int startVertex;
	char answer;
	cout << "Please enter the source node : " << endl;
	cin >> startVertex;
	cout << "The output for " << startVertex << " is : " << endl;
	g.BFS(startVertex);
	cout << endl;
	cout << "Do you want to continue (y / n) : " << endl;
	cin >> answer;
	if (answer == 'y') {
		getNumOfShortestPaths(g);
	}


}

void main() {
	
	int startVertex;
	string fname;
	ifstream myfile;

	fname = fileNameInput();
	myfile.open(fname);
	int numOfVertices = getNumOfVertices(myfile);
	myfile.close();
	Vertex* arrayOfEdges = getEdges(myfile, fname,numOfVertices);
	Graph g = createAndFillGraph(arrayOfEdges, numOfVertices);
	getNumOfShortestPaths(g);
	
	


	

	system("pause");


}