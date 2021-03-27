#include <iostream>
#include <string>
#include <time.h> //Para crear nuestra función que detiene la aplicación
#include "MisFunciones.h"
#include "Matriz.h"
#include "Cuaternio.h"
#include "Vector3.h"

#define CLS system("cls");cout<<"\n";
#define PI 3.14159265

using std::cout;
using std::cin;
using std::endl;
using std::string;

void Operaciones();
void CambiarValores();
void Sumar();
void Restar();
void Multiplicar();
void MatrizPorVector();
void CambiarDimensionesMatriz();
void GenerarMatrizCompuesta();
void MatrizCompuesta2();
void Cuaternios();

Matriz matriz1, matriz2, matrizR;
Matriz matrizTra, matrizRot, matrizEsc, matrizCom;



float matrizCompuesta[4][4] = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
};

float matrizAuxiliar[4][4] = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
};

float matrizTransformacion[4][4] = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
};


void main() {
	matrizCom = matrizTra = matrizRot = matrizEsc = Matriz(4, 4); //Iniciamos las matrices de transformacion

	//Variable para guardar la opción de la operación que quiere realizar
	bool bValMatriz1=true, bValMatriz2=true; //Variables para validar si las matrices son correctas
	char cOperacion, cAccion;
	char cfilas[2], ccolumnas[2], cfilas2[2], ccolumnas2[2]; //filas y columnas de las matrices en char para validarlas
	unsigned short nfilas=1, ncolumnas=1, nfilas2=1, ncolumnas2=1;
	
	cout << endl;
	MisFunciones::Mensaje("Iniciando programa...");
	
	///En este do While hacemos la captura y validación de las matrices
	do
	{
		bValMatriz1 = true;
		CLS
		cout << "\t\t\t\tDimensiones de la [Matriz A]:" << endl;

		cout << "\t\t\t\tFilas: ";
		cin >> cfilas;
		if (!MisFunciones::EsEntero(cfilas)) {
			bValMatriz1 = false;
			continue;
		}

		cout << "\t\t\t\tColumnas: ";
		cin >> ccolumnas;
		if (!MisFunciones::EsEntero(ccolumnas)) {
			bValMatriz1 = false;
			continue;
		}

	} while (!bValMatriz1);

	do
	{
		bValMatriz2 = true;
		CLS
		cout << "\t\t\t\tDimensiones de la [Matriz B]:" << endl;

		cout << "\t\t\t\tFilas: ";
		cin >> cfilas2;
		if (!MisFunciones::EsEntero(cfilas2)) {
			bValMatriz2 = false;
			continue;
		}

		cout << "\t\t\t\tColumnas: ";
		cin >> ccolumnas2;
		if (!MisFunciones::EsEntero(ccolumnas2)) {
			bValMatriz2 = false;
			continue;
		}
	} while (!bValMatriz2);

		
	nfilas = (unsigned short)atoi(cfilas);
	ncolumnas = (unsigned short)atoi(ccolumnas);
	nfilas2 = (unsigned short)atoi(cfilas2);
	ncolumnas2 = (unsigned short)atoi(ccolumnas2);
	
	matriz1.CrearMatriz(nfilas, ncolumnas);
	matriz2.CrearMatriz(nfilas2, ncolumnas2);

	//system("pause>nul");
	do
	{
		CLS
		MisFunciones::Mensaje("Cargando...");
		CLS
		cout << "\n\t\t\t\t[Matriz A]" << endl;
		matriz1.DibujaMatriz();
		cout << "\n\t\t\t\t[Matriz B]" << endl;
		matriz2.DibujaMatriz();

		cout << endl;
		cout << "\t\t\t\t///////////////////////////////////////////////\n";
		cout << "\t\t\t\t/// Elige una accion a realizar             ///\n";
		cout << "\t\t\t\t/// [1] Operaciones                         ///\n";
		cout << "\t\t\t\t/// [2] Cambiar valores de las matrices     ///\n";
		cout << "\t\t\t\t/// [3] Intercambiar matrices               ///\n";
		cout << "\t\t\t\t/// [4] Cambiar dimensiones de las matrices ///\n";
		cout << "\t\t\t\t/// [5] Matriz por vector                   ///\n";
		cout << "\t\t\t\t/// [6] Generar matriz compuesta            ///\n";
		cout << "\t\t\t\t/// [7] Generacion por cuaternios            ///\n";
		cout << "\t\t\t\t/// [0] Salir                               ///\n";
		cout << "\t\t\t\t///////////////////////////////////////////////\n";
		cout << "\t\t\t\tElige una accion: ";
		cin >> cAccion;


		switch (cAccion)
		{
		case '0': //Salir del programa
			MisFunciones::Mensaje("Saliendo del programa");
			return;

		case '1': //Operaciones con matrices
			Operaciones();

			break;

		case '2': //Cambiar valores de las matrices
			CambiarValores();

			break;

		case '3': //Intercambiar matrices
			matriz1 << matriz2; //Con esta operación cambiamos los valores de la matriz 1 a la 2 y viceversa
			MisFunciones::Mensaje("Intercambiando matrices...");

			//system("pause");
			break;

		case '4':
			CambiarDimensionesMatriz();
			break;

		case '5':
			MatrizPorVector();
			break;

		case '6':
			//GenerarMatrizCompuesta();
			MatrizCompuesta2();
			break;
			
		case '7':
			Cuaternios();
			break;
		default:
			MisFunciones::Mensaje("Escribe un numero del menu");
			break;
		}
	} while (true);

}

void Sumar() {
	if (matriz1.ObtenerFilas() != matriz2.ObtenerFilas() || matriz1.ObtenerColumnas() != matriz2.ObtenerColumnas()) {
		throw "Para poder sumar las matrices tienen que ser de las mismas dimensiones.";
		return;
	}

	matrizR.CrearMatriz(matriz1.ObtenerFilas(), matriz1.ObtenerColumnas());

	matrizR = matriz1 + matriz2;
	
	CLS
	cout << "\n\t\t\t\t[Matriz A]" << endl;
	matriz1.DibujaMatriz();
	cout << endl << "\t\t\t\t     +" << endl;
	cout << "\n\t\t\t\t[Matriz B]" << endl;
	matriz2.DibujaMatriz();
	cout << endl << "\t\t\t\t     =" << endl<<endl;
	matrizR.DibujaMatriz();

	cout << "\n\t\t\t\tPresione una tecla para continuar";
	system("pause>nul");
}

void Restar() {
	if (matriz1.ObtenerFilas() != matriz2.ObtenerFilas() || matriz1.ObtenerColumnas() != matriz2.ObtenerColumnas()) {
		throw "Para poder restar las matrices tienen que ser de las mismas dimensiones.";
		return;
	}

	matrizR.CrearMatriz(matriz1.ObtenerFilas(), matriz1.ObtenerColumnas());

	matrizR = matriz1 - matriz2;

	CLS
	cout << "\n\t\t\t\t[Matriz A]" << endl;
	matriz1.DibujaMatriz();
	cout << endl << "\t\t\t\t     -" << endl;
	cout << "\n\t\t\t\t[Matriz B]" << endl;
	matriz2.DibujaMatriz();
	cout << endl << "\t\t\t\t     =" << endl << endl;
	matrizR.DibujaMatriz();

	cout << "\n\t\t\t\tPresione una tecla para continuar";
	system("pause>nul");
}

void Multiplicar() {
	if (matriz1.ObtenerColumnas() != matriz2.ObtenerFilas()) {
		throw "Para hacer una multiplicacion de matrices, la matriz A debe tener la misma cantidad de columnas que de filas de la matriz B.";
		return;
	}

	matrizR.CrearMatriz(matriz1.ObtenerFilas(), matriz2.ObtenerColumnas());

	matrizR = matriz1 * matriz2;

	CLS
	cout << "\n\t\t\t\t[Matriz A]" << endl;
	matriz1.DibujaMatriz();
	cout << endl << "\t\t\t\t     X" << endl;
	cout << "\n\t\t\t\t[Matriz B]" << endl;
	matriz2.DibujaMatriz();
	cout << endl << "\t\t\t\t     =" << endl << endl;
	matrizR.DibujaMatriz();

	cout << "\n\t\t\t\tPresione una tecla para continuar";
	system("pause>nul");
}

void Operaciones() {
	bool salir = false;
	char cOperacion;
	
	do {

		CLS
		cout << "\n\t\t\t\t[Matriz A]" << endl;
		matriz1.DibujaMatriz();
		cout << "\n\t\t\t\t[Matriz B]" << endl;
		matriz2.DibujaMatriz();

		cout << endl;
		cout << "\t\t\t\t///////////////////////////////////////////////\n";
		cout << "\t\t\t\t/// Elige una accion a realizar             ///\n";
		cout << "\t\t\t\t/// [1] Sumar                               ///\n";
		cout << "\t\t\t\t/// [2] Restar                              ///\n";
		cout << "\t\t\t\t/// [3] Multiplicar                         ///\n";
		cout << "\t\t\t\t/// [0] Atras                               ///\n";
		cout << "\t\t\t\t///////////////////////////////////////////////\n";
		cout << "\t\t\t\tElige una accion: ";
		cin >> cOperacion;

		switch (cOperacion)
		{
		case '1':
			try
			{
				Sumar();
			}
			catch (const char* e)
			{
				MisFunciones::Mensaje(e);
			}
			break;

		case '2':
			try
			{
				Restar();
			}
			catch (const char* e)
			{
				MisFunciones::Mensaje(e);
			}
			break;

		case '3':
			try
			{
				Multiplicar();
			}
			catch (const char* e)
			{
				MisFunciones::Mensaje(e);
			}
			break;

		case '0':
			salir = true;
			break;

		default:
			break;
		}
	} while (!salir);
}

void CambiarValores() {
	bool salir = false;
	char cMatriz;

	float MATRA[4][4] = {1,0,0,0};


	do {
		MisFunciones::Mensaje("Cargando...");
		CLS
		cout << "\t\t\t\t//[0] Regresar                           //" << endl;
		cout << "\n\t\t\t\t[Matriz A]" << endl;
		matriz1.DibujaMatriz();
		cout << "\n\t\t\t\t[Matriz B]" << endl;
		matriz2.DibujaMatriz();

		cout << "\n\t\t\t\tElige una matriz para cambiar sus valores [A o B]: ";
		cin >> cMatriz;
		CLS
		switch (cMatriz)
		{
		case '0':
			salir = true;
			break;
		case 'A':
		case 'a':
			cout << "\t\t\t\t[Matriz A]";
			matriz1.AsignarValoresManual();
			break;

		case 'B':
		case 'b':
			cout << "\t\t\t\t[Matriz B]";
			matriz2.AsignarValoresManual();
			break;
		default:
			break;
		}
	} while (!salir);
}

void MatrizPorVector() {
	bool salir = false, validarVector=true;
	char cMatriz;
	char cx[20], cy[20], cz[20];
	float nx, ny, nz;
	Matriz vector = Matriz(4, 1);
	Matriz matrizR = Matriz(4, 1);

	do {
		MisFunciones::Mensaje("Cargando...");
		CLS
		cout << "\t\t\t\t//[0] Regresar                           //" << endl;
		cout << "\n\t\t\t\t[Matriz A]" << endl;
		matriz1.DibujaMatriz();
		cout << "\n\t\t\t\t[Matriz B]" << endl;
		matriz2.DibujaMatriz();
		cout << "\n\t\t\t\t[Matriz Compuesta]" << endl;
		matrizCom.DibujaMatriz();

		cout << "\n\t\t\t\tElige una matriz para multiplicarla por un vector [A, B o C]: ";
		cin >> cMatriz;
		if (cMatriz == '0') {
			salir = true;
			continue;
		}else if(cMatriz != 'A' && cMatriz != 'a' && cMatriz != 'B' && cMatriz != 'b' && cMatriz != 'C' && cMatriz != 'c') {
			MisFunciones::Mensaje("Elige una matriz correcta");
			salir = false;
			continue;
		}

		switch (cMatriz)
		{
		case 'A':
		case 'a':
			if (matriz1.ObtenerColumnas() != vector.ObtenerFilas()) {
				MisFunciones::Mensaje("Imposible realizar la operacion, escoge otra matriz");
				salir = false;
				continue;
			}
			break;

		case 'B':
		case 'b':
			if (matriz2.ObtenerColumnas() != vector.ObtenerFilas()) {
				MisFunciones::Mensaje("Imposible realizar la operacion, escoge otra matriz");
				salir = false;
				continue;
			}
			break;

		case 'C':
		case 'c':
			if (matrizCom.ObtenerColumnas() != vector.ObtenerFilas()) {
				MisFunciones::Mensaje("Imposible realizar la operacion, escoge otra matriz");
				salir = false;
				continue;
			}
			break;
		}


		do
		{
			validarVector = true;
			cout << "\n\t\t\t\tInserta los valores del vector: ";
			cout << "\n\t\t\t\tx: ";
			cin >> cx;
			if (!MisFunciones::EsFlotante(cx)) {
				validarVector = false;
				continue;
			}

			cout << "\n\t\t\t\ty: ";
			cin >> cy;
			if (!MisFunciones::EsFlotante(cy)) {
				validarVector = false;
				continue;
			}

			cout << "\n\t\t\t\tz: ";
			cin >> cz;
			if (!MisFunciones::EsFlotante(cz)) {
				validarVector = false;
				continue;
			}

		} while (!validarVector);

		nx = atof(cx);
		ny = atof(cy);
		nz = atof(cz);

		vector.AsignarValor(1, 1, nx);
		vector.AsignarValor(2, 1, ny);
		vector.AsignarValor(3, 1, nz);
		vector.AsignarValor(4, 1, 1.0);

		CLS
		switch (cMatriz)
		{
		case '0':
			salir = true;
			break;
		case 'A':
		case 'a':
			//cout << "\t\t\t\t[Matriz A]";
			matrizR = matriz1 * vector;

			cout << "\n\t\t\t\t[Matriz A]" << endl;
			matriz1.DibujaMatriz();
			cout << endl << "\t\t\t\t     X" << endl;
			cout << "\n\t\t\t\t[Vector]" << endl;
			vector.DibujaMatriz();
			cout << endl << "\t\t\t\t     =" << endl << endl;
			matrizR.DibujaMatriz();

			break;

		case 'B':
		case 'b':
			//cout << "\t\t\t\t[Matriz B]";
			matrizR = matriz2 * vector;

			cout << "\n\t\t\t\t[Matriz B]" << endl;
			matriz2.DibujaMatriz();
			cout << endl << "\t\t\t\t     X" << endl;
			cout << "\n\t\t\t\t[Vector]" << endl;
			vector.DibujaMatriz();
			cout << endl << "\t\t\t\t     =" << endl << endl;
			matrizR.DibujaMatriz();
			break;

		case 'C':
		case 'c':
			//cout << "\t\t\t\t[Matriz B]";
			matrizR = matrizCom * vector;

			cout << "\n\t\t\t\t[Matriz Compuesta]" << endl;
			matrizCom.DibujaMatriz();
			cout << endl << "\t\t\t\t     X" << endl;
			cout << "\n\t\t\t\t[Vector]" << endl;
			vector.DibujaMatriz();
			cout << endl << "\t\t\t\t     =" << endl << endl;
			matrizR.DibujaMatriz();
			break;
		}

		system("pause>nul");

	} while (!salir);
}

void CambiarDimensionesMatriz() {
	bool salir = false, bValMatriz1=true, bValMatriz2=true;
	char cMatriz, cfilas[2], ccolumnas[2], cfilas2[2], ccolumnas2[2];
	unsigned short nfilas, ncolumnas, nfilas2, ncolumnas2;

	do {
		MisFunciones::Mensaje("Cargando...");
		CLS
		cout << "\t\t\t\t//[0] Regresar                           //" << endl;
		cout << "\n\t\t\t\t[Matriz A]" << endl;
		matriz1.DibujaMatriz();
		cout << "\n\t\t\t\t[Matriz B]" << endl;
		matriz2.DibujaMatriz();

		cout << "\n\t\t\t\tElige una matriz para cambiar sus dimensiones [A o B]: ";
		cin >> cMatriz;
		///CLS
		switch (cMatriz)
		{
		case '0':
			salir = true;
			break;
		case 'A':
		case 'a':
			do
			{
				bValMatriz1 = true;
				CLS
				cout << "\t\t\t\tDimensiones de la [Matriz A]:" << endl;

				cout << "\t\t\t\tFilas: ";
				cin >> cfilas;
				if (!MisFunciones::EsEntero(cfilas)) {
					bValMatriz1 = false;
					continue;
				}

				cout << "\t\t\t\tColumnas: ";
				cin >> ccolumnas;
				if (!MisFunciones::EsEntero(ccolumnas)) {
					bValMatriz1 = false;
					continue;
				}

			} while (!bValMatriz1);

			nfilas = (unsigned short)atoi(cfilas);
			ncolumnas = (unsigned short)atoi(ccolumnas);

			matriz1.CrearMatriz(nfilas, ncolumnas);

			break;

		case 'B':
		case 'b':
			do
			{
				bValMatriz2 = true;
				CLS
				cout << "\t\t\t\tDimensiones de la [Matriz B]:" << endl;

				cout << "\t\t\t\tFilas: ";
				cin >> cfilas2;
				if (!MisFunciones::EsEntero(cfilas2)) {
					bValMatriz2 = false;
					continue;
				}

				cout << "\t\t\t\tColumnas: ";
				cin >> ccolumnas2;
				if (!MisFunciones::EsEntero(ccolumnas2)) {
					bValMatriz2 = false;
					continue;
				}
			} while (!bValMatriz2);

			nfilas2 = (unsigned short)atoi(cfilas2);
			ncolumnas2 = (unsigned short)atoi(ccolumnas2);

			matriz2.CrearMatriz(nfilas2, ncolumnas2);

			break;

		default:
			break;
		}

			
	} while (!salir);
}

void GenerarMatrizCompuesta() {
	bool salir = false;
	char cOperacion, cEjeRotar;

	do {

		CLS
		cout << "\n\t\t\t\t[Matriz Compuesta]" << endl;
		matrizCom.DibujaMatriz();

		cout << endl;
		cout << "\t\t\t\t/////////////////////////////////////////////////\n";
		cout << "\t\t\t\t/// Elige los valores de las transformaciones ///\n";
		cout << "\t\t\t\t/// [1] Trasladar                             ///\n";
		cout << "\t\t\t\t/// [2] Rotar                                 ///\n";
		cout << "\t\t\t\t/// [3] Escalar                               ///\n";
		cout << "\t\t\t\t///                                           ///\n";
		cout << "\t\t\t\t/// [4] Calcular matriz compuesta             ///\n";
		cout << "\t\t\t\t/// [0] Atras                                 ///\n";
		cout << "\t\t\t\t/////////////////////////////////////////////////\n";
		cout << "\t\t\t\tElige una accion: ";
		cin >> cOperacion;

		switch (cOperacion)
		{
		case '1': {
			matrizTra = Matriz(4,4);
			Vector3 valor;
			CLS
			cout << "\t\t\t\tIngresa el vector de traslacion: " << endl;
			cout << "\t\t\t\tx: ";
			cin >> valor.x;

			cout << "\t\t\t\ty: ";
			cin >> valor.y;

			cout << "\t\t\t\tz: ";
			cin >> valor.z;

			matrizTra.AsignarValor(1, 4, valor.x);
			matrizTra.AsignarValor(2, 4, valor.y);
			matrizTra.AsignarValor(3, 4, valor.z);
			cout << endl;
			matrizTra.DibujaMatriz();
			
			
			system("pause>nul");
		}
		break;

		case '2': {
			matrizRot = Matriz(4,4);
			float angulo, sen0, cos0;
			CLS
			cout << "\t\t\t\tIngresa el angulo a rotar: ";
			cin >> angulo;

			CLS
			cout << "\t\t\t\t/////////////////////////////////////////////////\n";
			cout << "\t\t\t\t/// Selecciona el angulo para rotar           ///\n";
			cout << "\t\t\t\t/// [1] Eje x                                 ///\n";
			cout << "\t\t\t\t/// [2] Eje y                                 ///\n";
			cout << "\t\t\t\t/// [3] Eje z                                 ///\n";
			cout << "\t\t\t\t/////////////////////////////////////////////////\n";
			cout << "\t\t\t\tElige un eje: ";
			cin >> cEjeRotar;

			sen0 = sin(angulo*PI/180);
			cos0 = cos(angulo*PI/180);

			switch (cEjeRotar)
			{
			case '1':
				matrizRot.AsignarValor(2, 2, cos0);
				matrizRot.AsignarValor(2, 3, -sen0);
				matrizRot.AsignarValor(3, 2, sen0);
				matrizRot.AsignarValor(3, 3, cos0);
				break;
			case '2':
				matrizRot.AsignarValor(1, 1, cos0);
				matrizRot.AsignarValor(1, 3, sen0);
				matrizRot.AsignarValor(3, 1, -sen0);
				matrizRot.AsignarValor(3, 3, cos0);
				break;
			case '3':
				matrizRot.AsignarValor(1, 1, cos0);
				matrizRot.AsignarValor(1, 2, -sen0);
				matrizRot.AsignarValor(2, 1, sen0);
				matrizRot.AsignarValor(2, 2, cos0);
				break;
			default:
				matrizRot.AsignarValor(2, 2, cos0);
				matrizRot.AsignarValor(2, 3, -sen0);
				matrizRot.AsignarValor(3, 2, sen0);
				matrizRot.AsignarValor(3, 3, cos0);
				break;
			}

			cout << endl;
			matrizRot.DibujaMatriz();
			system("pause>nul");
		}
		break;

		case '3': {
			matrizEsc = Matriz(4,4);
			Vector3 valor;
			CLS
			cout << "\t\t\t\tIngresa el vector de escala: " << endl;
			cout << "\t\t\t\tx: ";
			cin >> valor.x;

			cout << "\t\t\t\ty: ";
			cin >> valor.y;

			cout << "\t\t\t\tz: ";
			cin >> valor.z;

			matrizEsc.AsignarValor(1, 1, valor.x);
			matrizEsc.AsignarValor(2, 2, valor.y);
			matrizEsc.AsignarValor(3, 3, valor.z);
			cout << endl;
			matrizEsc.DibujaMatriz();
			system("pause>nul");
		}
		break;

		case '4': {
			char orden;

			CLS
			cout << "\t\t\t\t/////////////////////////////////////////////////\n";
			cout << "\t\t\t\t/// Elige el orden                            ///\n";
			cout << "\t\t\t\t/// [1] Traslacion->Rotacion->Escalacion      ///\n";
			cout << "\t\t\t\t/// [2] Traslacion->Escalacion->Rotacion      ///\n";
			cout << "\t\t\t\t/// [3] Rotacion->Traslacion->Escalacion      ///\n";
			cout << "\t\t\t\t/// [4] Rotacion->Escalacion->Traslacion      ///\n";
			cout << "\t\t\t\t/// [5] Escalacion->Traslacion->Rotacion      ///\n";
			cout << "\t\t\t\t/// [6] Escalacion->Rotacion->Traslacion      ///\n";
			cout << "\t\t\t\t/////////////////////////////////////////////////\n";
			cout << "\t\t\t\tElige un eje: ";
			cin >> orden;

			switch (orden)
			{
			case '1':
				matrizCom = matrizEsc * matrizRot * matrizTra;
				break;
			case '2':
				matrizCom = matrizRot * matrizEsc * matrizTra;
				break;
			case '3':
				matrizCom = matrizEsc * matrizTra * matrizRot;
				break;
			case '4':
				matrizCom = matrizTra * matrizEsc * matrizRot;
				break;
			case '5':
				matrizCom = matrizRot * matrizTra * matrizEsc;
				break;
			case '6':
				matrizCom = matrizTra * matrizRot * matrizEsc;
				break;
			default:
				matrizCom = matrizEsc * matrizRot * matrizTra;
				break;
			}
		}
		break;
		case '0':
			salir = true;
			break;

		default:
			break;
		}
	} while (!salir);
}

void Cuaternios() {
	Cuaternio punto, conjugado, q, vector, final, pprimas;
	float v1=0, v2=0, v3=0, a1=0, a2=0, a3=0, grados=0, magnitud=0;

	CLS

	cout << "Ingresa el punto"<<endl;
	cout << "x: ";
	cin >> a1;
	cout << "y: ";
	cin >> a2;
	cout << "z: ";
	cin >> a3;

	punto.SetA(0);
	punto.SetA1(a1);
	punto.SetA2(a2);
	punto.SetA3(a3);

	CLS

	cout << "Ingresa el vector"<<endl;
	cout << "x: ";
	cin >> v1;
	cout << "y: ";
	cin >> v2;
	cout << "z: ";
	cin >> v3;

	CLS

	cout << "Ingresa los grados a rotar: ";
	cin >> grados;

	vector.SetA(cos((grados / 2) * PI / 180));
	vector.SetA1(v1);
	vector.SetA2(v2);
	vector.SetA3(v3);

	magnitud = sqrt(pow(v1, 2) + pow(v2, 2) + pow(v3, 2));

	q.SetA(cos((grados / 2) * PI / 180));
	q.SetA1((v1 / magnitud) * sin((grados / 2) * PI / 180));
	q.SetA2((v2 / magnitud) * sin((grados / 2) * PI / 180));
	q.SetA3((v3 / magnitud) * sin((grados / 2) * PI / 180));

	pprimas = q * punto;

	conjugado = Cuaternio(q.GetA(), -q.GetA1(), -q.GetA2(), -q.GetA3());

	final = pprimas * conjugado;

	cout << "(" << final.GetA1() << ", " << final.GetA2() << ", " << final.GetA3() << ")"<<endl;

	system("pause>nul");

}

void MatrizCompuesta2(){
	char opciont, volverTransformar, volverPunto;
	float x = 0, y = 0, z = 0, grados = 0, eje = 1;
	float puntoX[4][1] = { 0 , 0 , 0 , 0 };
	int veces = 0, i,j,k;

	do {
		veces++;
		system("cls");
		cout << "///Ingresa una transformación///" << endl;
		cout << "1- Trasladar" << endl;
		cout << "2- Rotacion" << endl;
		cout << "3- Escalar " << endl;
		cout << "0- Multiplicar por punto " << endl;
		cin >> opciont;

		matrizTransformacion[0][0] = 1;
		matrizTransformacion[0][1] = 0;
		matrizTransformacion[0][2] = 0;
		matrizTransformacion[0][3] = 0;

		matrizTransformacion[1][0] = 0;
		matrizTransformacion[1][1] = 1;
		matrizTransformacion[1][2] = 0;
		matrizTransformacion[1][3] = 0;

		matrizTransformacion[2][0] = 0;
		matrizTransformacion[2][1] = 0;
		matrizTransformacion[2][2] = 1;
		matrizTransformacion[2][3] = 0;

		matrizTransformacion[3][0] = 0;
		matrizTransformacion[3][1] = 0;
		matrizTransformacion[3][2] = 0;
		matrizTransformacion[3][3] = 1;

		switch (opciont)
		{
		case '1'://trasladar
			system("cls");
			cout << "Ingresa los valores de traslacion: " << endl;
			cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
			cout << "z: ";
			cin >> z;

			matrizTransformacion[0][3] = x;
			matrizTransformacion[1][3] = y;
			matrizTransformacion[2][3] = z;

			break;

		case '2'://rotar

			system("cls");
			cout << "Ingresa los grados a rotar: " << endl;
			cin >> grados;
			cout << "Ingresa el eje a rotar: " << endl;
			cout << "1. Eje x" << endl;
			cout << "2. Eje y" << endl;
			cout << "3. Eje z" << endl;
			cin >> eje;
			//cout << "Ingresa los valores de rotacion: " << endl;
			/*cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
			cout << "z: ";
			cin >> z;*/

			if (eje == 1) {//eje x
				matrizTransformacion[1][1] = cos(grados * PI / 180);
				matrizTransformacion[1][2] = -sin(grados * PI / 180);
				matrizTransformacion[2][1] = sin(grados * PI / 180);
				matrizTransformacion[2][2] = cos(grados * PI / 180);

			}
			else if (eje == 2) { //eje y
				matrizTransformacion[0][0] = cos(grados * PI / 180);
				matrizTransformacion[0][2] = sin(grados * PI / 180);
				matrizTransformacion[2][0] = -sin(grados * PI / 180);
				matrizTransformacion[2][2] = cos(grados * PI / 180);
			}
			else if (eje == 3) { //eje z
				matrizTransformacion[0][0] = cos(grados * PI / 180);
				matrizTransformacion[0][1] = -sin(grados * PI / 180);
				matrizTransformacion[1][0] = sin(grados * PI / 180);
				matrizTransformacion[1][1] = cos(grados * PI / 180);
			}
			else {
				cout << "Error" << endl;
			}

			break;

		case '3'://escalar
			system("cls");
			cout << "Ingresa los valores de escala: " << endl;
			cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
			cout << "z: ";
			cin >> z;

			matrizTransformacion[0][0] = x;
			matrizTransformacion[1][1] = y;
			matrizTransformacion[2][2] = z;
			break;
		default:
			break;
		}

		if (veces == 1) {
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					matrizAuxiliar[i][j] = matrizTransformacion[i][j];
					//cout << matrizAuxiliar[i][j] << "\t";
				}
				//cout << endl;
			}
		}
		else {
			for (i = 0; i < 4; i++) {
				for (k = 0; k < 4; k++) {
					//cout << "|\t";
					matrizAuxiliar[i][k] = 0;
					for (j = 0; j < 4; j++) {
						matrizAuxiliar[i][k] = matrizAuxiliar[i][k] + (matrizCompuesta[i][j] * matrizTransformacion[j][k]);
					}
					//cout << matrizAuxiliar[i][k];
					//cout << "\t|\t";
				}
				//cout << endl;
				//cout << endl;
			}




		}


		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				matrizCompuesta[i][j] = matrizAuxiliar[i][j];
				cout << matrizCompuesta[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "Quieres añadir otra transformacion?" << endl;
		cout << "1. SI" << endl;
		cout << "0. NO" << endl;
		cin >> volverTransformar;

	} while (volverTransformar != '0');


	do
	{
		system("cls");
		cout << "Esta es tu matriz compuesta" << endl;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				//matrizCompuesta[i][j] = matrizAuxiliar[i][j];
				cout << matrizCompuesta[i][j] << "\t";
			}
			cout << endl;
		}

		cout << endl;
		cout << "Ingresa el punto por el que deseas rotar" << endl;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		cout << "z: ";
		cin >> z;

		puntoX[0][0] = x;
		puntoX[1][0] = y;
		puntoX[2][0] = z;
		puntoX[3][0] = 1;

		for (i = 0; i < 4; i++) {
			for (k = 0; k < 1; k++) {
				//cout << "|\t";
				matrizAuxiliar[i][k] = 0;
				for (j = 0; j < 4; j++) {
					matrizAuxiliar[i][k] = matrizAuxiliar[i][k] + (matrizCompuesta[i][j] * puntoX[j][k]);
				}
				//cout << matrizAuxiliar[i][k];
				//cout << "\t|\t";
			}
			//cout << endl;
			//cout << endl;
		}

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 1; j++) {
				matrizAuxiliar[i][j] = matrizAuxiliar[i][j];
				cout << matrizAuxiliar[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "Quieres transformar otro punto=" << endl;
		cout << "1. SI" << endl;
		cout << "0. NO" << endl;
		cin >> volverPunto;


	} while (volverPunto != '0');


}