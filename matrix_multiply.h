#pragma once
#include "data_types.h"
#include<vector>
using namespace std;

/*
This function is used to enter multiplication so it takes no arguments but returns struct that contains 2 members:
constant (double variable that stores result of multiplication of all constants) and multiplyingMatricies 
(vector of string that contains all names of multiplying matricies)
*/
multiply enter_multiplication();

/*
This function is used to multiply two matricies si it take 2 arguments of type 2D vector of double
and returns the result of multiplication
*/
vector<vector<double>>multiply_two_matricies(vector<vector<double>>&mat1, vector<vector<double>>&mat2);

/*
This function is used to multiply any constant by matrix elements where this type of multiplication is called
scalar multiplication so that it takes 2 arguments which are constant and the matrix then returns the result
of scalar multiplication 
*/
vector<vector<double>>scalar_multiplication(double constant, vector<vector<double>>&matrix);

/*
This function is used to print the final result of multiplication of matricies by using the previous functions
so that it takes no arguments and returns void
*/
void print_matrix_multiplication();

/*
This function is used to return identity square matrix of order = matrixOrder so ot takes one argiment which
is matrixOrder but returns 2D vector (identity matrix)
*/
vector<vector<double>>identity_matrix(size_t matrixOrder);

/*
This function is used to print the final result of power square matrix so that it takes no arguments and returns void
*/
void print_matrix_power();