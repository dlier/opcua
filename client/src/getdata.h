#pragma once
#ifndef GETDATA_H
#define GETDATA_H

#include <vector>
#include <string>
#include <map>

using namespace std;


class CGetData
{
public:
    CGetData(const string p_sArgs);
    ~CGetData();

    void FromServer();

private:
    CGetData() {};
    map<string, vector<pair<string, unsigned int> > > m_MapParameterList;
    string m_sServerName;
};

#endif
