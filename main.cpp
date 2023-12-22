#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#define up 72
#define down 80
#define right 77
#define left 75
#define espace 32
#define enter 13
#define esc 27
//hacerlo en 255 lineas de codigo o menos
using namespace std;

void gotoxy(int x, int y) {//ancho 80 alto 25 gotoxy puede actualizarse con una variable
	HANDLE input = GetStdHandle(STD_OUTPUT_HANDLE);//hcon es una variable se le puede manipular el nombre
	COORD coord;//lo mismo con dwPos
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(input, coord);
}

class Bird {
private:
	const int X = 2;
	int Y = 10;
	char teclado = 0;
	char tecla = 32;
	char newtecla = 0;

public:

	void drawBird() {
		gotoxy(X, Y); cout << ("<(O>O)>");//3 de distancia
	}

	void Input(){
		if(_kbhit()) {
			teclado = _getch();
		}
		if(teclado == tecla) {
			Y-=2;
			teclado = 0;
		}
		else {
			Y++;
		}
	}

	int PosY() {
		return Y;
	}

	int PosX() {
		return X;
	}

	void SetTecla() {
		cout << "Presione la tecla con la que quiera usar el salto";
		newtecla = _getch();
		if (newtecla == tecla)SetTecla();
		if (newtecla == esc)return;
		else tecla = newtecla;
		system("cls");
	}

};Bird P;

class Tubos {
private:

	int Y = rand() % 15+7;
	int X;

public:

	void SetX(int X) {
		this->X = X;
	}

	void DrawTubos() {
		for (int i = Y; i > 0; i--) {
			gotoxy(X,i); cout << "[*]";
		}
		for (int i = 25; i > Y+4; i--) {
			gotoxy(X, i); cout << "[*]";
		}
	}

	void Reinicio() {
		if (X != 0)X--;
		else X = 60;
	}

	int GetX() {
		return X;
	}

	int GetY() {
		return Y;
	}
};Tubos tubos[4];

class Juego {
private:
	int puntaje = 0,RecordAnt = 0;
	bool perdiste = true;

	void RevisionTubos(Tubos tubos[4]) {
		for (int i = 0; i < 4; i++) {
			tubos[i].DrawTubos();
			tubos[i].Reinicio();
		}
	}

	void InicioTubos(Tubos tubos[4]) {
		int X = 20;
		for (int i = 0; i < 4; i++) {
			tubos[i].SetX(X);
			X += 17;
		}
	}

	void Puntaje(Bird bird, Tubos tubos[4], int* puntaje, bool* perder) {
		gotoxy(70, 1); cout << "Puntaje: " << *puntaje;
		for (int i = 0; i < 4; i++) {
			if (bird.PosX() == tubos[i].GetX()) {
				if ((bird.PosY() >= tubos[i].GetY()-1) && (bird.PosY() <= tubos[i].GetY() + 5)) {
					*puntaje += 1;
				}
				else {
					*perder = false;
				}
			}else if(bird.PosY() >= 26) {
				*perder = false;
			}
		}
	}

	void GameOver(bool* perder) {
		system("cls");
		gotoxy(20, 10); cout << "PERDISTE QUE MANCO\n";
		Sleep(1000);
		system("pause");
		*perder = true;
		system("cls");
	}

	void Record(int Puntaje) {
		ofstream archivo("record.txt", ios::out);
		if (Puntaje > RecordAnt)archivo << Puntaje;
		else archivo << RecordAnt;
		archivo.close();
	}

public:
	void Update() {
		InicioTubos(tubos);
		while (perdiste == true) {
			P.drawBird();
			P.Input();
			RevisionTubos(tubos);
			Puntaje(P, tubos, &puntaje, &perdiste);
			Sleep(17);
			system("cls");
		}
		Record(puntaje);
		GameOver(&perdiste);
	}

	void IniciarRecord() {
		int contenido;
		ifstream archivo("record.txt");
		bool retorno = archivo.fail();
		if (archivo.is_open()) {
			while (archivo >> contenido) {
				RecordAnt = contenido;
			}
		}
		archivo.close();
	}

	int puntos() {
		return RecordAnt;
	}

}; Juego Play;

class Interfaz {
private:
	int select = 5;
	int tecla;

	void Teclear(int* tecla) {
		if (_kbhit()) {
			*tecla = _getch();
		}
	}

	void MovimientoFlecha(int* result) {
		if (*result == down && select <= 7) {
			select++;
			*result = 0;
		}
		if (*result == up && select >= 6) {
			select--; 
			*result = 0;
		}
	}



	void Eleccion(int select) {
		system("cls");
		switch (select) {
		case 5:Play.Update(); break;
		case 6:P.SetTecla(); break;
		case 7:break;
		case 8:gotoxy(20, 10); cout << "Hecho por raton gamer\n"; break;
		}
		if (select != 7) {
			system("pause");
			tecla = 0;
			Seleccion();
		}
		else return;
	}

public:
	void Seleccion() {
		Play.IniciarRecord();
		while (tecla != enter) {
			gotoxy(5, select); cout << "->";
			gotoxy(8, 5); cout << "Jugar";
			gotoxy(8, 6); cout << "Cambiar tecla de salto";
			gotoxy(8, 7); cout << "salir";
			gotoxy(8, 8); cout << "Copyright";
			gotoxy(5, 10); cout << "Numero Seleccionado: " << select;
			gotoxy(40, 5); cout << "Record: " << Play.puntos();
			Teclear(&tecla);
			MovimientoFlecha(&tecla);
			Sleep(17);
			system("cls");
		}
		Eleccion(select);
	}
}; Interfaz interfaz;

int main() {
	interfaz.Seleccion();
	return 0;
}