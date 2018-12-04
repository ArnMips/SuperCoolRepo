#include "artoConverter.h"
#include <iostream>
#include <QCommandLineParser>
#include <fstream>

#include <memory>

template <classt4 T> struct StreamTraits {
};
template<> struct StreamTraits <std::ostream> {
    using streamType = std::ofstream;
    static constexpr std::ostream& stream = std::cout;
};

template<> struct StreamTraits <std::istream> {
    using streamType = std::ifstream;
    static constexpr std::istream& stream = std::cin;
};

template<class T>
std::unique_ptr<T, std::function<void(T*)> > createStream(std::string file){
    using func_t = std::function<void(T*)>;
    auto f = file.empty()
            ? static_cast<func_t>([](T* ) { /*empty*/ })
            : static_cast<func_t>([](T* fstream) { delete fstream; });
    T* ist = file.empty()
            ? &StreamTraits<T>::stream
            : new typename StreamTraits<T>::streamType(file);

    return std::unique_ptr<T, func_t>(ist, f);
}

std::unique_ptr<std::istream, std::function<void(std::istream*)> > createIStream(std::string inputFile)
{
    using func_t = std::function<void(std::istream*)>;
    auto f = inputFile.empty()
            ? static_cast<func_t>([](std::istream* ) { /*empty*/ })
            : static_cast<func_t>([](std::istream* ifstream) { delete ifstream; });
    std::istream* ist = inputFile.empty()
            ? &std::cin
            : new std::ifstream(inputFile);

    return std::unique_ptr<std::istream, func_t>(ist, f);
}

std::unique_ptr<std::ostream, std::function<void(std::ostream*)> > createOStream(std::string outputFile)
{
    using func_t = std::function<void(std::ostream*)>;
    auto f = outputFile.empty()
            ? static_cast<func_t>([](std::ostream* ) { /*empty*/ })
            : static_cast<func_t>([](std::ostream* ofstream) { delete ofstream; });
    std::ostream* ist = outputFile.empty()
            ? &std::cout
            : new std::ofstream(outputFile);

    return std::unique_ptr<std::ostream, func_t>(ist, f);
}

int main(int argc, char *argv[]) {

    QCoreApplication app(argc, argv);

    QCommandLineParser parser;
    QCommandLineOption inputOpt("i", "Input file name");
    QCommandLineOption outputOpt("o", "Output file name");
    parser.addOption(inputOpt);
    parser.addOption(outputOpt);
    parser.process(app);

    std::string inputFile = parser.value(inputOpt).toStdString();
    std::string outputFile = parser.value(outputOpt).toStdString();


    auto istr = createIStream(inputFile);
    //auto istr = createStream<std::istream>(inputFile);
    auto ostr = createOStream(outputFile);
    //auto ostr = createStream<std::ostream>(outputFile);
    convert_asciidigit_to_arabic(*istr, *ostr);

//    if(!inputFile.empty() && !outputFile.empty()) {
//        std::ifstream fin(inputFile);
//        std::ofstream fout(outputFile);
//        convert_asciidigit_to_arabic(inputFile.empty() ? std::cin : std::ifstream(inputFile),
//                                     fout);
//        std::cout << "1";
//    } else if (!inputFile.empty()){
//        std::ifstream fin(inputFile);
//        convert_asciidigit_to_arabic(fin, std::cout);
//        std::cout << "2";
//    } else if (!outputFile.empty()){
//        std::ofstream fout(outputFile);
//        convert_asciidigit_to_arabic(std::cin, fout);
//        std::cout << "3";
//    } else {
//        convert_asciidigit_to_arabic(std::cin, std::cout);
//        std::cout << "4";
//    }

    return 0;
}
