/*
 * String.cpp
 *
 *  Created on: Jan 15, 2011
 *      Author: ricardorodriguez
 */

#include <iostream>
#include "MyString.h"

namespace Sabiduria {

namespace Text {

//////////////////////////////////////////////////
MyString::MyString()
{
	_value = new char[256];
	_sizeOfString = 0;
}

//////////////////////////////////////////////////
MyString::MyString(char *value)
{
	_value = new char[Size(value)];
	_sizeOfString = Size(value);

	strcpy(_value, value);


}

//////////////////////////////////////////////////
MyString::~MyString()
{

}

//////////////////////////////////////////////////
void MyString::Copy(char *string)
{/*
	char *ptr = string;
	_value = "";

	while(*ptr != '\0')
	{

	}*/
}

//////////////////////////////////////////////////
int MyString::GetStringSize()
{
	return _sizeOfString;
}

//////////////////////////////////////////////////
void MyString::PrintString()
{
	std::cout << _value << " (" << Size(_value) << ")" << std::endl;
}

//////////////////////////////////////////////////
void MyString::SizeOf(char *string)
{
	std::cout << "Size of (" << string << ") is: " << Size(string) << std::endl;
}

//////////////////////////////////////////////////
int MyString::Size(char *string)
{
	int size = 0;
	char *ptr = string;

	while(*ptr != '\0')
	{
		size++;
		ptr++;
	}

	return size;
}

//////////////////////////////////////////////////
void MyString::Reverse()
{
	Reverse(_value, 0, -1);
}

//////////////////////////////////////////////////
void MyString::Reverse(char * value, int sizeBegin, int sizeEnd)
{
	if(sizeEnd == -1)
	{
		// We need to account for subscript value, i.e. 0 to n-1
		sizeEnd = Size(value)-1;
	}

	if (sizeBegin < sizeEnd) {
		char c;

		c = value[sizeBegin];
		value[sizeBegin] = value[sizeEnd];
		value[sizeEnd] = c;
		Reverse(value, sizeBegin+1, sizeEnd-1);
	}
}

//////////////////////////////////////////////////
} // InterviewPrep

} // Google
