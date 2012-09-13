/*
 * Math.h
 *
 *  Created on: Jan 16, 2011
 *      Author: ricardorodriguez
 */

#ifndef MATH_H_
#define MATH_H_

namespace Sabiduria {

namespace Math {

class Math {
public:
	Math();
	virtual ~Math();

	// Recursively finds the value of base, given the power of the exponent: O(n)
	void PowerOf(float base, int exponent);
	// Improved efficiency by "halving" the exponent, thereby halving the complexity: O(n/2)
	void AltPowerOf(float base, int exponent);
	void MultiplyTwo(int multiplicator, int multiplicand);
	void GCDOf(int first, int second);
	// Product of numbers in the range [start, finish]
	void ProductOf(int start, int finish);
	// The combination of n things taken k at a time
	void CombinatoricOf(int n, int k);

private:
	float Power(float base, int exponent);
	float AltPower(float base, int exponent);
	int Multiply(int multiplicator, int multiplicand);
	int GCD(int first, int second);
	double Product(int start, int finish);
	double Combinatoric(int n, int k);
};

}
}
#endif /* MATH_H_ */
