#include "Fixed.hpp"

Fixed::Fixed(void): fixedPointValue(0)
{
          std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
          *this = other;
          std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
          if (this != &other)
                    this->fixedPointValue = other.getRawBits();
          return *this;
}

Fixed::~Fixed(void)
{
          std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
          return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->fixedPointValue = raw;
}