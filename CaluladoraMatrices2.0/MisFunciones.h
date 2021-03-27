#pragma once

#include <string>
#include <iostream>
#include <time.h>

using std::string;

class MisFunciones
{
public:
	
#pragma region Metodos
	static void Sleep(unsigned int);
	static void Mensaje(string);
	static bool EsEntero(char texto[255]);
	static bool EsFlotante(char texto[255]);
#pragma endregion
};