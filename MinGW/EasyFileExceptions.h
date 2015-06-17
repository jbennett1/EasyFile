/*
		EasyFile - A small library built upon C++'s fstream for simpler file input, output and control.
										Copyright © - Jay Bennett 2015
					Source code publicly available at http://github.com/rekrom12/EasyFile/
		  Redistribution of this library is NOT permitted without the consent of the library creator.
*/

#pragma once
#include <exception>
#include <iostream>
#include <stdexcept> //MinGW

using namespace std;

	class FileNotFoundException : public runtime_error {
	public:
		FileNotFoundException() : runtime_error("Runtime Error: File not found") {}
		FileNotFoundException(string filename) : runtime_error("Runtime Error: File not found (" + filename + ")") {}
	};

	class FileOpenException : public runtime_error {
	public:
		FileOpenException() : runtime_error("Runtime Error: File Already Open") {}
		FileOpenException(string filename) : runtime_error("Runtime Error: File Already Open (" + filename + ")") {}
	};

	class FileNullException : public logic_error {
	public:
		FileNullException() : logic_error("Logic Error: File is null (open() function hasn't been called)") {}
	};

	class InvalidParametersException : public logic_error {
	public:
		InvalidParametersException() : logic_error("Logic Error: Invalid Parameters on open() function") {}
	};

	class FileFailedToOpenException : public runtime_error {
	public:
		FileFailedToOpenException() : runtime_error("Runtime Error: File failed to open") {}
		FileFailedToOpenException(string filename) : runtime_error("Runtime Error: File failed to open (" + filename + ")") {}
	};

	class LineIndexOutOfBoundsException : public runtime_error {
	public:
		LineIndexOutOfBoundsException() : runtime_error("Runtime error: Line index out of bounds") {}
	};
