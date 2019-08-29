#include "iostream"
class Person
{
    const char* pName;
    int age;

    public:
        Person(): pName(0),age(0)
        {
        }
        Person(const char* pName, int age): pName(pName), age(age)
        {
        }

        void Display()
        {
            std::cout << "Name = " << this->pName  << " Age = " << age << std::endl;
        }
        void Shout()
        {
            printf("Ooooooooooooooooo");
        } 
};