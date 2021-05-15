#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alquileres.h"
#include "utn.h"


int inicializarAlquileres(eAlquileres* alquileres, int tamAlquileres)
{
    int todoOk = -1;
    if(alquileres != NULL && tamAlquileres > 0)
    {
        for(int i = 0; i < tamAlquileres; i++)
        {
            alquileres[i].isEmpty = 1;
        }
        todoOk = 0;
    }

    return todoOk;
}

int altaAlquiler(eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCliente* clientes, int tamClientes, int* codigoAlquiler, eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;
    int indiceAlquiler;
    int indiceCliente;
    eAlquileres nuevoAlquiler;

    if(alquileres != NULL && tamAlquileres > 0 && juegos != NULL && tamJuegos > 0 && clientes != NULL && tamClientes > 0 && codigoAlquiler != NULL && categorias != NULL && tamCategorias > 0)
    {
        indiceAlquiler = buscarLibreAlquiler(alquileres, tamAlquileres);
        if(indiceAlquiler != -1)
        {
            nuevoAlquiler.codigoAlquiler = *codigoAlquiler;
            (*codigoAlquiler)++;

            printf("Alta nuevo alquiler\n\n");

            printf("Lista de juegos\n");
            mostrarJuegos(juegos, tamJuegos, categorias, tamCategorias);
            getInt("Ingrese el ID del juego: ", &nuevoAlquiler.codigoJuego, 1000, 1010);
            mostrarClientes(clientes, tamClientes);
            getInt("Ingrese el codigo del Cliente: ", &nuevoAlquiler.codigoCliente, 10000, 32767);
            indiceCliente = buscarClientePorID(clientes, tamClientes, nuevoAlquiler.codigoCliente);
            while(indiceCliente == -1)
            {
                getInt("Cliente no encontrado. Ingrese el codigo del Cliente nuevamente: ", &nuevoAlquiler.codigoCliente, 10000, 32767);
                indiceCliente = buscarClientePorID(clientes, tamClientes, nuevoAlquiler.codigoCliente);
            }

            printf("Ingresa la fecha\n");
            getInt("Ingrese el Dia: ", &nuevoAlquiler.fecha.dia, 1, 31);
            getInt("Ingrese el Mes: ", &nuevoAlquiler.fecha.mes, 1, 12);
            getInt("Ingrese el Anio: ", &nuevoAlquiler.fecha.anio, 1900, 2022);

            nuevoAlquiler.isEmpty = 0;
            alquileres[indiceAlquiler] = nuevoAlquiler;

            printf("Alquiler dado de alta con exito\n");
            todoOk = 1;
        }
    }

    return todoOk;
}

int buscarLibreAlquiler(eAlquileres* alquileres, int tamAlquileres)
{
    int todoOk = -1;
    if(alquileres != NULL && tamAlquileres > 0)
    {
        for(int i = 0; i < tamAlquileres; i++)
        {
            if(alquileres[i].isEmpty == 1)
            {
                todoOk = i;
                break;
            }
        }
    }

    return todoOk;
}


int listarAlquiler(eAlquileres UnAlquiler, eJuego Unjuego, eCliente Uncliente, eCategoria unaCategoria)
{
    printf("%5d %10s%10s     %3d  %10s    %5.2f  %10s      %2d/%d/%4d\n",
           Uncliente.codigo,
           Uncliente.nombre,
           Uncliente.apellido,
           UnAlquiler.codigoAlquiler,
           Unjuego.descripcion,
           Unjuego.importe,
           unaCategoria.descripcion,
           UnAlquiler.fecha.dia,
           UnAlquiler.fecha.mes,
           UnAlquiler.fecha.anio);


    return 0;
}

int listarAlquileres(eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCliente* clientes, int tamClientes, eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;

    if(alquileres != NULL && tamAlquileres > 0 && juegos != NULL && tamJuegos > 0 && clientes != NULL && tamClientes > 0 && categorias != NULL && tamCategorias > 0)
    {
        printf("Codigo    Nombre  Apellido   Codigo      Juego    Importe   Categoria      Fecha(D/M/A)\n");
        for(int i = 0; i < tamAlquileres; i++)
        {
            for(int j = 0; j < tamJuegos; j++)
            {
                for(int k = 0; k < tamClientes; k++)
                {
                    for(int l = 0; l < tamCategorias; l++)
                    {
                        if(alquileres[i].isEmpty == 0 && alquileres[i].codigoJuego == juegos[j].codigo && juegos[j].idCategoria == categorias[l].id && clientes[k].isEmpty == 0 && alquileres[i].codigoCliente == clientes[k].codigo)
                        {
                            listarAlquiler(alquileres[i], juegos[j], clientes[k], categorias[l]);
                        }
                    }
                }
            }
        }

        todoOk = 0;
    }

    return todoOk;
}


