/*
 * ErrorHandler.cpp
 *
 *  Created on: Jul 11, 2013
 *      Author: vplytan
 */

#include "Handler.hpp"


class ErrorHandler: public Handler {
public:
	Response* do_handle(Request* aRequest);
private:
	std::string _errorPage;
};

