/*
 * Communicator.cpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */

#include "Communicator.hpp"
#include "../configurator/Configurator.hpp"
#include "../builders/RequestManager.hpp"

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
#define MAXBUF	1024

using namespace std;

Communicator* Communicator::_instance = NULL;
Configurator* _configurator;
char *Host = new char[20];

Communicator* Communicator::get_instance() {
	if (!_instance) {
		_instance = new Communicator();
	}
	return _instance;
}
void* handle_request(void *client) {
	RequestManager *requestManager = new RequestManager();
	char *buffer = new char[MAXBUF];

	recv((int) client, buffer, MAXBUF, 0);
	char *response = requestManager->process_request(buffer);

	cout << endl;
	cout << "response  ---------------------" << endl;
	cout << response << endl;
	cout << "response  ---------------------" << endl;

	FILE* ClientFP = fdopen((int) client, "w");
	fprintf(ClientFP, response);
	fclose(ClientFP);
	close((int) client);
	return 0;
}

void* wait_for_client(void* unused) {
	string host;
	host.append(_configurator->get_parameter("ip"));
	host.append(":");
	host.append(_configurator->get_parameter("port"));
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
		int client =
				accept(sd, (struct sockaddr*) &addr, (socklen_t*) &addrlen);
		printf("Connected: %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(
				addr.sin_port));
		pthread_t client_thread_id;
		pthread_create(&client_thread_id, NULL, &handle_request,
				(void *) client);
		pthread_join(client_thread_id, NULL);

	}
	return NULL;
}

void Communicator::start_listening() {
	cout << "Communicator::startListening()" << endl;
	cout << "\t port = " << _port << endl;
	_isWorking = true;

	pthread_t thread_id;
	pthread_create(&thread_id, NULL, &wait_for_client, NULL);
	pthread_join(thread_id, NULL);
}

void Communicator::stop_listening() {
	cout << "Communicator::stopListening()" << endl;

}

void Communicator::reboot() {
	cout << "Communicator::reboot(int portNumber)" << endl;
	cout << "\t port = " << _port << endl;

}

void Communicator::set_port(int portNumber) {
	cout << "Communicator::setPort(int portNumber) = " << portNumber << endl;
	_port = portNumber;
}

Communicator::Communicator() {
	cout << "Communicator::Communicator()" << endl;
	_isWorking = false;
	_configurator = Configurator::get_instance();
	_configurator->set_listener(this);
	set_port(_configurator->get_port());
}

void Communicator::port_changed(int newPort) {
	set_port(newPort);
	reboot();
}
