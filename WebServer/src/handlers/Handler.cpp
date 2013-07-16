/*
 * Handler.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */
#include <fstream>
#include <iostream>
#include <string.h>

#include "Handler.hpp"
#include "../configurator/Configurator.hpp"

using namespace std;

std::string Handler::getFileFormat(const std::string &path) {
	int pos = path.find('.');
	return path.substr(pos, path.length() - pos);
}

std::string Handler::getRoot() {
	return Configurator::getInstance()->getParameter("root");
}

std::string Handler::getPage(const std::string &page_root) {
	std::string page;
	std::string file = getRoot();
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

