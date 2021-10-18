/*
*************************************************************************************************
@file     matrix_turn.cpp
@author   Zeyad Mohamed Abd ElHamid
@brief    This file controls matrix transpose (operation number 2)
**************************************************************************************************
*/

#include "data_types.h"
#include"matrix_show.h"
#include<iostream>
#include<vector>
using namespace std;

vector<vector<double>>turn(vector<vector<double>>&mat)
{
	vector<double>row{};
	vector<vector<double>>matrix{};

	/*
	The next block is used to turn matrix by representing j as row and i as column
	let's take an example on matrix 3*3 and trace the pushing process on matrix elements:
	 (0,0)-->(1,0)-->(2,0) inside first row of matrix
	 (0,1)-->(1,1)-->(2,1) inside second row of matrix
	 (0,2)-->(1,2)-->(2,2) inside third row of matrix
	*/
	for (size_t i = 0; i < mat[0].size(); i++)
	{
		for (size_t j = 0; j < mat.size(); j++)
		{
			row.push_back(mat[j][i]);
		}
		matrix.push_back(row);
		row.clear();
	}
	return matrix;
}

void print_matrix_transpose()
{
	    string turningName{};
		vector<vector<double>>matrix{};

	    cout << "Enter the name of matrix you want to turn\n";
		cin.ignore();
		getline(cin, turningName);

		for (size_t i = 0; i < mainData.matrixName.size(); i++)
		{
			if (turningName == mainData.matrixName[i])  //search about the entered name in matrixName vector
			{
				matrix = turn(mainData.matricies[i]);  // stores matrix after transpone in matrix 2D vector

				mainData.matricies[0] = matrix;  // The first index in matricies 3D vector is allocated for MatAns
				mainData.rows[0] = matrix.size();  // The first index in row vector is allocated for MatAns rows 
				mainData.columns[0] = matrix[0].size();  // The first index in column vector is allocated for MatAns columns
				print_matrix(mainData.matricies[0]);  //to print matrix answer
				break;
			}
			else if (i == mainData.matrixName.size() - 1)  //reach the final loop without finding the name of matrix 
			{
				cout << "There is no matrix of this name\n\n";
			}
		}

}