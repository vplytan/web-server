/*
 * main.cpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */

#include "src/communicator/Communicator.hpp"
#include "src/configurator/Configurator.hpp"

#include <iostream>
#include <fstream>
#include <time.h>
#include <errno.h>

#include "src/handlers/HandlerBuild.hpp"
#include "src/builders/Request.hpp"

using namespace std;

int main() {

	Communicator* communicator = Communicator::getInstance();
	communicator->startListening();


	return 0;
}

