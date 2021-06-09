#pragma once

#include <iostream>

class String
{
public:
    String(const char* str)
    {
        std::cout << "[String] Constructor with arg: '" << std::string(str) << "'"
                  << std::endl << std::flush;
    }

    String()
    {
        std::cout << "[String] DefaultConstructor" << std::endl << std::flush;
    }
    
    ~String() = default;

public:
    String(const String&)
    {
        std::cout << "[String] CopyConstructor" << std::endl << std::flush;
    }
    
    String& operator=(const String&)
    {
        std::cout << "[String] AssignmentOperator" << std::endl << std::flush;

        return *this;
    }

public:
    String(String&&)
    {
        std::cout << "[String] MoveConstructor" << std::endl << std::flush;
    }

    String& operator=(String&&)
    {
        std::cout << "[String] MoveAssignmentOperator" << std::endl << std::flush;

        return *this;
    }

public:
    String operator+(const String&) const
    {
        std::cout << "[String] [+]Operator" << std::endl << std::flush;

        return String(); // not the correct implementation, just for testing
    }
};
