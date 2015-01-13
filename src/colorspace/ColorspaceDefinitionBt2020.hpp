#ifndef _VQA_COLORSPACE_COLORSPACE_DEFINITION_BT2020_HPP_
#define _VQA_COLORSPACE_COLORSPACE_DEFINITION_BT2020_HPP_

#include <vector>
#include <pair>

class ColorspaceDefinitionBt2020 : ColorspaceDefinition
{
public:
  typedef XyCoordinate std::pair<float, float>;

  ColorspaceDefinitionBt2020()
  {
    primaries.push_back( std::make_pair( 0.3127, 0.3290 ) );
    primaries.push_back( std::make_pair( 0.7080, 0.2920 ) );
    primaries.push_back( std::make_pair( 0.1700, 0.7970 ) );
    primaries.push_back( std::make_pair( 0.1310, 0.0460 ) );
  }

  const std::string& getId() const
  {
    return "bt2020";
  }

  const std::string& getName() const
  {
    return "BT.2020";
  }

  const std::string& getDescription() const
  {
    return "Colorspace for ultra-high definition television systems for production and international programme exchange";
  }
};

# endif
