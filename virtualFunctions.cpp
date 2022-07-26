#include <iostream>
using namespace std;

class Instrument{
public:
    void printType(){   // non-virtual function --> called here
        cout<<"Musical Instrument\n";
    }

    virtual void printUse(){ // virtual function with no copy in derived class --> called here
        cout<<"Used to play music\n";
    }

    virtual void makeSound(){ // virtual function --> called in derived class
        cout<<"Instrument playing........\n";
    }

    virtual void printName(){
        cout<<"Instrument\n";
    }

    virtual void printCost() = 0; // pure virtual function --> called in derived class
};

class Piano: public Instrument{
public:         
    void printType(){
        cout<<"Piano\n";
    }

    void makeSound(){
        cout<<"Piano playing........\n";
    }
private:   // private functions of base class can be called with virtual functions
    virtual void printName(){
        cout<<"Piano\n";
    }

    void printCost(){
        cout<<"Rs. 5000/-\n";
    }


};

int main(){
    Instrument *ptr = new Piano();

    ptr->printType();
    ptr->printUse();
    ptr->makeSound();
    ptr->printName();
    ptr->printCost();
    

    return 0;

}









/* 
- Base class pointers can also point to derived class

- When we use virtual functions the most derived version 
  of the function is called 

- Abstract Class: A class which has atleast 1 pure virtual function
  Ex: Instruments class in above program

- We cannot make objects of an abstract class (because the pure virtual 
  function has no defination)

- Derived class of an abstract must have defination for the pure-virtual 
  inside them otherwise that derived class also becomes an abstract class

- private functions of base class can be called with virtual functions
- Because compiler checks access specifier only during compilation, 
  it is not rechecked during runtime
*/