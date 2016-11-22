#include "StdAfx.h"
#include "Utility.h"
#include <sstream>

using namespace std;
using namespace System;

double string_to_double( const std::string& s )
{
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
} 
string int_to_string( int num )
{
	return to_string((long double)num);
}
string double_to_string( double num )
{
	return to_string((long double)num);
}





