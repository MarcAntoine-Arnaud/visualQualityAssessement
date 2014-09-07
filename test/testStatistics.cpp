
#include <Statistics/Statistics.hpp>

#include <cassert>
#include <iostream>

int main( int argc, char** argv )
{
	std::cout << "-> run tests" << std::endl;

	Statistics s;

	std::vector<unsigned char> data0( 256, 0 );
	s.process( data0 );
	assert( s.getMin().at(0) == 0 );
	assert( s.getMax().at(0) == 0 );
	
	std::vector<unsigned char> data255( 256, 255 );
	s.process( data255 );
	assert( s.getMin().at(0) == 255 );
	assert( s.getMax().at(0) == 255 );

	std::vector<unsigned char> dataMix( 256, 0 );
	dataMix.at( dataMix.size() - 1 ) = 255;
	s.process( dataMix );
	assert( s.getMin().at(0) == 0 );
	assert( s.getMax().at(0) == 255 );
	std::cout << "-> tests passed" << std::endl;
}