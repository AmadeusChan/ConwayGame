#include "CellsImpl.h"

CellsImpl :: CellsImpl( int _height , int _width ) {
	height = _height , width = _width ; 
	data.resize( height + 2 ) ; 
	for ( int i = 0 ; i < height + 2 ; ++ i ) {
		data[ i ].resize( width + 2 ) ; 
		for ( int j = 0 ; j < width + 2 ; ++ j ) {
			data[ i ][ j ] = 0 ;
		}
	}
	srand( time( NULL ) ) ; 
	for ( int i = 1 ; i <= height ; ++ i ) {
		for ( int j = 1 ; j <= width ; ++ j ) {
			data[ i ][ j ] = rand(  ) % 2 ;
		}
	}
	counter = 0 ;
}

void CellsImpl :: Generate(  ) {
	vector < vector < int > > _data( height + 2 , vector < int > ( width + 2 , 0 )  ) ;
	for ( int i = 1 ; i <= height ; ++ i ) {
		for ( int j = 1 ; j <= width ; ++ j ) {
			int cnt = 0 ; 
			cnt += data[ i + 1 ][ j ] ; 
			cnt += data[ i + 1 ][ j + 1 ] ; 
			cnt += data[ i + 1 ][ j - 1 ] ; 
			cnt += data[ i ][ j + 1 ] ;
			cnt += data[ i ][ j - 1 ] ;
			cnt += data[ i - 1 ][ j ] ; 
			cnt += data[ i - 1 ][ j + 1 ] ;
			cnt += data[ i - 1 ][ j - 1 ] ;
			if ( data[ i ][ j ] ) {
				if ( cnt < 2 ) _data[ i ][ j ] = 0 ; 
				else if ( cnt > 3 ) _data[ i ][ j ] = 0 ;
				else _data[ i ][ j ] = 1 ; 
			} else {
				if ( cnt == 3 ) _data[ i ][ j ] = 1 ; 
				else _data[ i ][ j ] = 0 ;
			}
		}
	}
	for ( int i = 1 ; i <= height ; ++ i ) {
		for ( int j = 1 ; j <= width ; ++ j ) {
			data[ i ][ j ] = _data[ i ][ j ] ; 
		}
	}
	++ counter ; 
}

void CellsImpl :: Show(  ) {
	system( "clear" ) ; 
	cout << "Generation : " << counter << endl ; 
	for ( int i = 1 ; i <= height ; ++ i ) {
		for ( int j = 1 ; j <= width ; ++ j ) {
			if ( data[ i ][ j ] ) cout << "*"  ; else cout << " " ;
		}
		cout << endl ; 
	}
}

int CellsImpl :: Hash(  ) { 
	int _hash = 1 ; 
	for ( int i = 1 ; i <= height ; ++ i ) {
		for ( int j = 1 ; j <= height ; ++ j ) {
			_hash = ( _hash * 7 + data[ i ][ j ] ) % 100000049 ; 
		}
	}
	return _hash ;
}
