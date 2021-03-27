#include "Cuaternio.h"

Cuaternio::Cuaternio():a(1), a1(1), a2(1), a3(1) {

}

Cuaternio::Cuaternio(float a, float a1, float a2, float a3) : a(a), a1(a1), a2(a2), a3(a3) {

}

Cuaternio Cuaternio::operator+(Cuaternio c2) {
	return Cuaternio(this->a + c2.a, this->a1 + c2.a1, this->a2 + c2.a2, this->a3 + c2.a3);
}

Cuaternio Cuaternio::operator-(Cuaternio c2) {
	return Cuaternio(this->a - c2.a, this->a1 - c2.a1, this->a2 - c2.a2, this->a3 - c2.a3);
}

Cuaternio Cuaternio::operator*(Cuaternio c2) {
	float a = (this->a * c2.a) - (this->a1 * c2.a1) - (this->a2 * c2.a2) - (this->a3 * c2.a3);
	float a1 = (this->a * c2.a1) + (c2.a * this->a1) + (this->a2 * c2.a3) - (this->a3 * c2.a2);
	float a2 = (c2.a * this->a2) + (this->a * c2.a2) + (this->a3 * c2.a1) - (this->a1 * c2.a3);
	float a3 = (c2.a * this->a3) + (this->a * c2.a3) - (this->a2 * c2.a1) + (this->a1 * c2.a2);

	return Cuaternio(a, a1, a2, a3);
}

void Cuaternio::SetA(float a)
{
	this->a = a;
}

void Cuaternio::SetA1(float a1)
{
	this->a1 = a1;
}

void Cuaternio::SetA2(float a2)
{
	this->a2 = a2;
}

void Cuaternio::SetA3(float a3)
{
	this->a3 = a3;
}

float Cuaternio::GetA()
{
	return a;
}

float Cuaternio::GetA1()
{
	return a1;
}

float Cuaternio::GetA2()
{
	return a2;
}

float Cuaternio::GetA3()
{
	return a3;
}
