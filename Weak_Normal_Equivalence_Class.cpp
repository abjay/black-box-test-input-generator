
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Weak_Normal_Equivalence_Class.h"

//
//Weak_Normal_Equivalence_Class
//
Weak_Normal_Equivalence_Class::Weak_Normal_Equivalence_Class()
{

}

//
//~Weak_Normal_Equivalence_Class
//
Weak_Normal_Equivalence_Class::~Weak_Normal_Equivalence_Class()
{

}

//
//generate()
//
void Weak_Normal_Equivalence_Class::generate()
{
	//Variables to help with generating the test cases
	int* NO_VALUE = 0;
	int n, row, col, number_count = 0, largest_partition_count = 0, k;
	//Taking in the number of input variables
	std::cin >> n;
	//Array to store the input ranges
	std::string *input_ranges = new std::string[n];
	//Storing the input range partitions
	for (int i = 0; i < n; ++i)
	{
		std::cin >> input_ranges[i];
	}
	//Getting the count of the largest number of partitions
	largest_partition_count = largest_partition(input_ranges, n);
	row = n;
	col = (largest_partition_count / 2);
	//Array to store the valid results
	int **valid_result_array = new int*[row];
	for (int i = 0; i < row; ++i) {
		valid_result_array[i] = new int[col];
	}
	//Parsing the input range partitions and storing the results in valid result array
	parse(valid_result_array, input_ranges, n, largest_partition_count, 3, NO_VALUE);
	//Displaying the test case values
	for (int p_j = 0; p_j < (largest_partition_count / 2); p_j++)
	{
		for (int p_i = 0; p_i < n; p_i++)
		{
			if (valid_result_array[p_i][p_j] != 0)
			{
				std::cout << valid_result_array[p_i][p_j] << " ";
			}
			else if (valid_result_array[p_i][p_j] == 0)
			{
				k = p_j;
				while (valid_result_array[p_i][k] == 0)
				{
					k--;
				}
				if (valid_result_array[p_i][k] != 0)
				{
					std::cout << valid_result_array[p_i][k] << " ";
				}
			}
		}
		std::cout << std::endl;
	}
	//Deleting the objects created
	for (int i = 0; i < row; i++) {
		delete[] valid_result_array[i];
	}
	delete[] valid_result_array;

	delete[] input_ranges;
}