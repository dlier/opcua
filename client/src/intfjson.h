#include <map>
#include <vector>
#include <string>

extern "C" {
	#include "json.h"
	#include "json_visit.h"
}

using namespace std;

#ifndef INTFJSON_H
#define INTFJSON_H

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

	std::string getServerName();
	void getParameterList(std::map< std::string, std::vector<std::string> > &p_ParameterList);

private:
	json_object *m_pJsonConfigFile;
};

#endif
