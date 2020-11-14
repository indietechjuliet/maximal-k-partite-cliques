/*Author: Rachel Offutt - University of Tennessee
*
*Main function of the program, take in command line arguetns, and reads in the 
*graph into an adjacency matrix
*
*Date Last Modified: Nov. 13, 2020
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

#include "inputprep.h"
#include "enumerate.h"
#include "helper.h"

int main(int argc, char* argv[])
{

	//Must have input file name, number of partite sets, and at least one partite set group
	if(argc < 4)
	{
		cerr<<"Invalid number of command line arguments. Please see github documentation\n"<<
		"for correct command line examples.\n";
		return -1;
	}

	//Variables to store the number of partities, number of vertices, and edges
	int partites = stoi(argv[2]);
	int vertices = 0;
	int edges = 0;
	
	//vectors need for the enumerate subroutine
	vector <int> R;
	vector < int> X;
	vector <int> P;
	vector < vector <int>> matrix;
	vector <int> partiteSets;


	//loop to read in partite set boundaries
	for (int i = 0; i < partites; i++)
	{
		string l = argv[i+3];
		stringstream ss(l);

		int min, max;
		char trash;

		ss>>min>>trash>>max;

		partiteSets.push_back(min);

	}

	//opening input file and error checking
	ifstream fin;
	fin.open(argv[1]);
	if(!fin)
	{
		cerr<<"File "<<argv[1]<<" does not  exist. Exiting now.\n";
		return -1;
	}

	//creating an output file for maximal cliques and opening the file
	string line;
	string outname;
	outname = argv[1];
	outname =  outname.substr(0, outname.size()-4);
	outname += "_maximalcliques.txt";
	ofstream fout;
	fout.open(outname);
	
	//read in vertices and edges
	while(getline(fin, line)){
		stringstream ss(line);
		if(vertices == 0)
		{
			ss>>vertices>>edges;
			
			matrix.resize(vertices);
			P.resize(vertices);
			for(int i = 0; i < vertices; i++)
				matrix[i].resize(vertices, 0);
			for(int i = 0; i < P.size(); i++)
				P[i] = i;
		}
		else
		{
			int node1, node2;
			ss>>node1>>node2;

			matrix[node1][node2] = 1;
			matrix[node2][node1] = 1;

		}

	}
	
	//add intrapartite edges to adjacency matrix
	addIntrapartiteEdges(matrix,  partiteSets);
	fout<<"Maximal Cliques:"<<endl;
	
	//call enumerate subroutine
	enumerate(matrix, R, P, X, partiteSets, fout);
	
	cout<<"Maximal Cliques output to "<<outname<<endl;
	fout.close();
}

