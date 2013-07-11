#include "../builders/Request.hpp"
#include "Handler.hpp"
#include <string.h>
#include <stdio.h>

using namespace std;

class TextHandler: public Handler {
public:
	TextHandler(const Handler &aHandler);
	char* doHandle(const Request &aRequest);
private:
	std::string getFileFormat(const std::string &path);
	std::string getPage(const std::string &root);
};

TextHandler::TextHandler(const Handler &aHandler) :
	Handler(aHandler) {
}

char* TextHandler::doHandle(const Request &aRequest) {
	std::string urlLine = aRequest.getAbsolutePath();
	if (getFileFormat(urlLine) == "html" || getFileFormat(urlLine) == "htm"
			|| getFileFormat(urlLine) == "css") {
		std::string outputFile = getPage(urlLine);
		if (outputFile != "") {
			char *cstr = new char[outputFile.length() + 1];
			strcpy(cstr, outputFile.c_str());
			return cstr;
		}
	}
	return Handler::doHandle(aRequest);
}

std::string TextHandler::getFileFormat(const std::string &path) {
	int pos = path.find('.');
	return path.substr(pos, path.length() - pos);
}

std::string TextHandler::getPage(const std::string &root) {
	std::string page;
	std::string file = root;
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
