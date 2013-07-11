/*
 * Handler.hpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */

#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "../builders/Request.hpp"

class Handler {
public:
	Handler();
	Handler(const Handler &aHandler);
	char* doHandle(const Request &aRequest);
private:
	Handler* _handler;
};
Handler::Handler(){
	// pattern don't need this, it's only for HandlerBuild
}
Handler::Handler(const Handler &aHandler) {
	*_handler = aHandler;
}

char* Handler::doHandle(const Request &aRequest) {
	if (_handler) {
		return _handler->doHandle(aRequest);
	} else {
		return NULL;
	}
}
#endif
