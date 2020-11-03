#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

class Graph
{
	public: 
		Graph(string);
		void readInGraph();
	private:
		int nodes;
		string infile;
		int edges;
		map <string, vector < pair< string, int > > > edgeMap;

};

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		cerr<<"Invalid number of command line arguments.\nUsage: ./readGraph <graphfile>\n"<<
			"Quitting now\n";
		return -1;
	}

	Graph G(argv[1]);

	G.readInGraph();

	return 0;
}

Graph::Graph(string f)
{
	infile = f;
	nodes = -1;
	edges = -1;
}



void Graph::readInGraph()
{
	ifstream fin;
	fin.open(infile);
	
	string line;

	while(getline(fin, line))
	{
		stringstream ss(line);
		if(nodes != -1)
		{
		
		}
		else
		{
			ss>>nodes>>edges;
		}
		cout<<line<<endl;
	}
	fin.close();
	cout<<"Nodes: "<<nodes<<endl;
	cout<<"Edges: "<<edges<<endl;
}

