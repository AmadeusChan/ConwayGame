#ifndef CELLS_IMPL_H
#define CELLS_IMPL_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include "Cells.h"

using namespace std ;

class CellsImpl : public Cells {
	private :
		vector < vector < int > > data ; 
		int height , width , counter ;
	public :
		CellsImpl( int _height , int _width ) ;
		void Generate(  ) ; 
		void Show(  ) ;
		int Hash(  ) ; 
} ;

#endif
