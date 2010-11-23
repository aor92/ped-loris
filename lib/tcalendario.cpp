#include "tcalendario.h"
#include <math.h>
#include <string>
#include <cstring>
#include <stdlib.h>
/** \file tcalendario.cpp
* 	\brief Este fichero contiene las funciones de  tcalendario
*
* 	En el fichero se incluyen las funciones de la clase calendario a excepcion de las inline
*/


/** \brief EsVacio
*   Devuelva  true si la funcion esta vacia
*/
bool TCalendario::EsVacio() const{
	return (dia==1 && mes==1 && anyo==1900 && mens==NULL);
}

/** \brief FechaCorrecta
*    Devuelve true si la fecha es correcta
*   \param dia dia de la fecha que se quiere comprobar
*   \param mes mes de la fecha que se quiere comprobar
*   \param anyo anyo de la fecha que se quiere comprobar
*/
bool FechaCorrecta(int dia,int mes,int anyo){
	//Comprobar la fecha
        bool correcto = false;
        bool bisiesto = false;
        
        if ( anyo >= 1900 )
        {
                        if( anyo%4 == 0)
                        {
                                        //Primer nivel bisiesto
                                if( anyo%100 == 0)
                                {
                                                //Puede que no sea.. a no ser... 400
                                                if ( anyo%400 == 0)
                                                {
                                                        //Es bisiesto....
                                                        bisiesto = true;
                                                }
                                                else bisiesto = false;
                                                
                                }
                                else bisiesto = true;
                        }
                        
                        switch (mes)
                        {
                                case 1: 
                                {
                                        if( dia >= 1 && dia <= 31 ) correcto = true;
                                
                                        break;
                                }
                                
                                case 2: 
                                {       
                                        if( bisiesto )
                                        {
                                                if( dia >= 1 && dia <= 29 ) correcto = true;
                                        }
                                        else if( dia >= 1 && dia <= 28 ) correcto = true;
                                                                        
                                        break;
                                }
                                
                                case 3:
                                {       
                                        if( dia >= 1 && dia <= 31 ) correcto = true;
                                        
                                        break;
                                }
                                
                                case 4:
                                {       
                                        if( dia >= 1 && dia <= 30 ) correcto = true;
                                        break;
                                }
                                
                                case 5:
                                {       
                                        if( dia >= 1 && dia <= 31 ) correcto = true;
                                        break;
                                }       
                                
                                case 6:
                                {       
                                        if( dia >= 1 && dia <= 30 ) correcto = true;
                                        break;
                                }       
                                
                                case 7:
                                {       
                                        if( dia >= 1 && dia <= 31 ) correcto = true;
                                        break;
                                }               
                                        
                                case 8:
                                {       
                                        if( dia >= 1 && dia <= 31 ) correcto = true;
                                        break;
                                }       
                                
                                case 9:
                                {       
                                        if( dia >= 1 && dia <= 30 ) correcto = true;
                                        break;
                                }       
                                
                                case 10:
                                {       
                                        if( dia >= 1 && dia <= 31 ) correcto = true;
                                        break;
                                }
                                case 11:
                                {       
                                        if( dia >= 1 && dia <= 30 ) correcto = true;
                                        break;
                                }       
                                case 12:
                                {       
                                        if( dia >= 1 && dia <= 31 ) correcto = true;
                                        break;
                                }       
                        }
                        
        }
        
        return correcto;
}

/** \brief Constructor de TCalendario
*   Se ocupa de contruir un calendario por defecto con la fecha 1/1/1900 y borra el mensaje si lo hubiera
*/
TCalendario::TCalendario(){
	mes=dia=1;
	anyo=1900;
	mens=NULL;
}


/** \brief Constructor sobrecargado de TCalendario
*   Construye el TCalendario con unos valores dados
*   \param dia dia del calendario a construir
*   \param mes mes del calendario a construir
*   \param anyo anyo del calendario a construir
*   \param m mensaje del calendario a construir
*/
TCalendario::TCalendario(int dia, int mes, int anyo, const char * m){
	bool correcto=FechaCorrecta(dia,mes,anyo);
	if(correcto){
		this->dia=dia;
		this->mes=mes;
		this->anyo=anyo;
		this->mens=NULL;
		this->ModMensaje(m);
	}
	else{
		this->dia=this->mes=1;this->anyo=1900;this->mens=NULL;
	}
}

/** \brief Constructor de copia de TCalendario
*   Constructor de copia de TCalendario
*  \param cal Calendario del que se van a copiar los datos
*/
TCalendario::TCalendario(const TCalendario &cal){
		dia=cal.Dia();
		mes=cal.Mes();
		anyo=cal.Anyo();
		this->mens=NULL;
		this->ModMensaje(cal.Mensaje());
}

/** \brief Destructor de TCalendario
*   Asigna la fecha por defecto al calendario y borra su nombre
*/
TCalendario::~TCalendario(){
	dia=mes=1;anyo=1900;
	if(mens!=NULL){delete[] mens;}
	mens=NULL;
}

/** \brief Operador de suma sobrecargado
*  Al llamar al operador de suma de la manera TCalendario+int devuelve un TCalendario con los dias sumados
*  \param ex numero de dias que se quieren sumar a la fecha
*/
TCalendario TCalendario::operator+(const int ex){
	TCalendario tmp((*this));
	int i;
	if(ex>0){
		for(i=1;i<=ex;i++){
			if(FechaCorrecta((tmp.dia+1),tmp.mes,tmp.anyo)) tmp.dia+=1;
			else if(FechaCorrecta(1,(tmp.mes+1),tmp.anyo)){ tmp.dia=1;tmp.mes+=1;}
			else if(FechaCorrecta(1,1,(tmp.anyo+1))) {tmp.dia=tmp.mes=1;tmp.anyo+=1;}
		}
	}
	return (tmp);
}

/** \brief Operador de resta sobrecargado
*  Al llamar al operador de resta de la manera TCalendario-int devuelve un TCalendario con los dias restados
*  \param ex numero de dias que se quieren restar a la fecha
*/
TCalendario TCalendario::operator-(const int ex){
	TCalendario tmp((*this));
	int i;
	bool seg=true;
	if(ex>0){
		for(i=1;(i<=ex && seg);i++){
			if(tmp.dia==1 && tmp.mes==1 && tmp.anyo==1900) seg=false;
			else if(FechaCorrecta((tmp.dia-1),tmp.mes,tmp.anyo)) --tmp.dia;
			else if(FechaCorrecta(31,(tmp.mes-1),tmp.anyo)) {tmp.dia=31;--tmp.mes;}
			else if(FechaCorrecta(30,(tmp.mes-1),tmp.anyo)) {tmp.dia=30;--tmp.mes;}
			else if(FechaCorrecta(29,(tmp.mes-1),tmp.anyo)) {tmp.dia=29;--tmp.mes;}
			else if(FechaCorrecta(28,(tmp.mes-1),tmp.anyo)) {tmp.dia=28;--tmp.mes;}
			else if(FechaCorrecta(30,12,(tmp.anyo-1))) {tmp.dia=30;tmp.mes=12;--tmp.anyo;}
		}
	}
	if(!seg){
		if(mens!=NULL){
		 	delete[] tmp.mens;
			tmp.mens=NULL;
		}
	}
	return (tmp);
}

/** \brief Operador TCalendario++ sobrecargado
*  Aumenta la fecha del calendario en 1 dia y devuelve la fecha original
*  \param ex parametro que se usa para diferencia los dos operadores de incremento
*/
TCalendario TCalendario::operator++(const int n){
	TCalendario tmp(*this);
	*this=*this+1;
	return tmp;
}

/** \brief Operador ++TCalendario sobrecargado
*  Aumenta la fecha del calendario en 1 dia y la devuelve
*/
TCalendario& TCalendario::operator++(){
	*this=*this+1;
	return (*this);
}


/** \brief Operador TCalendario-- sobrecargado
*  Reduce la fecha del calendario en 1 dia y devuelve la fecha original
*  \param ex parametro que se usa para diferencia los dos operadores de decremento
*/
TCalendario TCalendario::operator--(const int n){
	TCalendario tmp(*this);
	*this=((*this)-1);
	return tmp;
}

/** \brief Operador --TCalendario sobrecargado
*  Reduce la fecha del calendario en 1 dia y la devuelve
*/
TCalendario& TCalendario::operator--(){
	*this=*this-1;
	return (*this);
}


/** \brief Operador de asignacion de la calse Calendario
*  Asigna los valores de un calendario a otro
*  \param as calendario del que se toman los valores
*/
TCalendario& TCalendario::operator=(const TCalendario &as){
	if(this!=&as){
		this->~TCalendario();
		mes=as.Mes();
		dia=as.Dia();
		anyo=as.Anyo();
		this->ModMensaje(as.Mensaje());
	}
	return(*this);
}


/** \brief Modificar el mensaje del Calendario
*  Modifica el mensaje del calendario
*  \param m nuevo mensaje que se le asigna al calendario
*/
void TCalendario::ModMensaje(const char *m){
	if(mens!=NULL){
		delete[] mens;
		mens=NULL;
	}
	if(m!=NULL){
		mens=new char[strlen(m)+1];
		strcpy(mens,m);
		mens[strlen(m)]='\0'; //incecesario?
	};
}


/** \brief Operador menor (comparacion) de calendario
*  Devuelve true si la primera fecha es menor que la segunda
*  \param en calendario de la derecha de la comparación
*/
bool TCalendario::operator<(const TCalendario &en)const{
	int tmpI=this->anyo*10000+this->mes*100+this->dia;
	int tmpE=en.Anyo()*10000+en.Mes()*100+en.Dia();
	if(tmpI==tmpE){
		if(mens==NULL && en.Mensaje()==NULL) return(false);
		else if(mens!=NULL && en.Mensaje()==NULL) return(false);
		else if(mens==NULL && en.Mensaje()!=NULL) return(true);
		else{
			if(strcmp(mens,en.Mensaje())==0) return(false);
			else if(strcmp(mens,en.Mensaje())==-1) return(true); 
			else return(false);
		}
	}
	else{
		return(tmpI<tmpE);
	}
}

/** \brief Operador mayor (comparacion) de calendario
*  Devuelve true si la primera fecha es mayor que la segunda
*  \param en calendario de la derecha de la comparación
*/
bool TCalendario::operator>(const TCalendario &en)const{
	int tmpI=anyo*10000+mes*100+dia;
	int tmpE=en.Anyo()*10000+en.Mes()*100+en.Dia();
	if(tmpI==tmpE){
		if(mens==NULL && en.Mensaje()==NULL) return(false);
		else if(mens!=NULL && en.Mensaje()==NULL) return(true);
		else if(mens==NULL && en.Mensaje()!=NULL) return(false);
		else{
			if(strcmp(mens,en.Mensaje())==0) return(false);
			else if(strcmp(mens,en.Mensaje())==-1) return(false); 
			else return(true);
		}
	}
	else{
		return(tmpI>tmpE);
	}
}


/** \brief Operador comparacion(igualdad) de calendarios
*  Devuelve true si la primera fecha es igual que la segunda
*  \param en calendario de la derecha de la comparación
*/
bool TCalendario::operator==(const TCalendario &en)const{
	bool iguales=false;
	if(anyo==en.Anyo() && mes==en.Mes() && dia==en.Dia()){
		if(mens==NULL && en.mens==NULL) iguales=true;
		else if(mens!=NULL && en.mens!=NULL){
			if(strcmp(mens,en.Mensaje())==0) iguales=true;
		}
	}
	return iguales;
}

/** \brief Operador comparacion(distinto) de calendarios
*  Devuelve true si la primera fecha es distinta que la segunda
*  \param en calendario de la derecha de la comparación
*/
bool TCalendario::operator!=(const TCalendario &en)const{
	return(!((*this)==en));
}


/** \brief Modificar la fecha de Calendario
*  Modifica la fecha de calendario
*  \param dia dia que se va a insertar
*  \param mes mes que se va a insertar
*  \param anyo anyo que se va a insertar
*/
bool TCalendario::ModFecha(const int dia,const int mes,const int anyo){
	bool correcto=FechaCorrecta(dia,mes,anyo);
	if(correcto){
		this->dia=dia;
		this->mes=mes;
		this->anyo=anyo;
	}
	return correcto;
}


/** \brief Operador de salida de la clase calendario
*  Muestra el calendario de una forma especifica
*  \param os flujo de salida
*  \param cal calendario a mostrar
*/
ostream & operator<<(ostream &os,const TCalendario &cal){
	if(cal.dia<10) os<<"0"<<cal.dia;
	else os<<cal.dia;
	os<<"/";
	if(cal.mes<10) os<<"0"<<cal.mes;
	else os<<cal.mes;
	os<<"/";
	os<<cal.anyo;
	if(cal.mens==NULL) os<<" \"\"";
	else os<<" "<<"\""<<cal.mens<<"\"";
	return os;
}
