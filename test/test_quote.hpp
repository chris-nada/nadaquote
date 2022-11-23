#pragma once

#include <doctest.h>

#include "../src/web.hpp"

class Test_nadaquote { TEST_CASE_CLASS("Test_nadaquote") {

    SUBCASE("download url") {
        const auto& response = Web::download_url("https://example.com/");
        REQUIRE(response.status == 200);
        REQUIRE(response.text.size() > 0);
        //std::cout << response.text << '\n';

        SUBCASE("parse") {

        }
    }

    SUBCASE("worldcat search") {
        //const std::string url = "https://stabikat.de/CHARSET=UTF-8/DB=1/LNG=DU/CMD?ACT=SRCHA&SRT=YOP&TRM=klimawandel+rhein+2020&IKT=1016";
        //const std::string url = "https://archive.org/search.php?query=klimawandel%20rhein%202020&sin=TXT";
        // researchgate: bot protection "https://www.researchgate.net/search/publication?q=saml+nkb"
        // CORE api key https://api.core.ac.uk/docs/v3
        // const std::string url = "https://serpapi.com/search.json?engine=google_scholar&q=biology"; // https://serpapi.com/manage-api-key" // 100 S/month
        //const std::string url = "https://www.base-search.net/Search/Results?lookfor=klimawandel+rhein&name=&oaboost=1&newsearch=1&refid=dcbasde";

        //const auto& response = Web::download_url("https://www.base-search.net/Search/Results?lookfor=klimawandel+rhein&name=&oaboost=1&newsearch=1&refid=dcbasde");
        //std::cout << response.status << '\n';
        //std::cout << response.text << '\n';
    }

}};
