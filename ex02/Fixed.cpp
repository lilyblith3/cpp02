#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int n)
{
    value = n << fractionalBits;
}

Fixed::Fixed(const float f)
{
    value = (int)roundf(f * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        value = other.value;
    return *this;
}

int Fixed::getRawBits() const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat() const
{
    return (float)value / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return value >> fractionalBits;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.value = this->value + other.value;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.value = this->value - other.value;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    long tmp = (long)this->value * (long)other.value;
    result.value = (int)(tmp >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    long tmp = ((long)this->value << fractionalBits) / other.value;
    result.value = (int)tmp;
    return result;
}

Fixed &Fixed::operator++()
{
    value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    value++;
    return temp;
}

Fixed &Fixed::operator--()
{
    value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    value--;
    return temp;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->value != other.value;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.value < b.value)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.value < b.value)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.value > b.value)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.value > b.value)
        return a;
    else
        return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}