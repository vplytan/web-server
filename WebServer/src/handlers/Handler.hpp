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
#include "../builders/Response.hpp"

using namespace std;

class Handler {
	Handler *next; // 1. "next" pointer in the base class
public:
	Handler() {
		next = 0;
	}
	void set_next(Handler *n) {
		next = n;
	}
	void add(Handler *n) {
		if (next)
			next->add(n);
		else
			next = n;
	}
	// 2. The "chain" method in the base class always delegates to the next obj
	virtual Response* do_handle(Request* aRequest) {
		return next->do_handle(aRequest);
	}

	std::string get_file_format(const std::string &path);
	std::string get_root();
	std::string get_page(const std::string &root);
	std::string build_status_line(std::string code);
	std::string build_content_type(const std::string &contentType, long pageLength);
};

#endif
