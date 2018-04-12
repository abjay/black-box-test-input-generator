
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Equivalence_Class_Generic.h"

//
// Equivalence_Class_Generic
//
Equivalence_Class_Generic::Equivalence_Class_Generic()
{

}

//
// ~Equivalence_Class_Generic
//
Equivalence_Class_Generic::~Equivalence_Class_Generic()
{

}

//
//largest_partition(std::string *input_ranges, int n)
//
int Equivalence_Class_Generic::largest_partition(std::string *input_ranges, int n)
{
	//Variables to help in calculating the count of the largest number of partitions
	int largest_partition_count = 0;
	int number_count = 0;
	//Calculating the count of the largest number of partitions
	for (int i = 0; i < n; i++)
	{
		std::istringstream ss1(input_ranges[i]);
		std::string token1;
		while (std::getline(ss1, token1, ',')) {
			if (token1[0] == '(' || token1[0] == '[')
			{
				number_count++;
				continue;
			}
			if (token1[token1.size() - 1] == ')' || token1[token1.size() - 1] == ']')
			{
				number_count++;
			}
		}
		//If the current number of partitions is greater than the previous greatest number then store current number
		if (largest_partition_count < number_count)
		{
			largest_partition_count = number_count;
		}
		number_count = 0;
	}
	return largest_partition_count;
}

//
//parse(int** &valid_result_array, std::string *input_ranges, int n, int largest_partition_count, int pgm, int* &invalid_array)
//
void Equivalence_Class_Generic::parse(int** &valid_result_array, std::string *input_ranges, int n, int largest_partition_count, int pgm, int* &invalid_array)
{
	//Variables to help with parsing the input partitions
	int row, col, lower, upper, random_number, l_flag = 0, u_flag = 0;
	int a_i, a_j, invalid_lower, invalid_upper, invalid_lower_flag = 0, invalid_upper_flag = 0, inv_index = 0;
	row = n;
	col = (largest_partition_count / 2);
	//Initializing the valid result array to 0
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			valid_result_array[i][j] = 0;
		}
	}
	a_i = 0;
	a_j = 0;
	//Parsing the partition and storing the values in the valid result array and invalid array
	for (int i = 0; i < n; i++)
	{
		std::istringstream ss(input_ranges[i]);
		std::string token, token2;
		while (std::getline(ss, token, ',')) {
			//Checking for '('
			if (token[0] == '(')
			{
				token = token.substr(1);
				lower = atoi(token.c_str());
				l_flag = 1;
				lower++;
				//If user has chosen Weak Robust Equivalence Class algorithm then invalid values are calculated
				if (pgm == 4)
				{
					if (!(invalid_lower_flag == 1))
					{
						invalid_lower = lower - 1;
						invalid_lower_flag = 1;
						invalid_array[inv_index] = invalid_lower;
						if (inv_index < (2 * n))
						{
							inv_index++;
						}
					}
				}
			}
			//Checking for '['
			else if (token[0] == '[')
			{
				token = token.substr(1);
				lower = atoi(token.c_str());
				l_flag = 1;
				//If user has chosen Weak Robust Equivalence Class algorithm then invalid values are calculated
				if (pgm == 4)
				{
					if (!(invalid_lower_flag == 1))
					{
						invalid_lower = lower - 1;
						invalid_lower_flag = 1;
						invalid_array[inv_index] = invalid_lower;
						if (inv_index < (2 * n))
						{
							inv_index++;
						}
					}
				}
			}
			//Checking for ')'
			else if (token[token.size() - 1] == ')')
			{
				upper = atoi(token.c_str());
				u_flag = 1;
				upper--;
			}
			//Checking for ']'
			else if (token[token.size() - 1] == ']')
			{
				upper = atoi(token.c_str());
				u_flag = 1;
			}
			//Storing the calculated values in the valid result array
			if ((l_flag == 1) && (u_flag == 1) && (a_j < col))
			{
				random_number = ((upper - lower) / 2) + lower;
				if (random_number == 0)
				{
					random_number++;
				}
				valid_result_array[a_i][a_j] = random_number;
				a_j++;
				l_flag = 0;
				u_flag = 0;
			}
		}
		if (a_i < row)
		{
			a_i++;
			a_j = 0;
		}
		//If user has chosen Weak Robust Equivalence Class algorithm then invalid values are stored
		if (pgm == 4)
		{
			invalid_lower_flag = 0;
			invalid_upper = upper + 1;
			if (inv_index < (2 * n))
			{
				invalid_array[inv_index] = invalid_upper;
				inv_index++;
			}
		}
	}
}