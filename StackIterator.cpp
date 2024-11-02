#include "StackIterator.h"

StackIterator:: StackIterator(TransportMode* mode)
{
    for (auto stop : mode->getStops()) {
        stack.push(stop);
    }
}
bool StackIterator:: hasNext() const
{
    return !(stack.empty());
}
TransportStation* StackIterator::next() 
{
    if(!stack.empty())
    {
        auto current= stack.top();
        stack.pop();

        return current;
    }
    return nullptr;
}
TransportStation* StackIterator::first(){
    if(hasNext())
    {
        return stack.top();
    }
    return nullptr;
}
TransportStation* StackIterator:: currItem() const {
 if(hasNext())
    {
        return stack.top();
    }
    return nullptr;

}