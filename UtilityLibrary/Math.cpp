/*
 * Math.cpp
 *
 *  Created on: Jan 16, 2011
 *      Author: ricardorodriguez
 */

#include "Math.h"
#include <stdio.h>
#include <iostream>

namespace Utilities {

namespace Math {

/////////////////////////////////////////////////////////
Math::Math() {
	// TODO Auto-generated constructor stub

}

/////////////////////////////////////////////////////////
Math::~Math() {
	// TODO Auto-generated destructor stub
}

/////////////////////////////////////////////////////////
void Math::PowerOf(float base, int exponent)
{
	std::cout << base << " to the power of " << exponent << " is: " << Power(base, exponent) << std::endl;
}

/////////////////////////////////////////////////////////
void Math::AltPowerOf(float base, int exponent)
{
	std::cout << base << " to the power of " << exponent << " is: " << AltPower(base, exponent) << std::endl;
}

/////////////////////////////////////////////////////////
float Math::Power(float base, int exponent)
{
	if(exponent == 0)
		return 1;

	return base * Power(base, exponent - 1);
}

/////////////////////////////////////////////////////////
float Math::AltPower(float base, int exponent)
{
	if(exponent == 1)
		return base;

	if(exponent % 2)
		return AltPower(base, exponent/2) * AltPower(base, exponent/2) * base;
	else
		return AltPower(base, exponent/2) * AltPower(base, exponent/2);
}

/////////////////////////////////////////////////////////
void Math::MultiplyTwo(int multiplicator, int multiplicand)
{
	std::cout << "The product of " << multiplicator << " and " << multiplicand << " is: " << Multiply(multiplicator, multiplicand) << std::endl;
}

/////////////////////////////////////////////////////////
int Math::Multiply(int multiplicator, int multiplicand)
{
	if(multiplicand == 1)
		return multiplicator;
	else
		return multiplicator + Multiply(multiplicator, multiplicand-1);
}

/////////////////////////////////////////////////////////
void Math::GCDOf(int first, int second)
{
	std::cout << "The GCD of " << first << " and " << second << " is: " << GCD(first, second) << std::endl;
}

/////////////////////////////////////////////////////////
int Math::GCD(int first, int second)
{
	if(second <= 0)
		return first;
	else
		GCD(second, first % second);
}

/////////////////////////////////////////////////////////
void Math::ProductOf(int start, int finish)
{
	std::cout << "The product of the numbers in the range " << start << " to " << finish << " is: " << Product(start, finish) << std::endl;
}

/////////////////////////////////////////////////////////
double Math::Product(int start, int finish)
{
	if (start == finish)
		return start;
	else
		return start * Product(start+1, finish);
}

/////////////////////////////////////////////////////////
void Math::CombinatoricOf(int n, int k)
{
	std::cout << "The combinatoric expression \"n choose k\" for n/k " << n << "/" << k << " is: " << Combinatoric(n, k) << std::endl;
}

/////////////////////////////////////////////////////////
double Math::Combinatoric(int n, int k)
{
	if(k == 0)
		return 1;
	if(n == k)
		return 1;

	return ( Product(n-(k-1), n) / Product(1, k) );
}


/////////////////////////////////////////////////////////
}
}
