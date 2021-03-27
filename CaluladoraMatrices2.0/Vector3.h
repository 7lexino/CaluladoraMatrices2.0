#pragma once
#include <math.h>
#include "Matriz.h"
class Vector3
{
	Matriz vector = Matriz(4, 4);

public:
	float x{ 0 }, y{ 0 }, z{0};
	Vector3();
	Vector3(float xyz);
	Vector3(float x, float y, float z);

	Vector3 operator-(Vector3& vector);
	Vector3 operator+(Vector3& vector);
	Vector3& operator=(Vector3& vector);

	Vector3 Trasladar(Vector3 valor);
	Vector3 Trasladar(float x, float y, float z);
	Vector3 Rotar(float angulo);
	Vector3 Escalar(Vector3 valor);
	Vector3 Escalar(float x, float y, float z);
};

