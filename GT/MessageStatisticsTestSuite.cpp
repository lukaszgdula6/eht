#include <algorithm>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MessageDispatcherMock.hpp"

#include "Message.hpp"
#include "MessageStatistics.hpp"

using namespace ::testing;

template <std::size_t N>
constexpr auto len(const char (&str)[N])
{
    return N;
}

struct MessageStatisticsTestSuite : Test
{
    NiceMock<MessageDispatcherMock> messageDispatcher;
    MessageStatistics sut { messageDispatcher };

    inline static const std::string name1 = "name #1";
    inline static const std::string name2 = "name #2";
    inline static const std::string name3 = "name #3";
    inline static char payload1[] { "payload #1" };
    inline static char payload2[] { "payload #2" };
    inline static char payload3[] { "payload #3" };
    const ::Message message1 { name1, payload1, len(payload1) };
    const ::Message message2 { name2, payload2, len(payload2) };
    const ::Message message3 { name3, payload3, len(payload3) };
};

MATCHER_P(MessageIs, right, "")
{
    const ::Message &left = arg;
    return (left.name == right.name) && std::equal(left.payload, left.payload + left.payloadSize, right.payload, right.payload + right.payloadSize);
}

TEST_F(MessageStatisticsTestSuite, shouldForwardCallToInnerDispatcher)
{
    {
        InSequence seq;
        EXPECT_CALL(messageDispatcher, onMessage(MessageIs(message1)));
        EXPECT_CALL(messageDispatcher, onMessage(MessageIs(message2)));
        EXPECT_CALL(messageDispatcher, onMessage(MessageIs(message3)));
    }

    sut.onMessage(message1);
    sut.onMessage(message2);
    sut.onMessage(message3);
}


TEST_F(MessageStatisticsTestSuite, shouldCountNoMessagesWhenNoneProvided)
{
    EXPECT_EQ(sut.getMessageCount(), 0);
}

TEST_F(MessageStatisticsTestSuite, shouldCountOneMessageWhenOneProvided)
{
    sut.onMessage(message1);

    EXPECT_EQ(sut.getMessageCount(), 1);
}

TEST_F(MessageStatisticsTestSuite, shouldCountNumberOfProvidedMessaged)
{
    sut.onMessage(message1);
    sut.onMessage(message2);
    sut.onMessage(message3);

    EXPECT_EQ(sut.getMessageCount(), 3);
}
