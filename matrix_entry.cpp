/*
*************************************************************************************************
@file     matrix_entry.cpp
@author   Zeyad Mohamed Abd ElHamid
@brief    This file controls the definitions of all matrix components
**************************************************************************************************
*/

#include "data_types.h"
#include"matrix_multiply.h"
#include<conio.h>
#include<iostream>
#include<string>
#include<vector>
#define DEFAULT__MATANS__ROWS 3
#define DEFAULT__MATANS__COLUMNS 3
#define __FIRST__  1
#define __SECOND__ 2
#define __THIRD__  3
#define MAX_CHAR  8
using namespace std;

/*global variable can be accessed because its scope is along the program files
  but its main advantage is lifeime so that the user can enter matrices and do operations as he want
  for example: the user define matrix called A then make transpone on this matrix then define 
  another matrix called B so that matrix A is not deleted from the memory but if the variable is local
  then matrix A will be deleted because its lifetime is along the function 
  (if static local then it will be extended along the file only) 
*/
definitions mainData{};

void identify_matrix_answer()
{
	mainData.matrixName.push_back("MatAns");
	mainData.rows.push_back(DEFAULT__MATANS__ROWS); // assume that the default number of rows is 3
	mainData.columns.push_back(DEFAULT__MATANS__COLUMNS); // assume that the default number of columns is 3
	mainData.matricies.push_back(identity_matrix(3));  //assume that the default matrix answer is identity matrix
}

string define_matrix_name (int counter)
{
	string name{};
	string checkResult{"No simlarity"};


	switch(counter)
	{
	case __FIRST__:
		cout << "Enter the name of " << counter << "st " << "matrix" << "\n";
		cin.ignore();
		getline(cin, name);

		for (size_t i = 1; i < mainData.matrixName.size(); i++)  //index zero in matrixName has MatAns
		{
			if (name == mainData.matrixName[i])
			{
				checkResult = "simlarity";
				cout << "This name is used before\n\n";
				break;
			}
		}
		if (checkResult == "No simlarity")
		{
			mainData.matrixName.push_back(name);
		}
		break;
	case __SECOND__:
		cout << "Enter the name of " << counter << "nd " << "matrix" << "\n";
		cin.ignore();
		getline(cin, name);

		for (size_t i = 1; i < mainData.matrixName.size(); i++)  //index zero in matrixName has MatAns
		{
			if (name == mainData.matrixName[i])
			{
				checkResult = "simlarity";
				cout << "This name is used before\n\n";
				break;
			}
		}
		if (checkResult == "No simlarity")
		{
			mainData.matrixName.push_back(name);
		}
		break;
	case __THIRD__:
		cout << "Enter the name of " << counter << "rd " << "matrix" << "\n";
		cin.ignore();
		getline(cin, name);

		for (size_t i = 1; i < mainData.matrixName.size(); i++)  //index zero in matrixName has MatAns
		{
			if (name == mainData.matrixName[i])
			{
				checkResult = "simlarity";
				cout << "This name is used before\n\n";
				break;
			}
		}
		if (checkResult == "No simlarity")
		{
			mainData.matrixName.push_back(name);
		}
		break;
	default:
		cout << "Enter the name of " << counter << "th " << "matrix" << "\n";
		cin.ignore();
		getline(cin, name);

		for (size_t i = 1; i < mainData.matrixName.size(); i++)  //index zero in matrixName has MatAns
		{
			if (name == mainData.matrixName[i])
			{
				checkResult = "simlarity";
				cout << "This name is used before\n\n";
				break;
			}
		}
		if (checkResult == "No simlarity")
		{
			mainData.matrixName.push_back(name);
		}
	}
	return checkResult;
}

vector<int>define_matrix_order()
{
	string checkResult{"No zero"};
	string order{};
	size_t z{0};  // stores the index of character that refers to the number of rows in variable order (string)
	int row{0};
	int column{0};
	vector<int> matrixOrder{};

	cout << "Enter the order of matrix (m*n) up to 9*9 ?" << "\n";
	getline(cin,order);
	/*
     This block is used find the first character in the string which refers to a number (its ascii between 48 & 58)
	 when we find this character, it will be converted to integer then pushed inside matrixOrder vector
	(it will be returned) and pushed inside the rows vector (holds the rows of all matricies)
	 then storing the nmber of counter in z to be the initial value of the next loop to find number of columns
	*/
	for (size_t i = 0; i < order.length(); i++)
	{
		if (order[i] == 48)
		{
			checkResult = "zero";
			cout << "There is no zero order\n";
		}
	}
	if (checkResult == "No zero")
	{
		for (size_t i = 0; i < order.length(); i++)
		{
			if ((order[i] > 48) && (order[i] < 58))
			{
				matrixOrder.push_back(order[i] - '0');
				mainData.rows.push_back((size_t)order[i] - '0');
				z = i;
				break;
			}
		}
		for (size_t j = z + 1; j < order.length(); j++)
		{
			if ((order[j] > 48) && (order[j] < 58))
			{
				matrixOrder.push_back(order[j] - '0');
				mainData.columns.push_back((size_t)order[j] - '0');
				break;
			}
		}
	}
	
	return matrixOrder;
}

void print_space(string element)
{
	size_t spaceNumber{0};

	/*
	The following equation is the main equation in the function that calculates the number of spaces 
	 that will be printed depending on the number of characters in each element and i assume that if the
	 user enetrs element has only one character then i prints 7 space.
	 1 char ---> 7 space
	 2 char ---> 6 space
	 3 char ---> 5 space
	 4 char ---> 4 space
	 5 char ---> 3 space
	 6 char ---> 2 space
	 7 char ---> 1 space
	 if there are more than 7 characters then i print only 1 space
	*/
	spaceNumber = MAX_CHAR - element.length(); 
	if (spaceNumber > 0)
	{
		for (int i = 0; i < spaceNumber; i++)
		{
			cout << ' ';
		}
	}
	else
	{
		cout << ' ';
	}
}

vector<vector<double>>define_matrix_elements(vector<int>&matrixOrder)
{
	string element{};
	int x{0};  // stores the ascii code of each charcter in the element
	char c{};  // stores each character after converting it from integer (ascii code)
	const char null{0};
	int row{0};
	int column{0};
	vector<vector<double>>matrix{};
	vector<double> rowElements{};

	row = matrixOrder[0];  // the first index of matrix order contains rows number that will be stored in row
	column = matrixOrder[1];  // the second index of matrix order contains columns number that will be stored in column

	cout << "Enter matrix elements\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			while (true)  //to wait the user until he finished entering the element 
			{
				/*
				The next block (if statement) is used in case last element which lies in last row and last column
				After the user entered this element, he presses enter key to store this matrix (cin) 
				*/
				if ((i == row - 1) && (j == column - 1))
				{
					cin >> element;
					break;
				}
				else //The next block is used in case the elemet is not the last element 
				{
			    /*
				 _getch function----> is a function present in conio.h header file where its protype is int getch()
				 so we notice it takes no parameters but returns the ascii code of the entered character
				 imprtance of getch function:- a) pauses the output console until a key is pressed
											   b) The entered character is immediately returned without waiting for
												  the enter key
											   c) The entered character doesn't show up on the console
				 I use getch function because i need the user to enter a character and this character stored without
				 pressing enter key but if i use cin then when the user enters the element and presses enter key
				 the cursor will become in the next line while i want the user to enter element then the element
				 is stored then by pressing right arrow key , it leaves some space to enter the second element
				 in the same line (row)
				 How to use getch function with arrow keys:
				 Arrow keys are special keys because using getch with arrow keys returns 2 ascii code
				 The four arrow keys hve the same first ascii code which is 224 
				 but they differ in the second ascii code:
				                                           up----->72
				                                           left--->75
														   right-->77
														   down--->80
			     so i check if the user presses arrow keys or not, if the user presses arrow keys then it means that
				 the user finised entering the element so i will store this element and leave some space to enter 
				 the second element.
				*/
					x = _getch();
					c = x;  // stores the ascii of this element in character variable

					if (c == '\b')   //To check on backspace character
					{
						cout << "\b" <<null << "\b";  //erase the last character on screan
						if (element.empty() == 0)
						{
							element.erase(element.end() - 1);  //erase the last charcter in element (string)
						}
						continue;
					}
					else if (x > 42 && x < 58 && x != 47 && x != 44)  // in case not pressing arrow keys(still entering the element)
					{
						cout << c;  // to show the user what he enters 
						element.push_back(c);
					}
					else if (x == 224)  // in case prssing arrow keys (finished entering the element)
					{
						if (element.empty() == 0)
						{
							while (true)  // to wait the user until he entered right arrow key
							{
								/*
								 The second getch is used to return the 2nd ascii of arrow key to identify which arrow key
								 has been pressed, if the user enters right key, i will chech the length of element
								 to leave a certain number of space depending on length so that the elements of
								 matrix will be under each other and this can be done by print_space function
								 then break from while(true).
								 but if the user enterd up or down or left (instead of right) then i will hear the user the
								 alarm (bell ring) and wait again for the user to enter the right key
								*/
								x = _getch();
								if (x == 77)
								{
									print_space(element);
									break;
								}
								else
								{
									cout << "\a";
								}
							}
						}
						break;
					}
				}
			}
			if (element.empty() == 0)
			{
				rowElements.push_back(stod(element));
				element.clear();
			}
			else
			{
				cout << "\a";
				j = j - 1;
				continue;
			}
		}
		matrix.push_back(rowElements);
		rowElements.clear();
		cout << "\n";
	}
	return matrix;
}

void define_matrix_components()
{  
	int counter{1};  // used to print 1st , 2nd,... that depends on the number of matrices the user will enter
	string checkResult{};
	int matrixNumber{}; 
	vector<int>matrixOrder{};
	vector<vector<double>>matrix{};

	if (mainData.matricies.empty() == 1)  //This condition to avoid pushing matrix answer at everytime we call define_matrix_components
	{
		identify_matrix_answer();  // so that first index in definitions struct vectors will be allocated
	}

	cout << "Enter the number of matrices\n";
	cin >> matrixNumber;
	for (int i = 0; i < matrixNumber; i++)
	{
		checkResult = define_matrix_name(counter);
		if (checkResult == "No simlarity")
		{
			matrixOrder = define_matrix_order();
			if (matrixOrder.empty() == 1)  //define_matrix_order will return empty matrix order in case finding zero order
			{
				mainData.matrixName.erase(mainData.matrixName.end() - 1); // erase last element in matrixName as its order is invalid
				break;
			}
			else
			{
				matrix = define_matrix_elements(matrixOrder);
				mainData.matricies.push_back(matrix);
				counter++;
			}
		}
		else
		{
			break;
		}
	}
}
#undef DEFAULT__MATANS__ROWS 
#undef DEFAULT__MATANS__COLUMNS 
#undef __FIRST__  
#undef __SECOND__ 
#undef __THIRD__  
#undef MAX_CHAR  