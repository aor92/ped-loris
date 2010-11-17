

#ifndef TCALENDARIO_H_
#define TCALENDARIO_H_	

class TCalendario
{
	public:

	TCalendario();
	TCalendario(int, int, int, char*);
	TCalendario( const TCalendario &);
	~TCalendario();
	
	TCalendario & operator=( const TCalendario& );
	
	TCalendario operator+(int);
	TCalendario operator-(int);
	TCalendario operator++(int);
	TCalendario & operator++();
	TCalendario operator--(int);
	TCalendario & operator--();
	
	
	private:
		
		int dia;
		int mes;
		int anyo;
		char* mens;
		
		bool CheckDate(int, int, int);
}


#endif
