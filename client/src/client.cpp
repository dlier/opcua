#include <iostream>
#include <memory>
#include <string>
#include <future>

#include "timer.h"
#include "getdata.h"

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

    // handle connecting the server an getting data
    CGetData data(vArgs.at(0));

    // create the timer to get data from the server every 3s
    shared_ptr<timer> timerSharedPtr = timer::create( 3000, std::bind(&CGetData::FromServer,data) );
    timerSharedPtr->run();
    
    // wait forever
    std::promise<void>().get_future().wait();

    return 0;
}
