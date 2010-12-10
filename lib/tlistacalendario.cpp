#include "tlistacalendario.h"

/**********Inicio TNodoCalendario**********************/
TNodoCalendario::TNodoCalendario():TCalendario()
{
	siguiente=NULL;
}
	
TNodoCalendario::TNodoCalendario(TNodoCalendario &)
{}
	
TNodoCalendario::~TNodoCalendario()
{}

TNodoCalendario::TNodoCalendario& operator=(TNodoCalendario &)
{}

/**********Fin TNodoCalendario**********************/
/**********Inicio TListaPos**********************/

TListaPos::TListaPos()
{}

TListaPos::TListaPos(TListaPos&)
{}

TListaPos::~TListaPos()
{}
	
TListaPos&
TListaPos::operator=(TListaPos &)
{}
	
bool
TListaPos::operator==(TListaPos &)
{}
			
bool
TListaPos::operator!=(TListaPos&)
{}
			
TListaPos
TListaPos::Siguiente()
{}

bool
TListaPos::EsVacia()
{}

/**********Fin TListaPos***************************/
/**********Inicio TListaCalendario**********************/

TListaCalendario::TListaCalendario()
{}

TListaCalendario::TListaCalendario(TListaCalendario &)
{}

TListaCalendario::~TListaCalendario()
{}

TListaCalendario& 
TListaCalendario::operator=(TListaCalendario &)
{}
	
bool
TListaCalendario::operator==(TListaCalendario &)
{}

TListaCalendario
TListaCalendario::operator+ (TListaCalendario &)
{}
		
TListaCalendario
TListaCalendario::operator- (TListaCalendario &)
{}
		
Bool
TListaCalendario::Insertar(TCalendario &)
{}
		
bool
TListaCalendario::Borrar(TCalendario &)
{}
		
bool
TListaCalendario::Borrar (TListaPos &)
{}
	
bool 
TListaCalendario::Borrar(int,int,int)
{}

bool
TListaCalendario::EsVacia()
{}

TCalendario
TListaCalendario::Obtener(TListaPos &)
{}
		
bool 
TListaCalendario::Buscar(TCalendario &)
{}
		
Int
TListaCalendario Longitud()
{}
		
TListaPos
TListaCalendario::Primera()
{}

TListaPos
TListaCalendario::Ultima()
{}
	
TListaCalendario
TListaCalendario::SumarSubl (int, int, TListaCalendario&, int, int)
{}
		
TListaCalendario
TListaCalendario::ExtraerRango (int , int )
{}
