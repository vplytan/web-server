/*
 * BinaryHandler.hpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */

#include "Handler.hpp"


class BinaryHandler: public Handler {
public:
	char* doHandle(const Request &aRequest);
private:
	long getFileSize(FILE *file);
};
