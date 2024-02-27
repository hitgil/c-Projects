#include "../inc/exception.h"
#include <iostream>

FileException::FileException(const std::string &message)
    : std::runtime_error("File Error: " + message){}

InsufficientDataException::InsufficientDataException(const std::string &message)
    : std::runtime_error("Insufficient Data: " + message) {}

JsonParseException::JsonParseException(const std::string &message)
    : std::runtime_error("JSON Parse Error: " + message) {}

EmptyCSVException::EmptyCSVException(const std::string &message)
    : std::runtime_error("Empty CSV File: " + message) {}

XmlParseException::XmlParseException(const std::string &message)
    : std::runtime_error("XML Parse Error: " + message) {}

XmlElementNotFoundException::XmlElementNotFoundException(const std::string &message)
    : std::runtime_error("XML Element Not Found: " + message) {}
