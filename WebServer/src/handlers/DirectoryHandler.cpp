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

Response* DirectoryHandler::do_handle(Request* aRequest) {
	std::string urlLine = aRequest->get_absolute_path();
	cout << "urlLine is ---------- : " << urlLine << endl;
	if (urlLine == "/*") {

		cout << "directoryHandler will handle ()))- ";
	}
	cout << "directoryHandler pass " << "  ";
	return Handler::do_handle(aRequest);
}
