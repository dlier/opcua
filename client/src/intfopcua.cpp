#include <stdio.h>
#include <iostream>
#include "intfopcua.h"

CInterfaceOpcUA::CInterfaceOpcUA(const string p_ServerName)
{
   	m_pClient = UA_Client_new(UA_ClientConfig_default);
    UA_StatusCode retval = UA_Client_connect(m_pClient, p_ServerName.c_str());
   	
	if(retval != UA_STATUSCODE_GOOD)
   	{
       	UA_Client_delete(m_pClient);
		m_pClient = NULL;
   	}
}


CInterfaceOpcUA::~CInterfaceOpcUA()
{}


int32_t CInterfaceOpcUA::getInt32(const int16_t p_iNamespaceIndex, const string p_ID)
{
	UA_Variant value;
	UA_Variant_init(&value);

	getValue(&p_iNamespaceIndex, p_ID.c_str(), &value);

	return *(int32_t*)value.data;
}


// read int32 value
void CInterfaceOpcUA::getValue(const int16_t *p_iNamespaceIndex, const string p_ID, UA_Variant *p_Return)
{
	if (NULL != m_pClient &&
		NULL != p_iNamespaceIndex &&
	   	NULL != p_Return &&
		!p_ID.empty())
	{
		UA_Variant result;
	    UA_Variant_init(&result);

		const UA_NodeId nodeId = UA_NODEID_STRING(*p_iNamespaceIndex, const_cast<char*>(p_ID.c_str()));
    	UA_StatusCode retval = UA_Client_readValueAttribute(m_pClient, nodeId, &result);

		if(retval == UA_STATUSCODE_GOOD)
		{
    	   	*p_Return = result;
		}
	}
}
