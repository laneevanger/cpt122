#include <iostream>
#include <string>

using std::string;
/*
Task 1: Create a base class called Person, which has private data members for a
name, age, gender, and height. Implement a constructor, copy constructor,
destructor, overloaded assignment operator, overloaded stream insertion and
extraction operators, and getters and setters. See Task 2 for testing this class.

Task 2: Create a derived class called TestPerson, which publically inherits from class
Person. Create test methods for each method in class Person. Remember these
functions should not accept any parameters or return any values. However, they
should print messages for “test case passed” or “test case failed”.

Task 3: Modify your class Person so that the data members are protected instead of
private. How does this affect the tests cases that you created in Task 2?

Task 4: Create a derived class called Student, which publically inherits from class
Person. Add three private data members to class Student. These include an array of
struct Course, the number of courses taken, and the total number of credits. The
struct Course should contain a string for course name, credits assigned to course, and
current grade in course. Implement appropriate constructors, overloaded operators,
and setters and getters for this class. Also, implement methods for computing total
credits taken and current GPA. How would your implementation change if you decided
to define a class Course instead of struct Course?

Task 5: Create a derived class called Teacher, which publically inherits from class
Person. Add three private data members to class Teacher. These include an array of
struct Course, the number of courses taken, and the total number of credits. The
struct Course should contain a string for course name, credits assigned to course, and
average grade of students’ in course. Implement appropriate constructors, overloaded
operators, and setters and getters for this class. Also, implement methods for
computing total credits taught and average grades of students across the courses
taught. How would your implementation change if you decided to derive class
Teacher from class Student instead of class Person?

Task 6: Create an application, which allows students to register for classes taught by
a particular teacher. For this task you may use generative AI to help create the
application from your preexisting classes. Please discuss with your teammates how to
generate valid prompts to perform the task. Can you design an application with using
only 3 prompts at most?

*/

int main(void)
{

}

class Person
{
    //name, age, gender, and height
    public:
    string name = "John Doe";
    int age = 69;
    string gender = "thing";
    int height = 28;

    Person() = default;
    ~Person() = default;
    Person(Person& other) = default;

    Person& operator=(Person& other) = default;

    private:

};

class TestPerson : Person
{
    public:
    string testCreate();
    string testDelete();
    string testCopy(Person& other);
    string testEquals(Person& other);

    private:

};

string TestPerson::testCreate()
{

}

string TestPerson::testDelete()
{

}

string TestPerson::testCopy(Person& other)
{

}

string TestPerson::testEquals(Person& other)
{

}