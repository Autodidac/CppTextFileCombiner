// TextFileCombiner.h
#pragma once

#include <string>

class TextFileCombiner {
public:
    static void combineFiles(const std::wstring& directoryPath, const std::wstring& outputFilePath);
};
