/*
		EasyFile - A small library built upon C++'s fstream for simpler file input, output and control.
										Copyright © - Jay Bennett 2015
					Source code publicly available at http://github.com/rekrom12/EasyFile/
		  Redistribution of this library is NOT permitted without the consent of the library creator.
*/

#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "EasyFileExceptions.h"

using namespace std;

class File
{
public:
	File() {}
	File(string filename) { open(filename); }

	//Control
	void open(string filename);
	void close();
	void reload();

	//Writing (technically ofstream)
	void writeToFile(string toWrite);
	void clear();

	//Reading (technically ifstream)
	string readEntireFile();
	string readLine(int lineNum);
	string readLineRange(int from, int to);
	int getLineAmount();
	string findLine(string s);
	int findLineNumber(string s);
	string findAllOccurrences(string s);
	string findAllOccurrencesLineNum(string s);
	fstream* getNative();
	int getAmountOfCharacters();
	int getAmountOfCharactersOnLine(int linenum);

private:
	string filename;
	fstream file;
	bool isNull = true;
};

void File::open(string filename) {
	file.open(filename, fstream::in | fstream::out | fstream::app);

	if (file.fail()) {
		throw FileFailedToOpenException(filename);
	}

	if (file.good()) {
		this->filename = filename;
		isNull = false;
	}
}

void File::close() {
	if (isNull) throw FileNullException();
	isNull = true;

	file.close();
}

void File::writeToFile(string toWrite) {
	if (isNull) throw FileNullException();

	file << toWrite.c_str();

	reload();
}

string File::readEntireFile() {
	if (isNull) throw FileNullException();

	string temp;
	string input;

	while (getline(file, temp)) {
		input += temp + "\n";
	}
	reload();
	return input;
}

void File::clear() {
	if (isNull) throw FileNullException();
	file.close();
	file.open(filename, fstream::in | fstream::out | fstream::trunc);

	reload();
}

string File::readLine(int lineNum) {
	if (isNull) throw FileNullException();
	string temp;
	string returnString = "";
	int i = 0;
	while (getline(file, temp)) {
		i++;
		if (i == lineNum) {
			returnString = temp;
			break;
		}
	}
	if (returnString == "") {
		throw LineIndexOutOfBoundsException();
	}

	reload();
	return returnString;
}

string File::readLineRange(int from, int to) {
	if (isNull) throw FileNullException();
	string temp;
	string returnString = "";
	int i = 0;

	while (getline(file, temp)) {
		i++;
		if (i >= from && i <= to) {
			returnString += temp + "\n";
		}
	}

	if (returnString == "") {
		throw LineIndexOutOfBoundsException();
	}

	reload();
	return returnString;
}

int File::getLineAmount() {
	if (isNull) throw FileNullException();
	int i = 0;
	string temp;
	while (getline(file, temp)) {
		i++;
	}

	reload();

	return i;
}

void File::reload() {
	if (isNull) throw FileNullException();
	file.close();
	file.open(filename, fstream::in | fstream::out | fstream::app);
}

string File::findLine(string s) {
	if (isNull) throw FileNullException();
	string temp;
	string returnval;
	while (getline(file, temp)) {
		if (temp.substr(0, s.length()) == s) {
			returnval = temp;
			break;
		}
	}
	return returnval;
}

int File::findLineNumber(string s) {
	if (isNull) throw FileNullException();
	string temp;
	int returnval = 0;
	while (getline(file, temp)) {
		returnval++;
		if (temp.substr(0, s.length()) == s) {
			break;
}
}
	return returnval;
}

string File::findAllOccurrences(string s) {
	if (isNull) throw FileNullException();
	string temp;
	string returnval = "";
	int i = 0;
	while (getline(file, temp)) {
		i++;
		if (temp.substr(0, s.length()) == s) {
			if (returnval == "") {
				returnval += to_string(i) + " - " + temp;
			}
			else{
				returnval += "\n" + to_string(i) + " - " + temp;
			}
		}
	}
	return returnval;
}

string File::findAllOccurrencesLineNum(string s) {
	if (isNull) throw FileNullException();
	string temp;
	string returnval = "";
	int i = 0;
	while (getline(file, temp)) {
		i++;
		if (temp.substr(0, s.length()) == s) {
			if (returnval == "") {
				returnval += to_string(i);
			}
			else{
				returnval += "\n" + to_string(i);
			}
		}
	}
	return returnval;
}

fstream* File::getNative() {
	if (isNull) throw FileNullException();
	return &file;
}

int File::getAmountOfCharacters() {
	if (isNull) throw FileNullException();

	string temp;
	int i = 0;
	while (file >> temp) {
		i++;
	}
	return i;
}

int File::getAmountOfCharactersOnLine(int linenum) {
	if (isNull) throw FileNullException();
	string line = readLine(linenum);
	return line.length();
}
