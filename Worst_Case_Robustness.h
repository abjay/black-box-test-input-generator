// -*- C++ -*-

//==============================================================================
/**
* @file       Worst_Case_Robustness.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef WORST_CASE_ROBUSTNESS_H_
#define WORST_CASE_ROBUSTNESS_H_

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include"Boundary_Value_Generic.h"

/**
* @class Worst_Case_Robustness
*
* Implementation of Worst-Case Robustness algorithm
*/
class Worst_Case_Robustness : public Boundary_Value_Generic
{
public:
	/// Default Constructor
	Worst_Case_Robustness(void);

	/// Destructor
	virtual ~Worst_Case_Robustness(void);

	/**
	* Generate the test cases
	*
	*/
	void generate(void);
};

#endif			//!defined WORST_CASE_ROBUSTNESS_H_