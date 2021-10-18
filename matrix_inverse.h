#pragma once
#include<vector>
using namespace std;

/*
This function is used to find the cofactor of any matrix so it takes only one parameter which the matrix
and return the cofavtor of this matrix
*/
vector<vector<double>>calculate_cofactor(vector<vector<double>>&mat);

/*
This function is used to find the inverse of matrix so it takes only one parameter which is the matrix
and returns the inverse of this matrix
*/
vector<vector<double>>calculate_inverse(vector<vector<double>>&mat);

/*
This function os used to check conditions of inverse matrix which are:
1) It must be square matrix
2) It must be non singular matrix (determinent != 0)
After checking on conditions, we print the inverse matrix depending on the previos 2 functions so this function 
takes no arguments and returns void
*/
void print_inverse_matrix();