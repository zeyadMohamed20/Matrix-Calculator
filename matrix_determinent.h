#pragma once
#include<vector>
using namespace std;

/*
This function is used to find the minor of any element in matrix so it takes 3 parameters 
which are: 1) Matrix
           2) Order of element to get minor that is represented in rowNumber and columnNumber
and returns the minor which is 2D vector 
*/
vector<vector<double>>calculate_minor(vector<vector<double>>&mat, size_t rowNumber, size_t columnNumber);

/*
This recursive function is used to find the value of determinent of any matrix so it takes 2 parameters which are:
1) Matrix
2) Order of square matrix that is represented in n variable
and returns double which is the value of determinent
*/
double calculate_determinent(vector<vector<double>>&mat,size_t n);

/*
This function is used to check on the conditions related to the matrix you want to get determinent
and print the determinent value of this matrix so it takes no parameters and returns void
*/
void print_determinent();