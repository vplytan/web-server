/*
 * Configurator.cpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */

#include "Configurator.hpp"
#include "IOnConfigurationChangeListener.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Configurator* Configurator::_instance = NULL;
Configurator* Configurator::getInstance() {
	if (!_instance) {
		_instance = new Configurator();
	}
	return _instance;
}

void Configurator::addNewInsertion(const string &newInsertion) {
	std::string currentInsertions = getParameter("insertions");
	std::size_t found = currentInsertions.find(newInsertion);
	if (found != std::string::npos) {
		std::cout << "we already have this insertion" << endl;
		return;
	}
	currentInsertions.append(" ");
	currentInsertions.append(newInsertion);
	changeParameter("insertions", currentInsertions);
}

void Configurator::addParameter(const string &paramName,
		const string &paramValue) {
	_configuration.insert(make_pair(paramName, paramValue));
}

void Configurator::changeParameter(const string &paramName,
		const string &paramValue) {
	std::map<std::string, std::string>::iterator it = _configuration.find(
			paramName);
	if (it != _configuration.end()) {
		it->second = paramValue;
	}
	if (paramName == "port") {
		int port;
		istringstream(paramValue) >> port;
		_observer->portChanged(port);
	}
}

map<std::string, std::string> Configurator::getAllParameters() {
	return _configuration;
}

std::string Configurator::getInsertions() {
	return getParameter("insertions");
}

std::string Configurator::getParameter(const string &parameterName) {
	map<std::string, std::string>::const_iterator pos = _configuration.find(
			parameterName);
	if (pos != _configuration.end()) {
		return pos->second;
	}
	return "no such parameter";
}

int Configurator::getPort() {
	string str_port = getParameter("port");
	int port;
	istringstream(str_port) >> port;
	return port;
}

Configurator::Configurator() {
	_configuration = getConfigurationFromFile();
}

Configurator::~Configurator() {
	saveConfigurationToFile(_configuration);
}

std::map<std::string, std::string> Configurator::getConfigurationFromFile() {

	map<std::string, std::string> configuration;
	std::string delimiter = "\t";
	string line;
	ifstream configFile(getConfigFilePath().c_str());
	if (configFile.is_open()) {
		while (configFile.good()) {
			getline(configFile, line);
			size_t pos = 0;
			std::string tokenF;
			std::string tokenS;
			while ((pos = line.find(delimiter)) != std::string::npos) {
				tokenF = line.substr(0, pos);
				tokenS = line.substr(pos + delimiter.length(), line.length());
				configuration.insert(make_pair(tokenF, tokenS));
				break;
			}
		}
		configFile.close();
	} else {
		cout << "Unable to open file";
	}
	return configuration;
}
void Configurator::saveConfigurationToFile(
		std::map<std::string, std::string> configuration) {
	ofstream configFile;
	configFile.open(getConfigFilePath().c_str());
	typedef std::map<std::string, std::string>::iterator it_type;
	for (it_type iterator = configuration.begin(); iterator
			!= configuration.end(); iterator++) {
		configFile << iterator->first << "\t" << iterator->second << endl;
	}
	configFile.close();
}

std::string Configurator::getConfigFilePath() {
	return "../WebServer/config.xml";
}

void Configurator::setListener(IOnConfigurationChangeListener *listener) {
	_observer = listener;
}
