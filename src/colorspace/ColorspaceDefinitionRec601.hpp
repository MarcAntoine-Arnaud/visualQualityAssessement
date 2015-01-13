#ifndef _VQA_COLORSPACE_COLORSPACE_DEFINITION_REC601_HPP_
#define _VQA_COLORSPACE_COLORSPACE_DEFINITION_REC601_HPP_

#include <vector>
#include <pair>

class ColorspaceDefinitionRec601 : ColorspaceDefinition
{
public:
  typedef XyCoordinate std::pair<float, float>;

  ColorspaceDefinitionRec601()
  {
    primaries.push_back( std::make_pair( 0.3127, 0.3290 ) );
    primaries.push_back( std::make_pair( 0.6400, 0.3300 ) );
    primaries.push_back( std::make_pair( 0.3000, 0.0600 ) );
    primaries.push_back( std::make_pair( 0.1500, 0.0600 ) );
  }

  const std::string& getId() const
  {
    return "rec601";
  }

  const std::string& getName() const
  {
    return "Rec. 601";
  }

  const std::string& getDescription() const
  {
    return "Colorspace of digital television for standard 4:3 and wide-screen 16:9 aspect ratios";
  }
};

# endif
