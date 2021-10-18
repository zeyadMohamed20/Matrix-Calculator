/*
*************************************************************************************************
@file     matrix_subtruct.cpp
@author   Zeyad Mohamed Abd ElHamid
@brief    This file controls the subtruction of matricies (operation number 4)
**************************************************************************************************
*/

#include "data_types.h"
#include"matrix_show.h"
#include"matrix_add.h"
#include<iostream>
#include<string>
#include<vector>

vector<string>enter_subtructing_matricies()
{
	string matrixName{};
	string subtructionExpression{}; 
	vector<string>subtructingMatricies{};  

	cout << "Enter the subtruction expression as (A-B-C)\n";
	cin.ignore();
	getline(cin, subtructionExpression);

	for (size_t i = 0; i < subtructionExpression.length(); i++)
	{
		if (subtructionExpression[i] == '-')
		{
			if (matrixName.empty() == 0)
			{
				subtructingMatricies.push_back(matrixName);
				matrixName.clear();
			}
		}
		else
		{
			matrixName.push_back(subtructionExpression[i]);
		}

	}
	subtructingMatricies.push_back(matrixName);
	matrixName.clear();
	return subtructingMatricies;
}

vector<vector<double>>subtruct_two_matricies(vector<vector<double>>&mat1, vector<vector<double>>&mat2)
{
	vector<double>rowResult{};
	vector<vector<double>> result{};

	/*
	The nested loop is used to subtruct two matricies and the result of subtruction of every 2 elements 
	will be pushed to resultRow vector and after finishing the subtruction of one row, 
	this row will be pushed to result 2D vector then the resultRow will be cleared , 
	while the same will be done with each row
	*/
	for (size_t i = 0; i < mat1.size(); i++)
	{
		for (size_t j = 0; j < mat1[i].size(); j++)
		{
			rowResult.push_back(mat1[i][j] - mat2[i][j]);
		}
		result.push_back(rowResult);
		rowResult.clear();
	}
	return result;
}

void print_matrix_subtruction()
{
	string checkResult{};
	vector<string>subtructingMatricies{};
	vector<size_t>indeces{};
	vector<vector<double>>result{};

	subtructingMatricies = enter_subtructing_matricies();
	checkResult = check_name(subtructingMatricies);

	if (checkResult == "All found")
	{
		indeces = push_index(subtructingMatricies);

		for (size_t i = 1; i < indeces.size(); i++)
		{
			/*
			The main condition of subtruction is that the subtructing matricies must be of same order
			(same number of rows & columns)
			let's assume there are 3 subtructing matricies so i want to check they have the same order
			so i check if the number of of rows of the first subtructing matrix is equal to the number of rows
			of the second subtructing matrix then i check if the number of columns of the first subtructing matrix
			is equal to the number of columns of the second subtructing matrix then i check if it is the final loop or not
			in our example, it is not the final loop so i check if the number of of rows of the first subtructing matrix is
			equal to the number of rows of the third subtructing matrix then i check if the number of columns of the
			first subtructing matrix is equal to the number of columns of the third subtructing matrix
			then i check if its the final loop, in our example , it is the final loop so i will subtruct these matricies
			so there is one question, why the initial value of i is 1?
			because if the initial value is zero then the first loop has no meaning
			because by this i will check if the number of rows of first matrix is equal to the number of rows of the first
			matrix where the the answer will be surely true because it is the same matrix i check on
			*/
			if (mainData.rows[indeces[0]] == mainData.rows[indeces[i]])
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
						indeces.erase(indeces.begin() + 0);

						for (size_t j = 0; j < indeces.size(); j++)
						{
							result = subtruct_two_matricies(result, mainData.matricies[indeces[j]]);
						}

						//Store The final result,rows,columns in MatAns that allocates the 1st index in global struct vectors
						mainData.matricies[0] = result;
						mainData.rows[0] = result.size();
						mainData.columns[0] = result[0].size();

						print_matrix(mainData.matricies[0]);  //to print matrix answer that holds the result of subtruction
						break;
					}
				}
				else
				{
					cout << "The subtructing matricies must be of same order\n\n";
					break;
				}
			}
			else
			{
				cout << "The subtructing matricies must be of same order\n\n";
				break;
			}
		}
	}
}