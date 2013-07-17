/*
 * BinaryHandler.hpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */

#include "Handler.hpp"


class BinaryHandler: public Handler {
public:
	Response* do_handle(Request* aRequest);
private:
	long get_file_size(FILE *file);
};
