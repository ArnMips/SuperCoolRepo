#include "artoConverter.h"
#include "streamHelper.h"

#include <QCommandLineParser>
#include <QDebug>

int main(int argc, char *argv[]) {

    QCoreApplication app(argc, argv);
    QCommandLineParser parser;
    QCommandLineOption inputOpt("i", "Input file name", "filePath");
    QCommandLineOption outputOpt("o", "Output file name", "filePath");
    parser.addOption(inputOpt);
    parser.addOption(outputOpt);
    parser.process(app);
    std::string inputFile = parser.value(inputOpt).toStdString();
    std::string outputFile = parser.value(outputOpt).toStdString();

    auto istr = createStream<std::istream>(inputFile);
    auto ostr = createStream<std::ostream>(outputFile);
    bool res = convert_asciidigit_to_arabic(*istr, *ostr);

    return 0;
}
