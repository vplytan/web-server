/*
 * BinaryHandler.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: vplytan
 */

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "BinaryHandler.hpp"

using namespace std;

long BinaryHandler::get_file_size(FILE *file) {
	long lCurPos, lEndPos;
	lCurPos = ftell(file);
	fseek(file, 0, 2);
	lEndPos = ftell(file);
	fseek(file, lCurPos, 0);
	return lEndPos;
}

Response* BinaryHandler::do_handle(Request* aRequest) {
	std::string urlLine = aRequest->get_absolute_path();
	if (get_file_format(urlLine) == ".png" || get_file_format(urlLine)
			== ".jpg" || get_file_format(urlLine) == ".ico") {
		cout << "binaryHandler handle ressssss" << endl;

		//	const char *filePath = (get_root() + urlLine).c_str();
		const char *filePath = "../WebServer/res/favicon.ico";

		cout << "filePath :" << filePath << endl;
		char *fileBuf; // Pointer to our buffered data
		FILE *file = fopen(filePath, "rb"); // File pointer

		if (file == NULL)
			cout << "Could not open specified file" << endl;
		else
			cout << "File opened successfully" << endl;

		long fileSize = get_file_size(file);
		cout << "File size : " << fileSize << endl;

		fileBuf = new char[fileSize];
		cout << "File buf " << endl;

		fread(fileBuf, fileSize, 1, file);
		//fread(fileBuf, sizeof(char), fileSize, file);
		cout << "Fread " << endl;

		//	delete[] fileBuf;
		fclose(file); // Almost forgot this
		cout << "fclose " << endl;

		std::string statusLine = build_status_line("200 OK");
		char *statusLineC = new char[statusLine.length() + 1];
		strcpy(statusLineC, statusLine.c_str());
		std::string contentType = build_content_type(
				aRequest->get_content_type(), fileSize);
		char *contentTypeC = new char[contentType.length() + 1];
		strcpy(contentTypeC, contentType.c_str());

		int responseSize = statusLine.length() + contentType.length()
				+ fileSize;
		char* response = new char[responseSize];

		memcpy(response, statusLineC, statusLine.length());
		memcpy(response + statusLine.length(), contentTypeC,
				contentType.length());
		memcpy(response + statusLine.length() + contentType.length(), fileBuf,
				fileSize);

		cout << "\n========== response ==============\n";
		for (int i = 0; i < responseSize; i++) {
			cout << response[i];
		}
		cout << "\n========== response ==============\n";

		return new Response(response);
	} else {
		cout << "binaryHandler pass " << "  ";
		return Handler::do_handle(aRequest);
	}
}

