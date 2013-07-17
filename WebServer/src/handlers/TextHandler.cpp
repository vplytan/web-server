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

Response* TextHandler::do_handle(Request* aRequest) {
	std::string urlLine = aRequest->get_absolute_path();
	cout << "urlLine is : " << urlLine << endl;
	if (get_file_format(urlLine) == ".html" || get_file_format(urlLine)
			== ".htm" || get_file_format(urlLine) == ".css") {
		std::string page = get_page(urlLine);
		if (page != "") {

			std::string textPage;

			textPage.append(build_status_line("200 OK"));
			textPage.append(build_content_type(aRequest->get_content_type(),
					page.length()));
			textPage.append(page);

			char *cstr = new char[page.length() + 1];
			strcpy(cstr, page.c_str());
			cout << "textHandler handle " << "  ";

			return new Response(cstr);
		}
	}
	cout << "textHandler pass " << "  ";
	return Handler::do_handle(aRequest);
}
