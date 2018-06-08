#pragma once
#ifndef INTJSON_H
#define INTJSON_H

#include <map>
#include <vector>
#include <string>

extern "C" {
	#include "json.h"
	#include "json_visit.h"
}

using namespace std;


struct JsonData
{
    const char  *pTagName_IN;
	json_object *pJsonObject_OUT;
	json_object *pJsonParentObject_OUT;

	JsonData(const char *p_pTagName)
	{
		pTagName_IN           = p_pTagName;
		pJsonObject_OUT       = NULL;
		pJsonParentObject_OUT = NULL;
 	}
};


class CInterfaceJson
{
public:
	CInterfaceJson(const string p_pFileName);
	~CInterfaceJson();

	string getServerName();
	void getParameterList(map<string, vector<pair<string, unsigned int> > > &p_ParameterList);

private:
	json_object *m_pJsonConfigFile;
};

#endif
