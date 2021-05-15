#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "categoria.h"
typedef struct
{
    int codigo;
    char descripcion[25];
    float importe;
    int idCategoria;
}eJuego;

#endif // JUEGO_H_INCLUDED


/** \brief carga los juegos antes de iniciar la aplicacion, retorna 0 si toda esta bien o -1 si algo salio mal
 *
 * \param juegos eJuego*
 * \param tamJuegos int
 * \return int
 *
 */
int hardcodearJuego(eJuego* juegos, int tamJuegos);

/** \brief muestra un solo juego retorna 0
 *
 * \param unJuego eJuego
 * \param unaCategoria eCategoria
 * \return int
 *
 */
int mostrarJuego(eJuego unJuego, eCategoria unaCategoria);

/** \brief muestra varios juegos, retorna 0 si toda esta bien o -1 si algo salio mal
 *
 * \param juegos eJuego*
 * \param tamJuegos int
 * \param categorias eCategoria*
 * \param tamCategorias int
 * \return int
 *
 */
int mostrarJuegos(eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias);
