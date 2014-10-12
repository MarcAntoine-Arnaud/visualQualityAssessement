#ifndef _VQA_STATISTICS_STATISTICS_HPP_
#define _VQA_STATISTICS_STATISTICS_HPP_

#include <vector>
#include <string>

class Statistics
{

public:
	Statistics();

	void setChannels(size_t channels){ _channels = channels; }
	void setPlanar(bool planar = true){ _planar = planar; }

	void process(const std::vector<char>& data);
	void process(const std::vector<short>& data);
	void process(const std::vector<int>& data);
	void process(const std::vector<unsigned char>& data);
	void process(const std::vector<unsigned short>& data);
	void process(const std::vector<unsigned int>& data);

	const std::vector<size_t> getMin(){ return _min; }
	const std::vector<size_t> getMax(){ return _max; }

private:
	std::vector<size_t> _max;
	std::vector<size_t> _min;

	size_t _channels;
	bool _planar;
};

#endif
