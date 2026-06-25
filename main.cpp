#include "main.h"

/*
 * Name: Max Powell
 * Assignment: Assignment 4 - Simple Int Stack
 * File: main.cpp
 * Description: Tests the simple integer stack ADT using explicit and random tests.
 */

int main()
{
    Stack stack;
    bool allTestsPassed = true;
    int testsRun = 0;
    int value = 0;
    bool result = false;

    cout << "Assignment 4: Simple Int Stack Tests" << endl;
    cout << "Stack size: " << STACK_SIZE << endl << endl;

    testsRun++;
    result = stack.isEmpty();
    cout << "Test empty stack with isEmpty(): " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = !stack.pop(&value);
    cout << "Test pop underflow on empty stack: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = !stack.peek(&value);
    cout << "Test peek underflow on empty stack: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = !stack.pop(nullptr);
    cout << "Test pop with incorrect null output pointer: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = !stack.peek(nullptr);
    cout << "Test peek with incorrect null output pointer: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = stack.push(42);
    cout << "Test push onto empty stack: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = !stack.isEmpty();
    cout << "Test non-empty stack with isEmpty(): " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = stack.peek(&value) && value == 42;
    cout << "Test peek returns last pushed value: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = stack.pop(&value) && value == 42 && stack.isEmpty();
    cout << "Test pop returns and removes value: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = stack.push(-10) && stack.push(0) && stack.push(10);
    cout << "Test push accepts negative, zero, and positive integers: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = stack.pop(&value) && value == 10;
    result = result && stack.pop(&value) && value == 0;
    result = result && stack.pop(&value) && value == -10;
    cout << "Test LIFO order with mixed integer values: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    for (int i = 0; i < STACK_SIZE; i++)
    {
        testsRun++;
        result = stack.push(i + 1);
        allTestsPassed = allTestsPassed && result;
    }

    testsRun++;
    result = !stack.push(STACK_SIZE + 1);
    cout << "Test overflow after filling stack: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = stack.peek(&value) && value == STACK_SIZE;
    cout << "Test peek after overflow attempt preserves top: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    for (int i = STACK_SIZE; i > 0; i--)
    {
        testsRun++;
        result = stack.pop(&value) && value == i;
        allTestsPassed = allTestsPassed && result;
    }

    testsRun++;
    result = stack.isEmpty();
    cout << "Test stack empty after popping all values: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    testsRun++;
    result = !stack.pop(&value);
    cout << "Test underflow after removing all values: " << (result ? "PASS" : "FAIL") << endl;
    allTestsPassed = allTestsPassed && result;

    Stack randomStack;
    int expected[STACK_SIZE];
    int expectedTop = -1;
    int randomTests = STACK_SIZE * RANDOM_TEST_MULTIPLIER;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < randomTests; i++)
    {
        int operation = rand() % 4;
        int randomValue = rand() % 10000;
        bool expectedResult = false;

        if (operation == 0)
        {
            result = randomStack.push(randomValue);
            expectedResult = expectedTop < STACK_SIZE - 1;

            if (expectedResult)
            {
                expectedTop++;
                expected[expectedTop] = randomValue;
            }

            allTestsPassed = allTestsPassed && result == expectedResult;
        }
        else if (operation == 1)
        {
            result = randomStack.pop(&value);
            expectedResult = expectedTop >= 0;

            if (expectedResult)
            {
                allTestsPassed = allTestsPassed && value == expected[expectedTop];
                expectedTop--;
            }

            allTestsPassed = allTestsPassed && result == expectedResult;
        }
        else if (operation == 2)
        {
            result = randomStack.peek(&value);
            expectedResult = expectedTop >= 0;

            if (expectedResult)
            {
                allTestsPassed = allTestsPassed && value == expected[expectedTop];
            }

            allTestsPassed = allTestsPassed && result == expectedResult;
        }
        else
        {
            result = randomStack.isEmpty();
            expectedResult = expectedTop < 0;
            allTestsPassed = allTestsPassed && result == expectedResult;
        }

        testsRun++;
    }

    cout << "Test random operations against expected model: "
         << (allTestsPassed ? "PASS" : "FAIL") << endl;
    cout << "Total tests run: " << testsRun << endl;
    cout << "Final result: " << (allTestsPassed ? "PASS" : "FAIL") << endl;

    return 0;
}
