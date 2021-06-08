#include <iostream>

#include "Person.h"

int main()
{
    std::cout << std::endl << "<=============| member_init |=============>" << std::endl << std::flush;

    std::cout << "p1" << std::endl << std::flush;
    String name = "Lakindu";    // [String] Constructor with arg: 'Lakindu'
    Person p1(name);            // [Person] Constructor that takes in LValue
    
    std::cout << "p2" << std::endl << std::flush;
    Person p2(std::move(name)); // [String] MoveConstructor
                                // [Person] Constructor that takes in RValue
    return 0;
}

// Terminal output :-
/*

<=============| member_init |=============>
p1
[String] Constructor with arg: 'Lakindu'
[String] CopyConstructor
[String] DefaultConstructor
[String] Constructor with arg: 'Sri Lanka'
[String] DefaultConstructor
[Person] Constructor that takes in LValue
[String] Constructor with arg: 'SE'
[String] MoveAssignmentOperator
p2
[String] MoveConstructor
[String] DefaultConstructor
[String] Constructor with arg: 'Sri Lanka'
[String] DefaultConstructor
[Person] Constructor that takes in RValue
[String] Constructor with arg: 'SE'
[String] MoveAssignmentOperator
*/
