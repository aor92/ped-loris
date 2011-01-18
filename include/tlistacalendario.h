#ifndef __TLISTACALENDARIO_H
#define __TLISTACALENDARIO_H

/** \file tlistacalendario.h
 *
 * \brief Estructura de la clase TListaCalendario.
 *
 * Definiciones de métodos y atributos de clase TListaCalendario.
 */

#include <iostream>
#include "tcalendario.h"
using namespace std;



class TNodoCalendario;
class TListaPos;

/** \brief Clase TListaCalendario.
 *
 * Estructura de la clase TListaCalendario.
 *
 */
class TListaCalendario
{
		friend class TNodoCalendario;
		
		/** \brief Sobrecarga del operador "<<", función amiga.
		 *
		 * Función amiga que se encarga de mostrar por pantalla, en un formato determinado un TPilaCalendario que le pasemos.
		 *
		 * \param os Ostream donde guardaremos la informacion que queremos mostrar.
		 * \param lista TListaCalendario que queremos mostrar.
		 *
		 * \return La funcion devuelve un ostream&.
		 */
		friend ostream& operator<<(ostream &, const TListaCalendario &);

	private:
	
		/** \brief TNodoCalendario *primero.
		 *
		 * Conforma la estructura interna de la lista TListaCalendario, indicando el primer TNodoCalendario del que está compuesta.
		 */
		TNodoCalendario *primero;
	
	public:
		
		/** \brief Constructor por defecto.
		 *
		 * Constructor por defecto que inicializa una TListaCalendario vacia.
		 */
		TListaCalendario();
		
		/** \brief Constructor de copia.
		 *
		 * Constructor de copia de TListaCalendario.
		 * \param lista TListaCalendario desde el que copiamos a la nueva TListaCalendario.
		 */
		TListaCalendario(const TListaCalendario &);
		
		/** \brief Destructor de la clase.
		 *
		 * Destructor de la clase, borra la memoria.
		 */
		~TListaCalendario();
		
		/** \brief Sobrecarga del operador asignacion.
		 *
		 *
		 * Asignamos el contenido del parámetro al objeto que llama al método.
		 * \param lista TListaCalendario del cual asignamos.
		 * \return Devuelve un TListaCalendario&.
		 */
		TListaCalendario& operator=( const TListaCalendario &);
		
		/** \brief Sobrecarga del operador igualdad.
		 *
		 * Devuelve true si las dos TPilaCalendario son iguales.
		 * \param lista TPilaCalendario del cual comprobamos que es igual.
		 * \return Devuelve un bool.
		 */
		bool operator==( const TListaCalendario &) const;
		
		/** \brief Operador suma.
		 *
		 * Inserta los elementos del operador de la izquierda más los del de la derecha que no estaban en el primero.
		 * \param lista TListaCalendario operador derecho.
		 * \return Devuelve un TListaCalendario con el resultado.
		 */
		TListaCalendario operator+ (const TListaCalendario &);
		
		/** \brief Operador resta.
		 *
		 * Sustrae los elementos del operador de la izquierda que están en el de la derecha.
		 * \param lista TListaCalendario operador derecho.
		 * \return Devuelve un TListaCalendario con el resultado.
		 */
		TListaCalendario operator- (const TListaCalendario &);
		
		/** \brief Operador resta.
		 *
		 * Inserta el TCalendario en la lista, de form ordenada, si éste no se encuentra ya en la lista.
		 * \param c TCalendario que deseamos insertar.
		 * \return Devuelve un bool para idicarnos si se insertó o no.
		 */
		bool Insertar( const TCalendario &);
		
		/** \brief Método Borrar.
		 *
		 * Borra el Tcalendeario que le pasamos por argumento si este se encuentra en la lista.
		 * \param c TCalendario que deseamos borrar.
		 * \return Devuelve un bool para idicarnos si se borro o no.
		 */
		bool Borrar( const TCalendario &);
		
		/** \brief Método Borrar.
		 *
		 * Borra la TListaPos que le pasamos por argumento si esta se encuentra en la lista.
		 * \param p TListaPos que deseamos borrar.
		 * \return Devuelve un bool para idicarnos si se borro o no.
		 */
		bool Borrar ( const TListaPos &);
		
		/** \brief Método Borrar.
		 *
		 * Borra las fechas menores a la que creemos a partir de los datos por argumento de la función.
		 * \param d int utilizado para crear fecha, el día.
		 * \param m int utilizado para crear fecha, el mes.
		 * \param a int utilizado para crear fecha, el año.
		 * 
		 * \return Devuelve un bool para idicarnos si se borro o no.
		 */
		bool Borrar( const int, const int, const int);
		
		/** \brief Método EsVacia.
		 *
		 * Este método se encarga de establecer si una lista esta vacia, es decir, no tiene ningún elemento.
		 * \return Devuelve un bool para idicarnos si está vacía o no.
		 */
		bool EsVacia() const;
		
		/** \brief Método Borrar.
		 *
		 * Obtiene el TCalendario implícito en una TListaPos de la TListaCalendario.
		 * \param p TListaPos de la que deseamos obtener su TCalendario.
		 * \return Devuelve un TCalendario, relativo a TListaPos.
		 */
		TCalendario Obtener(const TListaPos &) const;
		
		/** \brief Método Buscar.
		 *
		 * Busca en la TListaCalendario el elemento TCalendario que le pasamos por argumento.
		 * \param c TCalendario que queremos buscar.
		 * \return Devuelve un bool para indicar si se encontró o no.
		 */
		bool Buscar( const TCalendario &)const;
		
		/** \brief Método Longitud.
		 *
		 * Longitud, como su nombre indica, nos devolverá el número de elementos que tiene la TListaCalendario.
		 * \return Devuelve un int con el total de elementos.
		 */
		int Longitud() const;
		
		/** \brief Método Primera.
		 *
		 * Devuelve un TListaPos apuntando a la primera posicion de la lista.
		 * \return TListaPos.
		 */
		TListaPos Primera() const;
		
		/** \brief Método Ultima.
		 *
		 * Devuelve un TListaPos apuntando a la ultima posicion de la lista.
		 * \return TListaPos.
		 */
		TListaPos Ultima() const;
		
		/** \brief Método SumarSubl.
		 *
		 * Suma dos sublistas resultados de los rangos pasados por argumento de la función. Los dos primeros enteros extraen un subrango de la lista operator izquierdo, a su vez el segundo rango de la la lista operador derecho pasada por argumento.
		 * \param ini1 int que señala el donde empieza el primer intervalo.
		 * \param fi1 int que señala el donde termina el primer intervalo.
		 * \param lo TListaCalendario del que se recortará la segunda sublista.
		 * \param ini2 int que señala el donde empieza el segundo intervalo.
		 * \param fi2 int que señala el donde termina el segundo intervalo.
		 * 
		 * \return Devuelve un TListaCalendario con el resultado.
		 */
		TListaCalendario SumarSubl (const int, const int,const TListaCalendario&,const  int,const  int);
		
		/** \brief Método ExtraerRango.
		 *
		 * Extrae un subrango de una TListaCalendario
		 * \param ini1 int que indica por donde empezar a recortar la lista.
		 * \param fi1 int que indica por donde terminar de recortar la lista.
		 * 
		 * \return Devuelve un TListaCalendario
		 */
		TListaCalendario ExtraerRango (int , int );
};

/** \brief Clase TListaPos.
 *
 * Estructura de la clase TListaPos.
 *
 */
class TListaPos
{
		friend class TListaCalendario;
		private:
		
			/** \brief TNodoCalendario *pos.
			 *
			 * Conforma la estructura interna del TListaPos.
			 */
			TNodoCalendario *pos;
			
		public:
		
			/** \brief Constructor por defecto.
			 *
			 * Constructor por defecto que inicializa un TListaPos a NULL.
			 */
			TListaPos();
			
			/** \brief Constructor de copia.
			 *
			 * Constructor de copia de TListaPos.
			 * \param iter TListaPos a copiar.
			 */
			TListaPos(const TListaPos &);
			~TListaPos();
			TListaPos& operator=(const TListaPos &);
			bool operator==(const TListaPos &) const;
			bool operator!=(TListaPos &)const;
			TListaPos Siguiente() const;
			bool EsVacia() const;
};

class TNodoCalendario
{
	friend class TListaCalendario;
	friend class TListaPos;
	private:
	
		TCalendario c;
		TNodoCalendario *siguiente;

	public:
	
		TNodoCalendario();
		TNodoCalendario(const TNodoCalendario &);
		~TNodoCalendario();
		TNodoCalendario& operator=(const TNodoCalendario &);
};

#endif
