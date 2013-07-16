/*
 * BinaryHandler.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "BinaryHandler.hpp"

using namespace std;

long BinaryHandler::getFileSize(FILE *file) {
	long lCurPos, lEndPos;
	lCurPos = ftell(file);
	fseek(file, 0, 2);
	lEndPos = ftell(file);
	fseek(file, lCurPos, 0);
	return lEndPos;
}

char* BinaryHandler::doHandle(const Request &aRequest) {
	std::string urlLine = aRequest.getAbsolutePath();
	cout << "urlLine is ---------- : " << urlLine << endl;
	if (Handler::getFileFormat(urlLine) == ".png" || Handler::getFileFormat(
			urlLine) == ".jpg") {
		cout << "binaryHandler handle ";

		//		const char *filePath = "C:\\Users\\UrName\\Desktop\\testFile.bin";
//		const char *filePath = (getRoot() + aRequest.getAbsolutePath()).c_str();
		const char *filePath = "../WebServer/res/we/vitaP.jpg";

		cout << "filePath :" << filePath << endl;
		char *fileBuf; // Pointer to our buffered data
		FILE *file = fopen(filePath, "r"); // File pointer

		// Open the file in binary mode using the "rb" format string
		// This also checks if the file exists and/or can be opened for reading correctly

		if (file == NULL)
			cout << "Could not open specified file" << endl;
		else
			cout << "File opened successfully" << endl;

		// Get the size of the file in bytes
		long fileSize = getFileSize(file);
		cout << "File size : " << fileSize << endl;

		// Allocate space in the buffer for the whole file
		fileBuf = new char[fileSize];
		cout << "File buf " << endl;

		// Read the file in to the buffer
		fread(fileBuf, fileSize, 1, file);
		cout << "Fread " << endl;

		/*
		 // Now that we have the entire file buffered, we can take a look at some binary infomation
		 // Lets take a look in hexadecimal
		 for (int i = 0; i < 100; i++)
		 printf("%X ", fileBuf[i]);
		 */
//		cin.get();
		//	delete[] fileBuf;
		fclose(file); // Almost forgot this
		cout << "fclose " << endl;


		return fileBuf;
	} else {
		cout << "binaryHandler pass " << "  ";
		return Handler::doHandle(aRequest);
	}
}

