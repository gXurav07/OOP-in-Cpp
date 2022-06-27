#include <iostream>

using namespace std;

class EquilateralTriangle{
    float side;
    float perimeter;
    float area;
public:
    void setA(float length){
        side=length;
        perimeter=3*side;
        area = (1.732*side)/4;
    }
    friend float side(EquilateralTriangle et);
    friend float perimeter(EquilateralTriangle &et);
private:
    friend float area(EquilateralTriangle &et);
protected:
    friend float doubleArea();
};

float side(EquilateralTriangle et){
    return et.side; // This line shows error if the function is not declared as friend
}

float perimeter(EquilateralTriangle &et){
    return et.perimeter;
}

float area(EquilateralTriangle &et){
    return et.area;
}

EquilateralTriangle Et;
float doubleArea(){
    return 2*Et.area;
}



int main(){
    EquilateralTriangle et; 

    float length;
    cin>>length; 

    et.setA(length);
    Et.setA(length);

    cout<<"Side = "<<side(et)<<endl;
    cout<<"Perimeter = "<<perimeter(et)<<endl;
    cout<<"Area = "<<area(et)<<endl;
    cout<<"Double of Area = "<<doubleArea()<<endl;
    return 0;

}