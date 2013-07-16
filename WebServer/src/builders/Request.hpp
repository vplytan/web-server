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

using namespace std;

class Request {
private:
	std::string _httpMethod;
	std::string _httpVersion;
	std::string _absolutePath;
	std::string _url;
	std::string _contentType;
	std::map<std::string, std::string> _queryString;
	std::map<std::string, std::string> _cookies;
	std::map<std::string, std::string> _headers;
	bool _adminError;
	bool _isAdmin;
public:
	std::string getAbsolutePath() const {
		return _absolutePath;
	}
	void setAbsolutePath(std::string _absolutePath) {
		this->_absolutePath = _absolutePath;
	}
	/*
	 bool getAdminError() const;
	 std::string getContentType() const;
	 std::map<std::string, std::string> getCookies() const;
	 std::map<std::string, std::string> getHeaders() const;
	 std::string getHttpMethod() const;
	 std::string getHttpVersion() const;
	 bool getIsAdmin() const;
	 std::map<std::string, std::string> getQueryString() const;
	 std::string getUrl() const;
	 void setAdminError(bool _adminError);
	 void setContentType(std::string _contentType);
	 void setCookies(std::map<std::string, std::string> _cookies);
	 void setHeaders(std::map<std::string, std::string> _headers);
	 void setHttpMethod(std::string _httpMethod);
	 void setHttpVersion(std::string _httpVersion);
	 void setIsAdmin(bool _isAdmin);
	 void setQueryString(std::map<std::string, std::string> _queryString);
	 void setUrl(std::string _url);
	 */
};

/*
 bool Request::getAdminError() const {
 return _adminError;
 }

 std::string Request::getContentType() const {
 return _contentType;
 }

 std::map<std::string, std::string> Request::getCookies() const {
 return _cookies;
 }

 std::map<std::string, std::string> Request::getHeaders() const {
 return _headers;
 }

 std::string Request::getHttpMethod() const {
 return _httpMethod;
 }

 std::string Request::getHttpVersion() const {
 return _httpVersion;
 }

 bool Request::getIsAdmin() const {
 return _isAdmin;
 }

 std::map<std::string, std::string> Request::getQueryString() const {
 return _queryString;
 }

 std::string Request::getUrl() const {
 return _url;
 }


 void Request::setAdminError(bool _adminError = false) {
 this->_adminError = _adminError;
 }

 void Request::setContentType(std::string _contentType) {
 this->_contentType = _contentType;
 }

 void Request::setCookies(std::map<std::string, std::string> _cookies) {
 this->_cookies = _cookies;
 }

 void Request::setHeaders(std::map<std::string, std::string> _headers) {
 this->_headers = _headers;
 }

 void Request::setHttpMethod(std::string _httpMethod) {
 this->_httpMethod = _httpMethod;
 }

 void Request::setHttpVersion(std::string _httpVersion) {
 this->_httpVersion = _httpVersion;
 }

 void Request::setIsAdmin(bool _isAdmin = false) {
 this->_isAdmin = _isAdmin;
 }

 void Request::setQueryString(std::map<std::string, std::string> _queryString) {
 this->_queryString = _queryString;
 }

 void Request::setUrl(std::string _url) {
 this->_url = _url;
 }
 */
#endif
