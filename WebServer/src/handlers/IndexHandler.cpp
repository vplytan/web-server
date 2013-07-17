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

Response* IndexHandler::do_handle(Request* aRequest) {
	std::string urlLine = aRequest->get_absolute_path();
	cout << "urlLine is ----------" << urlLine << endl;
	if (urlLine == "/") {
		std::string root = get_root();
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

		std::string indexPage;

		indexPage.append(build_status_line("200 OK"));
		indexPage.append(build_content_type(aRequest->get_content_type(), page.length()));
		indexPage.append(page);


		char *cstr = new char[page.length() + 1];
		strcpy(cstr, page.c_str());
		cout << "textHandler handle " << "  ";
		return new Response(cstr);
	}
	cout << "indexHandler pass " << "  ";
	return Handler::do_handle(aRequest);
}
