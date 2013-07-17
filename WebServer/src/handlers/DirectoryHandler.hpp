/*
 * DirectoryHandler.hpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */

#ifndef ERROR_HANDLER_HPP
#define ERROR_HANDLER_HPP

#include "Handler.hpp"


class DirectoryHandler: public Handler {
public:
	Response* do_handle(Request* aRequest);
};


#endif
