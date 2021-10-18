#pragma once
#include<vector>
using namespace std;

/*
This function is used to return vector of string contains the names of matricies the user want to divide so that
it takes no parameters but returns vector of string
*/
vector<string>enter_division();

/*
This function is used to divide two matricies so it takes 2 parameters which are M1 ,M2 (dividing matrivies)
and returns the result (2D vector)
*/
vector<vector<double>>divide_two_matricies(vector<vector<double>>&mat1, vector<vector<double>>&mat2);

/*
This function is used to check on conditions of matrix division and prints the result of division
*/
void print_matrix_division();
