#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;



int findIndex(string target, vector < string> &nodes);
void printMatrix( vector < vector <int> > &matrix);
vector <int> returnFirstClique(vector <vector <int> > matrix, vector <int> partiteSets);
void addIntrapartiteEdges(vector <vector < int> > &matrix, vector <int> partiteSets);
void enumerate(vector <vector <int > > matrix, vector <int> R, vector <int> P, vector <int> X, vector <int> partiteSets, ofstream& fout );
vector <int> choosePivot(vector <int> P , vector <int> X, vector < vector <int >> matrix);
vector <int> intersection( vector <int> setA, vector <int> matrixRow);
int coverPartition(vector <int> R, vector <int> partiteSets);


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

void enumerate(vector <vector <int > > matrix, vector <int> R, vector <int> P, vector <int> X, vector <int> partiteSets, ofstream& fout )
{
	//cout<<"here"<<endl;
	//cout<<"P: "<<P.size()<<"   X:"<<X.size()<<endl;
	//for(int i = 0; i < P.size(); i++)
	//	cout<<P[i]<<"  ";
	//cout<<endl<<endl;
	if(P.size() == 0 && X.size() == 0)
	{
		if(coverPartition(R, partiteSets))
		{
			//vector <int> Rconnected = allConnected(R, matrix);
			//fout<<"Maximal Partite Clique: "<<endl;a
			for(int s = 0; s < R.size(); s++)
				fout<<R[s]<<" ";
			fout<<endl;
		}
		//cout<<"returning"<<endl;
		return;
	}
	vector <int>  pivot = choosePivot(P, X, matrix);
	if (pivot.size() > 0)
	{
		for(int f =0; f < pivot.size(); f++)
		{
			for(int v = 0; v < matrix[pivot[f]].size(); v++)
			{
				vector <int>::iterator it;
				it = find(P.begin(), P.end(), v);
				if(it != P.end() && matrix[pivot[f]][v]  == 0)
				{


					vector <int> PnNv = intersection(P, matrix[v]);
					vector <int> XnNv = intersection(X, matrix[v]);
					R.push_back(v);
					enumerate(matrix, R, PnNv, XnNv, partiteSets, fout);
					P.erase(it);
					X.push_back(v);
					R.pop_back();
				}
			}
		}
	}

}


vector <int> intersection( vector <int> setA, vector <int> matrixRow)
{
	vector <int>::iterator it;

	vector <int> intersect;
	for(int i = 0; i < matrixRow.size(); i++)
	{
		it = find(setA.begin(), setA.end(), i);
		if(it != setA.end() && matrixRow[i] == 1)
		{
			intersect.push_back(i);
		}
	}
	return intersect;
}
vector <int> choosePivot(vector <int> P , vector <int> X, vector < vector <int >> matrix)
{
	vector <int> PuX;

	PuX = P;

	vector <int> pivot;
	vector <pair < int, int> > temp;
	vector<int>::iterator it;
	for(int i = 0; i < X.size(); i++)
	{
		it  = find(PuX.begin(), PuX.end(), X[i]);
		if(it == PuX.end())
			PuX.push_back(X[i]);
	}

	//cout<<"PUX size:"<<PuX.size();
	if(PuX.size() == 1)
	{
		pivot.push_back(PuX[0]);
		return pivot;
	}
	int maxcount = 0;
	for(int u = 0; u < PuX.size(); u++)
	{
		vector <int> Nu = matrix[PuX[u]];
		int count  = 0;
		for(int n = 0; n < Nu.size(); n++)
		{
			it = find(P.begin(), P.end(), n);
			if(Nu[n] != 0 && it != P.end())
				count++;
		}

		temp.push_back(make_pair(PuX[u], count));
		if(count >= maxcount)
		{
			maxcount = count;
			//pivot.push_back(PuX[u]);
		}

	}

	for(int i = 0; i < temp.size(); i++)
	{
		if(temp[i].second == maxcount)
		{
			pivot.push_back(temp[i].first);
			//cout<<"PIV: "<<temp[i].first<<endl;
		}
	}



	return pivot;

}

int coverPartition(vector <int> R, vector <int> partiteSets)
{
	//cout<<"IN COVER"<<endl;
	vector <int> found;
	found.resize(partiteSets.size(), 0);
	for(int i = 0; i < partiteSets.size(); i++)
	{
		if(i+1 < partiteSets.size())
		{
			for(int node = 0; node < R.size(); node++)
			{
				if (R[node] > partiteSets[i] && R[node] < partiteSets[i+1])
				{
					if(found[i] ==1)
					{

					}
					found[i] = 1;
					break;
				}

			}

		}
		else
		{
			for(int node = 0; R.size(); node++)
			{
				if(R[node] > partiteSets[i])
				{
					found[i] = 1;
					break;
				}
			}

		}
	}

	for(int i = 0; i < found.size(); i++)
	{
		if(found[i] == 0)
			return false;
	}
	return true;

}


void addIntrapartiteEdges(vector <vector < int> > &matrix, vector <int> partiteSets)
{
	for(int i = 0; i < partiteSets.size(); i++)
	{
		if(i+1 < partiteSets.size())
		{
			int cap = partiteSets[i+1];
			for(int a  = partiteSets[i]; a < cap; a++)
			{
				for(int b = partiteSets[i]; b < cap; b++)
				{
					if(a != b)
					{
						matrix[a][b] = 2;
						matrix[b][a] = 2;
					}
				}
			}	

		}
		else
		{
			for(int a = partiteSets[i]; a < matrix[0].size(); a++)
			{
				for(int b = partiteSets[i]; b < matrix[0].size(); b++)
				{
					if(a != b)

					{
						matrix[a][b] = 2;
						matrix[b][a] =2;
					}
				}
			}

		}
	}

}



void printMatrix( vector < vector <int> > &matrix)
{
	cout<<"	";
	for(int i = 0; i < matrix[0].size(); i++)
	{
		cout<<i<<"	";
	}
	cout<<endl;
	for(int i = 0; i < matrix[0].size(); i ++)
	{
		cout<<i;
		for(int j = 0; j < matrix[0].size(); j++)
		{
			cout<<"	"<<matrix[i][j];
		}
		cout<<endl;
	}
}

