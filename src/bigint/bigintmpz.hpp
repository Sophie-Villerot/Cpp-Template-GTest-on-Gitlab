// bigintmpz.hpp

#ifndef SRC_BIGINT_BIGINTMPZ_HPP
#define SRC_BIGINT_BIGINTMPZ_HPP

#include <iostream>
#include <vector>
#include <cassert>
#include <gmpxx.h>

/**
  \brief A re-definition of the GMP C++ interface class for Big Integer
  In order to match most of the standard operators of integers in C++
  And establish operator similarities with other big integers libraries
 */

class BigIntMpz
{
public:
  // Constructors
  BigIntMpz() = default;
  /** Cstor requiring string */
  BigIntMpz(const std::string& myString) : m_BigIntMpz(mpz_class(myString)) {}
  /** Cstor converting integer into Big Int */
  explicit BigIntMpz(const int& myInt) : m_BigIntMpz(mpz_class(std::to_string(myInt))) {}
  /** Cstor converting unsigned integer into Big Int */
  explicit BigIntMpz(const unsigned int& myInt) : m_BigIntMpz(mpz_class(std::to_string(myInt))) {}
  /** Cstor converting unsigned long integer into Big Int */
  explicit BigIntMpz(const unsigned long int& myInt) : m_BigIntMpz(mpz_class(std::to_string(myInt))) {}
  /** Copy cstor */
  explicit BigIntMpz(const mpz_class& src) : m_BigIntMpz(src) {}
  /** Move cstor */
  explicit BigIntMpz(mpz_class&& src) : m_BigIntMpz(std::move(src)) {}
  /** Cstor rounding input double */
  BigIntMpz(const double realInput);

  //Comparison operators
  /** Comparison operator: Equality between Big Int Mpz*/
  bool operator == (const BigIntMpz& a) const;
  /** Comparison operator: Non-Equality between Big Int Mpz*/
  bool operator != (const BigIntMpz& a) const;
  /** Comparison operator: "Less than" between Big Int Mpz*/
  bool operator < (const BigIntMpz& a) const;
  /** Comparison operator: "Greater than" between Big Int Mpz */
  bool operator > (const BigIntMpz& a) const;
  /** Comparison operator: "Less than or equal to" between Big Int Mpz */
  bool operator <= (const BigIntMpz& a) const;
  /** Comparison operator: "Greater than or equal to" between Big Int Mpz */
  bool operator >= (const BigIntMpz& a) const;

  //Calculus operations
  /** Operator addition assignment overloaded */
  const BigIntMpz& operator += (const BigIntMpz& a);
  /** Operator subtraction assignment overloaded */
  const BigIntMpz& operator -= (const BigIntMpz& a);
  /** Operator multiplication assignment overloaded */
  const BigIntMpz& operator *= (const BigIntMpz& a);
  /** Operator division assignment overloaded - Warning: Quotient only */
  const BigIntMpz& operator /= (const BigIntMpz& a);
  /** Operator modulo assignment overloaded */
  const BigIntMpz& operator %= (const BigIntMpz& a);
  /** Function for multiplication followed by addition, from GMP lib. */
  void addmul(const BigIntMpz& a, const BigIntMpz& b);
  /** Function for power exponentiation at a given modulo, from GMP lib.
   * Warning: core dumped if modulo is even
   * Warning: core dumped if any value is < 0 */
  void powm_sec(const BigIntMpz& base, const BigIntMpz& exponent, const BigIntMpz& modulo);
  /** Function logarithm in a given base (2 to 62), from GMP lib. function returning the size of an int. in a given base */
  unsigned int log_in_base(const int base) const;

  /** Function to write into given ostream */
  inline std::ostream& write(std::ostream& os) const {return os << m_BigIntMpz;}

  /** Function to return a string */
  inline const std::string toString() const {return m_BigIntMpz.get_str();}

  /** Temporary function to return a signed long int */
  inline int toint () {return m_BigIntMpz.get_si();}

  /** Function to provide random unsigned long as seed */
  unsigned long provideSeed();

  /** Function to provide random Big Int Mpz of a given byte size */
  BigIntMpz& randomUpToTwoPower(const int& keyLength);
  /** Function to provide random Big Int Mpz up to a given limit */
  BigIntMpz& randomUpTo(const BigIntMpz& upperLimit);
  /** Function to provide random Big Int Mpz up to a given limit, with a random seed generator */
  BigIntMpz& randomWithGivenSeedUpTo(const int& seed, const BigIntMpz& upperLimit);

  /** Function providing bits decomposition of a big integer */
  std::vector<bool> decomposeIntoBits() const;

  /** Function to get the GMP C++ interface instance of Big Int Mpz */
  const mpz_class getBigInt() const {return m_BigIntMpz;}

  //Mathematical tests
  /** Function to determine if a Big Int Mpz is prime,
   * using a recursive algorithm whose iteration number should be given as input
   * from GMP lib. */
  bool testIfPrime(const int& reps) const;

  //Memory management
  void swap(BigIntMpz& a);
  static const BigIntMpz& zero() {  // thread-safe since c++11
    static const BigIntMpz s_zero = BigIntMpz(0); // initialized on first call of zero()
    return s_zero;
  }
  static const BigIntMpz& one() {  // thread-safe since c++11
    static const BigIntMpz s_one = BigIntMpz(1); // initialized on first call of one()
    return s_one;
  }

private:
  mpz_class m_BigIntMpz;
  /** Function to compare an input Big Int Mpz applied to the considered instance
* from GMP lib - should not be used by the user, only internally */
  int compMpz(const BigIntMpz& a) const;
};

inline std::ostream& operator<<(std::ostream& os, const BigIntMpz& bi) {
  return bi.write(os);
}

inline void addmul(BigIntMpz& res,
                   const BigIntMpz& a,
                   const BigIntMpz& b) {res.addmul(a, b);}

inline void powm_sec(BigIntMpz& res,
                     const BigIntMpz& base,
                     const BigIntMpz& exponent,
                     const BigIntMpz& modulo) {res.powm_sec(base, exponent, modulo);}

inline unsigned int log_in_base(const BigIntMpz& a,
                                const int base) { return a.log_in_base(base); }

inline unsigned int log_in_2base(const BigIntMpz& a) { return a.log_in_base(2); }

inline std::vector<bool> decomposeIntoBits(const BigIntMpz& a) { return a.decomposeIntoBits(); }

inline void swap(BigIntMpz& a, BigIntMpz& b) {a.swap(b);}

inline bool testIfPrime(const BigIntMpz& a, const int& reps) {return a.testIfPrime(reps);}

inline BigIntMpz getNonZeroRandomUpTo(const BigIntMpz UpperLimit)
{
  BigIntMpz testedNumber;

  do {testedNumber.randomUpTo(UpperLimit);}
  while(testedNumber == BigIntMpz::zero());

  return testedNumber;
}

inline BigIntMpz operator * (const BigIntMpz& a, const BigIntMpz& b)
{return BigIntMpz(a.getBigInt() * b.getBigInt());}

inline BigIntMpz operator * (const int& a, const BigIntMpz& b)
{return BigIntMpz(BigIntMpz(a).getBigInt() * b.getBigInt());}

inline BigIntMpz operator / (const BigIntMpz& a, const BigIntMpz& b)
{return BigIntMpz(a.getBigInt() / b.getBigInt());}

inline BigIntMpz operator % (const BigIntMpz& a, const BigIntMpz& b)
{return BigIntMpz(a.getBigInt() % b.getBigInt());}

inline BigIntMpz operator - (const BigIntMpz& a, const BigIntMpz& b)
{return BigIntMpz(a.getBigInt() - b.getBigInt());}

inline BigIntMpz operator + (const BigIntMpz& a, const BigIntMpz& b)
{return BigIntMpz(a.getBigInt() + b.getBigInt());}

#endif /* SRC_BIGINT_BIGINTMPZ_HPP */
