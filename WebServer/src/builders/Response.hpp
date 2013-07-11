/*
 * Response.hpp
 *
 *  Created on: Jul 10, 2013
 *      Author: vplytan
 */

class Response {
private:
	byte *_response[];
public:
	byte getResponse() const;
	void setResponse(byte _response[]);
	int getHeadLength() const;
};

byte Response::getResponse() const {
	return _response;
}

void Response::setResponse(byte _response[]) {
	this->_response = _response;
}

int Response::getHeadLength() const {
	return sizeof(_response) / sizeof(*_response);
}

