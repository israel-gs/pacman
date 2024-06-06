#include "miniwin.h"
#include <vector>
using namespace miniwin;
using namespace std;

const int ANCHO = 19;
const int ALTO = 21;
const int TAMANO = 25;

class Mapa
{
private:
	vector<vector<char>> laberinto;

public:
	Mapa()
	{

		vector<char> fila1 = {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};
        vector<char> fila2 = {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#'};
        vector<char> fila3 = {'#', '.', '#', '#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '.', '#'};
        vector<char> fila4 = {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'};
        vector<char> fila5 = {'#', '.', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '.', '#'};
        vector<char> fila6 = {'#', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#'};
        vector<char> fila7 = {'#', '#', '#', '#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '#', '#'};
        vector<char> fila8 = {'.', '.', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '.', '.'};
        vector<char> fila9 = {'#', '#', '#', '#', '.', '#', '.', '#', '#', '.', '#', '#', '.', '#', '.', '#', '#', '#', '#'};
        vector<char> fila10 = {'.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.'};
        vector<char> fila11 = {'#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#'};
        vector<char> fila12 = {'.', '.', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '.', '.'};
        vector<char> fila13 = {'#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#'};
        vector<char> fila14 = {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#'};
        vector<char> fila15 = {'#', '.', '#', '#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '.', '#'};
        vector<char> fila16 = {'#', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '#'};
        vector<char> fila17 = {'#', '#', '.', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '#'};
        vector<char> fila18 = {'#', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#'};
        vector<char> fila19 = {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#'};
        vector<char> fila20 = {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'};
        vector<char> fila21 = {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};

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
	    int y = 0;
	    for (auto it = laberinto.begin(); it != laberinto.end(); ++it, ++y)
	    {
	        int x = 0;
	        for (auto jt = it->begin(); jt != it->end(); ++jt, ++x)
	        {
	            if (*jt == '#')
	            {
	                color(AZUL);
	                rectangulo_lleno(x * TAMANO, y * TAMANO, (x + 1) * TAMANO, (y + 1) * TAMANO);
	            }
	            else if (*jt == '.')
	            {
	                color(BLANCO);
	                circulo_lleno(x * TAMANO + TAMANO / 2, y * TAMANO + TAMANO / 2, TAMANO / 8);
	            }
	        }
	    }
	}

	bool es_pared(int x, int y) const
	{
		return laberinto[y][x] == '#';
	}
	
	bool hay_dot(int x, int y) const
    {
        return laberinto[y][x] == '.';
    }

    void comer_dot(int x, int y)
    {
        if (laberinto[y][x] == '.')
        {
            laberinto[y][x] = ' ';
        }
    }
};

class Pacman
{
private:
	int x, y;
	int size;

public:
	Pacman(int _x, int _y, int _size) : x(_x), y(_y), size(_size) {}

	void move(int dx, int dy,  Mapa &mapa)
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
                if (mapa.hay_dot(x, y))
                {
                    mapa.comer_dot(x, y);
                }

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
