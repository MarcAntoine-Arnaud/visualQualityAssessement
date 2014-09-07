#ifndef _VQA_STATISTICS_STATISTICS_HPP_
#define _VQA_STATISTICS_STATISTICS_HPP_

#include <vector>
#include <string>

class Statistics
{

public:
	Statistics()
		: _channels( 1 )
		, _planar( false )
	{
	}

	void setChannels( size_t channels ){ _channels = channels; }

	void setPlanar( bool planar = true ){ _planar = planar; }

	void process( std::vector<unsigned char>& data );

	std::vector<unsigned char> getMin(){ return _min; }
	std::vector<unsigned char> getMax(){ return _max; }

private:

	std::vector<unsigned char> _max;
	std::vector<unsigned char> _min;

	size_t _channels;
	bool _planar;
};

#endif
