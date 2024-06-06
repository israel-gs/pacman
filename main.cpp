#include "miniwin.h"
#include <vector>
using namespace miniwin;
using namespace std;

const int ANCHO = 19;
const int ALTO = 21;
const int TAMANO = 20;

class Mapa
{
private:
	vector<vector<char> > laberinto;

public:
	Mapa()
	{
		vector<char> fila1;
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');
		fila1.push_back('#');

		vector<char> fila2;
		fila2.push_back('#');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('#');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('.');
		fila2.push_back('#');

		vector<char> fila3;
		fila3.push_back('#');
		fila3.push_back('.');
		fila3.push_back('#');
		fila3.push_back('#');
		fila3.push_back('.');
		fila3.push_back('#');
		fila3.push_back('#');
		fila3.push_back('#');
		fila3.push_back('.');
		fila3.push_back('#');
		fila3.push_back('.');
		fila3.push_back('#');
		fila3.push_back('#');
		fila3.push_back('#');
		fila3.push_back('.');
		fila3.push_back('#');
		fila3.push_back('#');
		fila3.push_back('.');
		fila3.push_back('#');

		vector<char> fila4;
		fila4.push_back('#');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('.');
		fila4.push_back('#');

		vector<char> fila5;
		fila5.push_back('#');
		fila5.push_back('.');
		fila5.push_back('#');
		fila5.push_back('#');
		fila5.push_back('.');
		fila5.push_back('#');
		fila5.push_back('.');
		fila5.push_back('#');
		fila5.push_back('#');
		fila5.push_back('#');
		fila5.push_back('#');
		fila5.push_back('#');
		fila5.push_back('.');
		fila5.push_back('#');
		fila5.push_back('.');
		fila5.push_back('#');
		fila5.push_back('#');
		fila5.push_back('.');
		fila5.push_back('#');

		vector<char> fila6;
		fila6.push_back('#');
		fila6.push_back('.');
		fila6.push_back('.');
		fila6.push_back('.');
		fila6.push_back('.');
		fila6.push_back('#');
		fila6.push_back('.');
		fila6.push_back('.');
		fila6.push_back('.');
		fila6.push_back('#');
		fila6.push_back('.');
		fila6.push_back('.');
		fila6.push_back('.');
		fila6.push_back('#');
		fila6.push_back('.');
		fila6.push_back('.');
		fila6.push_back('.');
		fila6.push_back('.');
		fila6.push_back('#');

		vector<char> fila7;
		fila7.push_back('#');
		fila7.push_back('#');
		fila7.push_back('#');
		fila7.push_back('#');
		fila7.push_back('.');
		fila7.push_back('#');
		fila7.push_back('#');
		fila7.push_back('#');
		fila7.push_back('.');
		fila7.push_back('#');
		fila7.push_back('.');
		fila7.push_back('#');
		fila7.push_back('#');
		fila7.push_back('#');
		fila7.push_back('.');
		fila7.push_back('#');
		fila7.push_back('#');
		fila7.push_back('#');
		fila7.push_back('#');

		vector<char> fila8;
		fila8.push_back('.');
		fila8.push_back('.');
		fila8.push_back('.');
		fila8.push_back('#');
		fila8.push_back('.');
		fila8.push_back('#');
		fila8.push_back('.');
		fila8.push_back('.');
		fila8.push_back('.');
		fila8.push_back('.');
		fila8.push_back('.');
		fila8.push_back('.');
		fila8.push_back('.');
		fila8.push_back('#');
		fila8.push_back('.');
		fila8.push_back('#');
		fila8.push_back('.');
		fila8.push_back('.');
		fila8.push_back('.');

		vector<char> fila9;
		fila9.push_back('#');
		fila9.push_back('#');
		fila9.push_back('#');
		fila9.push_back('#');
		fila9.push_back('.');
		fila9.push_back('#');
		fila9.push_back('.');
		fila9.push_back('#');
		fila9.push_back('#');
		fila9.push_back('.');
		fila9.push_back('#');
		fila9.push_back('#');
		fila9.push_back('.');
		fila9.push_back('#');
		fila9.push_back('.');
		fila9.push_back('#');
		fila9.push_back('#');
		fila9.push_back('#');
		fila9.push_back('#');

		vector<char> fila10;
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('#');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('#');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('.');
		fila10.push_back('.');

		vector<char> fila11;
		fila11.push_back('#');
		fila11.push_back('#');
		fila11.push_back('#');
		fila11.push_back('#');
		fila11.push_back('.');
		fila11.push_back('#');
		fila11.push_back('.');
		fila11.push_back('#');
		fila11.push_back('#');
		fila11.push_back('#');
		fila11.push_back('#');
		fila11.push_back('#');
		fila11.push_back('.');
		fila11.push_back('#');
		fila11.push_back('.');
		fila11.push_back('#');
		fila11.push_back('#');
		fila11.push_back('#');
		fila11.push_back('#');

		vector<char> fila12;
		fila12.push_back('.');
		fila12.push_back('.');
		fila12.push_back('.');
		fila12.push_back('#');
		fila12.push_back('.');
		fila12.push_back('#');
		fila12.push_back('.');
		fila12.push_back('.');
		fila12.push_back('.');
		fila12.push_back('.');
		fila12.push_back('.');
		fila12.push_back('.');
		fila12.push_back('.');
		fila12.push_back('#');
		fila12.push_back('.');
		fila12.push_back('#');
		fila12.push_back('.');
		fila12.push_back('.');
		fila12.push_back('.');

		vector<char> fila13;
		fila13.push_back('#');
		fila13.push_back('#');
		fila13.push_back('#');
		fila13.push_back('#');
		fila13.push_back('.');
		fila13.push_back('#');
		fila13.push_back('.');
		fila13.push_back('#');
		fila13.push_back('#');
		fila13.push_back('#');
		fila13.push_back('#');
		fila13.push_back('#');
		fila13.push_back('.');
		fila13.push_back('#');
		fila13.push_back('.');
		fila13.push_back('#');
		fila13.push_back('#');
		fila13.push_back('#');
		fila13.push_back('#');

		vector<char> fila14;
		fila14.push_back('#');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('#');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('.');
		fila14.push_back('#');

		vector<char> fila15;
		fila15.push_back('#');
		fila15.push_back('.');
		fila15.push_back('#');
		fila15.push_back('#');
		fila15.push_back('.');
		fila15.push_back('#');
		fila15.push_back('#');
		fila15.push_back('#');
		fila15.push_back('.');
		fila15.push_back('#');
		fila15.push_back('.');
		fila15.push_back('#');
		fila15.push_back('#');
		fila15.push_back('#');
		fila15.push_back('.');
		fila15.push_back('#');
		fila15.push_back('#');
		fila15.push_back('.');
		fila15.push_back('#');

		vector<char> fila16;
		fila16.push_back('#');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('#');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('#');
		fila16.push_back('.');
		fila16.push_back('.');
		fila16.push_back('#');

		vector<char> fila17;
		fila17.push_back('#');
		fila17.push_back('#');
		fila17.push_back('.');
		fila17.push_back('#');
		fila17.push_back('.');
		fila17.push_back('#');
		fila17.push_back('.');
		fila17.push_back('#');
		fila17.push_back('#');
		fila17.push_back('#');
		fila17.push_back('#');
		fila17.push_back('#');
		fila17.push_back('.');
		fila17.push_back('#');
		fila17.push_back('.');
		fila17.push_back('#');
		fila17.push_back('.');
		fila17.push_back('#');
		fila17.push_back('#');

		vector<char> fila18;
		fila18.push_back('#');
		fila18.push_back('.');
		fila18.push_back('.');
		fila18.push_back('.');
		fila18.push_back('.');
		fila18.push_back('#');
		fila18.push_back('.');
		fila18.push_back('.');
		fila18.push_back('.');
		fila18.push_back('#');
		fila18.push_back('.');
		fila18.push_back('.');
		fila18.push_back('.');
		fila18.push_back('#');
		fila18.push_back('.');
		fila18.push_back('.');
		fila18.push_back('.');
		fila18.push_back('.');
		fila18.push_back('#');

		vector<char> fila19;
		fila19.push_back('#');
		fila19.push_back('.');
		fila19.push_back('#');
		fila19.push_back('#');
		fila19.push_back('#');
		fila19.push_back('#');
		fila19.push_back('#');
		fila19.push_back('#');
		fila19.push_back('.');
		fila19.push_back('#');
		fila19.push_back('.');
		fila19.push_back('#');
		fila19.push_back('#');
		fila19.push_back('#');
		fila19.push_back('#');
		fila19.push_back('#');
		fila19.push_back('#');
		fila19.push_back('.');
		fila19.push_back('#');

		vector<char> fila20;
		fila20.push_back('#');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('.');
		fila20.push_back('#');

		vector<char> fila21;
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');
		fila21.push_back('#');

		laberinto.push_back(fila1);
		laberinto.push_back(fila2);
		laberinto.push_back(fila3);
		laberinto.push_back(fila4);
		laberinto.push_back(fila5);
		laberinto.push_back(fila6);
		laberinto.push_back(fila7);
		laberinto.push_back(fila8);
		laberinto.push_back(fila9);
		laberinto.push_back(fila10);
		laberinto.push_back(fila11);
		laberinto.push_back(fila12);
		laberinto.push_back(fila13);
		laberinto.push_back(fila14);
		laberinto.push_back(fila15);
		laberinto.push_back(fila16);
		laberinto.push_back(fila17);
		laberinto.push_back(fila18);
		laberinto.push_back(fila19);
		laberinto.push_back(fila20);
		laberinto.push_back(fila21);
	}

	void draw()
	{
		color(AZUL);
		int y = 0;
		// for (auto it = laberinto.begin(); it != laberinto.end(); ++it, ++y) {
		// for (vector<Enemy>::iterator it = enemies.begin(); it != enemies.end();)
		for (vector<vector<char> >::iterator it = laberinto.begin(); it != laberinto.end(); ++it, ++y)
		{
			// y = y + 1;
			int x = 0;
			// for (auto jt = it->begin(); jt != it->end(); ++jt, ++x) {
			for (vector<char>::iterator jt = it->begin(); jt != it->end(); ++jt, ++x)
			{
				// x = x + 1;
				if (*jt == '#')
				{
					rectangulo_lleno(x * TAMANO, y * TAMANO, (x + 1) * TAMANO, (y + 1) * TAMANO);
				}
			}
		}
	}

	bool es_pared(int x, int y) const
	{
		return laberinto[y][x] == '#';
	}
};

class Pacman
{
private:
	int x, y;
	int size;

public:
	Pacman(int _x, int _y, int _size) : x(_x), y(_y), size(_size) {}

	void move(int dx, int dy, const Mapa &mapa)
	{
		if (x == 0 && dx == -1)
		{
			x = ANCHO - 1;
		}
		else if (x == ANCHO - 1 && dx == 1)
		{
			x = 0;
		}
		else
		{
			int nuevo_x = x + dx;
			int nuevo_y = y + dy;
			if (!mapa.es_pared(nuevo_x, nuevo_y))
			{
				x = nuevo_x;
				y = nuevo_y;
			}
		}
	}

	void draw() const
	{
		color(AMARILLO);
		circulo_lleno(x * size + size / 2, y * size + size / 2, size / 2);
	}

	int get_x() const { return x; }
	int get_y() const { return y; }
	int get_size() const { return size; }
};

int main()
{
	vredimensiona(ANCHO * TAMANO, ALTO * TAMANO);

	Mapa mapa;
	Pacman pacman(1, 1, TAMANO);

	bool end = false;

	while (!end)
	{
		borra();

		mapa.draw();
		pacman.draw();

		refresca();

		int t = tecla();
		switch (t)
		{
		case DERECHA:
			pacman.move(1, 0, mapa);
			break;
		case IZQUIERDA:
			pacman.move(-1, 0, mapa);
			break;
		case ARRIBA:
			pacman.move(0, -1, mapa);
			break;
		case ABAJO:
			pacman.move(0, 1, mapa);
			break;
		case ESCAPE:
			end = true;
			break;
		}

		espera(1);
	}

	return 0;
}
