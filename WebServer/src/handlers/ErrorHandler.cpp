/*
 * ErrorHandler.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */
#include <iostream>
#include <string.h>

#include "ErrorHandler.hpp"
#include "Handler.hpp"

using namespace std;
char* ErrorHandler::doHandle(const Request &aRequest) {
	_errorPage = "ErrorHandler.html";
	std::string root = getRoot();
	std::string errorPage = getPage(_errorPage);
	char *cstr = new char[errorPage.length() + 1];
	strcpy(cstr, errorPage.c_str());
	cout << "errorHandler handle" << endl;
	return cstr;
}
