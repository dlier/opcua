#pragma once
#ifndef TIMER_H
#define TIMER_H

#include <memory>
#include <thread>

using namespace std;


class timer
{
public:
    explicit timer(unsigned int p_uiInterval, function<void(void)> p_FunctionPtr )
    : m_FunctionPtr(p_FunctionPtr)
    , m_uiInterval(p_uiInterval) { /*NOP*/  };

    ~timer() { m_WorkerThread.detach(); };

    static shared_ptr<timer> create(unsigned int p_uiInterval, function<void(void)> p_FunctionPtr)
    {
        // ctrate, hold as weak_ptr and return as shared_ptr
        shared_ptr<timer> returnSharedPtr = make_shared<timer>(p_uiInterval, p_FunctionPtr);
        returnSharedPtr->m_WeakPtr = returnSharedPtr;
        return returnSharedPtr;
    }

    void run()
    {
        // get the weak_ptr
        weak_ptr<timer> tempWeakPtr = this->m_WeakPtr;

        // create the worker thread
	    m_WorkerThread = thread([tempWeakPtr]()
        {
            // call the funcion as long as the the shared_ptr is alive
            while (shared_ptr<timer> tempSharedPtr = tempWeakPtr.lock())
            {
                auto futureTime = chrono::steady_clock::now() +
                                  chrono::milliseconds(tempSharedPtr->m_uiInterval);

                tempSharedPtr->m_FunctionPtr();
                this_thread::sleep_until(futureTime);
            }
        });
    }

private:
    weak_ptr<timer> m_WeakPtr;
    thread m_WorkerThread;
    function<void(void)> m_FunctionPtr;
    unsigned int m_uiInterval;
};

#endif
