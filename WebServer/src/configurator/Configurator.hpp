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
	static Configurator* get_instance();
	int get_port();
	std::string get_insertions();
	void add_new_insertion(const std::string &newInsertion);
	std::string get_parameter(const std::string &parameterName);
	void change_parameter(const std::string &paramName,
			const ::std::string &paramValue);
	void add_parameter(const std::string &paramName,
			const ::std::string &paramValue);
	std::map<std::string, std::string> get_all_parameters();
	~Configurator();

	void set_listener(IOnConfigurationChangeListener *listener);

private:

	IOnConfigurationChangeListener* _observer;

	static Configurator* _instance;
	Configurator();

	void save_configuration_to_file(
			std::map<std::string, std::string> configuration);
	std::map<std::string, std::string> get_configuration_from_file();
	std::string get_config_file_path();

	std::map<std::string, std::string> _configuration;
	std::string _config_file;

};
