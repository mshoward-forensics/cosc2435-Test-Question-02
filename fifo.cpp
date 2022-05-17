/*
 * Name: Nicole Howard
 */

#include "fifo.h"

#include <iostream>


Fifo::Fifo(){
    head = NULL;
    tail = NULL;
}

Fifo::~Fifo(){
    clearFifo();
}

bool Fifo::push(int x, string* s){ 
    bool pushed = false;
    if (x > 0 && s->length() != 0){  
        if (head == NULL && tail == NULL){
            Node *newNode = new Node;
            newNode->data.id = x;
            newNode->data.data = *s;
            head = newNode;
            tail = newNode;
            pushed = true;
        } else {
            addTail(x, s);
            pushed = true;
        }
    }
    return pushed; 
} 

bool Fifo::pull(Node* n){
    bool pulled = false;
    if (head != NULL){
        n->data.id = head->data.id;
        n->data.data = head->data.data;
        if (head->next != NULL){
            head = head->next;
            delete head->prev;
            head->prev = NULL;
        } else {
            delete head;
            head = NULL;
        }
        pulled = true;
    }
    return pulled;
} 

bool Fifo::peek(Data *d){
    bool peeked = false;
     if (head != NULL){
        d->id = head->data.id;
        d->data = head->data.data;
        peeked = true;
    } 
    return peeked; 
}

bool Fifo::isEmpty(){
    bool empty = true;
    if (head != NULL || tail != NULL){
        empty = false;
    }
    return empty;
} 

void Fifo::addTail(int id, string* s){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *s;
    tail->next = newNode;
    tail = newNode;
} 

bool Fifo::clearFifo(){
    bool listIsCleared = false;
    Node* current = tail;
    if (tail != NULL){
        Node* temp = current; 
        while(current){
            current = current->next;
            delete temp;
            temp = current;
        }
        head = NULL;
        listIsCleared = true;
    }   
    return listIsCleared;
}
