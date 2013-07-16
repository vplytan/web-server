/*
 * IndexHandler.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "IndexHandler.hpp"

using namespace std;

char* IndexHandler::doHandle(const Request &aRequest) {
	std::string urlLine = aRequest.getAbsolutePath();
	cout << "urlLine is ----------" << urlLine << endl;
	if (urlLine == "/") {
		std::string root = getRoot();
		std::string page;
		std::string file = root + "index.html";
		ifstream pageFile(file.c_str());
		string line;
		if (pageFile.is_open()) {
			while (pageFile.good()) {
				getline(pageFile, line);
				page.append(line);
			}
			pageFile.close();
		} else {
			cout << "Unable to open file";
		}
		cout << "indexHandler handle " << "  ";
		char *cstr = new char[page.length() + 1];
		strcpy(cstr, page.c_str());
		cout << "textHandler handle " << "  ";
		return cstr;
	}
	cout << "indexHandler pass " << "  ";
	return Handler::doHandle(aRequest);
}
