/*
 * RequestManager.hpp
 *
 *  Created on: Jul 16, 2013
 *      Author: vplytan
 */
#include "Request.hpp"
#include "RequestBuilder.hpp"
#include "Response.hpp"
#include "../handlers/HandlerBuild.hpp"

class RequestManager {
public:
	RequestManager() {
		_hb = new HandlerBuild();
	}

	char* process_request(char* request) {
		_requestBuilder = new RequestBuilder(request);
		_request = _requestBuilder->build();
		_response = _hb->get_body(_request);
		return _response->get_response();
	}

private:
	Request* _request;
	Response* _response;
	RequestBuilder* _requestBuilder;
	HandlerBuild* _hb;
};
