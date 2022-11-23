#pragma once

#include <tuple>
#include <string>

class Web final {

public:

    struct Response { 
        const std::string text;
        const long status;
    };

    static Response download_url(const std::string& url);

};
