#include "Statistics.hpp"

#include <algorithm>
#include <limits>

#include <iostream>

template< typename PixelType >
void processMinMax( const std::vector<PixelType>& data, const size_t channels, std::vector<size_t>& min, std::vector<size_t>& max )
{
	min.clear();
	max.clear();

	PixelType minimum{ std::numeric_limits<PixelType>::max() };
	PixelType maximum{ std::numeric_limits<PixelType>::min() };

	min.resize( channels, maximum );
	max.resize( channels, minimum );

	for( auto sample : data )
	{
		minimum = std::min( sample, minimum );
		maximum = std::max( sample, maximum );
	}
	min.at( 0 ) = minimum;
	max.at( 0 ) = maximum;
	std::cout << "min: " << minimum << std::endl;
	std::cout << "max: " << maximum << std::endl;
}

void Statistics::process( const std::vector<char>& data )
{
	processMinMax( data, _channels, _min, _max );
}

void Statistics::process( const std::vector<short>& data )
{
	processMinMax( data, _channels, _min, _max );
}

void Statistics::process( const std::vector<int>& data )
{
	processMinMax( data, _channels, _min, _max );
}

void Statistics::process( const std::vector<unsigned char>& data )
{
	processMinMax( data, _channels, _min, _max );
}

void Statistics::process( const std::vector<unsigned short>& data )
{
	processMinMax( data, _channels, _min, _max );
}

void Statistics::process( const std::vector<unsigned int>& data )
{
	processMinMax( data, _channels, _min, _max );
}
