#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <cmath>

template <class T>
double scalar_difference(T d1, T d2)
{
	return fabs(d1.getScalarValue() - d2.getScalarValue());
}

template <class T>
bool equals(T c1, T c2)
{
	return (c1 == c2) ? true : false;
}

template <class T>
bool smallerThan(const T &c1, const T &c2)
{
	return (c1 < c2) ? true : false;
}

template <class T>
bool greaterThan(const T &c1, const T &c2)
{
	return (c1 > c2) ? true : false;
}

#endif
