/*
 * Communicator.hpp
 *
 *  Created on: Jul 9, 2013
 *      Author: vplytan
 */

#include "../configurator/IOnConfigurationChangeListener.hpp"

class Communicator: public IOnConfigurationChangeListener {
public:
	void startListening();
	void stopListening();
	static Communicator* getInstance();
	virtual void portChanged(int newPort);

private:
	static Communicator* _instance;
	bool _isWorking;
	int _port;
	Communicator();
	void reboot();
	void setPort(int portNumber);
};
