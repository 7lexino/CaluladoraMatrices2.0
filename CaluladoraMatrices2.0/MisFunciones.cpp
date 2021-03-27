#include "MisFunciones.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

void MisFunciones::Sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

void MisFunciones::Mensaje(string mensaje) {
	system("cls");
	cout << "\n\t\t\t\t\t[ " << mensaje.c_str() << " ]" << endl;
	Sleep(mensaje.length() * 70);

}

bool MisFunciones::EsEntero(char texto[255]) {
	for (int i = 0; i < strlen(texto); i++) {
		if (!(texto[i] > '0' && texto[i] <= '9')) {
			Mensaje("Inserta un valor numerico y mayor a 0");
			return false;
		}
	}
	return true;
}

bool MisFunciones::EsFlotante(char texto[255]) {
	unsigned short puntos=0;
	for (int i = 0; i < strlen(texto); i++) {
		if (texto[i] == '.') puntos++;
		if (puntos > 1) {
			MisFunciones::Mensaje("Inserta un valor numerico correcto");
			return false;
		}
		if (!(texto[i] >= '0' && texto[i] <= '9')) {
			MisFunciones::Mensaje("Inserta un valor numerico");
			return false;
		}
	}
	return true;
}