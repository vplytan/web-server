/*
 * HandlerBuild.hpp
 *
 *  Created on: Jul 11, 2013
 *      Author: vplytan
 */

#include "../builders/Request.hpp"
#include "../handlers/TextHandler.hpp"
#include "../handlers/ErrorHandler.hpp"
#include "../handlers/Handler.hpp"


class HandlerBuild {
public:
	char* getBody(const Request &aRequest);
};

char* HandlerBuild::getBody(const Request &aRequest) {
	Handler null;
	Handler errorHandler = ErrorHandler(null);
	Handler textHandler = TextHandler(errorHandler);
	char* buf = textHandler.doHandle(aRequest);
	return buf;
}
