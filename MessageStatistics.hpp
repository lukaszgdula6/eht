#pragma once

#include "IMessageDispatcher.hpp"

class MessageStatistics : public IMessageDispatcher
{
public:
    using MessageCount = unsigned long ;

    MessageStatistics(IMessageDispatcher &messageDispatcher);
    void onMessage(const Message &message) override;

    MessageCount getMessageCount() const;

private:
    IMessageDispatcher &messageDispatcher;

    MessageCount messageCount = 0;
};

