# Member field instantiation in classes

With this simple code, I refreshed my understanding of how member fields of classes are instantiated with different types of constructors and assignment operators.

```c++
class String
{
public:
    String(const char* str) { ... }          // Constructor which takes an arg in
    String() = default;                      // DefaultConstructor
    ~String() = default;

public:
    String(const String&) { ... }            // CopyConstructor
    String& operator=(const String&) { ... } // AssignmentOperator

public:
    String(String&&) { ... }                 // MoveConstructor
    String& operator=(String&&) { ... }      // MoveAssignmentOperator
};
```

```c++
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
        occupation = "SE";            // [String] Constructor with arg: 'SE'
                                      // then,
                                      // [String] MoveAssignmentOperator
                                      // In this case, compiler intelligently choose
                                      // MoveAssignmentOperator over AssignmentOperator.
                                      // By doing that, compiler saves us a object copy.
    }

    Person(String&& aName) : name(std::move(aName))
    {
        occupation = std::move("SE"); // [String] Constructor with arg: 'SE'
                                      // then,
                                      // [String] MoveAssignmentOperator
    }
    
    ~Person() = default;

public:
    Person(const Person&)            = delete;
    Person& operator=(const Person&) = delete;
};
```

## Main learning

As an example, if we get `std::string` class, we have following main constructors.

```c++
namespace std
{
    class/struct string
    {
        string();
        string(const char*);
    };
}
```

Using these constructors, there are 2 ways that we can instantiate empty strings.

```c++
#include <string>

class/struct Employee
{
    std::string name          {}; // 1
    std::string designation = ""; // 2

    Employee()  = default;
    ~Employee() = default;
};
```

1. Calls `string();`

2. Calls `string(const char*);`

Between these 2 calls, `1` is better because it saves us from creating temporary char array (`""`).
