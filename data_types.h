#pragma once
#include<vector>
#include<string>
using namespace std;

struct definitions //has members related to matrix definitions as name,row,column & matrix elements
{
	vector<vector<vector<double>>>matricies{}; //3D vector stores all matricies the user had defined   
	vector<string>matrixName{};                // 1D vector stores the names of matricies
	vector<size_t>rows{};                      // 1D vector stores the number of rows in each matrix
	vector<size_t>columns{};                   // 1D vector stores the number of columns in each matrix
};

extern definitions mainData; // Declaration of global variable M

struct multiply  //has members related to matrix multiplication
{
	vector<string>multiplyingMatricies{};  //1D vector stores all names of matricies the user want to multiply
	double constantResult{1};  //stores the result of multiplying all constants  
};

enum process
{
	Start = 1,
	Matrixdefinition,
	Operation,
	Exit,
};