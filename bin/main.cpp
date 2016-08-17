#include <iostream>
#include <ctime>
#include <set>
#include "CellsImpl.h"

inline void delay( int _delay ) {
	int _now = clock(  ) ; 
	for ( ; clock(  ) - _now < _delay ; ) ;
}

int main(  ) { 
	int _height , _width , _delay ; 
	cin >> _height >> _width >> _delay ; 
	Cells *cells  ; 
	set < int > *bst = new set < int > ;
	while ( 1 ) { 
		cells = new CellsImpl( _height , _width ) ; 
		bst -> clear(  ) ; 
		bst -> insert( cells -> Hash(  ) ) ; 
		while ( 1 ) { 
			cells -> Generate(  ) ; 
			cells -> Show(  ) ; 
			delay( _delay ) ;
			int _hash = cells -> Hash(  ) ; 
			if ( bst -> find( _hash ) == bst -> end(  ) ) bst -> insert( _hash ) ; else break ; 
		}
		delete cells ; 
		delay( _delay * 10 ) ;
	}
	return 0 ; 
}
