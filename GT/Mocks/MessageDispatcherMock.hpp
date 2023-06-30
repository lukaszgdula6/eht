#pragma once

#include "gmock/gmock.h"
#include "IMessageDispatcher.hpp"

struct MessageDispatcherMock : IMessageDispatcher
{
    MOCK_METHOD1(onMessage, void (const Message &message));
};
