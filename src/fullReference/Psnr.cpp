
#include "Psnr.hpp"
#include "Mse.hpp"

#include <cmath>
#include <limits>
#include <iostream>

template< typename PixelType >
void processPsnr(const std::vector<PixelType>& dataRef, const std::vector<PixelType>& data, const size_t channels, std::vector<double>& psnr)
{
	Mse mse;
	mse.process(dataRef, data);
	const std::vector<double> mseResult = mse.get();

	const double psnrConstant = 20.0 * log10(std::numeric_limits<PixelType>::max());

	for( auto mseValue : mseResult )
	{
		if( mseValue == 0 ){
			psnr.push_back( - std::numeric_limits<double>::infinity() );
			continue;
		}

		psnr.push_back( psnrConstant - 10.0 * log10(mseValue) );
	}
}

Psnr::Psnr()
	: _channels( 1 )
	, _planar( false )
{
}

void Psnr::process(const std::vector<char>& dataRef, const std::vector<char>& data)
{
	processPsnr(dataRef, data, _channels, _psnr);
}

void Psnr::process(const std::vector<short>& dataRef, const std::vector<short>& data)
{
	processPsnr(dataRef, data, _channels, _psnr);
}

void Psnr::process(const std::vector<int>& dataRef, const std::vector<int>& data)
{
	processPsnr(dataRef, data, _channels, _psnr);
}

void Psnr::process(const std::vector<unsigned char>& dataRef, const std::vector<unsigned char>& data)
{
	processPsnr(dataRef, data, _channels, _psnr);
}

void Psnr::process(const std::vector<unsigned short>& dataRef, const std::vector<unsigned short>& data)
{
	processPsnr(dataRef, data, _channels, _psnr);
}

void Psnr::process(const std::vector<unsigned int>& dataRef, const std::vector<unsigned int>& data)
{
	processPsnr(dataRef, data, _channels, _psnr);
}
