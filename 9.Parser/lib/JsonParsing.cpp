#include "../inc/JsonParsing.h"

void JsonParsing::parse(const std::string &filename)
{
    std::ifstream file(filename);
    Json::Reader reader;
    Json::Value root;

    try
    {
        if (!file.is_open())
        {
            throw std::runtime_error("Unable to open the file: " + filename);
        }

        bool parsingSuccessful = reader.parse(file, root);
        if (!parsingSuccessful)
        {
            throw std::runtime_error("Failed to parse JSON from " + filename + ". Error: " + reader.getFormattedErrorMessages());
        }

        std::cout << "\nJSON data from '" << filename << "' has been successfully parsed.\n"
                  << std::endl;
        for (const Json::Value &restaurant : root)
        {
            if (restaurant.isMember("restaurantName"))
            {
                std::cout << "Restaurant Name: " << restaurant["restaurantName"].asString() << std::endl;
            }

            if (restaurant.isMember("location"))
            {
                std::cout << "Location: " << restaurant["location"].asString() << std::endl;
            }

            if (restaurant.isMember("cuisine"))
            {
                std::cout << "Cuisine: " << restaurant["cuisine"].asString() << std::endl;
            }

            if (restaurant.isMember("ratings"))
            {
                std::cout << "Ratings:" << std::endl;
                Json::Value ratings = restaurant["ratings"];
                if (ratings.isMember("Google"))
                {
                    std::cout << "  Google: " << ratings["Google"].asFloat() << std::endl;
                }
                if (ratings.isMember("Swiggy"))
                {
                    std::cout << "  Swiggy: " << ratings["Swiggy"].asFloat() << std::endl;
                }
                if (ratings.isMember("Zomato"))
                {
                    std::cout << "  Zomato: " << ratings["Zomato"].asFloat() << std::endl;
                }
            }

            if (restaurant.isMember("contact"))
            {
                std::cout << "Contact Information:" << std::endl;
                Json::Value contact = restaurant["contact"];
                if (contact.isMember("phone"))
                {
                    std::cout << "  Phone: " << contact["phone"].asString() << std::endl;
                }
                if (contact.isMember("email"))
                {
                    std::cout << "  Email: " << contact["email"].asString() << std::endl;
                }
                if (contact.isMember("website"))
                {
                    std::cout << "  Website: " << contact["website"].asString() << std::endl;
                }
            }

            if (restaurant.isMember("popularDishes"))
            {
                std::cout << "Popular Dishes:" << std::endl;
                for (const auto &dish : restaurant["popularDishes"])
                {
                    std::cout << "  - " << dish.asString() << std::endl;
                }
            }

            if (restaurant.isMember("isVegetarianFriendly"))
            {
                std::cout << "Vegetarian Friendly: " << (restaurant["isVegetarianFriendly"].asBool() ? "Yes" : "No") << std::endl;
            }

            if (restaurant.isMember("hasOutdoorSeating"))
            {
                std::cout << "Outdoor Seating: " << (restaurant["hasOutdoorSeating"].asBool() ? "Yes" : "No") << std::endl;
            }
            std::cout << "-----------------------------------\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}
