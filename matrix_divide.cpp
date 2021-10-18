/*
*************************************************************************************************
@file     matrix_divide.cpp
@author   Zeyad Mohamed Abd ElHamid
@brief    This file controls the division of matricies (opeartion number 7)
**************************************************************************************************
*/

#include "data_types.h"
#include"matrix_add.h"
#include"matrix_inverse.h"
#include"matrix_multiply.h"
#include"matrix_show.h"
#include<iostream>
#include<vector>
using namespace std;

vector<string>enter_division()
{
	string matrixName{};
	string divisionExprssion{}; 
	vector<string>dividingMatricies{};  
	                                    
	cout << "Enter the division expression as (A/B/C)\n";
	cin.ignore();
	getline(cin, divisionExprssion);
	for (size_t i = 0; i < divisionExprssion.length(); i++)
	{
		if (divisionExprssion[i] == '/')
		{
			if (matrixName.empty() == 0)
			{
				dividingMatricies.push_back(matrixName);
				matrixName.clear();
			}
		}
		else
		{
			matrixName.push_back(divisionExprssion[i]);
		}
	}
	if (matrixName.empty() == 0)
	{
		dividingMatricies.push_back(matrixName);
		matrixName.clear();
	}
	return dividingMatricies;
}

vector<vector<double>>divide_two_matricies(vector<vector<double>>&mat1, vector<vector<double>>&mat2)
{
	vector<vector<double>>inverseMatrix = calculate_inverse(mat2);

	/*
	To understand this code then we must understand how does division matricies work?
	To divide two matricies as A/B then we must multiply A by inverse B
	But why we don't divide normally?
	because in math there is nothing called matrix division because matrix is set of numbers so one of numbers 
	maybe zero so we can't divide on zero which is meaningless
	*/
	return multiply_two_matricies(mat1, inverseMatrix);
}

void print_matrix_division()
{
	string checkResult{};
	vector<string>dividingMatricies{};
	vector<size_t>indeces{};
	vector<vector<double>>result{};

	dividingMatricies = enter_division();
	checkResult = check_name(dividingMatricies);

	if (checkResult == "All found")
	{
		indeces = push_index(dividingMatricies);  //This function is used to return vector of int contains the index of 
											 // the dividing matricies present in matricies 3D vector

		for (size_t i = 0; i < indeces.size(); i++)
		{
			if (mainData.rows[indeces[0]] == mainData.rows[indeces[i]])  //All dividing matricies must be square matricies
			{
				if (mainData.columns[indeces[0]] == mainData.columns[indeces[i]])
				{
					if (i != indeces.size() - 1)
					{
						continue;
					}
					else
					{
						result = mainData.matricies[indeces[0]];
						indeces.erase(indeces.begin() + 0); //To erase first element (that holds index of first matrix)

						for (int j = 0; j < indeces.size(); j++)
						{
							result = divide_two_matricies(result, mainData.matricies[indeces[j]]);
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
					cout << "The dividing matricies must be of same order\n\n";
					break;
				}
			}
			else
			{
				cout << "The dividing matricies must be of same order\n\n";
				break;
			}
		}
	}
}