/*
 * HandlerBuild.hpp
 *
 *  Created on: Jul 11, 2013
 *      Author: vplytan
 */
#ifndef HANDLER_BUILD_HPP
#define HANDLER_BUILD_HPP

#include "../builders/Request.hpp"
#include "../builders/Response.hpp"
#include "../handlers/IndexHandler.hpp"
#include "../handlers/DirectoryHandler.hpp"
#include "../handlers/TextHandler.hpp"
#include "../handlers/BinaryHandler.hpp"
#include "../handlers/ErrorHandler.hpp"
#include "../handlers/Handler.hpp"

#include <iostream>

using namespace std;

class HandlerBuild {
public:
	Response* get_body(Request* aRequest) {
		cout << "in get body" << endl;
		IndexHandler index;
		DirectoryHandler directory;
		TextHandler text;
		BinaryHandler binary;
		ErrorHandler error;
		index.add(&text);
		//	directory.add(&text);
		text.add(&binary);
		binary.add(&error);
		//	error.setNext(&text);
		return index.do_handle(aRequest);
	}
};

#endif
