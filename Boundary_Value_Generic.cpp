
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Boundary_Value_Generic.h"

//
// Boundary_Value_Generic
//
Boundary_Value_Generic::Boundary_Value_Generic()
{

}

//
// ~Boundary_Value_Generic
//
Boundary_Value_Generic::~Boundary_Value_Generic()
{

}

//
//parse(int** &case_variables, std::string *input_ranges, int n, int size)
//
void Boundary_Value_Generic::parse(int** &case_variables, std::string *input_ranges, int n, int size)
{
	//Variables to help with parsing entered range
	int lower, upper;
	int min, min_plus, nom, max_minus, max, min_minus, max_plus;
	int c_i = 0;
	//Extracting the string and parsing the integer values entered
	for (int i = 0; i < n; i++)
	{
		std::istringstream ss(input_ranges[i]);
		std::string token;
		while (std::getline(ss, token, ',')) {
			//Checking for '('
			if (token[0] == '(')
			{
				token = token.substr(1);
				lower = atoi(token.c_str());
				lower++;
			}
			//Checking for '['
			else if (token[0] == '[')
			{
				token = token.substr(1);
				lower = atoi(token.c_str());
			}
			//Checking for ')'
			else if (token[token.size() - 1] == ')')
			{
				upper = atoi(token.c_str());
				upper--;
			}
			//Checking for ']'
			else if (token[token.size() - 1] == ']')
			{
				upper = atoi(token.c_str());
			}
		}
		//Calculating case variable values
		min_minus = lower - 1;
		min = lower;
		min_plus = lower + 1;
		max_minus = upper - 1;
		max = upper;
		max_plus = upper + 1;
		nom = ((max - min) / 2) + min;
		//Storing the calculated values in an array according to the type of algorithm chosen
		if (size == 5)
		{
			int value[5] = { min, min_plus, nom, max_minus, max };
			for (int j = 0; j < size; j++)
			{
				case_variables[c_i][j] = value[j];
			}
			c_i++;
		}
		//Storing the calculated values in an array according to the type of algorithm chosen
		else if (size == 7)
		{
			int value[7] = { min_minus, min, min_plus, nom, max_minus, max, max_plus };
			for (int j = 0; j < size; j++)
			{
				case_variables[c_i][j] = value[j];
			}
			c_i++;
		}
	}
}