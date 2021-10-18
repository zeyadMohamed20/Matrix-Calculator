#pragma once
#include<vector>
using namespace std;

/*
This function is used to print matrix elements to be as orginal matrix (elements under each other)
so it takes only one parameter which is the matrix that will be printed where this parameter is passed
by reference to keep the memory storage then the function will print this matrix so it returns void
*/
void print_matrix(vector<vector<double>>&matrix);

/*
This function is used to execute the operation number one where the user enters the name of matrix to show
then by depending on print_matri0x function, this matrix will be peinted so this function don't take any arguments 
and returns void
*/
void show_matrix();

