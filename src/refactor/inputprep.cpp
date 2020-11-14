#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


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

