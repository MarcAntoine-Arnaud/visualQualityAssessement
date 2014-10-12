#ifndef _VQA_FULLREFERENCE_MSE_HPP_
#define _VQA_FULLREFERENCE_MSE_HPP_

#include <vector>
#include <string>

class Mse
{

public:
	Mse();

	void setChannels(size_t channels){ _channels = channels; }
	void setPlanar(bool planar = true){ _planar = planar; }

	void process(const std::vector<char>& dataRef, const std::vector<char>& data);
	void process(const std::vector<short>& dataRef, const std::vector<short>& data);
	void process(const std::vector<int>& dataRef, const std::vector<int>& data);
	void process(const std::vector<unsigned char>& dataRef, const std::vector<unsigned char>& data);
	void process(const std::vector<unsigned short>& dataRef, const std::vector<unsigned short>& data);
	void process(const std::vector<unsigned int>& dataRef, const std::vector<unsigned int>& data);

	const std::vector<double> get(){ return _mse; }

private:
	std::vector<double> _mse;

	size_t _channels;
	bool _planar;
};

#endif
