#include "LibDoses.h"

#pragma once
class vector2
{
public:
	double x, y;
	vector2(double X = 0, double Y = 0) : x(X), y(Y) {}
};

class vector3
{
public:
	double x, y, z;
	vector3(double X = 0, double Y = 0, double Z = 0) : x(X), y(Y), z(Z) {}
};

class vector4
{
public:
	double x, y, z, w;
	vector4(double X = 0, double Y = 0, double Z = 0, double W = 0) : x(X), y(Y), z(Z), w(W) {}
};

// Basis Vectors
const vector3 i(1, 0, 0);
const vector3 j(0, 1, 0);
const vector3 k(0, 0, 1);

// Addition
vector2 operator+(vector2& lhs, vector2& rhs)
{
	return vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}
vector3 operator+(vector3& lhs, vector3& rhs)
{
	return vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}
vector4 operator+(vector4& lhs, vector4& rhs)
{
	return vector4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

// Dot product
double operator*(vector2& lhs, vector2& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

// Magnatude
double mag(vector2& vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

// Angle Between
double angle(vector2& vec1, vector2& vec2)
{

}

// Normalizing
vector3& normal(const vector3& vec)
{

}

void normalize(vector3& vec)
{

}

// Cross Product
vector3 operator^(vector3& lhs, vector3 rhs)
{
	
}

