/*
 * TextHandler.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "TextHandler.hpp"
#include "Handler.hpp"

using namespace std;

char* TextHandler::doHandle(const Request &aRequest) {
	std::string urlLine = aRequest.getAbsolutePath();
	cout << "urlLine is : " << urlLine << endl;
	if (getFileFormat(urlLine) == ".html" || getFileFormat(urlLine) == ".htm"
			|| getFileFormat(urlLine) == ".css") {
		std::string outputFile = getPage(urlLine);
		if (outputFile != "") {
			char *cstr = new char[outputFile.length() + 1];
			strcpy(cstr, outputFile.c_str());
			cout << "textHandler handle " << "  ";
			return cstr;
		}
	}
	cout << "textHandler pass " << "  ";
	return Handler::doHandle(aRequest);
}
