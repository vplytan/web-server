/*
 * Communicator.hpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */

#include "../configurator/IOnConfigurationChangeListener.hpp"

class Communicator: public IOnConfigurationChangeListener {
public:
	void start_listening();
	void stop_listening();
	static Communicator* get_instance();
	virtual void port_changed(int newPort);

private:
	static Communicator* _instance;
	bool _isWorking;
	int _port;
	Communicator();
	void reboot();
	void set_port(int portNumber);
};
