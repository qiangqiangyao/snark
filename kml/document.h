#ifndef SNARK_KML_DOCUMENT_H_
#define SNARK_KML_DOCUMENT_H_

#include <iostream>
#include <boost/concept_check.hpp>
#include "./placemark.h"

namespace snark { namespace kml {

struct document
{
    std::vector< kml::placemark > placemarks;
};

const std::string& header();

const std::string& footer();

void write( std::ostream& os, const document& d );

} } // namespace snark { namespace kml {

#endif // SNARK_KML_DOCUMENT_H_
