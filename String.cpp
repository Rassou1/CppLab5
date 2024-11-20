#include "String.h"
#include <cassert>

String::~String()
{

}

String::String()
{

}

String::String(const String& rhs)
{
	stringCapacity = rhs.size() * 2;
	thisConstString = new char[stringCapacity];
	
}

const char& String::operator[](size_t i) const
{
	// TODO: insert return statement here
}

size_t String::size() const
{
	return stringSize;
}

size_t String::capacity() const
{
	return stringCapacity;
}

void String::push_back(char c)
{
}

const char* String::data() const
{
	return nullptr;
}

bool operator==(const String& lhs, const String& rhs)
{
	return false;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return false;
}

std::ostream& operator<<(std::ostream& out, const String& rhs)
{
	for (size_t i = 0; i < rhs.size(); ++i)
		out << rhs[i];
	return out;
	// TODO: insert return statement here
}

void String::Invariant() {
	assert(size() <= capacity());
	//Obs! Ändra och lägg till så det passar er klass
}
