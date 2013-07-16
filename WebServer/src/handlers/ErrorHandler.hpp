/*
 * ErrorHandler.cpp
 *
 *  Created on: Jul 11, 2013
 *      Author: vplytan
 */

#include "Handler.hpp"


class ErrorHandler: public Handler {
public:
	char* doHandle(const Request &aRequest);
private:
	std::string _errorPage;
};

