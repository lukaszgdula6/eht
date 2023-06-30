#include "MessageStatistics.hpp"

MessageStatistics::MessageStatistics(IMessageDispatcher &messageDispatcher) : messageDispatcher(messageDispatcher)
{
}

MessageStatistics::MessageCount MessageStatistics::getMessageCount() const
{
    return messageCount;
}

void MessageStatistics::onMessage(const Message &message)
{
    ++messageCount;
    messageDispatcher.onMessage(message);
}
