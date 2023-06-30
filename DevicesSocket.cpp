#include "DevicesSocket.hpp"

DevicesSocket::DevicesSocket(IMessageDispatcher &messageDispatcher) : messageDispatcher(messageDispatcher)
{}

void DevicesSocket::listen()
{
/* here we would have a loop listening on some socked, packaging message to the Message struct and calling dispatcher
    while (true)
        if (socket.has_data)
            Message message = socket.read
            messageDispatcher.onMessage(message)
*/
}
