// -*- C++ -*-

//==============================================================================
/**
* @file       Weak_Normal_Equivalence_Class.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef WEAK_NORMAL_EQUIVALENCE_CLASS_H_
#define WEAK_NORMAL_EQUIVALENCE_CLASS_H_

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include"Equivalence_Class_Generic.h"

/**
* @class Weak_Normal_Equivalence_Class
*
* Implementation of Weak Normal Equivalence Class algorithm
*/
class Weak_Normal_Equivalence_Class : public Equivalence_Class_Generic
{
public:
	/// Default Constructor
	Weak_Normal_Equivalence_Class(void);

	/// Destructor
	virtual ~Weak_Normal_Equivalence_Class(void);

	/**
	* Generate the test cases
	*
	*/
	void generate(void);
};

#endif			//!defined WEAK_NORMAL_EQUIVALENCE_CLASS_H_