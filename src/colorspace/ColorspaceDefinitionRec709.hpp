#ifndef _VQA_COLORSPACE_COLORSPACE_DEFINITION_REC709_HPP_
#define _VQA_COLORSPACE_COLORSPACE_DEFINITION_REC709_HPP_

#include <vector>
#include <pair>

class ColorspaceDefinitionRec709 : ColorspaceDefinition
{
public:
  typedef XyCoordinate std::pair<float, float>;

  ColorspaceDefinitionRec709()
  {
    primaries.push_back( std::make_pair( 0.3127, 0.3290 ) );
    primaries.push_back( std::make_pair( 0.6400, 0.3300 ) );
    primaries.push_back( std::make_pair( 0.3000, 0.0600 ) );
    primaries.push_back( std::make_pair( 0.1500, 0.0600 ) );
  }

  const std::string& getId() const
  {
    return "rec709";
  }

  const std::string& getName() const
  {
    return "Rec. 709";
  }

  const std::string& getDescription() const
  {
    return "Colorspace for the HDTV standards for production and international programme exchange";
  }
};

# endif
