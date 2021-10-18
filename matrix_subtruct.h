#pragma once
#include<string>
#include<vector>
using namespace std;

/*
This function is used to store the names matrices the user want to subtruct inside the vector of string
so this function takes no arguments but returns vector of string (carrys the names of matrices the user will subtruct)
*/
vector<string>enter_subtructing_matricies();

/*
This function is used to subtruct two matricies so it takes 2 parameters of type 2D vector of double
where these 2 parameters holds the matricies that will be subtructed and returns 2D vector which is 
the result of subtruction
*/
vector<vector<double>>subtruct_two_matricies(vector<vector<double>>&mat1, vector<vector<double>>&mat2);

/*
This function is used to print the result of subtruction of the matricies the user want to subtruct 
by using the previous functions so it takes no arguments and returns void
*/
void print_matrix_subtruction();