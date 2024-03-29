#ifndef READ_FILE_H
#define READ_FILE_H

#include <string>

namespace ReadFile
{
    void processConfigFile();
    void readIdxRange(std::string readConfigLine, size_t found_IdxRange, int &count);
    void readTextFile(std::string textFileName);
    void initialiseVectorMembers(std::string textFileName, const std::vector<std::string> &dataVector, const std::vector<std::string> &coordinatesVector);
    std::vector<std::string> tokenizeString(std::string str, std::string delimiter);
}
#endif
