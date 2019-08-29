#include <cstddef>
#include <iostream>
#include "referenceCounter.hpp"

template<typename T> class SharedPtr
{
private:
    T* pData; // pointer to data
    referenceCounter* counter; // reference counter

public:
    SharedPtr() : pData(0), counter(0){
        counter = new referenceCounter();
        counter->incCount();
        std::cout << "This is the constructor, count is " << counter->getCount() << std::endl;

    };

    // Making the constructor explicit to avoid the compiler try to convert stuff.
    // Example:
    // void test(SharedPtr<int> ptr){
    // std::cout << "hallo!" <<   *ptr << std::endl;
    // } 
    // If the constructor wasnt explicit, the compiler would try to convert this int foo to a SharedPtr and it wouldnt be happy about it. 
    // int foo = 5;
    // test(&foo);
    //    
    explicit SharedPtr(T* pValue) : pData(pValue), counter(0){
        counter = new referenceCounter();
        counter->incCount();
        std::cout << "This is the constructor, count is " << counter->getCount() << std::endl;
    
    };


    // Denne explicitte defination af bool() operatoren gør at man kan bruge eksempelvis 
    // if(SharedPtr object){bla bla}
    // Hvis ikke man deklarerer operatoren explcit, vil compileren være i stand til at lave forkerte converteringer.
    // tjek Reference :  https://www.kdab.com/explicit-operator-bool/
    explicit operator bool() const { return true; }



    SharedPtr(const SharedPtr<T>& sp) : pData(sp.pData), counter(sp.counter)
    {
        // Copy constructor
        // Copy the data and reference pointer
        // and increment the reference count
        counter->incCount();
        std::cout << "This is the copy constructor, count is " << counter->getCount() << std::endl;

    }
    
    ~SharedPtr(){
        if(counter->decCount() == 0){
            std::cout << "destroying object, cleaning up! count is now : " << counter->getCount() << std::endl;
            delete pData;
            delete counter;
            return; 
        }
        std::cout << "This is the destructor, count is " << counter->getCount() << std::endl;
        
    };

    T & operator*(){return *pData;};
    T * operator->(){return pData;};    
    
    SharedPtr<T>& operator=(const SharedPtr<T> &sp){
        if(this != &sp)
        {
            if(counter->decCount() == 0)
            {
                delete pData;
                delete counter;
            }
            pData = sp.pData;
            counter = sp.counter;
            counter->incCount();
        std::cout << "This is the assignment, count is " << counter->getCount() << std::endl;

        }
        return *this;
    }
};

