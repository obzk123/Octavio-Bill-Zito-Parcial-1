#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"
#include "cliente.h"


int inicializarClientes(eCliente* clientes, int tamClientes)
{
    int todoOk = -1;

    if(clientes != NULL && tamClientes > 0)
    {
        for(int i = 0; i < tamClientes; i++)
        {
            clientes[i].isEmpty = 1;
        }

        todoOk = 0;
    }


    return todoOk;
}

int buscarLibreCliente(eCliente* clientes, int tamClientes)
{
    int todoOk = -1;

    if(clientes != NULL && tamClientes > 0)
    {
        for(int i = 0; i < tamClientes; i++)
        {
            if(clientes[i].isEmpty == 1)
            {
                todoOk = i;
                break;
            }
        }
    }
    return todoOk;
}

int altaCliente(eCliente* clientes, int tamClientes, int* codigoCliente)
{
    int todoOk = -1;
    int indice;
    eCliente nuevoCliente;

    if(clientes != NULL && tamClientes > 0 && codigoCliente != NULL)
    {
        indice = buscarLibreCliente(clientes, tamClientes);
        if(indice != -1)
        {
            printf("Alta cliente\n\n");
            nuevoCliente.codigo = *codigoCliente;
            (*codigoCliente)++;
            printf("Codigo de cliente: %d\n", nuevoCliente.codigo);
            getString("Ingrese el nombre del cliente: ", nuevoCliente.nombre, 51);
            getString("Ingrese el apellido del cliente: ", nuevoCliente.apellido, 51);
            printf("Ingrese el sexo (F/M): ");
            fflush(stdin);
            scanf("%c", &nuevoCliente.sexo);
            nuevoCliente.sexo = toupper(nuevoCliente.sexo);
            while(nuevoCliente.sexo != 'F' && nuevoCliente.sexo != 'M')
            {
                printf("Error sexo invalido.Ingrese nuevamente (F/M): ");
                fflush(stdin);
                scanf("%c", &nuevoCliente.sexo);
                nuevoCliente.sexo = toupper(nuevoCliente.sexo);
            }

            getString("Ingrese el telefono: ", nuevoCliente.telefono, 21);
            nuevoCliente.isEmpty = 0;

            clientes[indice] = nuevoCliente;

            printf("\nCliente dado de alta\n");
            todoOk = 1;
        }
    }
    return todoOk;
}

int modificarCliente(eCliente* clientes, int tamClientes)
{
    int todoOk = -1;
    int codigoCliente;
    int indice;
    int opcion;
    eCliente auxCliente;
    if(clientes != NULL && tamClientes > 0)
    {
        mostrarClientes(clientes, tamClientes);
        getInt("\nIngrese el Codigo del cliente: ", &codigoCliente, 10000, 32767);
        indice = buscarClientePorID(clientes, tamClientes, codigoCliente);
        if(indice != -1)
        {
            auxCliente = clientes[indice];
            printf("Cliente seleccionado\n");
            mostrarCliente(clientes[indice]);
            getInt("\nEliga que desea modificar:\n1.Nombre\n2.Apellido\n3.Telefono\n4.Volver\nEscoja su opcion: ", &opcion, 1, 4);
            switch(opcion)
            {
            case 1:
                getString("Escriba el nuevo nombre: ", auxCliente.nombre, 51);
                break;
            case 2:
                getString("Escriba el nuevo apellido: ", auxCliente.apellido, 51);
                break;
            case 3:
                getString("Escriba el nuevo telefono: ", auxCliente.telefono, 21);
                break;
            case 4:
                printf("Se cancelo la modificacion.\n");
                break;
            }
            if(opcion != 4)
            {
                clientes[indice] = auxCliente;
                printf("Cliente modificado con exito.\n");
                mostrarCliente(clientes[indice]);
            }
            todoOk = 0;
        }else
        {
            printf("El codigo ingresado es erroneo.\n");
        }
    }
    return todoOk;
}

int buscarClientePorID(eCliente* clientes, int tamClientes, int codigoCliente)
{
    int todoOk = -1;

    if(clientes != NULL && tamClientes > 0 && codigoCliente > 9999)
    {
        for(int i = 0; i < tamClientes; i++)
        {
            if(clientes[i].codigo == codigoCliente && clientes[i].isEmpty == 0)
            {
                todoOk = i;
                break;
            }
        }
    }

    return todoOk;
}

int mostrarCliente(eCliente unCliente)
{
    printf("%5d%10s%10s    %10s   %c\n",
           unCliente.codigo,
           unCliente.nombre,
           unCliente.apellido,
           unCliente.telefono,
           unCliente.sexo);

    return 0;
}

int mostrarClientes(eCliente* clientes, int tamClientes)
{
    int todoOk = -1;

    if(clientes != NULL && tamClientes > 0)
    {
        printf("Codigo   Nombre  Apellido      Telefono   Sexo\n");
        for(int i = 0; i < tamClientes; i++)
        {
            if(clientes[i].isEmpty == 0)
            {
                mostrarCliente(clientes[i]);
                todoOk = 0;
            }
        }
    }

    return todoOk;
}

int bajaCliente(eCliente* clientes, int tamClientes)
{
    int todoOk = -1;
    int codigoCliente;
    int indice;

    if(clientes != NULL && tamClientes > 0)
    {
        mostrarClientes(clientes, tamClientes);
        getInt("Ingrese el Codigo del cliente: ", &codigoCliente, 10000, 32767);
        indice = buscarClientePorID(clientes, tamClientes, codigoCliente);
        if(indice != -1)
        {
            clientes[indice].isEmpty = 1;
            todoOk = 1;
            printf("Cliente eliminado con exito\n");
        }else
        {
            printf("Codigo de cliente inexistente\n");
        }
    }
    return todoOk;
}


int ordenarClientes(eCliente* clientes, int tamClientes)
{
    int todoOk = -1;
    eCliente auxCliente;

    if(clientes != NULL && tamClientes > 0)
    {
        for(int i = 0; i < tamClientes - 1; i++)
        {
            for(int j = i + 1; j < tamClientes; j++)
            {
                if( (strcmpi(clientes[i].apellido, clientes[j].apellido) > 0) || (strcmpi(clientes[i].apellido, clientes[j].apellido) == 0 && strcmpi(clientes[i].nombre, clientes[j].nombre) > 0))
                {
                    auxCliente = clientes[i];
                    clientes[i] = clientes[j];
                    clientes[j] = auxCliente;
                }
            }
        }

        todoOk = 0;
    }

    return todoOk;
}
