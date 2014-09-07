#include "Statistics.hpp"

#include <algorithm>
#include <limits>

void Statistics::process( std::vector<unsigned char>& data )
{
	_min.clear();
	_max.clear();

	_min.resize( _channels, std::numeric_limits<unsigned char>::max() );
	_max.resize( _channels, std::numeric_limits<unsigned char>::min() );

	for( auto sample : data )
	{
		_min.at( 0 ) = std::min( sample, _min.at( 0 ) );
		_max.at( 0 ) = std::max( sample, _max.at( 0 ) );
	}
}