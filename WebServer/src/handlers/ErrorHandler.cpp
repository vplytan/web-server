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
#include "../builders/Response.hpp"

using namespace std;
Response* ErrorHandler::do_handle(Request* aRequest) {
	_errorPage = "ErrorHandler.html";
	std::string errorPage;
	std::string page = get_page(_errorPage);

	errorPage.append(build_status_line("404 NOT FOUND"));
	std::string requestContentType = "Content-Type: text/html\n";
	errorPage.append(build_content_type(requestContentType, page.length()));
	errorPage.append(page);


	char *cstr = new char[errorPage.length() + 1];
	strcpy(cstr, errorPage.c_str());
	Response* response = new Response(cstr);
	cout << "errorHandler handle" << endl;
	return response;
}
