#include <iostream>
#include <string>
using namespace std;

class String
{
	int length;
	char* str;
public:
	String();
	String(const char* str);
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
	int Length();
	void Print();
	char* Find(const char* tmp);
	char* FirstFind(const char* ch);
	void Getline(const char* ch);
};

String::String() {
	str = nullptr;
	length = 0;
}
String::String(const char* str) {
	length = strlen(str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->str[i] = str[i];
	}
	this->str[length] = '\0';

}

String::String(String& a) {
	length = strlen(a.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->str[i] = a.str[i];
	}
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
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->str[i] = ch[i];
	}
	str[length] = '\0';
}

String String::operator+ (const String& a) {
	String NewStr;
	int thisLength = strlen(this->str);
	int aLength = strlen(a.str);
	NewStr.length = thisLength + aLength;
	NewStr.str = new char[thisLength + aLength + 1];
	int i = 0;
	for (; i < thisLength; i++) {
		NewStr.str[i] = this->str[i];
	}
	for (int j = 0; j < aLength; j++, i++) {
		NewStr.str[i] = a.str[j];
	}
	NewStr.str[thisLength + aLength] = '\0';
	return NewStr;
}

String& String::operator= (const String& a) {
	if (this->str != nullptr) {
		delete[] str;
	}
	length = strlen(a.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->str[i] = a.str[i];
	}
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
	return length < a.length;
}
char& String::operator[] (int index) {
	return this->str[index];
}

ostream& operator<< (ostream& os, const String& a) {
	for (int i = 0; i < a.length; i++) {
		os << a.str[i];
	}
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
	delete[] this->str;
}

int String::Length() {
	return length;
}

void String::Print() {
	cout << str << endl;
}

char* String::Find(const char* tmp) {
	char* c = strstr(str, tmp);
	return c;
}

char* String::FirstFind(const char* ch) {
	char* c = strstr(str, ch);
	return c;
}

void String::Getline(const char* ch) {
	char* c = strtok(str, ch);
	while (c != NULL) {
		cout << c << endl;
		c = strtok(NULL, ch);
	}
}

int main() {
	String str;
	String str2("Hello");
	String str3(str2);
	cout << str2.GetStr() << endl;
	cout << str3.GetStr() << endl;
	str3.SetStrLength("World");
	cout << str3 << endl;
	String result;
	result = str2 + str3;
	bool equal = str2 == str3;
	cout << "+ : " << result << endl;
	cout << "== : " << equal << endl;
	cout << str2.Length() << endl;
	cout << str3.Length() << endl;
	cout << result.Length() << endl;
	String str4("IITMM FIIT");
	String str5("IITMM FIIT");
	bool equal2 = str4 == str5;
	cout << "== : " << equal2 << endl;
	str5.SetStrLength("FIIT");
	bool res = str4 < str5;
	cout << "< : " << res << endl;
	bool res2 = str4 > str5;
	cout << "> : " << res2 << endl;
	cout << "[] : " << str4[0] << endl;
	cout << str4.Find("I") << endl;
	cout << str4.FirstFind("T") << endl;
	str4.Getline(" ");

	return 0;
}