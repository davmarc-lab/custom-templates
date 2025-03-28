#include <iostream>

#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
    std::string path = "resources/file.txt";
    std::string content{};

    std::ifstream file{};
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        file.open(path.c_str());

        std::stringstream contentStream{};
        contentStream << file.rdbuf();
        file.close();

        content = contentStream.str();
    } catch (std::ifstream::failure e) {
        std::cout << e.what() << "\n";
    }
    std::cout << content << "\n";

    return 0;
}
