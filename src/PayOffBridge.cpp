/*
 * PayOffBridge.cpp
 *
 *  Created on: 8 May 2016
 *      Author: Michael
 */

#include "PayOffBridge.h"

PayOffBridge::PayOffBridge(const PayOffBridge& original) {
	ThePayOffPtr = original.ThePayOffPtr->clone();
}

PayOffBridge::~PayOffBridge() {
	delete ThePayOffPtr;
}

PayOffBridge::PayOffBridge(const PayOff& innerPayOff) {
	ThePayOffPtr = innerPayOff.clone();
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original)
{
	if (this!= &original)
	{
		delete ThePayOffPtr;
		ThePayOffPtr = original.ThePayOffPtr->clone();
	}
	return *this;
}
