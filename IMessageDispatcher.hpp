#pragma once

struct Message;

struct IMessageDispatcher
{
    virtual ~IMessageDispatcher() = default;
    virtual void onMessage(const Message &message) = 0;
};
