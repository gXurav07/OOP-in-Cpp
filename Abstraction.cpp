/*
Abstaction means showing only the necessary information 
while hiding the implementation/complex details. Ex: working of a mixer grinder
Abstraction can be used to make the user of the program more comfortable to use it
Abstraction can also be used to improve the implementation os a program 
while keeping things same for the user

A more technical example of Abstraction is an abstract class that contains 
only pure virtual functions. 
This is abstraction because it shows all the functionalities that the class 
has without displaying the actual implementation 
Example is implemented bellow:
*/

#include <iostream>
using namespace std;

class SmartPhone{
public:
    virtual void takeASelfie()=0;
    virtual void makeACall()=0;
};

class Android: public SmartPhone{
public:
    void takeASelfie(){
        cout<<"Android took a Selfie~\n";
    }
    void makeACall(){
        cout<<"Android is making a Call.......\n";
    }
};

class IPhone: public SmartPhone{
public:
    void takeASelfie(){
        cout<<"IPhone took a Selfie~\n";
    }
    void makeACall(){
        cout<<"IPhone is making a Call.......\n";
    }
};

int main(){
    SmartPhone* sp1 = new Android();
    SmartPhone* sp2 = new IPhone();
    sp1->takeASelfie();
    sp1->makeACall();

    sp2->takeASelfie();
    sp2->makeACall();

    /*
    In this case the user only needs to know the functions of a smartphone.
    He requires knowledge of neither the implementation nor the type of 
    smartphone in use. This is a type of abstraction where user is only 
    introduced to functionalities of a smartphone and all other details are hidden.
    This allows phone companies to improve their product functionalities without
    causing inconvenience for the users. This also allows users to switch their
    phones without much trouble

    */
}


