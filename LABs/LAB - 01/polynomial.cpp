#include "polynomial.h"

polynomial::polynomial()
{
    this->size = 1;

    ptr = new poly[size];

    (* ptr).cof = 0;
    (* ptr).pow = 0;

    this->var = "x";

}

polynomial::polynomial( const polynomial &p )
{
    size = p.size;
    var = p.var;

    ptr = new poly[size];

    for ( int i = 0; i < size; i++ )
    {
        ptr[i] = p.ptr[i];
    }
}

void polynomial::Ctor( int c, int p )
{
    if ( c == 0 )
    {
        cout << "Coefficient of polynomial cant' be zero" << endl;
        return;
    }

    (* ptr ).cof = c;
    (* ptr ).pow = p;

}

void polynomial::AddTerm( int c, int p )
{
    if ( c == 0 )
    {
        return;
    }

    for ( int i = 0; i < this->size; i++ )
    {
        if ( ptr[i].pow == p )
        {
            ptr[i].cof += c;
            return;
        }
    }

    int stop = this->size;
    this->size = this->size + 1;
    poly *newptr = new poly[size];

    for ( int i = 0; i < stop; i++ )
    {
        newptr[i].cof = ptr[i].cof;
        newptr[i].pow = ptr[i].pow;
    }

    newptr[stop].cof = c;
    newptr[stop].pow = p;

    delete[] ptr;
    ptr = newptr;

    return;
}

int polynomial::GetDegree() const
{
    int degree = INT_MIN;

    for ( int i = 0; i < this->size; i++ )
    {
        if ( ptr[i].pow > degree )
        {
            degree = ptr[i].pow;
        }
    }

    return degree;
}

int polynomial::GetCoefficient( int p ) const
{

    for ( int i = 0; i < this->size; i++ )
    {
        if  ( ptr[i].pow == p )
        {
            return ptr[i].cof;
        }
    }

    return 0;
}

double polynomial::operation( int value )const
{
    double final = 0;

    for ( int i = 0; i < this->size; i++ )
    {
        double result = ptr[i].cof * ( pow(value,ptr[i].pow));
        final += result;
    }

    return final;
}


polynomial polynomial::derivative()
{
    polynomial result;

    for ( int i = 0; i < size; i++ )
    {
        if ( ptr[i].pow != 0 )
        {
            int c = ptr[i].cof * ptr[i].pow;
            int p = ptr[i].pow - 1;

            result.AddTerm(c, p);
        }
    }

    return result;
}

polynomial polynomial::AntiDerivative()
{
    polynomial result;

    result.size = 0;
    delete[] result.ptr;
    result.ptr = nullptr;

    for ( int i = 0; i < size; i++ )
    {
        if ( ptr[i].cof == 0 )
        {
            continue;
        }

        int newCof = ptr[i].cof / (ptr[i].pow + 1);
        int newPow = ptr[i].pow + 1;

        result.AddTerm(newCof, newPow);
    }

    result.AddTerm(5,0);

    return result;

}

void polynomial::print() const
{
    for ( int power = GetDegree(); power >= 0; power-- )
    {
        for ( int i = 0; i < size; i++ )
        {
            if ( ptr[i].pow == power && ptr[i].cof != 0 )
            {
                if ( ptr[i].cof > 0 )
                {
                    cout << "+";
                }
                cout << ptr[i].cof;

                if ( power == 1 )
                {
                    cout << var;
                }
                else if ( power > 1 )
                {
                    cout << var << "^" << power;
                }

                cout << " ";
            }
        }
    }
}

polynomial& polynomial::operator = (const polynomial &p)
{
    if ( this == &p )
    {
        return *this;
    }

    delete[] ptr;

    size = p.size;
    var = p.var;

    ptr = new poly[size];

    for ( int i = 0; i < size; i++ )
    {
        ptr[i].cof = p.ptr[i].cof;
        ptr[i].pow = p.ptr[i].pow;
    }

    return *this;
}

polynomial::~polynomial()
{
    delete[] ptr;
    ptr = nullptr;
}

void polynomial::AddToCoefficient( int c, int p )
{
    for ( int i = 0; i < this->size; i++ )
    {
        if ( ptr[i].pow == p )
        {
            ptr[i].cof += c;
            return;
        }
    }

    if ( c != 0 )
    {
        this->AddTerm(c, p);
    }
}

void polynomial::clear()
{
    for ( int i = 0; i < this->size; i++ )
    {
        ptr[i].cof  = 0;
    }
}

ostream &operator << ( ostream &out, const polynomial &p )
{
    p.print();
    return out;
}

polynomial polynomial::operator + ( const polynomial &p )
{
    polynomial result;

    result.size = 0;
    delete[] result.ptr;
    result.ptr = nullptr;

    for ( int i = 0; i < size; i++ )
    {
        result.AddTerm( ptr[i].cof, ptr[i].pow );
    }

    for ( int i = 0; i < p.size; i++ )
    {
        result.AddToCoefficient( p.ptr[i].cof, p.ptr[i].pow );
    }

    return result;
}

polynomial polynomial::operator - ( const polynomial &p )
{
    polynomial result;

    result.size = 0;
    delete[] result.ptr;
    result.ptr = nullptr;

    for ( int i = 0; i < size; i++ )
    {
        result.AddTerm( ptr[i].cof, ptr[i].pow );
    }

    for ( int i = 0; i < p.size; i++ )
    {
        result.AddToCoefficient( -p.ptr[i].cof, p.ptr[i].pow );
    }

    return result;
}

void polynomial::SetToCoefficient( int c, int p )
{
    for ( int i = 0; i < this->size; i++ )
    {
        if ( ptr[i].pow == p )
        {
            ptr[i].cof = c;
            return;
        }
    }

    if ( c != 0 )
    {
        this->AddTerm(c, p);
    }
}

polynomial polynomial::operator * ( const polynomial &p )
{
    polynomial result;

    result.size = 0;
    delete[] result.ptr;
    result.ptr = nullptr;

    for ( int i = 0; i < size; i++ )
    {
        for ( int j = 0; j < p.size; j++ )
        {
            int newCof = ptr[i].cof * p.ptr[j].cof;
            int newPow = ptr[i].pow + p.ptr[j].pow;

            result.AddToCoefficient(newCof, newPow);
        }
    }

    return result;
}