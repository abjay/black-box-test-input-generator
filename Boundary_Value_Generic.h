// -*- C++ -*-

//==============================================================================
/**
* @file       Boundary_Value_Generic.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef BOUNDARY_VALUE_GENERIC_H_
#define BOUNDARY_VALUE_GENERIC_H_

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include"Testing_Technique.h"

/**
* @class Boundary_Value_Generic
*
* Implementation of Boundary Value Analysis algorithm
*/
class Boundary_Value_Generic : public Testing_Technique
{
public:
	/// Default constructor
	Boundary_Value_Generic(void);

	/// Destructor
	virtual ~Boundary_Value_Generic(void);
	
	/**
	* Generate the test cases
	*
	*/
	virtual void generate(void) = 0;

	/**
	* Parse the given range set
	*
	* @param[in]		case_variables		array containing testcase variables
	* @param[in]		input_ranges		array of ranges
	* @param[in]		n					number of variables
	* @param[in]		size				number of case variables
	*/
	void parse(int** &case_variables, std::string *input_ranges, int n, int size);
};

#endif			//!defined BOUNDARY_VALUE_GENERIC_H_