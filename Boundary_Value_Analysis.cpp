
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Boundary_Value_Analysis.h"

//
// Boundary_Value_Analysis
//
Boundary_Value_Analysis::Boundary_Value_Analysis()
{

}

//
// ~Boundary_Value_Analysis
//
Boundary_Value_Analysis::~Boundary_Value_Analysis()
{

}

//
// generate()
//
void Boundary_Value_Analysis::generate()
{
	//Variables to help in generating the test cases
	int n, row, col, c_i, c_j, a_i;
	//Taking in the number of input variables
	std::cin >> n;
	std::string *input_ranges = new std::string[n];
	//Storing the input range
	for (int i = 0; i < n; ++i)
	{
		std::cin >> input_ranges[i];
	}
	//Array to store the BVA case variables (min, min+, nom, max-, max)
	int **case_variables = new int*[n];
	for (int i = 0; i < n; ++i) {
		case_variables[i] = new int[5];
	}
	//Parsing the entered input ranges
	parse(case_variables, input_ranges, n, 5);
	//Variables to create the result array according to the number of input variables entered	
	row = (4 * n) + 1;
	col = n;
	//Result array to store the final test case values
	int **result_array = new int*[row];
	for (int i = 0; i < row; ++i) {
		result_array[i] = new int[col];
	}
	c_i = 0;
	//Storing nom values in the result array
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < ((4 * n) + 1); i++)
		{
			result_array[i][j] = case_variables[c_i][2];
		}
		c_i++;
	}
	c_i = 0;
	c_j = 0;
	a_i = 0;
	//Storing all other case variable values in the result array
	for (int j = 0; j < n; j++)
	{
		while (a_i < ((4 * n) + 1))
		{
			if (c_j >= 5)
			{
				c_j = 0;
				break;
			}
			if (c_j == 2)
			{
				c_j++;
			}
			result_array[a_i][j] = case_variables[c_i][c_j];
			c_j++;
			a_i++;
		}
		c_i++;
	}
	//Displaying the result array values
	for (int i = 0; i < ((4 * n) + 1); i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << result_array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	//Deleting objects created
	for (int i = 0; i < row; i++) {
		delete[] result_array[i];
	}
	delete[] result_array;
	delete[] input_ranges;
	for (int i = 0; i < n; i++) {
		delete[] case_variables[i];
	}
	delete[] case_variables;
}