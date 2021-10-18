/*
*************************************************************************************************
@file     matrix_inverse.cpp
@author   Zeyad Mohamed Abd ElHamid
@brief    This file controls the inverse matrix (operation number 8)
**************************************************************************************************
*/
#include "data_types.h"
#include"matrix_determinent.h"
#include"matrix_show.h"
#include"matrix_turn.h"
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

vector<vector<double>>calculate_cofactor(vector<vector<double>>&mat)
{
	const int powerBase{-1};
	vector<vector<double>>minor{};
	vector<double>row{};
	vector<vector<double>>cofactorMatrix{};

	/*
	To understand the code, we must the method of finding the cofactor mathematically by the following steps:
	1) Calculate the matrix of minors
	2) Calculate matrix of signs
	3) Multiply matrix of minors by matrix of signs to get cofactor matrix
	Example:  1		2	3
	          8		9	6
			  12	11	13
    matrix of minors------> 51		32		-20
	                       -7	   -23		-13
						   -15	   -18		-7
	sign matrix-----> +		-		+
	                  -		+		-
					  +		-		+
	Multiply minor matrix by sign matrix ---> 51	-32		-20
	                                           7	-23		 13
											  -15	 18		  7

	By tracing code:
	1) Find the minor of the first element  
	2) Find determinent of minor 
	3) Multiply determinent by the sign to get first element of cofactor
	4) Make the same with all elements
	*/
	for (size_t i = 0; i < mat.size(); i++)
	{
		for (size_t j = 0; j < mat[0].size(); j++)
		{
			minor = calculate_minor(mat, i, j);
			row.push_back (pow(powerBase, i+j) * calculate_determinent(minor,minor.size()));
		}
		cofactorMatrix.push_back(row);
		row.clear();
	}
	return cofactorMatrix;
}

vector<vector<double>>calculate_inverse(vector<vector<double>>&mat)
{
	vector<vector<double>>cofactorMatrix{};
	vector<vector<double>> adjoint{};
	vector<double>row{};
	vector<vector<double>>inverseMatrix{};

	/*
	To find inverse of any matrix, you must follow this rule: inverse = (1\determinent)*adjoint
	where adjoint matrix is thr transpose of cofactor matrix
	*/
	cofactorMatrix = calculate_cofactor(mat);
	adjoint = turn(cofactorMatrix);

	for (size_t i = 0; i < adjoint.size(); i++)
	{
		for (size_t j = 0; j < adjoint[0].size(); j++)
		{
			row.push_back((1 / calculate_determinent(mat,mat.size())) * adjoint[i][j]);
		}
		inverseMatrix.push_back(row);
		row.clear();
	}
	return inverseMatrix;
}

void print_inverse_matrix()
{
	string name{};
	vector<vector<double>>inverseMatrix{};

	cout << "Enter the name of matrix you want to get inverse\n";
	cin.ignore();
	getline(cin, name);

	for (size_t i = 0; i < mainData.matrixName.size(); i++)
	{
		if (name == mainData.matrixName[i])  //searches the entered name in matrixName vector
		{
			if (mainData.rows[i] == mainData.columns[i])  // checks that the inverse matrix is square matrix
			{  
				//checks that the inverse matrix is non singular matrix
				if (calculate_determinent(mainData.matricies[i],mainData.rows[i]) != 0)  
				{
					inverseMatrix = calculate_inverse(mainData.matricies[i]);

					//Store The final result,rows,columns in MatAns that allocates the 1st index in global struct vectors
					mainData.matricies[0] = inverseMatrix; 
					mainData.rows[0] = inverseMatrix.size();
					mainData.columns[0] = inverseMatrix[0].size();
					print_matrix(mainData.matricies[0]);
				}
				else
				{
					cout << "The inverse matrix must have determinent value not equal to zero\n\n";
				}
			}
			else
			{
				cout << "The matrix must be square matrix\n\n";
			}
			break;
		}
		else if (i == mainData.matrixName.size() - 1)
		{
			cout << "There is no matrix of this name\n\n";
		}
	}
}