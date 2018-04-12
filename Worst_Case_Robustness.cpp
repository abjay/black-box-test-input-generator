
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Worst_Case_Robustness.h"

//
//Worst_Case_Robustness
//
Worst_Case_Robustness::Worst_Case_Robustness()
{

}

//
//~Worst_Case_Robustness
//
Worst_Case_Robustness::~Worst_Case_Robustness()
{

}

//
//generate()
//
void Worst_Case_Robustness::generate()
{
	//Variables to help with generating the test cases
	int n, row, col, k, count, oi, oj, c_i, newcount;
	//Taking in the number of input variables
	std::cin >> n;
	//Array to store input ranges
	std::string *input_ranges = new std::string[n];
	//Storing the input ranges
	for (int i = 0; i < n; ++i)
	{
		std::cin >> input_ranges[i];
	}
	//Array to store the Worst-Case Robustness BVA case variables (min-, min, min+, nom, max-, max, max+)
	int **case_variables = new int*[n];
	for (int i = 0; i < n; ++i) {
		case_variables[i] = new int[7];
	}
	//Parsing the entered input ranges
	parse(case_variables, input_ranges, n, 7);
	//Variables to create the result array according to the number of input variables entered
	row = (int) pow(7, n);
	col = n;
	//Result array to store the final test case values
	int **result_array = new int*[row];
	for (int i = 0; i < row; ++i) {
		result_array[i] = new int[col];
	}
	k = 0;
	count = 1;
	oi = 0;
	oj = 0;
	c_i = 0;
	//Storing the case variables in the result array
	while (oj < n)
	{
		//Storing case variables in the first column of the result array
		while (oj == 0)
		{
			result_array[oi][oj] = case_variables[c_i][k];
			oi++;
			if (oi >= (pow(7, n)))
			{
				break;
			}
			k++;
			//Resetting the index for the case variables array
			if (k >= 7)
			{
				k = 0;
			}
		}
		oj++;
		c_i++;
		count = count * 7;
		newcount = 1;
		k = 0;
		//Storing case variables in the rest of the columns of the result array
		while (oj < n)
		{
			for (oi = 0; oi < (pow(7, n)); oi++)
			{
				newcount = 1;
				while (count > 0)
				{
					result_array[oi][oj] = case_variables[c_i][k];
					oi++;
					if (oi >= (pow(7, n)))
					{
						oj++;
						c_i++;
						//Setting repeating factor for the subsequent columns of the result array
						newcount = (newcount * 7) + 1;
						break;
					}
					count--;
					newcount++;
				}
				k++;
				//Resetting the index for the case variables array
				if (k >= 7)
				{
					k = 0;
				}
				newcount--;
				count = newcount;
				oi--;
				if (oi >= (pow(7, n)))
				{
					break;
				}
			}
		}
	}
	//Displaying the result array
	for (int i = 0; i < (pow(7, n)); i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << result_array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	//Deleting the objects created
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