/*
*************************************************************************************************
@file     matrix_determinent.cpp
@author   Zeyad Mohamed Abd ElHamid
@brief    This file controls the deterrminent of matrix (opeartion number 9)
**************************************************************************************************
*/


#include "data_types.h"
#include<cmath>
#include<iostream>
#include<vector>
#define ORDER__ONE__BY__ONE 1
#define ORDER__TWO__BY__TWO 2
using namespace std;

vector<vector<double>>calculate_minor(vector<vector<double>>&mat, size_t rowNumber, size_t columnNumber)
{
	vector<double>row{};
	vector<vector<double>>minor{};

	for (size_t i = 0; i < mat.size(); i++)
	{
		for (size_t j = 0; j < mat[0].size(); j++)
		{
			//To find minor of any element , you must omit the row and the column of this element
			if (i == rowNumber || j == columnNumber)
			{
				continue;
			}
			else
			{
				row.push_back(mat[i][j]);
			}
		}
		// check row is empty or not to avoid pushing empty vector inside 2D vector
		if (row.empty() == 0)
		{
			minor.push_back(row);
			row.clear();
		}
	}
	return minor;
}

double calculate_determinent(vector<vector<double>>&mat,size_t n)
{
    /*
    This function is recursive function where:
    Recursion: is calling the function for itself and it is used to divide complex problems into simpler ones
    so recursive function consists of two blocks:-
    1) Base case:        2) Recursive case

    -Base case: it is the simplest possible input and this case is very important to avoid stack overflow error
     because if the base case is not found then recursive caase will repaeat infinitely till stack overflow occur
     where it can be more than one base case
    -Recursive case: it contains a relation between f(n) and f(n-1)
	*/
	const int rowNumber{0};
	const int poweBase{-1};
	vector<vector<double>>minor{};
	double determinentValue{0};

	/*
	The next 2 if blocks represent the base case of the recursive function at which the simplest possible input 
	is 1 and 2 
	if it's 1 then it means that matrix is 1*1  then return this only element as determinent value
	if it's 2 then it means that matrix is 2*2 then return the result of[0][0]*[1][1]-[0][1]*[1][0] as determinent value
	*/
	if (n == ORDER__ONE__BY__ONE)
	{
		determinentValue = mat[0][0];
	}
	else if (n == ORDER__TWO__BY__TWO)
	{
		determinentValue = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
	}
	/*
	The next block represents the recursive case
	But to understand this block then we must understand the determinent mathematically
	for example: find determinet of the following matrix:  1	4	7
	                                                       8	9	6
														   5	2	3
	then dterminent = 1 * (-1)^0 * determinet of  9    6 +  4 * (-1)^1 * determinet of  8    6 
	                                              2    3                                5    3
	+ 7 * (-1)^2 * determinet of  8    9
	                              5    2
    then we can say that, to find determinet, there are 5 steps:
	1) Determine element
	2) Determine sign
	3) Find dterminet of minor
	4) Multiply step 1 by 2 by 3
	5) Make the previous 4 steps on all elements of any row then add all results

	Hint: The determinent of first row as second row as third row as ....
    So i always choose the first row to find the determinent so the column number is variable so i make for loop
	to count column in the first row 
	so to do the previous 5 steps, do the following:
	1) The element must be in row 0 (first row) but in unknown column (x)
	2) The sign is (-1)^x, so the fist element is +ve , the second is -ve , the third is +ve
	3) Call calculate minor function to find the minor of the element then find determinent of minor
	   But remember that the order of minor is less than the original matrix by 1
	4) Multiply element by sign by det(minor of order -1)
	5) Make the same with all elements in the first row then add these results 
	*/
	else
	{
		for (size_t x = 0; x < mat[0].size(); x++)
		{
			minor = calculate_minor(mat, rowNumber, x);
			determinentValue = determinentValue + mat[0][x] * pow(poweBase, x) * calculate_determinent(minor,n-1);
		}
	}
	return determinentValue;
}

void print_determinent()
{
	string name{};

	cout << "Enter the name of matrix you want to get determinent\n";
	cin.ignore();
	getline(cin,name);
	cout << "\n";

	for (size_t i = 0; i < mainData.matrixName.size(); i++)  //used to search the entered name in matrixName vector
	{
		if (name == mainData.matrixName[i]) 
		{
			if (mainData.rows[i] == mainData.columns[i])  //used to check that the matrix is square matrix
			{
				cout << "The result of determinent is " << calculate_determinent(mainData.matricies[i],mainData.rows[i]) << "\n\n";
			}
			else
			{
				cout << "The matrix must be square matrix\n\n";
			}
			break;
		}
		else if(i == mainData.matrixName.size()-1)
		{
			cout << "There is no matrix of this name\n\n";
		}
	}
}
#undef ORDER__ONE__BY__ONE
#undef ORDER__TWO__BY__TWO