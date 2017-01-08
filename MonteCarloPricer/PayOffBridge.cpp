#include "stdafx.h"
#include "PayOffBridge.h"


PayOffBridge::PayOffBridge(const PayOffBridge& original)
{
	payOff = original.payOff->clone();
}


PayOffBridge::PayOffBridge(const PayOff& innerPayOff)
{
	payOff = innerPayOff.clone();
}


PayOffBridge::~PayOffBridge()
{
	delete payOff;
}


PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original)
{
	if (this != &original)
	{
		delete payOff;
		payOff = original.payOff->clone();
	}

	return *this;
}