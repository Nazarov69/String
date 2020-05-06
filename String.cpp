#include "String.h"
String::String() {
	str = nullptr;
	length = 0;
}
String::String(const char* str) {
	length = strlen(str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) 
		this->str[i] = str[i];
	this->str[length] = '\0';

}

String::String(char st, int length) {
	this->length = length + 1;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = st;
	str[length] = '\0';

}

String::String(String& a) {
	length = strlen(a.str);
	str = new char[length + 1];
	for (int i = 0; i < length; i++) 
		this->str[i] = a.str[i];
	this->str[length] = '\0';
}

char* String::GetStr() {
	return str;
}
int String::GetLength() {
	return length;
}

void String::SetStrLength(const char* ch) {
	length = strlen(ch);
	str = new char[length + 1];
	for (int i = 0; i < length; i++) 
		str[i] = ch[i];
	str[length] = '\0';
}

String String::operator+ (const String& a) {
	String NewStr;
	int thisLength = strlen(this->str);
	int aLength = strlen(a.str);
	NewStr.length = thisLength + aLength;
	NewStr.str = new char[thisLength + aLength + 1];
	int i = 0;
	for (; i < thisLength; i++) 
		NewStr.str[i] = this->str[i];
	for (int j = 0; j < aLength; j++, i++) 
		NewStr.str[i] = a.str[j];
	NewStr.str[thisLength + aLength] = '\0';
	return NewStr;
}

String& String::operator= (const String& a) {
	if (this->str != nullptr) {
		delete[] str;
	}
	length = strlen(a.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) 
		this->str[i] = a.str[i];
	this->str[length] = '\0';
	return*this;
}

bool String::operator== (const String& a) {
	if (this->length != a.length) {
		return false;
	}
	for (int i = 0; i < this->length; i++) {
		if (this->str[i] != a.str[i]) {
			return false;
		}
	}
	return true;
}
bool String::operator< (const String& a) {
	return length < a.length;

}

bool String::operator> (const String& a) {
	return length > a.length;
}
char& String::operator[] (int index) {
	if (index >= 0 && index < length) 
	return this->str[index];
}

ostream& operator<< (ostream& os, const String& a) {
	for (int i = 0; i < a.length; i++) 
		os << a.str[i];
	return os;
}

istream& operator>> (istream& is, String& a) {
	char c[256];
	is.getline(c, 256);
	String tmp(c);
	a = tmp;
	return is;
}

String::~String() {
	delete[] str;
}

char* String::Find(const char* tmp) {
	char* c = strstr(str, tmp);
	return c;
}

char* String::FirstFind(const char* ch) {
	char* c = strstr(str, ch);
	return c;
}

String* String::Getline(const char* ch) {
	String tmp = str;
	int digit = 0;
	char* c = strtok(tmp.str, ch);
	while (c != NULL) {
		digit += 1;
		c = strtok(NULL, ch);
	}
	tmp = c;
	String* a = new String[digit];
	digit = 0;
	c = strtok(tmp.str, ch);
	while (c != NULL){
		a[digit] = c;
		digit += 1;
		c = strtok(NULL, c);
	}

	return a;
}