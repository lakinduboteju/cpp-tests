#include <iostream>

#include "Person.h"

void func1(const String& aStr)   { String str = aStr; }
String getName1(const Person& p) { return p.GetNameByValue(); }
String getName2(const Person& p) { return p.GetNameByReference(); }
String func2(const Person& p)    { return p.GetNameByValue() + String(); }
String func3(const Person& p)    { return p.GetNameByReference() + String(); }
void func4(String&& aStr)        { String str = std::move(aStr); }
void func5(const String&& aStr)  { String str = std::move(aStr); }

int main()
{
    std::cout << std::endl << "<=============| object_alloc |=============>" << std::endl << std::flush;

    std::cout << std::endl << "p" << std::endl << std::flush;
    Person p("Lakindu");

    std::cout << std::endl << "** p.GetNameByValue() **" << std::endl << std::flush;
    String nameVal = p.GetNameByValue();

    std::cout << std::endl << "** p.GetNameByReference() **" << std::endl << std::flush;
    const String& nameRef = p.GetNameByReference();

    std::cout << std::endl << "** String() + p.GetNameByValue() **" << std::endl << std::flush;
    String s1 = String() + p.GetNameByValue();

    std::cout << std::endl << "** String() + p.GetNameByReference() **" << std::endl << std::flush;
    String s2 = String() + p.GetNameByReference();

    std::cout << std::endl << "** func1( p.GetNameByValue() ) **" << std::endl << std::flush;
    func1( p.GetNameByValue() );

    std::cout << std::endl << "** func1( p.GetNameByReference() ) **" << std::endl << std::flush;
    func1( p.GetNameByReference() );

    std::cout << std::endl << "** getName1(p) **" << std::endl << std::flush;
    String s3 = getName1(p);

    std::cout << std::endl << "** getName2(p) **" << std::endl << std::flush;
    String s4 = getName2(p);

    std::cout << std::endl << "** func2(p) **" << std::endl << std::flush;
    String s5 = func2(p);

    std::cout << std::endl << "** func3(p) **" << std::endl << std::flush;
    String s6 = func3(p);

    std::cout << std::endl << "** func4( p.GetNameByValue() ) **" << std::endl << std::flush;
    func4( p.GetNameByValue() );

    std::cout << std::endl << "** func4( p.GetNameByReference() ) **" << std::endl << std::flush;
    String s7 = p.GetNameByReference();
    func4( std::move(s3) );
    
    // func4( p.GetNameByReference() ); // Compile error

    std::cout << std::endl << "** func5( RVALUE ) 1 **" << std::endl << std::flush;
    String s8;
    func5( std::move(s5) );

    std::cout << std::endl << "** func5( RVALUE ) 2 **" << std::endl << std::flush;
    func5( String() );

    // func5( p.GetNameByReference() ); // Compile error

    return 0;
}

// Terminal output :-
/*
*/
