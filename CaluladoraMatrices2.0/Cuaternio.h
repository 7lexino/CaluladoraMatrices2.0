#pragma once
class Cuaternio
{
	float a, a1, a2, a3;
public:
	Cuaternio();
	Cuaternio(float, float a1, float a2, float a3);

	Cuaternio operator+(Cuaternio c2);
	Cuaternio operator-(Cuaternio c2);
	Cuaternio operator*(Cuaternio c2);

	void SetA(float a);
	void SetA1(float a1);
	void SetA2(float a2);
	void SetA3(float a3);

	float GetA();
	float GetA1();
	float GetA2();
	float GetA3();
};

