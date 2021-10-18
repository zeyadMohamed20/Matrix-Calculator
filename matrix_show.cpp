/*
*************************************************************************************************
@file     matrix_show.cpp
@author   Zeyad Mohamed Abd ElHamid
@brief    This file controls the matrix show (operation number 1)
**************************************************************************************************
*/


#include "data_types.h"
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
using namespace std;

void print_matrix(vector<vector<double>>&matrix)
{
	cout << "\n";
	cout << "The result is" << ":" << "\n";
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			/*
			The three functions setw, fixed, setprecision are present in iomanip header file at which:
			setw: it is used to set the width of the field, for example:cout<<setw(7)<<"Hello";
			      The output will be:  Hello.....we notice that before Hello there are 2 spaces because Hello
			      contains 5 characters and i set the width of field = 7 so 7-5 = 2 so there are 2 characters empty
				  they will be default as space
			fixed + setprecision: are used to determine the number of digits after decimal point (after approximation) 
			for example:cout<<fixed<<setprecision(4)<<1.25;----->output:1.2500
			for example:cout<<fixed<<setprecision(4)<<1;----->output:1.0000

			But why i use setw+fixed+setprecision??
			to print  matrix elements under each other where fixed+setprecision(3)--->always consume 4 characrers
			which are decimal ponit and 3 digits after decimal point and i make setw(9) so the width of field is 9
			then every element will surely consume at least 4 characrers so the remaining is 9-4=5
			then i assume it will be at most 5 characters before decimal point
			But if there are more than 5 characters before decimal point, the 2 elements will be beside each other
			(no spaces between them)
			To avoid this problem, i always print 2 spaces that their target comes when the width of field ends

			But, there is another problem with number as -0.0001
			fixed + setprecision(3), it will be -0.000 where  zero neither positive nor negative
			to avoid this problem:
			we must notice a thing in ceil, floor function
			ceil---> return the highest integer value, so ceil(3.2)--->4 but ceil(-3.2)--->-3(highest integer value)
			floor--> return the lowest integer value, so floor(3.2)--->3 but floor(-3.2)--->-4(lowest integer value)
			to solve negative zero problem by (ceil(num*1000))
			for examle: with number as -0.0001
			step(1)-->-0.0001*1000=-0.1
			step(2)-->ceil(-0.1)=-0
			step(3)-->abs(-0)=0
			so i check if the ceil(number*1000)==-0 then i abs this number then print it
			*/
			if (ceil(matrix[i][j]*1000)==-0)
			{
				matrix[i][j] = abs(matrix[i][j]);
			}
			cout << setw(9) << fixed << setprecision(3)<<matrix[i][j] << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void show_matrix()
{
	    string name{};

    	cout << "Enter the name of matrix you want to show\n";
		cin.ignore();
		getline(cin,name);

		for (size_t i = 0; i < mainData.matrixName.size(); i++)
		{
			if (name == mainData.matrixName[i])  //search about the entered name in matrixName vector
			{
				print_matrix(mainData.matricies[i]);
				break;
			}
			else if (i == mainData.matrixName.size() - 1)  //if i reach to the final loop and don't find this name 
			{
				cout << "There is no matrix of this name\n\n";
			}
		}
}