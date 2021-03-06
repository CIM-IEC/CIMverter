/*
 * ModBaseClass.cpp
 *
 */

#include "ModBaseClass.h"

namespace ModelicaWorkshop {

ModBaseClass::ModBaseClass() {

}

ModBaseClass::ModBaseClass(const ModBaseClass &rhs) {
  this->_name = rhs._name;
  this->_connected = rhs._connected;
  this->annotation = rhs.annotation;
}

ModBaseClass & ModBaseClass::operator=(const ModBaseClass &rhs) {

  if(this == &rhs) return *this;
  this->_name = rhs._name;
  this->_connected = rhs._connected;
  this->annotation = rhs.annotation;
  return *this;
}


ModBaseClass::~ModBaseClass() {
  // TODO Auto-generated destructor stub
}

/*
 * Output the formatted transformation extent point of modelica
 */
std::string ModBaseClass::output_trans_extent_points() const {
  std::stringstream stream[4];
  stream[0] << std::fixed << std::setprecision(1) << this->annotation.placement.transformation.extent.first.x;
  stream[1] << std::fixed << std::setprecision(1) << this->annotation.placement.transformation.extent.first.y;
  stream[2] << std::fixed << std::setprecision(1) << this->annotation.placement.transformation.extent.second.x;
  stream[3] << std::fixed << std::setprecision(1) << this->annotation.placement.transformation.extent.second.y;

  std::string p1 = "{" + stream[0].str() + "," + stream[1].str() + "}";
  std::string p2 = "{" + stream[2].str() + "," + stream[3].str() + "}";

  return "{" + p1 + "," + p2 + "}";
}

/*
 * Output the formatted transformation origin point of modelica
 */
std::string ModBaseClass::output_trans_origin_points() const {
  std::stringstream stream[2];
  stream[0] << std::fixed << std::setprecision(1) << this->annotation.placement.transformation.origin.x;
  stream[1] << std::fixed << std::setprecision(1) << this->annotation.placement.transformation.origin.y;

  std::string p1 = stream[0].str() + "," + stream[1].str();

  return "{" + p1 + "}";
}

/*
 * Fill the annotation part of modelica template
 */
bool ModBaseClass::set_template_annotation_values(ctemplate::TemplateDictionary *dictionary) {
  dictionary->SetValue("TRANS_EXTENT_POINTS", this->output_trans_extent_points());
  dictionary->SetValue("ORIGIN_POINT", this->output_trans_origin_points());
  dictionary->SetIntValue("ROTATION", this->annotation.placement.transformation.rotation);
  dictionary->SetFormattedValue("VISIBLE", "%s", this->annotation.placement.visible ? "true" : "false");

  return true;
}

/*
 * Fill the modelica template, overriade
 */
bool ModBaseClass::set_template_values(ctemplate::TemplateDictionary *dictionary) {
  this->set_template_annotation_values(dictionary);
  return true;
}

} /* namespace ModelicaWorkshop */
