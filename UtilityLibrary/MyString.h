/*
 * String.h
 *
 *  Created on: Jan 15, 2011
 *      Author: ricardorodriguez
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_

namespace Utilities {

namespace MyString {

class MyString {
public:
	MyString();
	MyString(char *value);
	virtual ~MyString();

	// This function take the edges of the string/char array, swapping them,
	// working inward, until the entire string is swapped
	void Reverse();

	int GetStringSize();
	void PrintString();
	void SizeOf(char *string);

private:
	int Size(char *string);
	void Copy(char *string);
	void Reverse(char *value, int sizeBegin, int sizeEnd);

	char *_value;
	int _sizeOfString;
};

}

}

#endif /* STRING_H_ */
