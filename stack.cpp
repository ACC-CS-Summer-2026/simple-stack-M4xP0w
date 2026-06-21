#include "stack.h"

/*
 * Name: Max Powell
 * Assignment: Assignment 4 - Simple Int Stack
 * File: stack.cpp
 * Description: Implements the simple integer stack ADT.
 */

bool Stack::pop(int* value)
{
    bool success = false;

    if (value != nullptr && !isEmpty())
    {
        *value = stack[top];
        top--;
        success = true;
    }

    return success;
}

bool Stack::peek(int* value)
{
    bool success = false;

    if (value != nullptr && !isEmpty())
    {
        *value = stack[top];
        success = true;
    }

    return success;
}

bool Stack::push(int value)
{
    bool success = false;

    if (top < STACK_SIZE - 1)
    {
        top++;
        stack[top] = value;
        success = true;
    }

    return success;
}

bool Stack::isEmpty()
{
    bool empty = false;

    if (top < 0)
    {
        empty = true;
    }

    return empty;
}