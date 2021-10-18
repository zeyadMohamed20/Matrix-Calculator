/*
*************************************************************************************************
@file     matrix_multiply.cpp
@author   Zeyad Mohamed Abd ElHamid
@brief    This file controls the multiplication and power (operation number 5 and number 6)
**************************************************************************************************
*/

#include "data_types.h"
#include"matrix_show.h"
#include"matrix_add.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

multiply enter_multiplication()
{
	multiply A{};  //struct variable stores vector of string that holds multiplying matrices names  
	              // and double variable that stores the result of multiplication all constants
	string matrixName{};
	string multiplicationExpression{}; 
	string multiplyingConstant{};  

	cout << "Enter the multiplication expression as (2*A*B*3*C)\n";
	cin.ignore();
	getline(cin, multiplicationExpression);

	for (size_t i = 0; i < multiplicationExpression.length(); i++)
	{
		if ((multiplicationExpression[i] > 44) && (multiplicationExpression[i] < 58) && (multiplicationExpression[i] != 47))
		{
			multiplyingConstant.push_back(multiplicationExpression[i]);
		}
		else if (multiplicationExpression[i]== '*')
		{
			if (multiplyingConstant.empty() == 0)
			{
				A.constantResult = A.constantResult * stod(multiplyingConstant);
				multiplyingConstant.clear();
			}
			else if (matrixName.empty() == 0)
			{
				A.multiplyingMatricies.push_back(matrixName);
				matrixName.clear();
			}
		}
		else
		{
			matrixName.push_back(multiplicationExpression[i]);
		}
	}
	if (multiplyingConstant.empty() == 0)
	{
		A.constantResult = A.constantResult * stod(multiplyingConstant);
		multiplyingConstant.clear();
	}
	else if (matrixName.empty() == 0)
	{
		A.multiplyingMatricies.push_back(matrixName);
		matrixName.clear();
	}
	
	return A;
}

vector<vector<double>>scalar_multiplication(double constant, vector<vector<double>>&matrix)
{
	vector<double>row{};
	vector<vector<double>>result{};

	//The next nested for loop is used to multiply constant by multiplying matrix elements	
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[0].size(); j++)
		{
			row.push_back(constant * matrix[i][j]);
		}
		result.push_back(row);
		row.clear();
	}
	return result;
}

vector<vector<double>>multiply_two_matricies(vector<vector<double>>&mat1, vector<vector<double>>&mat2)
{
	int h{0};
	double multiply{0};
	double sum{0};
	vector<double>resultRow{};
	vector<vector<double>>result{};

	/*
	The algorithm of multiplying 2 matricies is something deep so we must know the mathematical method of multiplication
    to multiply 2 matricies, number of columns of M1 = number of rows of M2 (necessary condition)
	if we have 2 matricies 3*3 and we ant to multiplt then we must follow these steps:
	1) myltiply first row by first column to create an element
	2) multiply first row by second column then fist row by third column so we finished the first row in the result
	3) make the same with second row and third row
	so we can conclude that we need to create an element then create row then create other row 
	so let's explain the following block from inside to outside:
	The second for loop is used to create an element by multiplying row of M1 by column of M2
	while loop is used to change column number of M2 to finish the first row in the result
	the first for loop is used to change the row nimber of M1
	for example: if we have 2 matricies 3*3 called A & B where
	A = 1	4	7          B = 1	2	3 
 		5	8	9              3	4	5
		2	3	6              6	7	8
		then A*B=?
		by tracing the algoritm then
		sum = A[0][0]*B[0][0] + A[0][1]*B[1][0] + A[0][2]*B[2][0] = 1*1+4*3+7*6=55
		then 55 will be pushed to resultRow then initialize sum to be zero again then increase counter (h) to be 1
		where h is used to change the column number of the second matrix
		then sum = A[0][0]*B[0][1] + A[0][1]*B[1][1] + A[0][2]*B[2][1] = 1*2+4*4+7*7=67
		then 67 will be pushed in resultRow and h will increase to be 2 then check condition of while 
		where 2<3 so sum = A[0][0]*B[0][2] + A[0][1]*B[1][2] + A[0][2]*B[2][2] = 79 
		then 79 will be pushed in resultRow the sum will be zero and h increases to be 3 so the condition 
		of while will be false so that we have finished the first row in result so this row will be pushed 
		to result 2D vector and clear resultRow an initialize h thus we do the same with the second 
		row and the third row.
	*/
	for (size_t i = 0; i < mat1.size(); i++)
	{
		while (h < mat2[i].size())
		{
			for (size_t j = 0; j < mat2.size(); j++)
			{
				multiply = mat1[i][j] * mat2[j][h];
				sum = sum + multiply;
			}
			resultRow.push_back(sum);
			sum = 0;
			h++;
		}
		result.push_back(resultRow);
		resultRow.clear();
		h = 0;
	}
	return result;
}

void print_matrix_multiplication()
{
	string checkResult{};
	multiply A{};
	int counter{1};
	vector<size_t>indeces{};
	vector<vector<double>>result{};

	A = enter_multiplication();
	checkResult = check_name(A.multiplyingMatricies);

	if (checkResult == "All found")
	{
		indeces = push_index(A.multiplyingMatricies);  //used to store the index of multiplying matricies 
												  //present in matricies 3D vector
	/*
	The main condition of matrix multiplication is that the number of columns of first matrix must be equal to the
	number of rows of second matrix.
	Let there are 4 matricies i want to multiply which are A,B,C,D
	then i check if the number of columns of A equal to number of rows of B
	then i check if the number of columns of B equal to number of rows of C
	then i check if the number of columns of C equal to number of rows of D
	then we notice there are 3 loops which is less than the number of matricies by 1
	so i make the condition of for loop is i<indeces.size()-1 so that the final loop will be when i==indeces.size()-2
	when i reach the final loop then i am sure that all matricies satisfy the condition of multiplication
	thus we can multiply these matricies

	but there is an impoortant test case as 2*A so that we add a condition about indeces.size()
	if the size > 1 ----> apply first test case
	if the size ==1 ----> apply second test case
	*/
		if (A.multiplyingMatricies.size() > 1)
		{
			for (size_t i = 0; i < indeces.size() - 1; i++)
			{
				if (mainData.columns[indeces[i]] == mainData.rows[indeces[counter]])
				{
					if (i != indeces.size() - 2)
					{
						counter++;
						continue;
					}
					else
					{
						//To multiply constant member (stores the result of multiplication of all constants) by the first matrix
						result = scalar_multiplication(A.constantResult, mainData.matricies[indeces[0]]);
						indeces.erase(indeces.begin() + 0); //To erase first element (that holds index of first matrix)
						for (size_t matrix_counter = 0; matrix_counter < indeces.size(); matrix_counter++)
						{
							result = multiply_two_matricies(result, mainData.matricies[indeces[matrix_counter]]);
						}

						//Store The final result,rows,columns in MatAns that allocates the 1st index in global struct vectors
						mainData.matricies[0] = result;
						mainData.rows[0] = result.size();
						mainData.columns[0] = result[0].size();
						print_matrix(mainData.matricies[0]);
						break;
					}
				}
				else
				{
					cout << "Matrix " << mainData.matrixName[indeces[i]] << " columns" << " not equal";
					cout << " Matrix " << mainData.matrixName[indeces[counter]] << " rows\n";
					break;
				}
			}
		}
		else if (A.multiplyingMatricies.size() == 1)
		{
			result = scalar_multiplication(A.constantResult, mainData.matricies[indeces[0]]);
			mainData.matricies[0] = result;
			mainData.rows[0] = result.size();
			mainData.columns[0] = result[0].size();
			print_matrix(mainData.matricies[0]);
		}
	}
}

vector<vector<double>>identity_matrix(size_t matrixOrder)
{
	vector<double>row{};
	vector<vector<double>>result{};

	/*
	The next block is used to fill identity matrix by numbers whose main diagonal elements are all one 
	while the other elements are all zeros
	*/
	for (size_t i = 0; i < matrixOrder; i++)
	{
		for (size_t j = 0; j < matrixOrder; j++)
		{
			if (i == j)
			{
				row.push_back(1);
			}
			else
			{
				row.push_back(0);
			}
		}
		result.push_back(row);
		row.clear();
	}
	return result;
}

void print_matrix_power()
{
	    string checkResult{"found"};
	    string name{};
		size_t z{};
	    int power{};
	    vector<vector<double>>result{};

		cout << "Enter the name of power matrix \n";
		cin.ignore();
		getline(cin, name);
        
		for (size_t i = 0; i < mainData.matrixName.size(); i++)
		{
			if (name == mainData.matrixName[i])
			{
				z = i;
				break;
			}
			else
			{
				if (i == mainData.matrixName.size() - 1)
				{
					checkResult = "Not found";
					cout << "There is no matrix of name " << name << "\n\n";
				}
			}
		}
		if (checkResult == "found")
		{
			cout << "Enter the power of matrix\n";
			cin >> power;

				if (mainData.rows[z] == mainData.columns[z])  //power matrix must be square matrix
				{
					if (power >= 0)  //power of matrix must br positive
					{
						result = identity_matrix(mainData.rows[z]);

						for (int x = 0; x < power; x++)
						{
							result = multiply_two_matricies(result, mainData.matricies[z]);
						}
						//Store The final result,rows,columns in MatAns that allocates the 1st index in global struct vectors
						mainData.matricies[0] = result;
						mainData.rows[0] = result.size();
						mainData.columns[0] = result[0].size();
						print_matrix(mainData.matricies[0]);
					}
					else
					{
						cout << "The power must be postive value\n\n";
					}
				}
				else
				{
					cout << "The power matrix must be square matrix\n\n";
				}
	    }
}