#pragma once

#include <iostream>

#include "String.h"

class Person
{
private:
    String name;
    String address {};

public:
    Person(const String& aName) : name(aName)
    {
        std::cout << "[Person] Constructor that takes in LValue" << std::endl << std::flush;
    }

    Person(String&& aName) : name(std::move(aName))
    {
        std::cout << "[Person] Constructor that takes in RValue" << std::endl << std::flush;
    }
    
    ~Person() = default;

public:
    Person(const Person&)            = delete;
    Person& operator=(const Person&) = delete;

public:
    String GetNameByValue() const { return name; }

    const String& GetNameByReference() const { return name; }
};
