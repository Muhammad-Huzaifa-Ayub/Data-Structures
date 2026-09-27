#include "polynomial.h"

int main()
{
    polynomial p1;

    p1.print();
    cout << endl;

    p1.Ctor(6,2);

    p1.print();
    cout << endl;

    p1.AddTerm(5,3);
    p1.print();
    cout << endl;

    p1.AddTerm(0,5);
    p1.print();
    cout << endl;

    p1.AddTerm(8,0);
    p1.print();
    cout << endl;

    cout << p1.GetDegree();
    cout << endl;

    cout << p1.GetCoefficient(0);
    cout << endl;

    polynomial p2;
    p2 = p1;

    cout << "p2 is : "; p2.print(); cout << endl;

    cout << "When x = 2 , polynomial value is : " << p2.operation(2) << endl;

    polynomial p3 = p1.derivative();
    cout << "Derivative of p2 is : "; p3.print(); cout << endl;

    polynomial p4 = p3.AntiDerivative();
    cout << "Anti-Derivative of p3 is : "; p4.print(); cout << endl;

    cout << p1 << endl;

    cout << "adding" << endl;
    polynomial p5 = p1 + p2 + p3 + p4;
    cout << p5 << endl;

    cout << "subtracting" << endl;
    polynomial p6 = p1 - p2 - p3 - p4;
    cout << p6 << endl;

    cout << "Multiplying" << endl;
    polynomial p7 = p1 * p2;
    cout << p7 << endl;

    return 0;
}
