#ifndef _VQA_COLORSPACE_COLORSPACE_DEFINITION_HPP_
#define _VQA_COLORSPACE_COLORSPACE_DEFINITION_HPP_

#include <string>
#include <vector>
#include <pair>

class ColorspaceDefinition
{
public:
  typedef XyCoordinate std::pair<float, float>;

  virtual const std::string& getId() const = 0;
  virtual const std::string& getName() const = 0;
  virtual const std::string& getDescription() const = 0;

  const std::vector< XyCoordinate>& getPrimaries() const
  {
    return primaries;
  }

  const XyCoordinate& getPrimaryWhite() const
  {
    return primaries.at(0);
  }

  const XyCoordinate& getPrimaryRed() const
  {
    return primaries.at(1);
  }

  const XyCoordinate& getPrimaryGreen() const
  {
    return primaries.at(2);
  }

  const XyCoordinate& getPrimaryBlue() const
  {
    return primaries.at(3);
  }

private:
  std::vector< XyCoordinate > primaries;
};

# endif
