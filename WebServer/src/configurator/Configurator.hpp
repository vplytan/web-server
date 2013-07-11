/*
 * Configurator.hpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */

#include <map>
#include <string>
#include "IOnConfigurationChangeListener.hpp"

class Configurator {
public:
	static Configurator* getInstance();
	int getPort();
	std::string getInsertions();
	void addNewInsertion(const std::string &newInsertion);
	std::string getParameter(const std::string &parameterName);
	void changeParameter(const std::string &paramName,
			const ::std::string &paramValue);
	void addParameter(const std::string &paramName,
			const ::std::string &paramValue);
	std::map<std::string, std::string> getAllParameters();
	~Configurator();

	void setListener(IOnConfigurationChangeListener *listener);

private:

	IOnConfigurationChangeListener* _observer;

	static Configurator* _instance;
	Configurator();

	void saveConfigurationToFile(
			std::map<std::string, std::string> configuration);
	std::map<std::string, std::string> getConfigurationFromFile();
	std::string getConfigFilePath();

	std::map<std::string, std::string> _configuration;
	std::string _config_file;

};
