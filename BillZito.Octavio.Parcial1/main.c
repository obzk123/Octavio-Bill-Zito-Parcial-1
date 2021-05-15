#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "utn.h"
#include "juego.h"
#include "categoria.h"
#include "cliente.h"
#include "alquileres.h"
#include "fecha.h"


#define TAMJUEGOS 10
#define TAMCATEGORIAS 5
#define TAMCLIENTES 10
#define TAMALQUILERES 10


/** \brief retorna un caracter dependiendo a la opcion ingresada por el usuario
 *
 * \return char
 *
 */
char menu();

int main()
{
    char opcion = 'N';

    int contadorClientes = 0;
    int codigoCliente = 10000;
    int contadorAlquileres = 0;
    int codigoAlquileres = 500;

    eJuego juegos[TAMJUEGOS];
    eCategoria categorias[TAMCATEGORIAS];
    eCliente clientes[TAMCLIENTES];
    eAlquileres alquileres[TAMALQUILERES];


    hardcodearCategoria(categorias, TAMCATEGORIAS);
    hardcodearJuego(juegos, TAMJUEGOS);

    inicializarClientes(clientes, TAMCLIENTES);
    inicializarAlquileres(alquileres, TAMALQUILERES);

    do
    {
        system("cls");
        switch(menu())
        {
        case 'A':
            if(contadorClientes < TAMCLIENTES)
            {
                system("cls");
                if(altaCliente(clientes,TAMCLIENTES, &codigoCliente))
                {
                    contadorClientes++;
                }
            }else
            {
                printf("Array lleno no se pueden agregar clientes.\n");
            }
            break;
        case 'B':
            if(contadorClientes > 0)
            {
                system("cls");
                modificarCliente(clientes, TAMCLIENTES);
            }else
            {
                printf("No hay clientes cargados para modificar.\n");
            }
            break;
        case 'C':
            if(contadorClientes > 0)
            {
                system("cls");
                if(bajaCliente(clientes, TAMCLIENTES) != -1)
                {
                    contadorClientes--;
                }
            }else
            {
                printf("No hay clientes cargados para eliminar.\n");
            }
            break;
        case 'D':
            if(contadorClientes > 0)
            {
                system("cls");
                ordenarClientes(clientes, TAMCLIENTES);
                mostrarClientes(clientes, TAMCLIENTES);
            }else
            {
                printf("No hay clientes para mostrar.\n");
            }
            break;
        case 'E':
            if(contadorAlquileres < TAMALQUILERES && contadorClientes > 0)
            {
                system("cls");
                if(altaAlquiler(alquileres, TAMALQUILERES, juegos, TAMJUEGOS, clientes, TAMCLIENTES, &codigoAlquileres, categorias, TAMCATEGORIAS))
                {
                    contadorAlquileres++;
                }
            }else
            {
                printf("Array lleno no se puede cargar mas alquileres o no existen clientes.\n");
            }
            break;
        case 'F':
            if(contadorAlquileres > 0 && contadorClientes > 0)
            {
                system("cls");
                listarAlquileres(alquileres, TAMALQUILERES, juegos, TAMJUEGOS, clientes, TAMJUEGOS, categorias, TAMCATEGORIAS);
            }else
            {
                printf("No hay alquileres para mostrar.\n");
            }
            break;
        case 'G':
            printf("Seguro desea salir S/N: ");
            fflush(stdin);
            scanf("%c", &opcion);
            opcion = toupper(opcion);
            while(opcion != 'S' && opcion != 'N')
            {
                printf("Opcion incorrecta. Ingrese nuevamente: ");
                fflush(stdin);
                scanf("%c", &opcion);
                opcion = toupper(opcion);
            }

            if(opcion == 'N')
            {
                printf("Salir cancelado\n");
            }
            break;
        }

    system("pause");
    }while(opcion == 'N');

    return 0;
}


char menu()
{
    char opcion;

    printf("Menu de opciones\n\n");
    printf("A.Altas Clientes\n");
    printf("B.Modificar Clientes\n");
    printf("C.Baja Clientes\n");
    printf("D.Listar Clientes\n");
    printf("E.Alta alquiler\n");
    printf("F.Lista alquiler\n");
    printf("G.Salir\n\n");
    printf("Escoja su opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);
    while(opcion != 'A' && opcion != 'B' && opcion != 'C' && opcion != 'D' && opcion != 'E' && opcion != 'F' && opcion != 'G')
    {
        printf("Opcion incorrecta, Ingrese nuevamente:");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = toupper(opcion);
    }

    return opcion;
}
