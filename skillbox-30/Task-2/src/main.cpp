#include <iostream>
#include <cpr/cpr.h>

int main(){
    cpr::Response response = cpr::Get(
            cpr::Url("http://httpbin.org/html"),
            cpr::Header({{"accept", "text/html"}})
        );
    std::string text = response.text;
    std::string header = text.substr(text.find("<h1>") + 4, text.find("</h1>") - text.find("<h1>") - 4);
    std::cout << header;
    return 0;
}