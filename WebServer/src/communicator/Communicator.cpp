/*
 * Communicator.cpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */

#include "Communicator.hpp"
#include "../configurator/Configurator.hpp"

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
#include <fstream>
#include <pthread.h>

#define	MY_PORT		9999
#define MAXNAME	25
#define MAXPATH	150
#define PERROR(msg)	{ perror(msg); abort(); }
#define MAXBUF	1024

char buffer[MAXBUF];

using namespace std;

Communicator* Communicator::_instance = NULL;
Configurator* _configurator;
char *Host = new char[20];

std::string getSimplePage() {
	std::string page;
	ifstream pageFile("../WebServer/res/login_pg.html");
	string line;
	if (pageFile.is_open()) {
		while (pageFile.good()) {
			getline(pageFile, line);
			page.append(line);
		}
		pageFile.close();
	} else {
		cout << "Unable to open file";
	}
	return page;
}

void DirListing(FILE* FP, char* request) {
	fprintf(FP, getSimplePage().c_str());
}

Communicator* Communicator::getInstance() {
	if (!_instance) {
		_instance = new Communicator();
	}
	return _instance;
}

void* thread_t(void* unused) {
	string host;
	host.append(_configurator->getParameter("ip"));
	host.append(":");
	host.append(_configurator->getParameter("port"));
	strcpy(Host, host.c_str());
	struct sockaddr_in addr;
	int sd, addrlen = sizeof(addr);

	if ((sd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
		perror("Socket");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(MY_PORT);
	addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sd, (struct sockaddr*) &addr, addrlen) < 0)
		perror("Bind");
	if (listen(sd, 20) < 0)
		perror("Listen");
	while (1) {
		int len;
		int client =
				accept(sd, (struct sockaddr*) &addr, (socklen_t*) &addrlen);
		printf("Connected: %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(
				addr.sin_port));

		if ((len = recv(client, buffer, MAXBUF, 0)) > 0) {
			cout << "--------------start buffer-----------------" << endl;
			cout << buffer << endl;
			cout << "--------------end buffer-----------------" << endl;
			FILE* ClientFP = fdopen(client, "w");
			if (ClientFP == NULL)
				perror("fpopen");
			else {
				char Req[MAXPATH];
				sscanf(buffer, "GET %s HTTP", Req);
				printf("Request: \"%s\"\n", Req);
				DirListing(ClientFP, Req);
				fclose(ClientFP);
			}
		}
		close(client);
	}
	return NULL;
}

void Communicator::startListening() {
	cout << "Communicator::startListening()" << endl;
	cout << "\t port = " << _port << endl;
	_isWorking = true;
	pthread_t thread_id;
	int i = pthread_create(&thread_id, NULL, &thread_t, NULL);
	pthread_join(thread_id, NULL);
}

void Communicator::stopListening() {
	cout << "Communicator::stopListening()" << endl;

}

void Communicator::reboot() {
	cout << "Communicator::reboot(int portNumber)" << endl;
	cout << "\t port = " << _port << endl;

}

void Communicator::setPort(int portNumber) {
	cout << "Communicator::setPort(int portNumber) = " << portNumber << endl;
	_port = portNumber;
}

Communicator::Communicator() {
	cout << "Communicator::Communicator()" << endl;
	_isWorking = false;
	_configurator = Configurator::getInstance();
	_configurator->setListener(this);
	setPort(_configurator->getPort());
}

void Communicator::portChanged(int newPort) {
	setPort(newPort);
	reboot();
}
