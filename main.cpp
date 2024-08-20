// main.cpp
#include <iostream>
#include "FileManagerWin32.h"
#include "TextFileCombiner.h"

int main() {
    FileManager fileManager;
    std::wstring folderPath;
    std::wstring outputFilePath;

    // Open folder dialog to select the folder
    if (!fileManager.OpenFolderDialog(folderPath)) {
        std::cerr << "Failed to select folder." << std::endl;
        return 1;
    }

    // Open save file dialog to select the output file
    if (!fileManager.SaveFileDialog(outputFilePath, L"combined_output.txt")) {
        std::cerr << "Failed to save output file." << std::endl;
        return 1;
    }

    TextFileCombiner::combineFiles(folderPath, outputFilePath);

    std::cout << "Files combined successfully." << std::endl;

    return 0;
}
