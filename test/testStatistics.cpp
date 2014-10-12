
#include <Statistics/Statistics.hpp>

#include <cassert>
#include <iostream>
#include <limits>
#include <cstring>

template< typename PixelType, size_t DataSize, PixelType PixelValue >
Statistics& testSetAndProcessData( Statistics& s )
{
	std::vector<PixelType> data( DataSize, PixelValue );
	s.process( data );
	return s;
}


template< typename PixelType, size_t DataSize1, PixelType PixelValue1, size_t DataSize2, PixelType PixelValue2 >
Statistics& testSetAndProcessData( Statistics& s )
{
	std::vector<PixelType> data( DataSize1 + DataSize2, PixelValue2 );
	std::fill( data.begin(), data.begin() + DataSize1, PixelValue1 );
	s.process( data );
	return s;
}

template< typename PixelType >
void testMin()
{
	Statistics s;

	const size_t dataSize{ 16 };
	const PixelType pixelBlack{ 0 };
	const PixelType pixelMin{ std::numeric_limits<PixelType>::min() };
	const PixelType pixelMax{ std::numeric_limits<PixelType>::max() };

	assert( (PixelType) ( testSetAndProcessData< PixelType, dataSize, pixelBlack >( s ).getMin().at(0) ) == pixelBlack );
	assert( (PixelType) ( testSetAndProcessData< PixelType, dataSize, pixelMin >( s ).getMin().at(0) ) == pixelMin );
	assert( (PixelType) ( testSetAndProcessData< PixelType, dataSize, pixelMax >( s ).getMin().at(0) ) == pixelMax );

	assert( (PixelType) ( testSetAndProcessData< PixelType, dataSize, pixelMin, dataSize, pixelMax >( s ).getMin().at(0) ) == pixelMin );
	assert( (PixelType) ( testSetAndProcessData< PixelType, dataSize, pixelMax, dataSize, pixelMin >( s ).getMin().at(0) ) == pixelMin );
	assert( (PixelType) ( testSetAndProcessData< PixelType, dataSize, pixelBlack, dataSize, pixelMax >( s ).getMin().at(0) ) == pixelBlack );
	assert( (PixelType) ( testSetAndProcessData< PixelType, dataSize, pixelMax, dataSize, pixelBlack >( s ).getMin().at(0) ) == pixelBlack );
	assert( (PixelType) ( testSetAndProcessData< PixelType, dataSize, pixelMin, dataSize, pixelBlack >( s ).getMin().at(0) ) == pixelMin );
	assert( (PixelType) ( testSetAndProcessData< PixelType, dataSize, pixelBlack, dataSize, pixelMin >( s ).getMin().at(0) ) == pixelMin );
}

template< typename PixelType >
void testMax()
{
	Statistics s;

	const size_t dataSize{ 16 };
	const PixelType pixelBlack{ 0 };
	const PixelType pixelMin{ std::numeric_limits<PixelType>::min() };
	const PixelType pixelMax{ std::numeric_limits<PixelType>::max() };

	assert( ( testSetAndProcessData< PixelType, dataSize, pixelBlack >( s ).getMax().at(0) ) == pixelBlack );
	assert( ( testSetAndProcessData< PixelType, dataSize, pixelMin >( s ).getMax().at(0) ) == pixelMin );
	assert( ( testSetAndProcessData< PixelType, dataSize, pixelMax >( s ).getMax().at(0) ) == pixelMax );
	assert( ( testSetAndProcessData< PixelType, dataSize, pixelMin, dataSize, pixelMax >( s ).getMax().at(0) ) == pixelMax );
	assert( ( testSetAndProcessData< PixelType, dataSize, pixelMax, dataSize, pixelMin >( s ).getMax().at(0) ) == pixelMax );
	assert( ( testSetAndProcessData< PixelType, dataSize, pixelBlack, dataSize, pixelMax >( s ).getMax().at(0) ) == pixelMax );
	assert( ( testSetAndProcessData< PixelType, dataSize, pixelMax, dataSize, pixelBlack >( s ).getMax().at(0) ) == pixelMax );
	assert( ( testSetAndProcessData< PixelType, dataSize, pixelMin, dataSize, pixelBlack >( s ).getMax().at(0) ) == pixelBlack );
	assert( ( testSetAndProcessData< PixelType, dataSize, pixelBlack, dataSize, pixelMin >( s ).getMax().at(0) ) == pixelBlack );
}

int main( int argc, char** argv )
{
	std::cout << "-> run tests" << std::endl;

	testMin<char>();
	testMin<short>();
	testMin<int>();

	testMin<unsigned char>();
	testMin<unsigned short>();
	testMin<unsigned int>();

	testMax<unsigned char>();
	testMax<unsigned short>();
	testMax<unsigned int>();

	std::cout << "-> tests passed" << std::endl;
}