#pragma once
#include <iostream>
class String
{
	const char* thisConstString;
	int stringSize;
	int stringCapacity;

public:
	String();

	String(const String& rhs);

	String(const char* cstr);

	String& operator=(const String& rhs);

	char& operator[](size_t i);

	const char& operator[](size_t i) const;

	size_t size() const;

	size_t capacity() const;

	void push_back(char c);

	friend bool operator==(const String& lhs, const String& rhs);

	friend bool operator!=(const String& lhs, const String& rhs);

	const char* data() const;

	friend std::ostream& operator<< (std::ostream& out, const String& rhs);

	void Invariant();

	~String();

};

