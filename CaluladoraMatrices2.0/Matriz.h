#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

class Matriz
{
private:
#pragma region Atributos_Privados
	unsigned short filas{1};
	unsigned short columnas{1};
	string nombreMatriz="";
	float matriz[10][10];

#pragma endregion

#pragma region Métodos_Privados
	void GenerarMatriz();
#pragma endregion

public:
#pragma region Atributos_Publicos
	enum  TiposMatrices
	{
		MatrizNula = 1, //Todos sus elementos son 0
		MatrizCuadrada, //Tiene el mismo número de filas y columnas
		MatrizRectangular, //Tiene distinta cantidad de filas que de columnas
		MatrizColumna, //Tiene solo 1
		MatrizFila, //Tiene solo 1 fila
		MatrizDiagonalPrincipal, //Matriz cuadrada donde sus elementos son todos nulos excepto la diagonal principal
		MatrizDiagonalSecundaria, //Matriz cuadrada donde sus elementos son todos nulos excepto la diagonal secundaria
		MatrizIdentidad //Matriz diagonal 
	};
#pragma endregion

#pragma region Constructores_Destructores
	Matriz();
	Matriz(unsigned short, unsigned short);
	Matriz(unsigned short);
	~Matriz() {};
#pragma endregion

#pragma region Métodos_Públicos
	unsigned short ObtenerFilas();
	unsigned short ObtenerColumnas();
	void LimpiarMatriz();
	void CrearMatriz(unsigned short, unsigned short);
	void AsignarValor(short, short, float);
	void AsignarValores(float);
	void AsignarValoresManual();
	float ObtenerValor(unsigned short, unsigned short);
	void DibujaMatriz();

	void operator<<(Matriz&);
	Matriz operator+(Matriz);
	Matriz operator-(Matriz);
	Matriz operator*(Matriz);

#pragma endregion
};