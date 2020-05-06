#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class String{
	int length;
	char* str;
public:
	String();
	String(const char* str);
	String(char str, int length);
	String(String& a);
	char* GetStr();
	int GetLength();
	void SetStrLength(const char* ch);
	String operator+ (const String& a);
	String& operator= (const String& a);
	bool operator== (const String& a);
	bool operator< (const String& a);
	bool operator> (const String& a);
	char& operator[] (int index);
	friend ostream& operator<< (ostream& os, const String& a);
	friend istream& operator>> (istream& is, String& a);
	~String();
	char* Find(const char* tmp);
	char* FirstFind(const char* ch);
	String* Getline(const char* ch);
};