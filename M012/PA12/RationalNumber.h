
#include <string>
using namespace std;
class RationalNumber {
 public:
 RationalNumber( int = 0, int = 1 ); // default constructor

 // default constructor
 RationalNumber addition( const RationalNumber & );
 RationalNumber subtraction( const RationalNumber & );
 RationalNumber multiplication( const RationalNumber & );
 RationalNumber division( RationalNumber & );
 string toString();
 string toStringRationalNumber() const;
 string toStringRationalNumberAsDouble() const;
 
 RationalNumber operator+( const RationalNumber& );
 RationalNumber operator-( const RationalNumber& );
 RationalNumber operator*( const RationalNumber& );
 RationalNumber operator/( RationalNumber& );
 bool operator>( const RationalNumber& ) const;
 bool operator<( const RationalNumber& ) const;
 bool operator>=( const RationalNumber& ) const;
 bool operator<=( const RationalNumber& ) const;
 bool operator==( const RationalNumber& ) const;
 bool operator!=( const RationalNumber& ) const;
 
 private:
 int numerator;
 int denominator;

 void reduction( void );
 };







