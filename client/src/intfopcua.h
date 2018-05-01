#include "open62541.h"
#include <string>

using namespace std;

#ifndef INTFOPCUA_H
#define INTFOPCUA_H

class CInterfaceOpcUA
{
public:
	CInterfaceOpcUA(const string p_ServerName);
	~CInterfaceOpcUA();

	int32_t getInt32(const int16_t p_iNamespaceIndex, const string p_ID);
	void getValue(const UA_Int16 *p_iNamespaceIndex, const string p_ID, UA_Variant *p_Return);

private:
	UA_Client *m_pClient;
};

#endif
