//bigintmpz.cpp

#include <cstdlib>
#include <cmath>

#include "bigIntMPZ.hpp"


// Cstor
BigIntMpz::BigIntMpz(const double realInput)
{
  m_BigIntMpz = mpz_class("0", 10);
  mpz_set_d(m_BigIntMpz.get_mpz_t(), realInput);

  double remainder = fabs(realInput - stod(m_BigIntMpz.get_str()));
  //std::cout << "Double = " << realInput << " - Remainder = " << remainder << std::endl;

  if((remainder >= 0.5) && (realInput >= 0.))
  {m_BigIntMpz += BigIntMpz::one().m_BigIntMpz;}
  else if ((remainder >= 0.5) && (realInput < 0.))
  {m_BigIntMpz -= BigIntMpz::one().m_BigIntMpz;}
}


//Comparison Operations
bool BigIntMpz::operator == (const BigIntMpz& a) const
{
  if (this->compMpz(a) == 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator == (const double& d) const
{
  if (this->compMpzVsD(d) == 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator == (const unsigned int& ui) const
{
  if (this->compMpzVsUi(ui) == 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator == (const unsigned long int& ui) const
{
  if (this->compMpzVsUi(ui) == 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator == (const signed int& si) const
{
  if (this->compMpzVsSi(si) == 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator == (const signed long int& di) const
{
  if (this->compMpzVsSi(di) == 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator != (const BigIntMpz& a) const
{ return !(*this == a); }

bool BigIntMpz::operator != (const double& d) const
{ return !(*this==d); }

bool BigIntMpz::operator != (const unsigned int& ui) const
{ return !(*this==ui); }

bool BigIntMpz::operator != (const unsigned long int& ui) const
{ return !(*this==ui); }

bool BigIntMpz::operator != (const signed int& si) const
{ return !(*this==si); }

bool BigIntMpz::operator != (const signed long int& di) const
{ return !(*this==di); }

bool BigIntMpz::operator < (const BigIntMpz& a) const
{
  if (this->compMpz(a) < 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator < (const double& d) const
{
  if (this->compMpzVsD(d) < 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator < (const unsigned int& ui) const
{
  if (this->compMpzVsUi(ui) < 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator < (const unsigned long int& ui) const
{
  if (this->compMpzVsUi(ui) < 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator < (const signed int& si) const
{
  if (this->compMpzVsSi(si) < 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator < (const signed long int& si) const
{
  if (this->compMpzVsSi(si) < 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator > (const BigIntMpz& a) const
{
  if (this->compMpz(a) > 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator > (const double& d) const
{
  if (this->compMpzVsD(d) > 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator > (const unsigned int& ui) const
{
  if (this->compMpzVsUi(ui) > 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator > (const unsigned long int& ui) const
{
  if (this->compMpzVsUi(ui) > 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator > (const signed int& si) const
{
  if (this->compMpzVsSi(si) > 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator > (const signed long int& si) const
{
  if (this->compMpzVsSi(si) > 0)
  {return true;}
  else
  {return false;}
}

bool BigIntMpz::operator <= (const BigIntMpz& a) const
{ return !(*this > a); }

bool BigIntMpz::operator <= (const double& d) const
{ return !(*this > d); }

bool BigIntMpz::operator <= (const unsigned int& ui) const
{ return !(*this > ui); }

bool BigIntMpz::operator <= (const unsigned long int& ui) const
{ return !(*this > ui); }

bool BigIntMpz::operator <= (const signed int& si) const
{ return !(*this > si); }

bool BigIntMpz::operator <= (const signed long int& si) const
{ return !(*this > si); }

bool BigIntMpz::operator >= (const BigIntMpz& a) const
{ return !(*this < a); }

bool BigIntMpz::operator >= (const double& d) const
{ return !(*this < d); }

bool BigIntMpz::operator >= (const unsigned int& ui) const
{ return !(*this < ui); }

bool BigIntMpz::operator >= (const unsigned long int& ui) const
{ return !(*this < ui); }

bool BigIntMpz::operator >= (const signed int& si) const
{ return !(*this < si); }

bool BigIntMpz::operator >= (const signed long int& si) const
{ return !(*this < si); }

//Calculus Operations
const BigIntMpz& BigIntMpz::operator += (const BigIntMpz& a)
{
  //mpz_add(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), a.m_BigIntMpz.get_mpz_t());
  m_BigIntMpz = m_BigIntMpz + a.m_BigIntMpz;
  return *this;
}

const BigIntMpz& BigIntMpz::operator += (const unsigned int& ui)
{
  mpz_add_ui(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), ui);
  return *this;
}

const BigIntMpz& BigIntMpz::operator += (const unsigned long int& ui)
{
  mpz_add_ui(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), ui);
  return *this;
}

const BigIntMpz& BigIntMpz::operator += (const signed int& si)
{
  if(si >= 0)
  { *this += (unsigned) si; }
  else
  {*this -= (unsigned) si;}
  return *this;
}

const BigIntMpz& BigIntMpz::operator += (const signed long int& si)
{
  if(si >= 0)
  { *this += (long unsigned) si; }
  else
  {*this -= (long unsigned) si;}
  return *this;
}

const BigIntMpz& BigIntMpz::operator -= (const BigIntMpz& a)
{
  //mpz_sub(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), a.m_BigIntMpz.get_mpz_t());
  m_BigIntMpz = m_BigIntMpz - a.m_BigIntMpz;
  return *this;
}

const BigIntMpz& BigIntMpz::operator -= (const unsigned int& ui)
{
  mpz_sub_ui(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), ui);
  return *this;
}

const BigIntMpz& BigIntMpz::operator -= (const unsigned long int& ui)
{
  mpz_add_ui(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), ui);
  return *this;
}

const BigIntMpz& BigIntMpz::operator -= (const signed int& si)
{
  if(si >= 0)
  { *this -= (unsigned) si; }
  else
  {*this += (unsigned) si;}
  return *this;
}

const BigIntMpz& BigIntMpz::operator -= (const signed long int& si)
{
  if(si >= 0)
  { *this -= (unsigned) si; }
  else
  {*this += (unsigned) si;}
  return *this;
}

const BigIntMpz& BigIntMpz::operator *= (const BigIntMpz& a)
{
  //mpz_mul(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), a.m_BigIntMpz.get_mpz_t());
  m_BigIntMpz = m_BigIntMpz * a.m_BigIntMpz;
  return *this;
}

const BigIntMpz& BigIntMpz::operator *= (const unsigned int& ui)
{
  mpz_mul_ui(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), ui);
  return *this;
}

const BigIntMpz& BigIntMpz::operator *= (const unsigned long int& ui)
{
  mpz_mul_ui(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), ui);
  return *this;
}

const BigIntMpz& BigIntMpz::operator *= (const signed int& si)
{
  mpz_mul_si(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), si);
  return *this;
}

const BigIntMpz& BigIntMpz::operator *= (const signed long int& si)
{
  mpz_mul_si(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), si);
  return *this;
}

const BigIntMpz& BigIntMpz::operator /= (const BigIntMpz& a)
{
  m_BigIntMpz = m_BigIntMpz / a.m_BigIntMpz;
  return *this;
}

const BigIntMpz& BigIntMpz::operator /= (const unsigned int& ui)
{
  mpz_div_ui(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), ui);
  return *this;
}

const BigIntMpz& BigIntMpz::operator /= (const unsigned long int& ui)
{
  mpz_div_ui(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), ui);
  return *this;
}

const BigIntMpz& BigIntMpz::operator /= (const signed int& si)
{
  if(si > 0)
  { *this /= (unsigned int) si; }
  else
  {
    *this /= (unsigned int) si;
    *this *= (-1);
  }
  return *this;
}

const BigIntMpz& BigIntMpz::operator /= (const signed long int& si)
{
  if(si > 0)
  { *this /= (unsigned long int) si; }
  else
  {
    *this /= (unsigned long int) si;
    *this *= (-1);
  }
  return *this;
}

const BigIntMpz& BigIntMpz::operator %= (const BigIntMpz& a)
{
  //mpz_mod(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), a.m_BigIntMpz.get_mpz_t());
  m_BigIntMpz = m_BigIntMpz % a.m_BigIntMpz;
  return *this;
}

const BigIntMpz& BigIntMpz::operator %= (const unsigned int& ui)
{
  mpz_mod_ui(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), ui);
  return *this;
}

const BigIntMpz& BigIntMpz::operator %= (const unsigned long int& ui)
{
  mpz_mod_ui(m_BigIntMpz.get_mpz_t(), m_BigIntMpz.get_mpz_t(), ui);
  return *this;
}

const BigIntMpz& BigIntMpz::operator %= (const signed int& si)
{
  if(si > 0)
  { *this %= (unsigned long int) si; }
  else
  {
    *this %= (unsigned long int) si;
    *this += si;
  }
  return *this;
}

const BigIntMpz& BigIntMpz::operator %= (const signed long int& si)
{
  if(si > 0)
  { *this %= (unsigned long int) si; }
  else
  {
    *this %= (unsigned long int) si;
    *this += si;
  }
  return *this;
}

void BigIntMpz::addmul(const BigIntMpz& a, const BigIntMpz& b)
{
  //mpz_addmul(m_BigIntMpz.get_mpz_t(), a.m_BigIntMpz.get_mpz_t(), b.m_BigIntMpz.get_mpz_t());
  m_BigIntMpz = m_BigIntMpz + a.m_BigIntMpz * b.m_BigIntMpz;
}

//Warning: core dumped if modulo is even
//Warning: core dumped if any value is < 0
void BigIntMpz::powm_sec(const BigIntMpz& base, const BigIntMpz& exponent, const BigIntMpz& modulo)
{
  mpz_powm_sec(m_BigIntMpz.get_mpz_t(),
               base.m_BigIntMpz.get_mpz_t(),
               exponent.m_BigIntMpz.get_mpz_t(),
               modulo.m_BigIntMpz.get_mpz_t());
}

unsigned int BigIntMpz::log_in_base(const int base) const
{
  return mpz_sizeinbase(m_BigIntMpz.get_mpz_t(),
                        base);
}

BigIntMpz& BigIntMpz::randomUpToTwoPower(const int& keyLength)
{
  BigIntMpz nbBits(keyLength);
  gmp_randclass randomState(gmp_randinit_default);
  randomState.seed(provideSeed()); //uses std::rand to generate random seed at each call
  m_BigIntMpz = randomState.get_z_bits(nbBits.getBigInt());
  return *this;
}

BigIntMpz& BigIntMpz::randomUpTo(const BigIntMpz& upperLimit)
{
  randomWithGivenSeedUpTo(int(provideSeed()), upperLimit);
  return *this;
}

unsigned long BigIntMpz::provideSeed()
{return (unsigned long)(std::rand());}

BigIntMpz& BigIntMpz::randomWithGivenSeedUpTo(const int& seed, const BigIntMpz& upperLimit)
{
  gmp_randclass randomState(gmp_randinit_default);
  unsigned long mySeed {(unsigned long) seed}; // Clean casting
  randomState.seed(mySeed);

  m_BigIntMpz = randomState.get_z_range(upperLimit.m_BigIntMpz);
  return *this;
}

std::vector<bool> BigIntMpz::decomposeIntoBits() const
{
  std::vector<bool> myBits;
  unsigned int nbBits = this->log_in_base(2);
  std::cout << "nbBits = " << nbBits << std::endl;
  // Decompose big int into vector of bools, length=nbBits

  mpz_class consideredNbForDivision = m_BigIntMpz;
  mpz_class divisor(2);
  for(unsigned int i=0; i<nbBits; i++)
  {
    mpz_class intQuotient;
    mpz_class intRemainder;

    // Divide the number by 2.
    // Get the integer quotient for the next iteration.
    // Get the remainder for the binary digit.
    mpz_tdiv_qr(intQuotient.get_mpz_t(),
                intRemainder.get_mpz_t(),
                consideredNbForDivision.get_mpz_t(),
                divisor.get_mpz_t());
    // More on the selected function: https://gmplib.org/manual/Integer-Division#index-mpz_005ftdiv_005fr

    // Repeat the steps until the quotient is equal to 0.
    consideredNbForDivision = intQuotient;

    if(intRemainder == mpz_class(0))
    {myBits.push_back(false);}
    else
    {myBits.push_back(true);}

    // If nbBits is overestimated - which could happen because of approximation in log_2
    if(intQuotient == mpz_class(0))
    {break;}
  }

  std::cout << "myBits size = " << myBits.size() << std::endl;
  return myBits;
}

//Mathematical tests
bool BigIntMpz::testIfPrime(const int& reps) const
{
  if (mpz_probab_prime_p(m_BigIntMpz.get_mpz_t(), reps) == 2)
  {
    //std::cout << "High probability that " << m_BigIntMpz << " is prime" << std::endl;
    return true;
  }
  else if (mpz_probab_prime_p(m_BigIntMpz.get_mpz_t(), reps) == 1)
  {
    //std::cout << "Non-zero probability that " << m_BigIntMpz << " is prime" << std::endl;
    return false;
  }
  else
  {
    //std::cout << "Zero probability that " << m_BigIntMpz << " is prime" << std::endl;
    return false;
  }
}

int BigIntMpz::compMpz(const BigIntMpz& a) const
{ return cmp(m_BigIntMpz, a.m_BigIntMpz); }

int BigIntMpz::compMpzVsUi(const unsigned long int& ui) const
{ return mpz_cmp_ui(m_BigIntMpz.get_mpz_t(), ui); }

int BigIntMpz::compMpzVsSi(const signed long int& si) const
{ return mpz_cmp_si(m_BigIntMpz.get_mpz_t(), si); }

int BigIntMpz::compMpzVsD(const double& d) const
{ return mpz_cmp_d(m_BigIntMpz.get_mpz_t(), d); }


//Memory management
void BigIntMpz::swap(BigIntMpz& a)
{
  //mpz_swap(myBigIntGMP.get_mpz_t(), b.myBigIntGMP.get_mpz_t());
  m_BigIntMpz.swap(a.m_BigIntMpz);
}
