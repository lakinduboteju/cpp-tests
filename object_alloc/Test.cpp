#include <string>
#include <memory>
#include <list>

#include <gtest/gtest.h>

class Person
{
private:
    std::string name;

public:
    // Person constructor 1
    Person(std::string&& aName) : name( std::move(aName) )
    {
    }

    // Person constructor 2
    Person(const std::string& aName) : name(aName)
    {
    }

    ~Person() = default;

public:
    std::string getNameByValue() const
    {
        return name;
    }

    const std::string& getNameByReference() const
    {
        return name;
    }

public:
    Person(const Person&)            = delete;
    Person& operator=(const Person&) = delete;

public:
    Person(Person&& other)
    {
        name = std::move(other.name);
    }
    Person& operator=(Person&& other)
    {
        name = std::move(other.name);
        return *this;
    }
};

TEST(object_alloc_test, make_shared)
{
    Person p1("Lakindu");
    ASSERT_STREQ("Lakindu", p1.getNameByValue().c_str());
    ASSERT_STREQ("Lakindu", p1.getNameByReference().c_str());

    auto p2 = std::make_shared<Person>( p1.getNameByValue() );     // Person constructor 1 used
    ASSERT_STREQ("Lakindu", p2->getNameByValue().c_str());
    ASSERT_STREQ("Lakindu", p2->getNameByReference().c_str());

    auto p3 = std::make_shared<Person>( p1.getNameByReference() ); // Person constructor 2 used
    ASSERT_STREQ("Lakindu", p3->getNameByValue().c_str());
    ASSERT_STREQ("Lakindu", p3->getNameByReference().c_str());

    auto p4 = std::make_shared<Person>( "Sumudu" );                // Person constructor 1 used
    ASSERT_STREQ("Sumudu", p4->getNameByValue().c_str());
    ASSERT_STREQ("Sumudu", p4->getNameByReference().c_str());
}

TEST(object_alloc_test, list)
{
    // std::list<Person> l { Person("Lakindu"), Person("Sumudu") }; // Compile error:-
                                                                    // use of deleted function ‘Person::Person(const Person&)

    std::list<Person> l;
    l.emplace_back("Lakindu");
    l.emplace_back("Sumudu");
    ASSERT_EQ(l.size(), 2);

    std::list<Person> l1( std::move(l) );
    ASSERT_EQ(l1.size(), 2);
    ASSERT_EQ(l.size(),  0);
}
