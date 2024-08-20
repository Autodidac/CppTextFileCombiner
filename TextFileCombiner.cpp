// TextFileCombiner.cpp
#include "TextFileCombiner.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

namespace fs = std::filesystem;

void TextFileCombiner::combineFiles(const std::wstring& directoryPath, const std::wstring& outputFilePath) {
    std::wofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        std::wcerr << L"Failed to open output file: " << outputFilePath << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            std::wstring filePath = entry.path().wstring();
            std::wstring extension = entry.path().extension().wstring();
            if (extension == L".cpp" || extension == L".h") {
                std::wifstream inputFile(filePath);
                if (inputFile.is_open()) {
                    std::wstringstream buffer;
                    buffer << inputFile.rdbuf();
                    std::wstring fileContents = buffer.str();
                    outputFile << L"/* Start of file: " << entry.path().filename().wstring() << L" */\n";
                    outputFile << fileContents << L"\n";
                    outputFile << L"/* End of file: " << entry.path().filename().wstring() << L" */\n";
                    inputFile.close();
                }
                else {
                    std::wcerr << L"Failed to open input file: " << filePath << std::endl;
                }
            }
        }
    }

    outputFile.close();
}
