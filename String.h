#pragma once
#include <iostream>
class String
{
    char* thisString;

public:

	size_t size;
	size_t capacity;

	String();

	String(const String& rhs);

	String(const char* cstr);

	String& operator=(const String& rhs);

	char& operator[](size_t i);

	const char& operator[](size_t i) const;

	size_t getSize() const;

	size_t getCapacity() const;

	void push_back(char c);

	friend bool operator==(const String& lhs, const String& rhs);

	friend bool operator!=(const String& lhs, const String& rhs);

	const char* data() const;

	friend std::ostream& operator<< (std::ostream& out, const String& rhs);

	void Invariant();

	void Reserve(size_t newCapacity);

	void Resize();

	~String();

};

