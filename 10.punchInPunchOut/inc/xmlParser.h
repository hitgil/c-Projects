#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <tinyxml2.h>
#include <stdexcept>
#include"./IPraser.h"


class XmlParser: public IParser 
{
public:
    void parse(const std::string& filename) override;

private:
    void displayEmployeeDetailsFromXML(const tinyxml2::XMLElement* employeeElement);
};

#endif 
