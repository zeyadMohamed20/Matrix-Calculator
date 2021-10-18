/*
**********************************************************************************************************
@file      main.cpp
@author    Zeyad Mohamed Abd ElHamid
@brief     This file contains the main process that control the flow of the program
*********************************************************************************************************
*/

#include "data_types.h"
#include"matrix_add.h"
#include"matrix_determinent.h"
#include"matrix_divide.h"
#include"matrix_entry.h"
#include"matrix_inverse.h"
#include"matrix_multiply.h"
#include"matrix_show.h"
#include"matrix_subtruct.h"
#include"matrix_turn.h"
#include <iostream>
#define OPERATION__SIZE
using namespace std;

/*
We notice that all variables in all files use initialization of type direct brace initialization as int x {3}
and don't use copy initialization as int x = 3
beacause copy initialization has 2 side effects:- 1) it copis the value at right hand side and stores it in the left
                                                     hand side
												  2) it is not safe with narowing converstion
Hint: narrowing convertion is the convertion from large data type to small data type e.g double to int
But, Direct brace initialization is more safe and preferred:- 1) it doesn't copy the value at right hand side 
                                                                 but direct stores it in the left hand side
															  2) it avoids narrowing convertion
example: int x = 3.14 -----> output: 3
         int x {3.14} -----> output:error: from double to int requries narrowing convertion
                                                                 
*/
int main()
{ 
	unsigned short int process{};     //number of process that user enters between 1 to 4
	unsigned short int operation{};   //number of operation that user enters between 1 to 9
	void (*oper[OPERATION__SIZE])() //array pointer to function of no parameters and return void to be used instead of switch case in operation block
	{
		show_matrix, print_matrix_transpose, print_matrix_addition, print_matrix_subtruction, print_matrix_multiplication, 
		print_matrix_power, print_matrix_division, print_inverse_matrix, print_determinent
	};  

	cout << "Instructions:-\n";
	cout << "1) When entering matrix elements ,use right key to move from one element to the next element\n";
	cout << "   and after finishing your matrix, press enter key to store your matrix in the system\n";
	cout << "2) If you want to access matrix answer at any time then MatAns indicates to this matrix\n\n";
	/* The following menu appears in matrix calculator so that the user must enter the 
	   number of process to be applied where:
	   Start:               is used to start matrix calculator
	   Matrix definition:   is used to define the matrix (name,order)
	   Operation:           is used to show operation list to select the number of operation
	                        you want to apply on matrix
       Exit:                is used to close the matrix calculator
bash: 1: command not found
	*/
	cout << "Menu:-\n";
	cout << "1-Start" << "\t\t" << "2-Matrix definition" << "\n" << "3-Operation" << "\t" << "4-Exit\n\n";
	cout << "Enter the number of process you want\n";
 
	/* while(true) is used to wait the user until he enters the right number of process (from 1 to 4)
	   if he enters another number (less than 1 or grater than 4) then I ask him to enter the right number 
	   while this number must be 1 to start the calculator at first, if he enters 2 or 3 or 4 , i will refuse it
	   because the calculator was closed
	*/
	while (true)
	{
		cin >> process;
		if (process == Start)
		{
			cout << "Matrix calculator is ON\n\n";

			/* while true is used to wait the user again to enter the right number of process, 
			   if he enters 1 again then i tell him that calculator is already open, if he enters
			   2 then he will go to define_matrix function, if he enters 3 then he will go to operation functions
			   ,if he enters 4 then it returns 0(means closing the program) but if the user enters another number 
			   , i will wait him untill entering the correct number
			*/
			while (true)
			{
				cout << "Menu:-\n";
				cout << "1-Start" << "\t\t" << "2-Matrix definition" << "\n" << "3-Operation" << "\t" << "4-Exit\n\n";
				cout << "Enter the number of process you want\n";
				cin >> process;
				switch (process)
				{
				case Start:
					cout << "Matrix calculator is already ON\n\n";
					break;
				case Matrixdefinition:
					define_matrix_components();
					break;
				case Operation:
					cout << "Operations:\n";
					cout << "1-Show matrix\t\t" << "2-Transpose\n";
					cout << "3-Addition\t\t" << "4-Subtraction\n";
					cout << "5-Multiplication\t" << "6-Power\n";
					cout << "7-Division\t\t" << "8-inverse\n";
					cout << "9-Determinent\n\n";
					cout << "Enter the number of operation you want\n";
					cin >> operation; 
					oper[operation - 1]();  //index of array begins from zero
					break;
				case Exit:
					return 0;
					break;
				}	 
			}
		}
		else if ((process == Matrixdefinition) || (process == Operation) || (process == Exit))
		{
			cout << "Please start the calculator at first\n";
		}
		else
		{
			cout << "Please enter one of the above processes\n";
		}
	}
}
#undef OPERATION__SIZE
