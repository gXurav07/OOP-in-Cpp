#include <iostream>
using namespace std;

class X {
private:
    ~X() { cout << "X destructor" << endl; }
public:
    void destroy() { delete this; }
    friend void destroyX(X *);
};
void destroyX(X * x) { delete x; }

int main(){
    // X x1;      // error: due to private destructor
    X *x2;
    X *x3 = new X;
    // delete x3; // error: due to private destructor
    x3->destroy();

    X *x4 = new X;
    destroyX(x4);

    return 0;
}

/*
Only dynamically are allowed to be created for class with private destructors.
*/