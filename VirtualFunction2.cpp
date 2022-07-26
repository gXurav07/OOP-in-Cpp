// C++ program demonstrating ambiguity in Multipath
// Inheritance

#include <iostream>
using namespace std;

class A {
public:
    virtual void location(){
        cout<<"This is A\n";
    }
    virtual void greet()=0;
    void yo(){
        cout<<"yo from A\n";
    }
};

class B : public A {
public:
    void location(){
        cout<<"This is B\n";
    }
    virtual void yo(){ // defining virtual here doesn't work
        cout<<"yo from B\n";
    }

};

class C : public B {
public:
    void location(){
        cout<<"This is C\n";
    }

    virtual void greet(){
        cout<<"Hello\n";
    }
    virtual void yo(){ // defining virtual here doesn't work
        cout<<"yo from C\n";
    }
};

int main()
{
    A* p = new C();
    p->greet();
    p->location();
    p->yo();

    C c;
    A& a = c;
    a.greet();
    a.location();
    a.yo();
    
}
