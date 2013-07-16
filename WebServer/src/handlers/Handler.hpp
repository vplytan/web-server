/*
 * Handler.hpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */

#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <iostream>

#include "../builders/Request.hpp"

using namespace std;

class Handler {
	Handler *next; // 1. "next" pointer in the base class
public:
	Handler() {
		next = 0;
	}
	void setNext(Handler *n) {
		next = n;
	}
	void add(Handler *n) {
		if (next)
			next->add(n);
		else
			next = n;
	}
	// 2. The "chain" method in the base class always delegates to the next obj
	virtual char* doHandle(const Request &aRequest) {
		return next->doHandle(aRequest);
	}

	std::string getFileFormat(const std::string &path);
	std::string getRoot();
	std::string getPage(const std::string &root);
};

#endif
