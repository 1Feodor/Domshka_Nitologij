#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include"Gonka_Class.h"
//#include "Class_TC.h"

void Zagolovok();
void Vykl_Podsvetka(int);
void Inform(short, bool);
int Vybor_Tipa_Gonki();
int Vybor_Rastojnij();
int Nazad_Vpered(int, int, int, int);
void Vykl_Podsvetka_TC(int, bool, int);
void Spisok_TC(int, bool, int, int);
void Inform_TC(int, int, int, int);
int Vybor_Car(short const);
void Vykl_Podsvetka_Gonka(int);
void Nazad(int);
int Vybor_Gonki(int const);
void Vykl_Podsvetka_Exit(int);
const char* Cislo_Wo_Wrema(int);
void Rezultaty_gonki(int const, int const, int const);
void Broadcast_gonki(int const, int const);
bool Menu_Exit(int const);