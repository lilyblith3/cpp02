#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(void) : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = n << bits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(f * (1 << bits));
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->fixedPointValue) / (1 << bits);
}

int Fixed::toInt(void) const {
    return this->fixedPointValue >> bits;
}

int Fixed::getRawBits(void) const {
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->fixedPointValue = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}