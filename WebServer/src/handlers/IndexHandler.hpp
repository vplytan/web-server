/*
 * IndexHandler.hpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */

#include "../builders/Request.hpp"
#include "Handler.hpp"

class IndexHandler: public Handler {
public:
	Response* do_handle(Request* aRequest);
};
