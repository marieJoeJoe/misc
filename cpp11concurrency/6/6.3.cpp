#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex



#include <nlohmann/json.hpp>


using json = nlohmann::json;

int main (int argc, char* argv[]) {

  json curr_version_info = {
    {"versions","1.0.2.3"},
	  {"module" , "pack"},
	  {"lang" , "en_US"}
  };

  //publish(upgrade_check_topic.c_str(),curr_version_info.dump(),strlen(curr_version_info.dump()),0,false);
  std::cout<<curr_version_info.dump()<<std::endl;
  std::cout<<curr_version_info.dump().length()<<std::endl;

    auto text = R"(
    {
        "Image": {
            "Width":  800,
            "Height": 600,
            "Title":  "View from 15th Floor",
            "Thumbnail": {
                "Url":    "http://www.example.com/image/481989943",
                "Height": 125,
                "Width":  100
            },
            "Animated" : false,
            "IDs": [116, 943, 234, 38793]
        }
    }
    )";

    // parse and serialize JSON
    json j_complete = json::parse(text);
    std::cout << std::setw(4) << j_complete << "\n\n";





    return 0;
}

