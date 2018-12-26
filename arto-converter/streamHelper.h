#pragma once
#include <iostream>
#include <fstream>
#include <memory>


template <class T> struct StreamTraits {
};
template<> struct StreamTraits <std::ostream> {
    using file = std::ofstream;
    static constexpr std::ostream& sys = std::cout;
};

template<> struct StreamTraits <std::istream> {
    using file = std::ifstream;
    static constexpr std::istream& sys = std::cin;
};

template<class T /*istream or ostream*/>
std::unique_ptr<T, std::function<void(T*)> > createStream(std::string fileName){
    using func_t = std::function<void(T*)>;
    func_t foo;
    T* stream;
    if (!fileName.empty()) {
        stream = new typename StreamTraits<T>::file(fileName);
        foo = [](T* fstream){ delete fstream; };
    } else {
        stream = &StreamTraits<T>::sys;
        foo = [](T* ){ /*empty*/ };
    }
    return std::unique_ptr<T, func_t>(stream, foo);
}

std::unique_ptr<std::istream, std::function<void(std::istream*)> > createIStream(std::string inputFile)
{
    using func_t = std::function<void(std::istream*)>;
    func_t foo;
    std::istream* ist;
    if (!inputFile.empty()){
        ist = new std::ifstream(inputFile);
        foo = [](std::istream* fstream) { delete fstream; };
    } else {
        ist = &std::cin;
        foo = [](std::istream* ){ /*empty*/ };
    }
    return std::unique_ptr<std::istream, func_t>(ist, foo);
}


std::unique_ptr<std::ostream, std::function<void(std::ostream*)> > createOStream(std::string outputFile)
{
    using func_t = std::function<void(std::ostream*)>;
    func_t foo;
    std::ostream* ost;
    if (!outputFile.empty()){
        ost = new std::ofstream(outputFile);
        foo = [](std::ostream* fstream) { delete fstream; };
    } else {
        ost = &std::cout;
        foo = [](std::ostream* ){ /*empty*/ };
    }
    return std::unique_ptr<std::ostream, func_t>(ost, foo);
}
