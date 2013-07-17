/*
 * IObserver.hpp
 *
 *  Created on: Jul 10, 2013
 *      Author: vplytan
 */
#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP
class IOnConfigurationChangeListener {
public:
	virtual void port_changed(int newPort) = 0;
};
#endif
