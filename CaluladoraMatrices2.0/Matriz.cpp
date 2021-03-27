#include "Matriz.h"

#define CLS system("cls");cout<<"\n";

void Matriz::GenerarMatriz() {
	if (filas > 10 || columnas > 10) {
		throw "Las dimensiones de la matriz no pueden ser mayor a 10 elementos";
		return;
	}


	if (filas == columnas) {
		nombreMatriz = "Matriz Cuadrada";//Como sabemos que es una matriz cuadrada, la nombramos como tal
		//Usamos este loop para inicializar la matriz como una matriz identidad
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				if (i == j) matriz[i][j] = 1;
				else matriz[i][j] = 0;
			}
		}
	}
	else {
		this->AsignarValores(0);
		nombreMatriz = "Matriz Rectangular";//En caso de no ser una matriz cuadrada la nombramos "Matriz rectangular"
	}
}

Matriz::Matriz():filas(3),columnas(3) {
	GenerarMatriz();
}

Matriz::Matriz(unsigned short filas,unsigned short columnas) :filas(filas), columnas(columnas) {
	GenerarMatriz();

}

Matriz::Matriz(unsigned short filasXcolumnas) : filas(filasXcolumnas), columnas(filasXcolumnas) {
	GenerarMatriz();
}

unsigned short Matriz::ObtenerFilas() {
	return filas;
}

unsigned short Matriz::ObtenerColumnas() {
	return columnas;
}

void Matriz::AsignarValor(short fila, short columna, float valor) {
	if (fila <= 0 || fila > this->filas) throw("Fila invalida");
	if (columna <= 0 || columna > this->columnas) {
		throw("Columna invalida");
	}

	this->matriz[fila-1][columna-1] = valor;
}

float Matriz::ObtenerValor(unsigned short fila, unsigned short columna) {
	if (fila <= 0 || fila > filas) throw("Fila invalida");
	if (columna <= 0 || columna > columnas) {
		throw("Columna invalida");
	}

	return matriz[fila-1][columna-1];
}

void Matriz::DibujaMatriz() {
	for (int i = 0; i < filas; i++) {
		cout << "\t\t\t\t|";
		for (int j = 0; j < columnas; j++) {
			if (j == columnas - 1)
				cout << matriz[i][j];
			else
				cout << matriz[i][j] << "\t";
		}
		cout << "|" << endl;
	}
}

void Matriz::AsignarValores(float valor) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			matriz[i][j] = valor;
		}
	}
}

void Matriz::AsignarValoresManual() {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			CLS
			this->DibujaMatriz();
			cout << "\n\t\t\t\tIngresa el valor [" << i + 1 << ", " << j + 1 << "]:";
			cin >> matriz[i][j];
		}
	}
}

void Matriz::CrearMatriz(unsigned short filas, unsigned short columnas) {
	LimpiarMatriz();

	this->filas = filas;
	this->columnas = columnas;

	GenerarMatriz();
}

void Matriz::LimpiarMatriz() {
	filas = 1;
	columnas = 1;
	nombreMatriz = "";
}

void Matriz::operator<<(Matriz& mat2) {
	Matriz aux;
	aux.LimpiarMatriz();
	aux = mat2;
	mat2.LimpiarMatriz();
	mat2 = *this;
	this->LimpiarMatriz();
	*this = aux;
}

Matriz Matriz::operator+(Matriz mat2) {
	if (filas != mat2.filas || columnas != mat2.columnas) {
		throw("Para hacer una suma de matrices ambas deben tener la misma dimensión.");
	}
	//Ya que verificamos que si se puede hacer una suma, creamos una matriz auxiliar y la
	//hacemos del tamaño de la matriz 2 (podria ser cualquiera de las 2)
	Matriz matrizResultante(filas, columnas);
	//matrizResultante.CrearMatriz(mat2.filas, mat2.columnas);

	for (int i = 1; i <= filas; i++) {
		for (int j = 1; j <= columnas; j++) {
			matrizResultante.AsignarValor(i, j, ObtenerValor(i, j) + mat2.ObtenerValor(i, j));
		}
	}
	return matrizResultante;
}

Matriz Matriz::operator-(Matriz mat2) {
	if (filas != mat2.filas || columnas != mat2.columnas) {
		throw("Para hacer una resta de matrices ambas deben tener la misma dimensión.");
	}
	//Ya que verificamos que si se puede hacer una suma, creamos una matriz auxiliar y la
	//hacemos del tamaño de la matriz 2 (podria ser cualquiera de las 2)
	Matriz matrizResultante(filas, columnas);
	//matrizResultante.CrearMatriz(mat2.filas, mat2.columnas);

	for (int i = 1; i <= filas; i++) {
		for (int j = 1; j <= columnas; j++) {
			matrizResultante.AsignarValor(i, j, ObtenerValor(i, j) - mat2.ObtenerValor(i, j));
		}
	}
	return matrizResultante;
}

Matriz Matriz::operator*(Matriz mat2) {
	if (columnas != mat2.filas) {
		throw("Para hacer una multiplicacion de matrices, la matriz A debe tener la misma cantidad de columnas que de filas de la matriz B.");
	}
	//Ya que verificamos que si se puede hacer una suma, creamos una matriz auxiliar y la
	//hacemos del tamaño de la matriz 2 (podria ser cualquiera de las 2)
	Matriz matrizResultante(filas, mat2.columnas);
	//Matriz aux(; 
	//matrizResultante.CrearMatriz(mat2.filas, mat2.columnas);
	matrizResultante.AsignarValores(0);
	for (int i = 1; i <= mat2.ObtenerColumnas(); i++) {
		for (int j = 1; j <= filas; j++) {
			for (int k = 1; k <= columnas; k++) {
				matrizResultante.AsignarValor(j, i, matrizResultante.ObtenerValor(j, i) + this->ObtenerValor(j, k) * mat2.ObtenerValor(k, i));
			}
		}
	}

	return matrizResultante;
}