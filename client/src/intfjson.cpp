#include <stdio.h>
#include <iostream>
#include <string>
#include "intfjson.h"
#include <cstring>

using namespace std;

extern "C" {
	static json_c_visit_userfunc find_object;
}


CInterfaceJson::CInterfaceJson(const string p_pFileName)
{
	m_pJsonConfigFile = json_object_from_file(p_pFileName.c_str());
}

CInterfaceJson::~CInterfaceJson()
{}

std::string CInterfaceJson::getServerName()
{
	std::string sResult;
	if (NULL != m_pJsonConfigFile)
	{
		struct JsonData data("server_name");

		// get the json object with the according tag name
		int iReturn = json_c_visit(m_pJsonConfigFile, 0, find_object, &data);

		// get the value
		if (NULL != data.pJsonObject_OUT)
			sResult = std::string( json_object_get_string(data.pJsonObject_OUT) );
	}
	return sResult;
}

void CInterfaceJson::getParameterList(std::map< std::string, std::vector<std::string> > &p_ParameterList)
{
	if (NULL != m_pJsonConfigFile)
	{
		struct JsonData data("server_values");

		// get the json object with the according tag name
		int iReturn = json_c_visit(m_pJsonConfigFile, 0, find_object, &data);

		// get the value
		if (NULL != data.pJsonObject_OUT &&
			json_object_is_type(data.pJsonObject_OUT, json_type_array))
		{
			// iterate through the array, get all values and add
			// them to the according map element
			size_t iSize = json_object_array_length(data.pJsonObject_OUT);
			for (size_t i = 0; i<iSize; ++i)
			{
				// get one json object from the array
				struct json_object *obj = json_object_array_get_idx(data.pJsonObject_OUT, i);
			
				if (NULL != obj)
				{
					// get the type
					struct JsonData dataType("type");
					iReturn = json_c_visit(obj, 0, find_object, &dataType);

					// get the value
					struct JsonData dataName("name");
					iReturn = json_c_visit(obj, 0, find_object, &dataName);

					// append/insert the type-value pair
					if (NULL != dataType.pJsonObject_OUT &&
						NULL != dataName.pJsonObject_OUT)
					{
						// get the exiting vector if any
						std::map< std::string, std::vector<std::string> >::iterator
							   	iter = p_ParameterList.find("int32");
						
						// get the server value name
						std::string sName = json_object_get_string(dataName.pJsonObject_OUT);

						if (iter != p_ParameterList.end())
						{
							// append the value to the existing vector
							iter->second.push_back(sName);
						}
						else
						{
							// create a vactor and add the first value
							std::vector< std::string > values;
							values.push_back(sName);

							// insert the new vector
							p_ParameterList.insert(std::make_pair("int32", values));
						}
					}
				}
			}
		}
	}	
}

extern "C" int find_object(json_object *jso, int flags,
 	                       json_object *parent_jso,
	  			           const char *jso_key,
 	   			           size_t *jso_index, void *userarg)
{
	if (NULL != userarg)
	{
		JsonData *data = (JsonData*)userarg;
		if (NULL != data && NULL != jso_key)
		{
			if (!strcmp(data->pTagName_IN, jso_key))
			{
				data->pJsonObject_OUT       = jso;
				data->pJsonParentObject_OUT = parent_jso;
				return JSON_C_VISIT_RETURN_STOP;
			}
		}
	}
	return JSON_C_VISIT_RETURN_CONTINUE;
}

