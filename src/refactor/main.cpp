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

int main(int argc, char* argv[])
{

	int partites = stoi(argv[2]);

	//cout << "PARTITE:" <<partites<<endl;
	int vertices = 0;
	int edges = 0;

	vector < vector <int>> matrix;
	vector <int> partiteSets;

	for (int i = 0; i < partites; i++)
	{
		string l = argv[i+3];
		stringstream ss(l);

		int min, max;
		char trash;

		ss>>min>>trash>>max;

		partiteSets.push_back(min);

	}
	//cout<<partiteSets.size()<<endl;
	//for(int i = 0; i < partiteSets.size(); i++)
	//	cout<<partiteSets[i]<<" ";
	//cout<<endl;
	ifstream fin;
	fin.open(argv[1]);

	string line;
	string outname;
	vector <int> P;

	outname = argv[1];
	outname =  outname.substr(0, outname.size()-4);
	outname += "_maximalcliques.txt";

	ofstream fout;
	fout.open(outname);
	while(getline(fin, line)){
		stringstream ss(line);
		if(vertices == 0)
		{
			ss>>vertices>>edges;
			//nodes.resize(vertices, "NA");
			matrix.resize(vertices);
			P.resize(vertices);
			for(int i = 0; i < vertices; i++)
				matrix[i].resize(vertices, 0);
			for(int i = 0; i < P.size(); i++)
				P[i] = i;
		}
		else
		{
			//cout<<line<<endl;
			int node1, node2;
			ss>>node1>>node2;

			/*
			   int i1 = findIndex(node1, nodes);
			   nodes[i1] = node1;
			   int i2 = findIndex(node2, nodes);
			   nodes[i2] = node2;
			   */

			matrix[node1][node2] = 1;
			matrix[node2][node1] = 1;

		}

	}

	//printMatrix(matrix);


	addIntrapartiteEdges(matrix,  partiteSets);
	//cout<<endl<<endl;
	//printMatrix(matrix);
	vector <int> R;
	vector < int> X;
	fout<<"Maximal Cliques:"<<endl;
	enumerate(matrix, R, P, X, partiteSets, fout);
	cout<<"Maximal Cliques output to "<<outname<<endl;
	fout.close();
}

