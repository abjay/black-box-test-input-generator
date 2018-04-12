#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <stdlib.h>
#include"Testing_Technique.h"
#include"Boundary_Value_Analysis.h"
#include"Worst_Case_Robustness.h"
#include"Weak_Normal_Equivalence_Class.h"
#include"Weak_Robust_Equivalence_Class.h"
#include"Boundary_Value_Generic.h"
#include"Equivalence_Class_Generic.h"

int main(int argc, char * argv[])
{
	//Variable to create object of specified testing strategy
	Testing_Technique * tt;
	std::string t;
	//Taking in the type of testing technique
	std::cin >> t;
	
	if (t == "1")
	{
		tt = new Boundary_Value_Analysis();
	}
	else if (t == "2")
	{
		tt = new Worst_Case_Robustness();
	}
	else if (t == "3")
	{
		tt = new Weak_Normal_Equivalence_Class();
	}
	else if (t == "4")
	{
		tt = new Weak_Robust_Equivalence_Class();
	}
	try
	{
		//Call the generate method of the specific testing strategy
		tt->generate();
	}
	catch (std::exception & exp)
	{
		std::cout << exp.what() << std::endl;
	}
	//Deleting created object after use	
	delete tt;
	
	return 0;
}