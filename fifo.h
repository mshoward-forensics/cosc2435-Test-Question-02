/*
 * Name: Nicole Howard
 * Test02
 */

#ifndef FIFO_H
#define FIFO_H

#include "data.h"

#include "string.h"
using std::string;


class Fifo {

public:

    Fifo();
    ~Fifo();

    bool push(int, string*);
    bool pull(Node*);
    bool isEmpty();
    bool peek(Data*);

private:

    int count;
    Node *head;
    Node *tail;

    void addTail(int, string*);
    bool clearFifo();
};

#endif //FIFO_H
