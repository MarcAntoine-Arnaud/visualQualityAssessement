
#include "Mse.hpp"

#include <cmath>
#include <cassert>
#include <iostream>

template< typename PixelType >
void processMse(const std::vector<PixelType>& dataRef, const std::vector<PixelType>& data, const size_t channels, std::vector<double>& mse)
{
	assert(dataRef.size() == data.size());
	mse.clear();

	double m2 = 0;
	for(size_t i = 0; i < dataRef.size(); ++i)
	{
		m2 += pow((long long int)dataRef[i] - data[i], 2);
	}

	mse.push_back( m2 / (double)(dataRef.size()) );
}

Mse::Mse()
	: _channels( 1 )
	, _planar( false )
{
}

void Mse::process(const std::vector<char>& dataRef, const std::vector<char>& data)
{
	processMse(dataRef, data, _channels, _mse);
}

void Mse::process(const std::vector<short>& dataRef, const std::vector<short>& data)
{
	processMse(dataRef, data, _channels, _mse);
}

void Mse::process(const std::vector<int>& dataRef, const std::vector<int>& data)
{
	processMse(dataRef, data, _channels, _mse);
}

void Mse::process(const std::vector<unsigned char>& dataRef, const std::vector<unsigned char>& data)
{
	processMse(dataRef, data, _channels, _mse);
}

void Mse::process(const std::vector<unsigned short>& dataRef, const std::vector<unsigned short>& data)
{
	processMse(dataRef, data, _channels, _mse);
}

void Mse::process(const std::vector<unsigned int>& dataRef, const std::vector<unsigned int>& data)
{
	processMse(dataRef, data, _channels, _mse);
}
