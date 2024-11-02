#include "QueueIterator.h"

QueueIterator:: QueueIterator(TransportMode* mode)
{
    for (auto stop : mode->getStops()) {
        queue.push(stop);
    }
}
bool QueueIterator::hasNext() const
{
    return !(queue.empty());
}
TransportStation* QueueIterator::next()
{
    if(!queue.empty())
    {
        auto current= queue.front();
        queue.pop();

        return current;
    }
    return nullptr;
    
}
TransportStation* QueueIterator:: first()
{
    if(hasNext())
    {
        return queue.front();
    }
    return nullptr;
}
TransportStation* QueueIterator:: currItem() const
{
    if(hasNext())
    {
        return queue.front();
    }
    return nullptr;
}