#ifndef STACK_H
#define STACK_H

/*
 * Name: Max Powell
 * Assignment: Assignment 4 - Simple Int Stack
 * File: stack.h
 * Description: Declares a simple integer stack ADT using a fixed-size array.
 */

const int STACK_SIZE = 10;

class Stack
{
private:
    int stack[STACK_SIZE];
    int top = -1;

public:
    bool pop(int* value);
    bool peek(int* value);
    bool push(int value);
    bool isEmpty();
};

#endif