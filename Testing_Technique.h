// -*- C++ -*-

//==============================================================================
/**
* @file       Testing_Technique.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef TESTING_TECHNIQUE_H_
#define TESTING_TECHNIQUE_H_

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>

/**
* @class Testing_Technique
*
* Implementation of Strategy design pattern for the testing technique
*/
class Testing_Technique
{
public:
	/// Default constructor
	Testing_Technique(void);

	/// Destructor
	virtual ~Testing_Technique(void);

	/**
	* Generate the test cases
	*
	*/
	virtual void generate(void) = 0;
};

#endif			//!defined TESTING_TECHNIQUE_H_