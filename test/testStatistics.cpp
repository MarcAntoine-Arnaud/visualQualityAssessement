
#include <Statistics/Statistics.hpp>

#include <cassert>
#include <iostream>
#include <limits>

template< typename PixelType >
void testMin()
{
	Statistics s;
	std::vector<PixelType> data_0( 16, 0 );
	s.process( data_0 );
	assert( s.getMin().at(0) == 0 );
	
	std::vector<PixelType> data_max( 16, std::numeric_limits<PixelType>::max() );
	s.process( data_max );
	assert( s.getMin().at(0) == std::numeric_limits<PixelType>::max() );

	std::vector<PixelType> data_mix( 16, 0 );
	data_mix.at( data_mix.size() - 1 ) = std::numeric_limits<PixelType>::max();
	s.process( data_mix );
	assert( s.getMin().at(0) == 0 );
}

template< typename PixelType >
void testMax()
{
	Statistics s;
	std::vector<PixelType> data_0( 16, 0 );
	s.process( data_0 );
	assert( s.getMax().at(0) == 0 );
	
	std::vector<PixelType> data_max( 16, std::numeric_limits<PixelType>::max() );
	s.process( data_max );
	assert( s.getMax().at(0) == std::numeric_limits<PixelType>::max() );

	std::vector<PixelType> data_mix( 16, 0 );
	data_mix.at( data_mix.size() - 1 ) = std::numeric_limits<PixelType>::max();
	s.process( data_mix );
	assert( s.getMax().at(0) == std::numeric_limits<PixelType>::max() );
}

int main( int argc, char** argv )
{
	std::cout << "-> run tests" << std::endl;

	testMin<unsigned char>();
	testMin<unsigned short>();
	testMin<unsigned int>();

	testMax<unsigned char>();
	testMax<unsigned short>();
	testMax<unsigned int>();


	std::cout << "-> tests passed" << std::endl;
}