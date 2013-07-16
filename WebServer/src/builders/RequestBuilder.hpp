/*
 * RequestBuilder.hpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */
#define MAXBUF	1024

#include "../handlers/HandlerBuild.hpp"
#include "Request.hpp"

#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>

using namespace std;

class RequestBuilder {
public:
	RequestBuilder(int client);
	Request build();
	char *proceed();
private:
	Request _request;
	int _client;
	char *_buffer;

	char *getPath();
	std::string extract(const std::string &str, const std::string &start,
			const std::string &end);
};

RequestBuilder::RequestBuilder(int client) {
	_client = client;
	_buffer = new char[MAXBUF];
	int len;
	if ((len = recv(client, _buffer, MAXBUF, 0)) > 0) {
	}
}

Request RequestBuilder::build() {
	_request.setAbsolutePath(getPath());

	return _request;
}

char *RequestBuilder::getPath() {
	char* path = new char[100];
	sscanf(_buffer, "GET %s HTTP", path);
	printf("Path: \"%s\"\n", path);
	return path;
}

char *RequestBuilder::proceed() {
	HandlerBuild hb = HandlerBuild();

	return hb.getBody(_request);
}

