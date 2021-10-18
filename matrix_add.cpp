/*
*************************************************************************************************
@file     matrix_add.cpp
@author   Zeyad Mohamed Abd ElHamid
@brief    This file controls the addition of matricies (operation number 3)  
**************************************************************************************************
*/

#include "data_types.h"
#include"matrix_show.h"
#include<iostream>
#include<string>
#include<vector>

vector<string>enter_adding_matricies()
{
	string additionExpession{};
	string matrixName{};
	vector<string>addingMatricies{};

	cout << "Enter the addition expression (A+B+C)\n";
	cin.ignore();
	getline(cin, additionExpession);

	for (size_t i = 0; i < additionExpession.length(); i++)
	{
		if (additionExpession[i] == '+')
		{
			if (matrixName.empty() == 0)
			{
				addingMatricies.push_back(matrixName);
				matrixName.clear();
			}
		}
		else
		{
			matrixName.push_back(additionExpession[i]);
		}
	}
	if (matrixName.empty() == 0)
	{
		addingMatricies.push_back(matrixName);
		matrixName.clear();
	}
	return addingMatricies;
}

string check_name(vector<string>&operatingMatricies)
{
	string checkResult{"All found"};
	for (size_t i = 0; i < operatingMatricies.size(); i++)
	{
		for (size_t j = 0; j < mainData.matrixName.size(); j++)
		{
			if (operatingMatricies[i] == mainData.matrixName[j])
			{
				break;
			}
			else
			{
				if (j == mainData.matrixName.size() - 1)
				{
					checkResult = "Not found";
					cout << "There is no matrix of name " << operatingMatricies[i] << "\n";
				}
			}
		}
	}
	return checkResult;
}

vector<size_t>push_index(vector<string>&operatingMatricies)
{
	vector<size_t>indeces{};

	/*
	At first we must know that struct global variable M has eqivalent members
	for example: if wae assume there is matrix called A where the name of this matrix exists in matrixName vector
	at index 3 so the numbers of rows of this matrix exists in rows vector at index 3 too, and the same with columns
	vector and matricies 3D vector so that all members are equivalent.
	The next nested for loop is used for searching  where i send to this function vector of string that holds the names
	of matricies that will be added or subtrucred or .... then i search for each name in this vector (parameter)
	inside matrixName(that holds all matrix names that must include the names of matrices the user want to add 
	or subtruct or ....) if the name i search for has been found then i push the index of this name  
	inside vector of int called indeces
	(the index of this name inside matrixName vector is same as its index inside matricies 3D vector)
	then i return the indeces vector that holds the index of each matrix (the user want to add or subtruct or ..) 
	inside matricies 3D vector.
	*/
	for (size_t i = 0; i < operatingMatricies.size(); i++)
	{
		for (size_t j = 0; j < mainData.matrixName.size(); j++)
		{
			if (operatingMatricies[i] == mainData.matrixName[j])
			{
				indeces.push_back(j);
				break;
			}
		}
	}
	return indeces;
}

vector<vector<double>>add_two_matricies(vector<vector<double>>&mat1, vector<vector<double>>&mat2)
{
	vector<double>rowResult{};
	vector<vector<double>> result{};
	 /*
	 The nested loop is used to add two matricies and the result of addition of every 2 elements will be pushed to 
	 resultRow vector and after finishing the addition of one row, this row will be pushed to result 2D vector 
	 then the resultRow will be cleared , then the same will be done with each row 
	 */
	for (size_t i = 0; i < mat1.size(); i++)
	{
		for (size_t j = 0; j < mat1[i].size(); j++)
		{
			rowResult.push_back(mat1[i][j] + mat2[i][j]);
		}
		result.push_back(rowResult);
		rowResult.clear();
	}
	return result;
}

void print_matrix_addition()
{  
	string checkResult{};
	vector<string>addingMatricies{};
	vector<size_t>indeces{};
	vector<vector<double>>result{}; 

	addingMatricies = enter_adding_matricies();
	checkResult = check_name(addingMatricies);

	if (checkResult == "All found")
	{
		indeces = push_index(addingMatricies);

		for (size_t i = 1; i < indeces.size(); i++)
		{
			/*
			The main condition of addition is that the adding matricies must be of same order(same number of rows & columns)
			let's assume there are 3 adding matricies so i want to check they have the same order
			so i check if the number of of rows of the first adding matrix is equal to the number of rows of the second
			adding matrix then i check if the number of columns of the first adding matrix is equal to
			the number of columns of the second adding matrix then i check if it is the final loop or not
			in our example, it is not the final loop so i check if the number of of rows of the first adding matrix is
			equal to the number of rows of the third adding matrix then i check if the number of columns of the
			first adding matrix is equal to the number of columns of the third adding matrix then i check if its the final
			loop, in our example , it is the final loop so i will add these matricies
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
							result = add_two_matricies(result, mainData.matricies[indeces[j]]);
						}

						//Store The final result,rows,columns in MatAns that allocates the 1st index in global struct vectors
						mainData.matricies[0] = result;
						mainData.rows[0] = result.size();
						mainData.columns[0] = result[0].size();
						print_matrix(mainData.matricies[0]);  //to print matrix answer that holds the result of addition
						break;
					}
				}
				else
				{
					cout << "The adding matricies must be of same order\n\n";
					break;
				}
			}
			else
			{
				cout << "The adding matricies must be of same order\n\n";
				break;
			}
		}
	}
}