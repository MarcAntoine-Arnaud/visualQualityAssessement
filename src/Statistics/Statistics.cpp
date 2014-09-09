#include "Statistics.hpp"

#include <algorithm>
#include <limits>

template< typename PixelType >
void processMinMax( const std::vector<PixelType>& data, const size_t channels, std::vector<size_t>& min, std::vector<size_t>& max )
{
	min.clear();
	max.clear();

	min.resize( channels, std::numeric_limits<size_t>::max() );
	max.resize( channels, std::numeric_limits<size_t>::min() );

	for( auto sample : data )
	{
		min.at( 0 ) = std::min( (size_t)sample, min.at( 0 ) );
		max.at( 0 ) = std::max( (size_t)sample, max.at( 0 ) );
	}
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
