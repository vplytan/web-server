/*
 * Handler.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "Handler.hpp"
#include "../configurator/Configurator.hpp"

using namespace std;

std::string Handler::get_file_format(const std::string &path) {
	int pos = path.find('.');
	return path.substr(pos, path.length() - pos);
}

std::string Handler::get_root() {
	return Configurator::get_instance()->get_parameter("root");
}

std::string Handler::get_page(const std::string &page_root) {
	std::string page;
	std::string file = get_root();
	file.append(page_root);
	ifstream pageFile(file.c_str());
	string line;
	if (pageFile.is_open()) {
		while (getline(pageFile, line)) {
			page.append(line);
		}
		pageFile.close();
	} else {
		cout << "Unable to open file";
	}
	return page;
}

std::string Handler::build_status_line(std::string code) {
	std::string type_http = "HTTP/1.1 ";
	type_http.append(code + "\n");
	return type_http;
}

std::string Handler::build_content_type(const std::string &contentType,
		const long pageLength) {
	std::string content_type = contentType + "\n";
	content_type.append("Content-Length: ");

	std::stringstream ss;
	long num = pageLength;
	ss << num;
	std::string s(ss.str());

	content_type.append(s + "\n");
	return content_type;
}
