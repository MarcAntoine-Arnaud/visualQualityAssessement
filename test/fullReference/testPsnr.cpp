
#include <fullReference/Psnr.hpp>

#include <cassert>
#include <iostream>
#include <limits>
#include <cmath>
#include <cstring>

template< typename PixelType, size_t DataSize, PixelType PixelValue >
Psnr& testSimilarSource( Psnr& s )
{
	std::vector<PixelType> data( DataSize, PixelValue );
	s.process(data, data);
	return s;
}


template< typename PixelType, size_t DataSize1, PixelType PixelValue1, size_t DataSize2, PixelType PixelValue2 >
Psnr& testSimilarSource( Psnr& s )
{
	std::vector<PixelType> data( DataSize1 + DataSize2, PixelValue2 );
	std::fill(data.begin(), data.begin() + DataSize1, PixelValue1);
	s.process(data, data);
	return s;
}

template< typename PixelType >
void testPsnr()
{
	Psnr s;

	const size_t dataSize{ 16 };
	const PixelType pixelBlack{ 0 };
	const PixelType pixelMin{ std::numeric_limits<PixelType>::min() };
	const PixelType pixelMax{ std::numeric_limits<PixelType>::max() };

	double minusInfinity = - std::numeric_limits<double>::infinity();

	assert( isinf( testSimilarSource< PixelType, dataSize, pixelBlack >( s ).get().at(0) ) );
	assert( isinf( testSimilarSource< PixelType, dataSize, pixelMin >( s ).get().at(0) ) );
	assert( isinf( testSimilarSource< PixelType, dataSize, pixelMax >( s ).get().at(0) ) );

	assert( isinf( testSimilarSource< PixelType, dataSize, pixelMin, dataSize, pixelMax >( s ).get().at(0) ) );
	assert( isinf( testSimilarSource< PixelType, dataSize, pixelMax, dataSize, pixelMin >( s ).get().at(0) ) );
	assert( isinf( testSimilarSource< PixelType, dataSize, pixelBlack, dataSize, pixelMax >( s ).get().at(0) ) );
	assert( isinf( testSimilarSource< PixelType, dataSize, pixelMax, dataSize, pixelBlack >( s ).get().at(0) ) );
	assert( isinf( testSimilarSource< PixelType, dataSize, pixelMin, dataSize, pixelBlack >( s ).get().at(0) ) );
	assert( isinf( testSimilarSource< PixelType, dataSize, pixelBlack, dataSize, pixelMin >( s ).get().at(0) ) );
}

int main( int argc, char** argv )
{
	std::cout << "-> run tests" << std::endl;

	testPsnr<char>();
	testPsnr<short>();
	testPsnr<int>();

	testPsnr<unsigned char>();
	testPsnr<unsigned short>();
	testPsnr<unsigned int>();

	std::cout << "-> tests passed" << std::endl;
}
