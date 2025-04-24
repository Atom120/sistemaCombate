// CombateP00.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Sebastián Selvas García

#include <iostream>
#include <stdlib.h>//para usar rand
#include <locale.h>//Para poder cambiar el idioma y usar ñ
class Personaje
{
private:
    int vida1;
    int defensa1;
    int ataque1;


    int vida2;
    int defensa2;
    int ataque2;

    int ataqueRecibido;

public:
 
    std::string nombre1;
    std::string nombre2;

    Personaje()//inicializa datos
    {
        std::srand(std::time(0));//Establecer hora actual como semilla
        vida1 = (rand() % 100) + 1;//Que arroje un numero aleatoria del 0 al 100
        defensa1 = rand() % 100 + 1;
        ataque1 = rand() % 100 + 1;
        ------------------------------
        vida2 = (rand() % 100) + 1;//Que arroje un numero aleatoria del 0 al 100
        defensa2 = rand() % 100 + 1;
        ataque2 = rand() % 100 + 1;
        ------------------------------
        ataqueRecibido = 0;
    }

    void pedirNombre()
    {
        std::cout << "Ingrese el nombre del peleador 1" << std::endl;
        std::cin >> nombre1;
        system("cls");

        std::cout << "Ingrese el nombre del peleador 2" << std::endl;
        std::cin >> nombre2;
        system("cls");
    }

    void MostrarStats()
    {
        std::cout << "\n---- Estado actual del jugador 1 ----" << std::endl;
        std::cout << "Nombre: " << nombre1 << std::endl;
        std::cout << "Vida: " << vida1 << std::endl;
        std::cout << "Defensa: " << defensa1 << std::endl;
        std::cout << "Ataque: " << ataque1 << std::endl;

        std::cout << "\n---- Estado actual del jugador 2 ----" << std::endl;
        std::cout << "Nombre: " << nombre2 << std::endl;
        std::cout << "Vida: " << vida2 << std::endl;
        std::cout << "Defensa: " << defensa2 << std::endl;
        std::cout << "Ataque: " << ataque2 << std::endl;
    }

    void Combate()
    {
        std::cout << std::endl << "----Combate----" << std::endl;


        if (nombre1 == nombre1)
        {
            ataqueRecibido = ataque2 - defensa1;
            if (ataqueRecibido >= 0)
            {
                vida1 = vida1 - ataqueRecibido;
                std::cout << nombre1 << " ha recibido " << ataqueRecibido << " de Daño " << std::endl;
            }
            else
            {
                std::cout << nombre1 << " ha recibido " << 0 << " de Daño " << std::endl;

            }
        }

        

        if (nombre2 == nombre2)
        {
            ataqueRecibido = ataque1 - defensa2;
            if (ataqueRecibido >= 0)
            {
                vida2 = vida2 - ataqueRecibido;
                std::cout << nombre2 << " ha recibido " << ataqueRecibido << " de Daño " << std::endl;
            }
            else
            {
                std::cout << nombre2 << " ha recibido " << 0 << " de Daño " << std::endl;

            }
        }
    }

    int getVida1()
    {
        return vida1;
    }
    int getVida2()
    {
        return vida2;
    }
   
};


int main()
{
     Personaje persona;
     std::locale::global(std::locale("es_ES.UTF-8")); // o una codificación UTF-8 similar //Codigo de Ia Gemini
     //setlocale(LC_ALL, "es_ES"); ---> El de arriba es para lo mismo pero se usa el UTF-8 y es para especificar el codigo de la pagina (charset)
     // o "es_ES" o una localización similar
     // Para poder usar ñ

     persona.pedirNombre();
    do
    {
        persona.MostrarStats();
        persona.Combate();
        persona.MostrarStats();
        system("pause");
        system("cls");
    } while (persona.getVida1() > 0 && persona.getVida2() > 0);
   
    std::cout << std::endl << "¡Fin del combate!";

    if (persona.getVida1() <= 0 && persona.getVida2() <= 0) {
        std::cout << "\nAmbos jugadores han caído, ¡Empate!" << std::endl;
    }
    else if (persona.getVida1() <= 0) {
        std::cout << "\n¡" << persona.nombre2 << " ha ganado el combate!" << std::endl;
    }
    else if (persona.getVida2() <= 0) {
        std::cout << "\n¡" << persona.nombre1 << " ha ganado el combate!" << std::endl;
    }

}