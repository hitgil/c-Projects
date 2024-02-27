#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>

class FileException : public std::runtime_error
{
public:
    explicit FileException(const std::string &message);
};

class InsufficientDataException : public std::runtime_error
{
public:
    explicit InsufficientDataException(const std::string &message);
};

class JsonParseException : public std::runtime_error
{
public:
    explicit JsonParseException(const std::string &message);
};

class EmptyCSVException : public std::runtime_error
{
public:
    explicit EmptyCSVException(const std::string &message);
};

class XmlParseException : public std::runtime_error
{
public:
    explicit XmlParseException(const std::string &message);
};

class XmlElementNotFoundException : public std::runtime_error
{
public:
    explicit XmlElementNotFoundException(const std::string &message);
};

#endif
