
#include <fullReference/Mse.hpp>

#include <cassert>
#include <iostream>
#include <limits>
#include <cstring>

template< typename PixelType, size_t DataSize, PixelType PixelValue >
Mse& testSimilarSource( Mse& s )
{
	std::vector<PixelType> data( DataSize, PixelValue );
	s.process(data, data);
	return s;
}

template< typename PixelType, size_t DataSize1, PixelType PixelValue1, size_t DataSize2, PixelType PixelValue2 >
Mse& testSimilarSource( Mse& s )
{
	std::vector<PixelType> data( DataSize1 + DataSize2, PixelValue2 );
	std::fill(data.begin(), data.begin() + DataSize1, PixelValue1);
	s.process(data, data);
	return s;
}

template< typename PixelType, size_t DataSize, PixelType PixelValue >
Mse& testWithOneDifferentPixel( Mse& s, size_t pixelIndex, PixelType value )
{
	std::vector<PixelType> data( DataSize, PixelValue );
	std::vector<PixelType> data2( DataSize, PixelValue );
	data2.at( pixelIndex ) = value;
	data2[pixelIndex] = value;
	s.process(data, data2);
	return s;
}

template< typename PixelType >
void testMse()
{
	Mse s;

	const size_t dataSize{ 16 };
	const PixelType pixelBlack{ 0 };
	const PixelType pixelMin{ std::numeric_limits<PixelType>::min() };
	const PixelType pixelMax{ std::numeric_limits<PixelType>::max() };

	assert( (PixelType) ( testSimilarSource< PixelType, dataSize, pixelBlack >( s ).get().at(0) ) == 0 );
	assert( (PixelType) ( testSimilarSource< PixelType, dataSize, pixelMin >( s ).get().at(0) ) == 0 );
	assert( (PixelType) ( testSimilarSource< PixelType, dataSize, pixelMax >( s ).get().at(0) ) == 0 );

	assert( (PixelType) ( testSimilarSource< PixelType, dataSize, pixelMin, dataSize, pixelMax >( s ).get().at(0) ) == 0 );
	assert( (PixelType) ( testSimilarSource< PixelType, dataSize, pixelMax, dataSize, pixelMin >( s ).get().at(0) ) == 0 );
	assert( (PixelType) ( testSimilarSource< PixelType, dataSize, pixelBlack, dataSize, pixelMax >( s ).get().at(0) ) == 0 );
	assert( (PixelType) ( testSimilarSource< PixelType, dataSize, pixelMax, dataSize, pixelBlack >( s ).get().at(0) ) == 0 );
	assert( (PixelType) ( testSimilarSource< PixelType, dataSize, pixelMin, dataSize, pixelBlack >( s ).get().at(0) ) == 0 );
	assert( (PixelType) ( testSimilarSource< PixelType, dataSize, pixelBlack, dataSize, pixelMin >( s ).get().at(0) ) == 0 );

}

template< typename PixelType >
void testMseWithDiffValue( const PixelType value )
{
	Mse s;

	const size_t dataSize{ 16 };
	const PixelType pixelBlack{ 0 };
	const PixelType pixelMin{ std::numeric_limits<PixelType>::min() };
	const PixelType pixelMax{ std::numeric_limits<PixelType>::max() };

	assert( ( testWithOneDifferentPixel< PixelType, dataSize, pixelBlack >( s, 5, pixelBlack + value ).get().at(0) ) == (1.0 * value * value / dataSize) );
	assert( ( testWithOneDifferentPixel< PixelType, dataSize, pixelMin >( s, 5, pixelMin + value ).get().at(0) ) == (1.0 * value * value / dataSize) );
	assert( ( testWithOneDifferentPixel< PixelType, dataSize, pixelMax >( s, 5, pixelMax - value ).get().at(0) ) == (1.0 * value * value / dataSize) );
}

void testMseWithDiffValue( const size_t value )
{
	testMseWithDiffValue<char>(value);
	testMseWithDiffValue<short>(value);
	testMseWithDiffValue<int>(value);

	testMseWithDiffValue<unsigned char>(value);
	testMseWithDiffValue<unsigned short>(value);
	testMseWithDiffValue<unsigned int>(value);
}

int main( int argc, char** argv )
{
	std::cout << "-> run tests" << std::endl;

	testMse<char>();
	testMse<short>();
	testMse<int>();

	testMse<unsigned char>();
	testMse<unsigned short>();
	testMse<unsigned int>();

	testMseWithDiffValue( 1 );
	testMseWithDiffValue( 16 );
	testMseWithDiffValue(100);

	std::cout << "-> tests passed" << std::endl;
}
