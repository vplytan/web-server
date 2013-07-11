/*
 * ErrorHandler.cpp
 *
 *  Created on: Jul 11, 2013
 *      Author: vplytan
 */

#include "Handler.hpp"

class ErrorHandler: public Handler {
public:
	ErrorHandler(const Handler &aHandler);
	char* doHandle(const Request &aRequest);
private:
	std::string getPage(const std::string &root);
	std::string getRoot();
	std::string _errorPage;
};
ErrorHandler::ErrorHandler(const Handler &aHandler) :
	Handler(aHandler) {
	_errorPage = "ErrorHandler.html";
}
char* ErrorHandler::doHandle(const Request &aRequest) {
	std::string root = getRoot();
	std::string errorPage = getPage(root);
	char *cstr = new char[errorPage.length() + 1];
	strcpy(cstr, errorPage.c_str());
	return cstr;
}

std::string ErrorHandler::getPage(const std::string &root) {
	std::string page;
	std::string file = root;
	file.append(_errorPage);
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
	return page;
}

std::string ErrorHandler::getRoot() {
	return Configurator::getInstance()->getParameter("root");
}

