// -*- C++ -*-

//==============================================================================
/**
* @file       Equivalence_Class_Generic.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef EQUIVALENCE_CLASS_GENERIC_H_
#define EQUIVALENCE_CLASS_GENERIC_H_

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include"Testing_Technique.h"

/**
* @class Equivalence_Class_Generic
*
* Implementation of Equivalence Class Testing algorithm
*/
class Equivalence_Class_Generic : public Testing_Technique
{
public:
	/// Default constructor
	Equivalence_Class_Generic(void);

	/// Destructor
	virtual ~Equivalence_Class_Generic(void);

	/**
	* Generate the test cases
	*
	*/
	virtual void generate(void) = 0;

	/**
	* Parse the given range set
	*
	* @param[in]		valid_result_array				array containing valid value result
	* @param[in]		input_ranges					array of ranges
	* @param[in]		n								number of variables
	* @param[in]		largest_partition_count			count of the largest number of partitions
	* @param[in]		pgm								technique program number
	* @param[in]		invalid_array					array containing invalid value result
	*/
	void parse(int** &valid_result_array, std::string *input_ranges, int n, int largest_partition_count, int pgm, int* &invalid_array);

	/**
	* Parse the given range set
	*
	* @param[in]		input_ranges					array of ranges
	* @param[in]		n								number of variables
	* return			int								count of the largest number of partitions
	*/
	int largest_partition(std::string *input_ranges, int n);
};

#endif			//!defined EQUIVALENCE_CLASS_GENERIC_H_