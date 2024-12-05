#include "String.h"
#include <cassert>
#include <cstring>

String::~String()
{
	Invariant();

	delete[] thisString;
}

String::String() : size(0), capacity(0), thisString(new char[1] {})
{	
	Invariant();
}

String::String(const String& rhs) : size(rhs.size), capacity(rhs.capacity), thisString(new char[capacity] {})
{
	std::memcpy(thisString, rhs.thisString, size);
	Invariant();
}

String::String(const char* cstr) : size(strlen(cstr)), capacity(size + 10), thisString(new char[capacity] {})
{
	std::memcpy(thisString, cstr, size);
	Invariant();
}

String& String::operator=(const String& rhs)
{
	Invariant();

	if (this == &rhs)
		return *this;

	if (capacity < rhs.size) {
		delete[] thisString;
		this->capacity = rhs.capacity;
		thisString = new char[capacity];
	}

	this->size = rhs.size;
	std::memcpy(thisString, rhs.thisString, size);
	Invariant();

	return *this;
}

char& String::operator[](size_t i)
{
	return thisString[i];
}

const char& String::operator[](size_t i) const
{
	return thisString[i];
}

size_t String::getSize() const
{
	return size;
}

size_t String::getCapacity() const
{
	return capacity;
}

void String::push_back(char c)
{
	Invariant();

	if (size == capacity) {
		if (capacity == 0) {
			Reserve(1);
		}
		else {
			Reserve(capacity * 2);
		}
	}

	thisString[size++] = c;
	Invariant();
}

const char* String::data() const
{
	return thisString;
}

bool operator==(const String& lhs, const String& rhs)
{
	if(lhs.size != rhs.size)
		return false;

	for (int i = 0; i < lhs.size; i++) {
		if (lhs[i] != rhs[i])
			return false;
	}

	return true;
}

bool operator!=(const String& lhs, const String& rhs) 
{
	return !(lhs == rhs);
}


std::ostream& operator<<(std::ostream& out, const String& rhs)
{
	for (size_t i = 0; i < rhs.getSize(); ++i)
		out << rhs[i];
	return out;
}

void String::Invariant() {
	assert(capacity >= 0);
	assert(size >= 0);
	assert(size <= capacity);
}

void String::Reserve(size_t newCapacity) {
	assert(newCapacity > capacity);
	char* newString = new char[newCapacity];
	std::memcpy(newString, thisString, size);
	delete[] thisString;
	thisString = newString;
	capacity = newCapacity;
}
