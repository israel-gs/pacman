#include "miniwin.h"
#include <vector>
#include <sstream>
using namespace miniwin;
using namespace std;

const int ANCHO = 19;
const int ALTO = 21;
const int TAMANO = 25;

enum EstadoFantasma { PERSECUCION, DISPERSION, HUIDA };

class Mapa
{
private:
    vector<vector<char>> laberinto;

public:
    Mapa()
    {
        vector<char> fila1 = {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};
        vector<char> fila2 = {'#', 'o', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', 'o', '#'};
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
        vector<char> fila20 = {'#', 'o', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'o', '#'};
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
                else if (*jt == 'o')
                {
                    color(ROJO);
                    circulo_lleno(x * TAMANO + TAMANO / 2, y * TAMANO + TAMANO / 2, TAMANO / 4);
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
    bool hay_power_pellet(int x, int y) const
    {
        return laberinto[y][x] == 'o';
    }

    void comer_dot(int x, int y)
    {
        if (laberinto[y][x] == '.')
        {
            laberinto[y][x] = ' ';
        }
    }
    void comer_power_pellet(int x, int y)
    {
        if (laberinto[y][x] == 'o')
        {
            laberinto[y][x] = ' ';
        }
    }
};

class Pacman;
class Fantasma
{
protected:
    int x, y;
    int size;
    EstadoFantasma estado;
    int velocidad;
    int contador_huida;

public:
    Fantasma(int _x, int _y, int _size, int _velocidad)
        : x(_x), y(_y), size(_size), estado(PERSECUCION), velocidad(_velocidad), contador_huida(0) {}

    virtual void mover(const Mapa& mapa, const Pacman& pacman) = 0;

    void draw() const
    {
    	if(estado == HUIDA){
    		color(CYAN);
        	circulo_lleno(x * size + size / 2, y * size + size / 2, size / 2);	
		}
    
    }

    void set_estado(EstadoFantasma nuevo_estado)
    {
        estado = nuevo_estado;
        if (nuevo_estado == HUIDA)
        {
            contador_huida = 200; // Duración del estado de huida
        }
    }

    void actualizar_estado()
    {
        if (estado == HUIDA && contador_huida > 0)
        {
            --contador_huida;
        }
        if (contador_huida == 0 && estado == HUIDA)
        {
            estado = PERSECUCION;
        }
    }

    int get_x() const { return x; }
    int get_y() const { return y; }
    EstadoFantasma get_estado() const { return estado; }
    void set_position(int new_x, int new_y) { x = new_x; y = new_y; }
};

class Pacman
{
private:
    int x, y;
    int size;
    bool poder_activo;
    int duracion_poder;
    int puntuacion;
    int vidas;

public:
    Pacman(int _x, int _y, int _size) : x(_x), y(_y), size(_size), poder_activo(false), duracion_poder(0), puntuacion(0), vidas(3) {}

    void move(int dx, int dy, Mapa &mapa, vector<Fantasma*> &fantasmas, bool &end)
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
                    puntuacion += 10;
                }
                if (mapa.hay_power_pellet(x, y))
                {
                    mapa.comer_power_pellet(x, y);
                    activar_poder(fantasmas);
                    puntuacion += 50;
                }
            }
        }

        // Comprobar si Pacman se encuentra con algún fantasma
        for (auto &fantasma : fantasmas)
        {
            if (x == fantasma->get_x() && y == fantasma->get_y())
            {
                if (poder_activo && fantasma->get_estado() == HUIDA)
                {
                    puntuacion += 200; // Pacman come al fantasma
                    fantasma->set_position(9, 10); // Reiniciar posición del fantasma
                    fantasma->set_estado(PERSECUCION);
                }
                else
                {
                    vidas--;
                    if (vidas <= 0)
                    {
                        end = true; // Fin del juego
                    }
                    else
                    {
                        x = 1; y = 1; // Reiniciar posición de Pacman
                    }
                }
            }
        }
    }

    void draw() const
    {
        color(AMARILLO);
        circulo_lleno(x * size + size / 2, y * size + size / 2, size / 2);
    }

    void activar_poder(vector<Fantasma*> &fantasmas)
    {
        poder_activo = true;
        duracion_poder = 200; // Duración del efecto de los power pellets
        for (auto &fantasma : fantasmas)
        {
            fantasma->set_estado(HUIDA);
        }
    }

    void actualizar_poder()
    {
        if (poder_activo && duracion_poder > 0)
        {
            --duracion_poder;
        }
        if (duracion_poder == 0)
        {
            poder_activo = false;
        }
    }

    void draw_score_and_lives() const
    {
        stringstream ss;
        ss << "Score: " << puntuacion << "   Lives: " << vidas;
        color(BLANCO);
        texto(10, 530, ss.str().c_str());
    }

    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_size() const { return size; }
};

class Blinky : public Fantasma
{
public:
    Blinky(int _x, int _y, int _size, int _velocidad)
        : Fantasma(_x, _y, _size, _velocidad) {}

    void mover(const Mapa& mapa, const Pacman& pacman) override
    {
        // Obtener la posición actual de Blinky
        int actual_x = get_x();
        int actual_y = get_y();

        // Obtener la posición actual de Pacman
        int pacman_x = pacman.get_x();
        int pacman_y = pacman.get_y();

        // Determinar la dirección hacia la que debe moverse Blinky para perseguir a Pacman
        if (actual_x < pacman_x && !mapa.es_pared(actual_x + 1, actual_y))
        {
            x = actual_x + 1;
        }
        else if (actual_x > pacman_x && !mapa.es_pared(actual_x - 1, actual_y))
        {
            x = actual_x - 1;
        }
        else if (actual_y < pacman_y && !mapa.es_pared(actual_x, actual_y + 1))
        {
            y = actual_y + 1;
        }
        else if (actual_y > pacman_y && !mapa.es_pared(actual_x, actual_y - 1))
        {
            y = actual_y - 1;
        }
    }
    
    void draw() const 
    {
        color(ROJO);
        circulo_lleno(x * size + size / 2, y * size + size / 2, size / 2);
    }
};

class Pinky : public Fantasma
{
public:
    Pinky(int _x, int _y, int _size, int _velocidad)
        : Fantasma(_x, _y, _size, _velocidad) {}

    void mover(const Mapa& mapa, const Pacman& pacman) override
    {
        // Obtener la posición actual de Pinky
        int actual_x = get_x();
        int actual_y = get_y();

        // Obtener la posición actual de Pacman
        int pacman_x = pacman.get_x();
        int pacman_y = pacman.get_y();

        // Calcular la posición objetivo cuatro cuadros delante de Pacman
        int objetivo_x = pacman_x;
        int objetivo_y = pacman_y;

        // Determinar la dirección hacia la que debe moverse Pinky para anticipar a Pacman
        if (pacman.get_x() > 3 && !mapa.es_pared(pacman.get_x() - 4, pacman.get_y()))
        {
            objetivo_x = pacman.get_x() - 4;
        }
        else if (!mapa.es_pared(pacman.get_x() + 4, pacman.get_y()))
        {
            objetivo_x = pacman.get_x() + 4;
        }

        if (pacman.get_y() > 3 && !mapa.es_pared(pacman.get_x(), pacman.get_y() - 4))
        {
            objetivo_y = pacman.get_y() - 4;
        }
        else if (!mapa.es_pared(pacman.get_x(), pacman.get_y() + 4))
        {
            objetivo_y = pacman.get_y() + 4;
        }

        // Mover Pinky hacia el objetivo
        if (actual_x < objetivo_x && !mapa.es_pared(actual_x + 1, actual_y))
        {
            x = actual_x + 1;
        }
        else if (actual_x > objetivo_x && !mapa.es_pared(actual_x - 1, actual_y))
        {
            x = actual_x - 1;
        }
        else if (actual_y < objetivo_y && !mapa.es_pared(actual_x, actual_y + 1))
        {
            y = actual_y + 1;
        }
        else if (actual_y > objetivo_y && !mapa.es_pared(actual_x, actual_y - 1))
        {
            y = actual_y - 1;
        }
    }
    
    void draw() const     {
        color(MAGENTA);
        circulo_lleno(x * size + size / 2, y * size + size / 2, size / 2);
    }
};

int main()
{
    vredimensiona(ANCHO * TAMANO, ALTO * TAMANO +30);

    Mapa mapa;
    Pacman pacman(1, 1, TAMANO);
    Blinky blinky(9, 8, TAMANO, 1);
    Pinky pinky(9, 9, TAMANO, 1);

    vector<Fantasma*> fantasmas = { &blinky, &pinky };

    bool end = false;

    while (!end)
    {
        borra();

        mapa.draw();
        pacman.draw();
        blinky.draw();
        pinky.draw();
        pacman.draw_score_and_lives();

        for (auto &fantasma : fantasmas)
        {
            fantasma->mover(mapa, pacman);
            fantasma->actualizar_estado();
            fantasma->draw();
        }

        pacman.actualizar_poder();

        refresca();

        int t = tecla();
        switch (t)
        {
        case DERECHA:
            pacman.move(1, 0, mapa, fantasmas, end);
            break;
        case IZQUIERDA:
            pacman.move(-1, 0, mapa, fantasmas, end);
            break;
        case ARRIBA:
            pacman.move(0, -1, mapa, fantasmas, end);
            break;
        case ABAJO:
            pacman.move(0, 1, mapa, fantasmas, end);
            break;
        case ESCAPE:
            end = true;
            break;
        }

        espera(1);
    }

    return 0;
}


