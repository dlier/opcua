#include <iostream>
#include "intfopcua.h"
#include "intfjson.h"

using namespace std;

int main(int argc, char* argv[])
{
	// get the arguments
	// 1st - json configuration file
	vector<string> vArgs(argv+1, argv+argc);

	if (vArgs.size() < 1)
	{
		cout << "missing arguments: client configuration.json" << endl;
		return 0;
	}

	// read the configuration file
	CInterfaceJson intfJson(vArgs[0].c_str());

	// connect to the server
	CInterfaceOpcUA intfOpcUA(intfJson.getServerName().c_str());

	// create the parameter list
	map< string, vector<string> > MapParameterList;
	intfJson.getParameterList(MapParameterList);

	// create paramater list iterator
	map< string, vector<string> >::iterator iterM = MapParameterList.begin();

	// get all values from server
	for (;iterM != MapParameterList.end(); ++iterM)
	{
		if ("int32" == iterM->first)
		{
			vector<string>::iterator iterV = iterM->second.begin();
			for (; iterV != iterM->second.end(); ++iterV)
			{
				cout << intfOpcUA.getInt32(1, iterV->c_str()) << endl;
			}
		}
	}

	return 0;
}
