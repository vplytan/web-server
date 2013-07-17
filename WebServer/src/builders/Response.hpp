/*
 * Response.hpp
 *
 *  Created on: Jul 10, 2013
 *      Author: vplytan
 */
#ifndef RESPONSE_HPP
#define RESPONSE_HPP

class Response {
public:
	Response(char* response) {
		_response = response;
	}
	char* get_response() {
		return _response;
	}
	int get_head_length() {
		return sizeof(_response) / sizeof(*_response);
	}
private:
	char* _response;
};
#endif
