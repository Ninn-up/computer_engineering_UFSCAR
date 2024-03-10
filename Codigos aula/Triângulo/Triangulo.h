#ifndef TRIANGULO_H
#define TRIANGULO_H

using namespace std;

class Triangulo
{
    public:
        Triangulo(double l1, double l2, double l3);
        ~Triangulo();
        double getPerimeter();
        //Usar virtual: Permite que as subclasses utilizem seus próprios métodos "getArea()"
        virtual double getArea();
        int compare(Triangulo t);
        void imprime();
        static int getContador();

    //Revisar
    protected:
        Triangulo(double lado);
        double l[3];

    private:
        static int contador;
        static void decrementa();
        static void incrementa();
};


#endif
