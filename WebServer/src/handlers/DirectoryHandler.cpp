/*
 * DirectoryHandler.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "DirectoryHandler.hpp"

using namespace std;

char* DirectoryHandler::doHandle(const Request &aRequest) {
	std::string urlLine = aRequest.getAbsolutePath();
	cout << "urlLine is ---------- : " << urlLine << endl;
	if (urlLine == "/*") {

		cout << "directoryHandler will handle ()))- ";
	}
	cout << "directoryHandler pass " << "  ";
	return Handler::doHandle(aRequest);
}
