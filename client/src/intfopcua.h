#include "open62541.h"

#ifndef INTFOPCUA_H
#define INTFOPCUA_H

class CInterfaceOpcUA
{
public:
	CInterfaceOpcUA(const char *p_ServerName);
	~CInterfaceOpcUA();

	int32_t getInt32(const int16_t p_iNamespaceIndex, const char *p_ID);
	void getValue(const UA_Int16 *p_iNamespaceIndex, const char *p_ID, UA_Variant *p_Return);

private:
	char *m_pServerName;
	UA_Client *m_pClient;
};

#endif
