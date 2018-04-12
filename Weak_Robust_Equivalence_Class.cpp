
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Weak_Robust_Equivalence_Class.h"

//
//Weak_Robust_Equivalence_Class
//
Weak_Robust_Equivalence_Class::Weak_Robust_Equivalence_Class()
{

}

//
//~Weak_Robust_Equivalence_Class
//
Weak_Robust_Equivalence_Class::~Weak_Robust_Equivalence_Class()
{

}

//
//generate()
//
void Weak_Robust_Equivalence_Class::generate()
{
	//Variables to help with generating the test cases
	int n, row, col, d_j, largest_partition_count = 0, inv_index_count, row_number, inv_flag, k;
	//Taking in the number of input variables
	std::cin >> n;
	//Array to store input ranges
	std::string *input_ranges = new std::string[n];
	//Array to store invalid values
	int *invalid_array = new int[2 * n];
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
	//Parsing the input range partitions and storing the results in valid result array and invalid array
	parse(valid_result_array, input_ranges, n, largest_partition_count, 4, invalid_array);
	//Displaying the valid test case values
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
				//Making sure that the values are valid
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
	d_j = 0;
	inv_index_count = 0;
	row_number = 0;
	//Displaying first set of invalid test case values
	for (int inv = 0; inv < (2 * n); inv++)
	{
		std::cout << invalid_array[inv] << " ";
		inv_index_count++;
		for (int i = 1; i < row; i++)
		{
			if (valid_result_array[i][d_j] == 0)
			{
				//Making sure that the values are valid
				k = d_j;
				while (valid_result_array[i][k] == 0)
				{
					k--;
				}
				std::cout << valid_result_array[i][k] << " ";
				continue;
			}
			std::cout << valid_result_array[i][d_j] << " ";
		}
		std::cout << std::endl;
		d_j++;
		if (inv_index_count == 2)
		{
			break;
		}
	}
	inv_flag = 0;
	//Displaying the rest of the invalid test case values
	for (int inv = 2; inv < (2 * n); inv++)
	{
		//Row number counter in the invalid array
		row_number++;
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < row; i++)
			{
				//If invalid values have been printed then ignore the valid values in this row
				if (inv_flag == 1)
				{
					inv_flag = 0;
					continue;
				}
				if (valid_result_array[i][j] == 0)
				{
					//Making sure that the values are valid
					k = j;
					while (valid_result_array[i][k] == 0)
					{
						k--;
					}
					std::cout << valid_result_array[i][k] << " ";
					//If the row number of the invalid values and the valid values is the same then print invalid values
					if (i == (row_number - 1))
					{
						std::cout << invalid_array[inv] << " ";
						inv_flag = 1;
						inv++;
					}
					continue;
				}
				std::cout << valid_result_array[i][j] << " ";
				//If the row number of the invalid values and the valid values is the same then print invalid values
				if (i == (row_number - 1))
				{
					std::cout << invalid_array[inv] << " ";
					inv_flag = 1;
					inv++;
				}
			}
			std::cout << std::endl;
		}
		inv--;
	}
	//Deleting the objects created
	for (int i = 0; i < row; i++) {
		delete[] valid_result_array[i];
	}
	delete[] valid_result_array;

	delete[] input_ranges;

	delete[] invalid_array;
}