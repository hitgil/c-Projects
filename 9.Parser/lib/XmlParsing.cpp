#include "../inc/XmlParsing.h"
#include <tinyxml2.h>

void XmlParsing::parse(const std::string &filename)
{
    try
    {
        tinyxml2::XMLDocument doc;
        tinyxml2::XMLError eResult = doc.LoadFile(filename.c_str());

        if (eResult != tinyxml2::XML_SUCCESS)
        {
            throw std::runtime_error("Error loading XML file");
        }
        std::cout << "\nXML data from '" << filename << "' has been successfully parsed.\n"
                  << std::endl;

        tinyxml2::XMLElement *root = doc.FirstChildElement("restaurant");
        if (root == nullptr)
        {
            throw std::runtime_error("Missing 'restaurant' element in XML");
        }

        tinyxml2::XMLElement *nameElement = root->FirstChildElement("restaurantName");
        if (nameElement != nullptr)
        {
            std::cout << "Restaurant Name: " << nameElement->GetText() << std::endl;
        }

        tinyxml2::XMLElement *locationElement = root->FirstChildElement("location");
        if (locationElement != nullptr)
        {
            std::cout << "Location: " << locationElement->GetText() << std::endl;
        }

        tinyxml2::XMLElement *cuisineElement = root->FirstChildElement("cuisine");
        if (cuisineElement != nullptr)
        {
            std::cout << "Cuisine: " << cuisineElement->GetText() << std::endl;
        }

        tinyxml2::XMLElement *ratingsElement = root->FirstChildElement("ratings");
        if (ratingsElement != nullptr)
        {
            tinyxml2::XMLElement *ratingElement = ratingsElement->FirstChildElement();
            while (ratingElement != nullptr)
            {
                std::cout << "Rating (" << ratingElement->Name() << "): " << ratingElement->GetText() << std::endl;
                ratingElement = ratingElement->NextSiblingElement();
            }
        }

        tinyxml2::XMLElement *contactElement = root->FirstChildElement("contact");
        if (contactElement != nullptr)
        {
            tinyxml2::XMLElement *contactDetail = contactElement->FirstChildElement();
            while (contactDetail != nullptr)
            {
                std::cout << "Contact (" << contactDetail->Name() << "): " << contactDetail->GetText() << std::endl;
                contactDetail = contactDetail->NextSiblingElement();
            }
        }

        tinyxml2::XMLElement *dishesElement = root->FirstChildElement("popularDishes");
        if (dishesElement != nullptr)
        {
            tinyxml2::XMLElement *dishElement = dishesElement->FirstChildElement("dish");
            std::cout << "Popular Dishes: ";
            while (dishElement != nullptr)
            {
                std::cout << dishElement->GetText();
                dishElement = dishElement->NextSiblingElement("dish");
                if (dishElement != nullptr)
                    std::cout << ", ";
            }
            std::cout << std::endl;
        }

        tinyxml2::XMLElement *vegetarianElement = root->FirstChildElement("isVegetarianFriendly");
        if (vegetarianElement != nullptr)
        {
            std::cout << "Vegetarian Friendly: " << vegetarianElement->GetText() << std::endl;
        }

        tinyxml2::XMLElement *outdoorSeatingElement = root->FirstChildElement("hasOutdoorSeating");
        if (outdoorSeatingElement != nullptr)
        {
            std::cout << "Outdoor Seating: " << outdoorSeatingElement->GetText() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Failed to parse XML file: " << e.what() << std::endl;
    }
}
