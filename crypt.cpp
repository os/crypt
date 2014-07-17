//============================================================================
// Task        : Assignment 1
// Student     : Oktay Sancak
// StudentID   : SAOKD0903
//============================================================================
// Compiler    : MinGW 5.1.6
// Editor      : Eclipse 3.5.1
//============================================================================

#include <iostream>
#include <math.h>

using namespace std;

const char PAIR_SIZE = 2;
const char ALPHA_CHAR_COUNT = 26;

string toString(int n) {
	string result;

	while (n) {
		result = static_cast<char>(('0' + n % 10)) + result;
		n /= 10;
	}

	return result;
}

int parseInt(string str) {
	double result = 0;

	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] >= '0' && str[i] <= '9') // is numeric?
			// find the integer representation and shift to left if required
			result += (str[i] - '0') * pow(10, str.length() - i - 1);
		else break; // break if not numeric
	}

	return static_cast<int>(result);
}

int asciiSum(string str) {
	int result = 0;

	for (int i = 0; i < str.length(); i++)
		result += str[i];

	return result;
}

string binaryRepresentation(char ch) {
	string result;

	while (ch) {
		result = (ch % 2 ? '1' : '0') + result;
		ch = ch / 2;
	}

	return result;
}

int countOfOnes(string str) {
	int result = 0;

	for (int i = 0; i < str.length(); i++)
		if (str[i] == '1') result++;

	return result;
}

string representationByOne(string str) {
	string result;

	for (int i = 0; i < str.length(); i++)
		result += '0' + countOfOnes(binaryRepresentation(str[i])); // 48 + value

	return result;
}

int biggerThanFirstLetterCount(string str) {
	int result = 0;

	for (int i = 1; i < str.length(); i++)
		if (toupper(str[i]) > toupper(str[0])) result++;

	return result;
}

int uniqueLetterCount(string str) {
	string uniqueLetters;

	for (int i = 0; i < str.length(); i++) {
		if (uniqueLetters.find_first_of(toupper(str[i])) == string::npos)
			uniqueLetters += toupper(str[i]);
	}

	return uniqueLetters.length();
}

string evenize(string str) {
/* Adds '0' at the end of the string if the string length is odd */
	return str.length() % 2 ? str + '0' : str;
}


string combinedRepresentation(string str) {
	return toString(asciiSum(str)) +
		   representationByOne(str) +
		   toString(biggerThanFirstLetterCount(str)) +
		   toString(uniqueLetterCount(str));
}

string encode(string str) {
	string result, pair;
	str = evenize(str);

	while (str.length()) {
		pair = str.substr(str.length() - PAIR_SIZE, PAIR_SIZE);
		result = static_cast<char>(
					'A' + (parseInt(pair) % ALPHA_CHAR_COUNT)
				 ) + result;
		str.erase(str.length() - PAIR_SIZE);
	}

	return result;
}

int main() {
	string name;

	cout << "Please enter your name: ";
	cin >> name;

	cout << asciiSum(name) << endl;
	cout << representationByOne(name) << endl;
	cout << biggerThanFirstLetterCount(name) << endl;
	cout << uniqueLetterCount(name) << endl;
	cout << encode(combinedRepresentation(name)) << endl;
}
