#include <iostream>
using namespace std;

/* 
const Keyword can be described as a promise we make to the Program 
about not changing a certain entity within the program

But like all other promises it can also be broken
*/

class Entity{
private:
    int X, Y;
    mutable int Z;
public:
    // const after member function name
    int getX() const{  // Promises to not change any data members within the function
        //X=1; shows error
        int a=0; a=5;
        Z=7; // mutable data members can be changed
        return X;
    }
    int getX(){  // Overloading with const is allowed
        X=5;
        return X;
    }
    void setX(int x){
        X=x;
    }
    void greet(){
        cout<<"Hello\n";
    }

    /* promises to return a pointer whose data value and 
    value stored in address pointed by it cannot be changed
    Also the function cannot change any member variables*/
    const int* const fun() const{
        return new int();
    }
};

// const over here promises not to modify e
// even member function which don't promise to not modify e are not allowed to call
void printEntity(const Entity &e){ 
    cout<<e.getX()<<endl; // calls the getX() with const
    // e.greet(); can't call this function because it doesn't promises to not modify e 
}
void outputEntity(Entity &e){
    cout<<e.getX()<<endl; // calls the getX() without const 
}
int main(){
    const int TWO=2; // value of variable TWO can't be changed
    // TWO=3; gives error
    int *ptr=(int *)&TWO;
    *ptr=3; // A way to change the value of TWO
    // NOTE: cout<<TWO; will still print 2 because of pre processing by compiler


    // CONST AND POINTERS
    // pointer points to a constant int(Thats what the compiler thinks)
    const int* p; // we can change value of p but not the value stored in value of p
    int a=1,b=2;
    p=&a; p=&b; 
    // *p=3;   --> gives error (Can't change values at address pointed by p)
     
    int const *p2; // same as const int*



    // CONSTANT pointer variable (Its value can't be changed)
    int* const q=&a; // ****Remember: const is after *
    *q=3; // content of address pointed can be changed 
    // q=&b; gives error (address pointed can't be changed)

    Entity e;
    e.setX(3);
    printEntity(e);
    outputEntity(e);

}

