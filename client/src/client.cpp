#include <iostream>
#include "intfopcua.h"
#include "intfjson.h"

int main(void)
{
	// read the configuration file
	CInterfaceJson  intfJson("../cfg/configuration.json");

	// connect to the server
	CInterfaceOpcUA intfOpcUA(intfJson.getServerName().c_str());

	// create the parameter list
	std::map< std::string, std::vector<std::string> > MapParameterList;
	intfJson.getParameterList(MapParameterList);

	// create paramater list iterator
	std::map< std::string, std::vector<std::string> >::iterator
		   iterM = MapParameterList.begin();

	// get all values from server
	for (;iterM != MapParameterList.end(); ++iterM)
	{
		if ("int32" == iterM->first)
		{
			std::vector<std::string>::iterator iterV = iterM->second.begin();

			for (; iterV != iterM->second.end(); ++iterV)
			{
				std::cout << intfOpcUA.getInt32(1, iterV->c_str()) << std::endl;
			}
		}
	}

	return 0;
}
