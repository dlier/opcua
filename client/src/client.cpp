
extern "C" {
	#include "opcua.h"
}

#include <iostream>

int main(void)
{
	std::cout << "Hallo" << std::endl;

	int iReturn = opcua();
	return 0;
}
