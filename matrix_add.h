#pragma once
#include<string>
#include<vector>
using namespace std;

/*
This function is used to store the names of matrices the user want to add inside the vector of string
so this function takes no arguments but returns vector of string (carrys the names of matrices the user will add)
*/
vector<string>enter_adding_matricies();

/*
This function is used to check the name of matricies that the user entered to find if the matricies names ate present in matrixName vector
or not so this function takes only one parameter which is vector of string(holds the matricies names that will be checked) and returns string
which is the the result of checking
*/
string check_name(vector<string>&operatingMatricies);

/*
This function is used to push the index of the operating matricies (vector of string holds 
the names of matricies will be added or subtruced or multipliled or divided) present inside matricies 3D vector 
so that it takes only one argument which is vector of string (that holds the names of matricies the user want 
to add or subtruct or ...) but returns vector of size_t that holds the index of the matricies 
(that will be added or .....) inside matricies 3D vector
*/
vector<size_t>push_index(vector<string>&operatingMatricies);

/*
This function is used to add two matricies so it takes 2 parameters of type 2D vector of double
where these 2 parameters holds the matricies that will be added and returns 2D vector which is the result of addition
*/
vector<vector<double>>add_two_matricies(vector<vector<double>>&mat1, vector<vector<double>>&mat2);

/*
This function is used to print the result of addition of the matricies the user want to add by using the previous 
functions so it takes no arguments and returns void
*/
void print_matrix_addition();
