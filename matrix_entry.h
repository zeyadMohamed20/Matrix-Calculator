#pragma once
#include<string>
using namespace std;

/*
This function is used to allocate the first index in 3D vector (matricies) for 
matrix answer where this matrix has default value which is I so that if the 
user prints this matrix, no logical error occurs as it has stored default value
This function is also used to allocate the first index in matrixName, rows, columns vectors
so that this function takes no parameters and returns void
*/
void identify_matrix_answer();

/*
This function is used to allow the user to define matrix name then push the name to matName vector where it takes
only one parameter which is the counter  that responsible for 1st,2nd,3rd,... and returns string that tells us if there are simlarity in names or not 
*/
string define_matrix_name(int counter);

/*
This function is used to allow the user to enter the order of matrix then convert the character 
that carrys the number of rows to integer to push it to rows vector and the make the same with columns
This function takes no parameters but returns vector of int that hold in the first index the number of rows of this 
matrix while in the second index it holds the number of columns.
*/
vector<int> define_matrix_order();

/*
This function is used to define the matrix elements where it takes a parameter (vector of int) that holds row number &
column number which is called by reference and by depending on this parameter, 
the user can enter the matrix that will be returned to be pushed in matricies 3D vector
*/
vector<vector<double>>define_matrix_elements(vector<int>&matrixOrder);

/*
This function is used to make matrix elements under each other as original matrix by printing a certain
number of spaces depending on the number of characters of each element so that this function has only one 
parameter which is element (string) and returns void
*/
void print_space(string element);

/*
This function is used to define matrix where it takes no parameters and returns void because
the target of the function is storing the values of definitions in the struct global variable
where: 
1) The user will define the name of matrix that will be pushed inside matrixName vector
2) The user will define the order of matrix that will be pushed inside rows vector & columns vector
3) The user will define the matrix elements that will be pushed inside matricies 3D vector 
*/
void define_matrix_components();
