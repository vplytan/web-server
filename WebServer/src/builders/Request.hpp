/*
 * Request.hpp
 *
 *  Created on: Jul 10, 2013
 *      Author: vplytan
 */

#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <map>
#include <string>
#include <iostream>

using namespace std;

class Request {
private:
	std::string _httpMethod;
	std::string _httpVersion;
	std::string _absolutePath;
	std::string _url;
	std::string _contentType;
	std::map<std::string, std::string> _headers;
	bool _adminError;
	bool _isAdmin;
	std::map<std::string, std::string> _queryString;
	std::map<std::string, std::string> _cookies;
public:
	std::string get_absolute_path() const {
		return _absolutePath;
	}
	bool get_admin_error() {
		return _adminError;
	}
	std::string get_content_type() {
		return _contentType;
	}
	std::map<std::string, std::string> get_headers() {
		return _headers;
	}
	std::string get_http_method() {
		return _httpMethod;
	}
	std::string get_http_version() {
		return _httpVersion;
	}
	std::string get_url() {
		return _url;
	}
	void set_absolute_path(std::string absolutePath) {
		_absolutePath = absolutePath;
	}
	void set_content_type(std::string contentType) {
		_contentType = contentType;
	}
	void set_headers(std::map<std::string, std::string> headers) {
		_headers = headers;
	}
	void set_http_method(std::string httpMethod) {
		_httpMethod = httpMethod;
	}
	void set_http_version(std::string httpVersion) {
		_httpVersion = httpVersion;
	}
	void set_url(std::string url) {
		_url = url;
	}

	/*
	 std::map<std::string, std::string> getCookies() const;

	 void setAdminError(bool _adminError);
	 bool getIsAdmin() const;
	 std::map<std::string, std::string> getQueryString() const;
	 void setCookies(std::map<std::string, std::string> _cookies);
	 void setIsAdmin(bool _isAdmin);
	 void setQueryString(std::map<std::string, std::string> _queryString);
	 */
};

#endif
