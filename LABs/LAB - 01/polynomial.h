#ifndef Polynomial_H
#define Polynomial_H

#include <iostream>
#include <math.h>

using namespace std;

struct poly
{
    int cof;
    int pow;
};

class polynomial
{
    poly *ptr;
    int size;
    string var;

public:

    polynomial();
    polynomial(const polynomial &p);
    void Ctor(int c, int p);
    void AddTerm ( int c , int p);
    int GetDegree()const;
    int GetCoefficient( int p ) const;
    double operation ( int value)const;
    polynomial derivative();
    polynomial AntiDerivative();
    polynomial& operator = ( const polynomial &p );
    void AddToCoefficient(int c , int p);
    void print()const;
    void clear();
    ~polynomial();
    friend ostream& operator << ( ostream &out, const polynomial &p );
    polynomial operator + ( const polynomial &p );
    polynomial operator - ( const polynomial &p );
    void SetToCoefficient( int c, int p );
    polynomial operator * ( const polynomial &p );

}; 

#endif 



