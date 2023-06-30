#pragma once


struct IMessageDispatcher;

class DevicesSocket
{
public:
    DevicesSocket(IMessageDispatcher &messageDispatcher);
    void listen(/* configration parameters */);

private:
    IMessageDispatcher &messageDispatcher;
};

