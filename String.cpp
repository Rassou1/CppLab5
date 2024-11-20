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
}

String::String(const char* cstr)
{
	thisString = cstr;
}

String& String::operator=(const String& rhs)
{
	// TODO: insert return statement here
}

char& String::operator[](size_t i)
{
	// TODO: insert return statement here
}

const char& String::operator[](size_t i) const
{
	// TODO: insert return statement here
}

size_t String::size() const
{
	return size_t();
}

size_t String::capacity() const
{
	return size_t();
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
	assert(size <= capacity);
	//Obs! Ändra och lägg till så det passar er klass
}
