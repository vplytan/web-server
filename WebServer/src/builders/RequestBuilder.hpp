/*
 * RequestBuilder.hpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */
#include "Request.hpp"

#include <stdio.h>
#include <iostream>

using namespace std;

class RequestBuilder {
public:
	RequestBuilder(char* request);
	Request* build();
private:
	Request* _request;
	char *_buffer;

	char *get_path();
	const char *get_content_type(const std::string &content);
	std::map<std::string, std::string> get_headers();
	std::string get_http_method(const std::string &str);
	std::string get_http_version(const std::string &str);
	std::string get_url(const std::string &str);
	std::string extract(const std::string &str, const std::string &start,
			const std::string &end);
};

RequestBuilder::RequestBuilder(char* request) {
	_request = new Request();
	_buffer = request;
}

Request* RequestBuilder::build() {
	_request->set_absolute_path(get_path());
	_request->set_content_type(get_content_type(get_path()));
	//	_request.set_headers(get_headers());
	_request->set_http_method(get_http_method(_buffer));
	_request->set_http_version(get_http_version(_buffer));
//	_request.set_url(get_url(_buffer));
	return _request;
}

char *RequestBuilder::get_path() {
	char* path = new char[100];
	sscanf(_buffer, "GET %s HTTP", path);
	printf("In request builder - Path: \"%s\"\n", path);
	return path;
}

const char* RequestBuilder::get_content_type(const std::string &content) {
	std::map<std::string, std::string> contentType;
	std::map<std::string, std::string>::iterator it;
	contentType.insert(make_pair("html", "text/html"));
	contentType.insert(make_pair("htm", "text/htm"));
	contentType.insert(make_pair("jpeg", "image/jpeg"));
	contentType.insert(make_pair("jpg", "image/jpg"));
	contentType.insert(make_pair("ico", "image/ico"));
	contentType.insert(make_pair("png", "image/png"));
	contentType.insert(make_pair("gif", "image/gif"));
	contentType.insert(make_pair("css", "text/css"));
	contentType.insert(make_pair("js", "application/x-javascript"));
	contentType.insert(make_pair("mp3", "audio/mpeg"));
	contentType.insert(make_pair("zip", "application/zip"));
	contentType.insert(make_pair("rar", "application/x-rar-compressed"));

	unsigned found = content.find_last_of(".");
	std::string fileNameExtension = content.substr(found + 1, content.length());

	cout << "(in request builder) - fileNameExtension - " << fileNameExtension
			<< endl;
	it = contentType.find(fileNameExtension);
	std::string type = "Content-Type: " + it->second;
	return type.c_str();
}

std::map<std::string, std::string> RequestBuilder::get_headers() {
	map<std::string, std::string> headers;
	return headers;
}
std::string RequestBuilder::get_http_method(const std::string &str) {
	unsigned pos = str.find(" ");
	std::string res = (str.substr(0, pos));
	cout << " method = " << res << endl;
	return res;
}
std::string RequestBuilder::get_http_version(const std::string &str) {
	std::string res = extract(str, "HTTP/", "\n");
	cout << " version = " << res << endl;
	return res;
}
std::string RequestBuilder::get_url(const std::string &str) {
	std::string res = extract(str, "Referer:", "\n");
	cout << " url = " << res << endl;
	return res;
}
std::string RequestBuilder::extract(const std::string &str,
		const std::string &start, const std::string &end) {
	int s = str.find(start) + start.length();
	std::string new_str = str.substr(s, str.length() - s);
	int e = new_str.find(end) + str.length() - new_str.length();
	int len = e - s;
	cout << "     LEN = " << len << endl;
	return str.substr(s, len);
}

