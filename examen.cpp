#include <iostream>
#include <string>
using namespace std;

class Rectangulo
{
private:
    int ancho;
    int altura;

public:
    int esquinaX;
    int esquinaY;

    Rectangulo();
    Rectangulo(int x, int y);
    Rectangulo(int x, int y, int w, int h);

    int getAncho();
    void setAncho(int w);
    int getAltura();
    void setAltura(int h);
    int getArea();
    void intersecta(Rectangulo rect);
};

int main()
{
    Rectangulo r1;
    r1.setAncho(3);
    r1.setAltura(5);
    r1.esquinaX = 7;
    r1.esquinaY = 5;
    Rectangulo r2(6, 2);
    r2.setAltura(4);
    r2.setAncho(11);
    Rectangulo r3(1, 8, 7, 6);
    cout << r1.getArea() << endl;
    cout << r2.getArea() << endl;
    cout << r3.getArea() << endl;
    r1.intersecta(r2);
    r1.intersecta(r3);
    r2.intersecta(r3);
}

Rectangulo::Rectangulo()
{
    ancho = 0;
    altura = 0;
    esquinaX = 0;
    esquinaY = 0;
}

Rectangulo::Rectangulo(int x, int y)
{
    ancho = 0;
    altura = 0;
    esquinaX = x;
    esquinaY = y;
}

Rectangulo::Rectangulo(int x, int y, int w, int h)
{
    if (w < 0)
    {
        w = 0;
    }
    if (h < 0)
    {
        h = 0;
    }
    ancho = w;
    altura = h;
    esquinaX = x;
    esquinaY = y;
}

int Rectangulo::getAncho()
{
    return ancho;
}

void Rectangulo::setAncho(int w)
{
    if (w < 0)
    {
        w = 0;
    }
    ancho = w;
}

int Rectangulo::getAltura()
{
    return altura;
}

void Rectangulo::setAltura(int h)
{
    if (h < 0)
    {
        h = 0;
    }
    altura = h;
}

int Rectangulo::getArea()
{
    int area;
    area = ancho * altura;
    return area;
}

void Rectangulo::intersecta(Rectangulo rect)
{
    bool intx = false, inty = false;
    if (esquinaX <= (rect.esquinaX + rect.ancho) && (esquinaX + ancho) >= rect.esquinaX)
    {
        intx = true;
    }
    if (esquinaY <= (rect.esquinaY + rect.altura) && (esquinaY + altura) >= rect.esquinaY)
    {
        inty = true;
    }
    if (intx == true && inty == true)
    {
        cout << "Los rectangulos se intersectan" << endl;
    }
    else
    {
        cout << "Los rectangulos no se intersectan" << endl;
    }
}
