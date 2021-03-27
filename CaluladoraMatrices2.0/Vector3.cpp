#include "Vector3.h"

Vector3::Vector3() :x(0), y(0), z(0) {

}

Vector3::Vector3(float xyz) : x(xyz), y(xyz), z(xyz) {

}

Vector3::Vector3(float x, float y, float z) :x(x), y(y), z(z) {
	
}

Vector3 Vector3::operator-(Vector3& vector)
{
	Vector3 temp;

	temp.x = x - vector.x;
	temp.y = y - vector.y;
	temp.z = z - vector.z;

	return temp;
}

Vector3 Vector3::operator+(Vector3& vector)
{
	Vector3 temp;

	temp.x = x + vector.x;
	temp.y = y + vector.y;
	temp.z = z + vector.z;

	return temp;
}

Vector3& Vector3::operator=(Vector3& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;

	return *this;
}