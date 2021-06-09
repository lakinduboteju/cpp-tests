# Object allocations

With this simple code, I refreshed my understanding of how objects are allocated when passing/returning them by value and by reference.

```c++
class String
{
public:
    String(const char* str) { ... }               // Constructor which takes an arg in
    String() { ... }                              // DefaultConstructor
    ~String() = default;

public:
    String(const String&) { ... }                 // CopyConstructor
    String& operator=(const String&) { ... }      // AssignmentOperator

public:
    String(String&&) { ... }                      // MoveConstructor
    String& operator=(String&&) { ... }           // MoveAssignmentOperator

public:
    String operator+(const String&) const { ... } // [+]Operator
};
```

```c++
class Person
{
private:
    String name;
    String address {};

public:
    Person(const String& aName) : name(aName) { ... }
    Person(String&& aName) : name(std::move(aName)) { ... }
    ~Person() = default;

public:
    Person(const Person&)            = delete;
    Person& operator=(const Person&) = delete;

public:
    String GetNameByValue() const { return name; }
    const String& GetNameByReference() const { return name; }
};
```

```c++
Person p("Lakindu");

String nameVal = p.GetNameByValue();            // [String] CopyConstructor
const String& nameRef = p.GetNameByReference(); // no copying

String s1 = String() + p.GetNameByValue();      // [String] CopyConstructor
                                                // [String] DefaultConstructor
                                                // [String] [+]Operator
                                                // [String] CopyConstructor

String s2 = String() + p.GetNameByReference();  // [String] DefaultConstructor
                                                // [String] [+]Operator
                                                // [String] CopyConstructor
```

```c++
void func1(const String& aStr)   { String str = aStr; }

func1( p.GetNameByValue() );                    // [String] CopyConstructor
                                                // [String] CopyConstructor

func1( p.GetNameByReference() );                // [String] CopyConstructor
```

```c++
String getName1(const Person& p) { return p.GetNameByValue(); }
String getName2(const Person& p) { return p.GetNameByReference(); }

String s3 = getName1(p);                        // [String] CopyConstructor

String s4 = getName2(p);                        // [String] CopyConstructor
```

```c++
String func2(const Person& p)    { return p.GetNameByValue() + String(); }
String func3(const Person& p)    { return p.GetNameByReference() + String(); }

String s5 = func2(p);                           // [String] DefaultConstructor
                                                // [String] CopyConstructor
                                                // [String] [+]Operator
                                                // [String] CopyConstructor

String s6 = func3(p);                           // [String] DefaultConstructor
                                                // [String] [+]Operator
                                                // [String] DefaultConstructor
```

```c++
void func4(String&& aStr)        { String str = std::move(aStr); }
void func5(const String&& aStr)  { String str = std::move(aStr); }

func4( p.GetNameByValue() );                    // [String] CopyConstructor
                                                // [String] MoveConstructor

String s7 = p.GetNameByReference();             // [String] CopyConstructor
func4( std::move(s3) );                         // [String] MoveConstructor

// func4( p.GetNameByReference() ); // Compile error

String s8;                                      // [String] DefaultConstructor
func5( std::move(s5) );                         // [String] CopyConstructor

func5( String() );                              // [String] DefaultConstructor
                                                // [String] CopyConstructor

// func5( p.GetNameByReference() ); // Compile error
```

```c++
Person p1("Sumudu");

std::make_shared<Person>( p1.GetNameByValue() );
                                                // [String] CopyConstructor
                                                // [String] MoveConstructor
                                                // [String] DefaultConstructor
                                                // [Person] Constructor that takes in RValue

std::make_shared<Person>( p1.GetNameByReference() );
                                                // [String] CopyConstructor
                                                // [String] DefaultConstructor
                                                // [Person] Constructor that takes in LValue
```
