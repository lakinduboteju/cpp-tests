#pragma once

#include <iostream>

#include "String.h"

class Person
{
private:
    String name;
    String address {};                // [String] DefaultConstructor
    String country = "Sri Lanka";     // [String] Constructor with arg: 'Sri Lanka'
    String occupation;                // [String] DefaultConstructor

public:
    Person(const String& aName) :
        name(aName)                   // [String] CopyConstructor
    {
        std::cout << "[Person] Constructor that takes in LValue" << std::endl << std::flush;
        
        occupation = "SE";            // [String] Constructor with arg: 'SE'
                                      // [String] MoveAssignmentOperator
    }

    Person(String&& aName) : name(std::move(aName))
    {
        std::cout << "[Person] Constructor that takes in RValue" << std::endl << std::flush;

        occupation = std::move("SE"); // [String] Constructor with arg: 'SE'
                                      // [String] MoveAssignmentOperator
    }
    
    ~Person() = default;

public:
    Person(const Person&)            = delete;
    Person& operator=(const Person&) = delete;
};
