#include <iostream>

#include "intfopcua.h"
#include "intfjson.h"
#include "getdata.h"

using namespace std;

CGetData::CGetData(const string p_sArgs)
{
    // read the configuration file and create the parameter list
    CInterfaceJson intfJson(p_sArgs.c_str());
    intfJson.getParameterList(m_MapParameterList);

    // get the servr name
    m_sServerName = intfJson.getServerName();
};

CGetData::~CGetData()
{};

void CGetData::FromServer()
{
    // connect to the server
    CInterfaceOpcUA intfOpcUA(m_sServerName.c_str());

    // get all values from server
    for (auto iterM = m_MapParameterList.begin();
         iterM != m_MapParameterList.end(); ++iterM)
    {
        if ("int32" == iterM->first)
        {
            for (auto iterV = iterM->second.begin();
                 iterV != iterM->second.end(); ++iterV)
            {
                cout << intfOpcUA.getInt32(1, iterV->first.c_str()) << endl;
            }
        }
    }
};
