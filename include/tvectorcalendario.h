#ifndef TVECTORCALENDARIO_H_
#define TVECTORCALENDARIO_H_

#include "tcalendario.h"
/** \file tvectorcalendario.h
 *
 * \brief Estructura de la clase TVectorCalendario.
 *
 * Definiciones de métodos y atributos de clase TVectorCalendario.
 */



/** \brief Clase TVectorCalendario.
 *
 * Estructura de la clase TVectorCalendario.
 *
 */
class TVectorCalendario
{
	
	/** \brief Sobrecarga del operador "<<", función amiga.
	 *
	 * Función amiga que se encarga de mostrar por pantalla, en un formato determinado un TVectorCalendario que le pasemos.
	 *
	 * \param os Ostream donde guardaremos la informacion que queremos mostrar.
	 * \param v TVectorCalendario que queremos mostrar.
	 *
	 * \return La funcion devuelve un ostream&.
	 */
	friend ostream& operator <<(ostream&, const TVectorCalendario&);

public:

	/** \brief Constructor por defecto.
	 *
	 * Constructor por defecto que inicializa a 0 los componentes del TVectorCalendario.
	 */
	TVectorCalendario();

	/** \brief Constructor sobrecargado.
	 *
	 * Constructor sobrecargado que recibe un entero con el que le daremos una dimension al vector.
	 * \param tam Entero que contiene el valor de la dimensión que queremos asignarle al vector.
	 */
	TVectorCalendario( const int);

	/** \brief Constructor de copia.
	 *
	 * Constructor de copia de vectores.
	 * \param v TVectorCalendario desde el que copiamos al nuevo TVectorCalendario.
	 */
	TVectorCalendario( const TVectorCalendario&);

	/** \brief Destructor de la clase.
	 *
	 * Destructor de la clase, borra la memoria.
	 */
	~TVectorCalendario();
	/** \brief Sobrecarga del operador asignacion.
	 *
	 *
	 * Asignamos el contenido del parámetro al objeto que llama al método.
	 * \param v TVectorCalendario del cual asignamos.
	 * \return Devuelve un TVectorCalendario&.
	 */
	TVectorCalendario& operator=( const TVectorCalendario&);
	/** \brief Sobrecarga del operador igualdad.
	 *
	 * Devuelve true si los dos TVectorCalendario son iguales.
	 * \param v TVectorCalendario del cual comprobamos que es igual.
	 * \return Devuelve un bool.
	 */
	bool operator==( const TVectorCalendario&);
	/** \brief Sobrecarga del operador desigualdad.
	 *
	 * Devuelve true si los dos TVectorCalendario son desiguales.
	 * \param v TVectorCalendario del cual comprobamos que es desigual.
	 * \return Devuelve un bool.
	 */
	bool operator!=( const TVectorCalendario&);
	/** \brief Sobrecarga del operador corchete derecho.
	 *
	 * Inserta un TCalendario en el vector
	 * \param int posicion donde se guarda el TCalendario.
	 * \return Devuelve el TCalendario introducido.
	 */
	TCalendario & operator[](int);
	/** \brief Sobrecarga del operador corchete izquierdo.
	 *
	 * Devuelve un TCalendario del vector
	 * \param int posicion donde se encuentra el TCalendario.
	 * \return Devuelve el TCalendario de la posicion.
	 */
	TCalendario operator[](int) const;

	/** \brief Metodo Longitud.
	 *
	 * Devuelve un entero con la longitud del vector, que es su tamaño.
	 * \return Devuelve un entero, dimension del vector.
	 */
	int Tamano() const;

	/** \brief Metodo Cantidad.
	 *
	 * Este metodo se encarga de contar los Calendarios del vector que no estan vacios.
	 * \return Devuelve un entero con la cantidad de proos no vacios.
	 */
	int Ocupadas() const;

	
	bool ExisteCal(TCalendario&)const;
	
	void MostrarMensajes( const int, const int, const int);
	


	/** \brief Metodo Redimensionar.
	 *
	 * Este metodo efectúa una redimension del vector, eliminando los componenetes finales si el tamaño que le pasamos es menor que el anterior o creando Calendarios vacios si este es mayor.
	 * \param tam Entero mediante el cual introduciremos el nuevo valor de dimension del vector.
	 * \return Devuelve un bool, indica si se ha redimensionado o no.
	 */
	bool Redimensionar(int);

private:

	/** \brief Entero tamano.
	 *
	 * Contiene el valor del tamaño total del vector TVectorCalendario.
	 */
	int tamano;

	/** \brief Puntero a TCalendario.
	 *
	 * Con este puntero haremos las veces de vector donde almacenamos TCalendario's.
	 */
	TCalendario *c;

	/** \brief TCalendario error.
	 *
	 * TCalendario creado por si hay alguna situacion de error devolverlo.
	 */
	TCalendario error;

};


#endif /* TVECTORCALENDARIO_H_ */
