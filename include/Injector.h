#pragma once

#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Injector
{
public:
    Injector();
    ~Injector();

    bool executeShellCode(const BYTE* shellCode, size_t shellCodeSize);
    std::vector<unsigned char> loadShellCodeFromFile(const std::string& filePath);
};