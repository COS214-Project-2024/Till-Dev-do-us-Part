#ifndef STACKITERATOR_H
#define STACKITERATOR_H

#include "TransportationIterator.h"
#include "TransportStation.h"
#include <list>
#include <stack>

class TransportStation;

class StackIterator : public TransportationIterator {
private:
    std::stack<TransportStation*> stack;


public:
    ~StackIterator();
    StackIterator(TransportMode* mode);
    bool hasNext() const;
    TransportStation* next() ;
    TransportStation* first() ;
    TransportStation* currItem() const ;
};

#endif
