#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;




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

