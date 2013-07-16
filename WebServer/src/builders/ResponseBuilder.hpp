/*
 * ResponseBuilder.hpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ResponseBuilder {
public:

private:
	std::string build_status_line(std::string code) {
		std::string type_http = "HTTP/1.1 ";
		return type_http.append("200 OK\r\n");
	}

	std::string get_content_type(std::string content) {
		std::map<std::string, std::string> contentType;
		std::map<std::string, std::string>::iterator it;
		contentType.insert(make_pair("html", "text/html"));
		contentType.insert(make_pair("html", "text/html"));
		contentType.insert(make_pair("htm", "text/htm"));
		contentType.insert(make_pair("jpeg", "image/jpeg"));
		contentType.insert(make_pair("jpg", "image/jpg"));
		contentType.insert(make_pair("png", "image/png"));
		contentType.insert(make_pair("gif", "image/gif"));
		contentType.insert(make_pair("css", "text/css"));
		contentType.insert(make_pair("js", "application/x-javascript"));
		contentType.insert(make_pair("mp3", "audio/mpeg"));
		contentType.insert(make_pair("zip", "application/zip"));
		contentType.insert(make_pair("rar", "application/x-rar-compressed"));

		unsigned found = str.find_last_of(".");
		std::string fileNameExtension = str.substr(found + 1);

		cout << "(in response builder) - fileNameExtension - "
				<< fileNameExtension << endl;
		it = contentType.find(fileNameExtension);

		return "Content-Type: " + it->second;
	}
};
