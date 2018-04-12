// -*- C++ -*-

//==============================================================================
/**
* @file       Boundary_Value_Analysis.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef BOUNDARY_VALUE_ANALYSIS_H_
#define BOUNDARY_VALUE_ANALYSIS_H_

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include"Boundary_Value_Generic.h"

/**
* @class Boundary_Value_Analysis
*
* Implementation of Boundary Value Analysis algorithm
*/
class Boundary_Value_Analysis : public Boundary_Value_Generic
{
public:
	/// Default constructor
	Boundary_Value_Analysis(void);

	/// Destructor
	virtual ~Boundary_Value_Analysis(void);

	/**
	* Generate the test cases
	*
	*/
	void generate(void);
};

#endif			//!defined BOUNDARY_VALUE_ANALYSIS_H_