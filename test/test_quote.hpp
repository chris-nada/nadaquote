#pragma once

#include <doctest.h>

#include "../src/web.hpp"

#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

class Test_nadaquote { TEST_CASE_CLASS("Test_nadaquote") {    

    SUBCASE("download url") {
        //const auto& response = Web::download_url("https://www.worldcat.org/de/search?q=kw%3ARussland+und+China+im+Wandel&itemType=book&limit=10&offset=1&orderBy=bestMatch");
        const auto& response = Web::download_url("https://www.fachportal-paedagogik.de/suche/trefferliste.html?searchIn%5B%5D=fis&searchIn%5B%5D=fdz&searchIn%5B%5D=fin&feldname1=Freitext&bool1=AND&suche=einfach&feldinhalt1=Human%C3%B6kologie");
        REQUIRE(response.status == 200);
        REQUIRE(response.text.size() > 0);
        std::cout << response.text << '\n';
        //std::ofstream out("fachportal_paedagogik_de.txt");
        //out << response.text;
    }

    SUBCASE("url encode") {
        const std::string url = cpr::util::urlEncode("http://www.httpbin.org/höchst seltsam");
        REQUIRE(url == "http%3A%2F%2Fwww.httpbin.org%2Fh%C3%B6chst%20seltsam");
    }

    SUBCASE("openalex") {
        std::ifstream in("test/openalex_response.json");
        REQUIRE(in.good());
        std::string str(std::istreambuf_iterator<char>{in}, {});
        auto data = nlohmann::json::parse(str, nullptr, false);
        REQUIRE(data.is_discarded() == false);
        REQUIRE(data["results"].size() > 0);
        //std::cout << data["results"] << std::endl;
        for (auto r : data["results"]) {
            //std::cout << "title=" << r["title"] << std::endl;
            //std::cout << "\tdisplay_name=" << r["display_name"] << std::endl;
            //std::cout << "\tpublication_year=" << r["publication_year"] << std::endl;
            //std::cout << r << std::endl;
            for (auto a : r["authorships"]) {
                //std::cout << "\tauthor=" << a["author"]["display_name"] << std::endl;
            }
        }
    }

    SUBCASE("search") {
        //https://docs.openalex.org/api/get-lists-of-entities/search-entity-lists#the-search-parameter
        //https://api.openalex.org/works?search=anke%20uhlenwinkel
        //https://www.fachportal-paedagogik.de/
        // https://www.dipf.de/de/wissensressourcen/open-access/show/view?feldname1=Freitext&mtz=500&feldinhalt1=Anke+Uhlenwinkel+Bev%C3%B6lkerung+und+Migration+in+China&pedocs=nur
        //https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c Datum
    }

}};
