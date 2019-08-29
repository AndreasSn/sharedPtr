#include <iostream>
#include <vector>
#include "sharedPtr.hpp"
#include "person.hpp"
using namespace std;

void test(SharedPtr<int> ptr){
    std::cout << "hallo!" <<   *ptr << std::endl;
}

int main (int argc, char *argv[]) 
{ 
    SharedPtr<Person> p (new Person("kurt", 23)); // constructor count 1
    p->Display();
    {
        SharedPtr<Person> p1 = p;

        p1->Display();
        //bool b1 = p1 ; 
        bool b2 = true;
        cout <<"b2: " << b2 << endl;

        // Ulovligt for at bool() operatoren er sat til at være explicit. Det betyder at compilering ikke må lave en konverteren implicit. 
        //int i(p1);
        
        // Ulovligt da compare operatoren ikke er overloadet. 
        //if(p == p1){
        //    cout << "hej" << endl;
        //}
    }

    //int foo = 5;
    //  test(&foo);


}