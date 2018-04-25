#include <stdio.h>
#include "open62541.h"


int opcua()
{
    UA_Client *client = UA_Client_new(UA_ClientConfig_default);
    UA_StatusCode retval = UA_Client_connect(client, "opc.tcp://localhost:4840");

    if(retval != UA_STATUSCODE_GOOD)
    {
        UA_Client_delete(client);
        return (int)retval;
    }

    /* Read the value attribute of the node. UA_Client_readValueAttribute is a
     * wrapper for the raw read service available as UA_Client_Service_read. */

    /* Variants can hold scalar values and arrays of any type */
    UA_Variant valueA; 
    UA_Variant_init(&valueA);

    /* NodeId of the variable holding the current time */
    const UA_NodeId nodeIdA = UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER_SERVERSTATUS_CURRENTTIME);
    retval = UA_Client_readValueAttribute(client, nodeIdA, &valueA);

    if(retval == UA_STATUSCODE_GOOD &&
       UA_Variant_hasScalarType(&valueA, &UA_TYPES[UA_TYPES_DATETIME]))
    {
        UA_DateTime raw_date = *(UA_DateTime*) valueA.data;
        UA_DateTimeStruct dts = UA_DateTime_toStruct(raw_date);
        UA_LOG_INFO(UA_Log_Stdout,
                    UA_LOGCATEGORY_USERLAND,
                    "date is: %u-%u-%u %u:%u:%u.%03u\n",
                    dts.day, dts.month, dts.year,
                    dts.hour, dts.min, dts.sec, dts.milliSec);
    }


	// read int32 value
    UA_Variant valueB; 
    UA_Variant_init(&valueB);

    const UA_NodeId nodeIdB = UA_NODEID_STRING(1, "the.answer");
    retval = UA_Client_readValueAttribute(client, nodeIdB, &valueB);

	
    if(retval == UA_STATUSCODE_GOOD)
    {
        UA_Int32 raw_value = *(UA_Int32*) valueB.data;
        UA_LOG_INFO(UA_Log_Stdout,
                    UA_LOGCATEGORY_USERLAND,
                    "value is: %i\n",
                    raw_value);
	}




    /* Clean up */
    UA_Variant_deleteMembers(&valueA);
    UA_Variant_deleteMembers(&valueB);
	UA_Client_delete(client); /* Disconnects the client internally */

    return UA_STATUSCODE_GOOD;
}

