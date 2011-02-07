#ifndef __TABBCALENDARIO_H
#define __TABBCALENDARIO_H

class TNodoABB
{
	private:
		// Elemento (etiqueta) del nodo
		TCalendario item;
		// Subárbol izquierdo y derecho
		TABBCalendario iz, de;	
		bool operator==(const TNodoABB&);
	
	public:
		TNodoABB();
		TNodoABB(const TNodoABB&);
		~TNodoABB();
		TNodoABB& operator=(const TNodoABB&);
};

class TABBCalendario
{
	friend ostream& operator<<(ostream&,const TABBCalentario&);
	private:
		TNodoABB* raiz;
		void InordenAux(TVectorCalendario&, int&);
		void PreordenAux(TVectorCalendario&, int&);
		void PostordenAux(TVectorCalendario&, int&);
	
	public:
		TABBCalendario();
		~TABBCalendario();
		TABBCalendario(const TABBCalendario&);
		TABBCalendario& operator=(const TABBCalendario&);
		bool operator==(const TABBCalendario&);
		bool EsVacio();
		bool Insertar(const TCalendario&);
		bool Borrar(const TCalendario&);
		bool Buscar(const TCalendario&);
		TCalendario Raiz() const;
		int Altura() const;
		int Nodos() const;
		int NodosHoja() const;
		TVectorCalendario Inorden();
		TVectorCalendario Preorden();
		TVectorCalendario Postorden();
		TABBCalendario operator+(const TABBCalendario&);
		TABBCalendario operator-(const TABBCalendario&);
		int* BuscarLista(const TListaCandario&) const;
};
#endif
