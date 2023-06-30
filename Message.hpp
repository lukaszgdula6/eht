#pragma once

#include <string>

struct Message
{
    using Name = std::string;
//    Note: in real life app Payload would be a conainer-like class allowing safe and easy access to the payload
//          something like read-only vector but with memory pooling
    using Payload = char*;
    using PayloadSize = unsigned;

    Name name;
    Payload payload;
    PayloadSize payloadSize;
};
