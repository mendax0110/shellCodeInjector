#include "../include/GenShellCode.h"
#include <fstream>
#include <iostream>

/**
 * @brief This method generates the shellcode to be injected.
 * @return std::vector<unsigned char> , the generated shellcode.
 */
std::vector<unsigned char> GenShellCode::generateShellCode()
{
    // spawns simple messageboxc with HelloWorld message via notepad.exe process
    std::vector<unsigned char> shellCode = {
        0x48, 0x31, 0xC0,
        0x48, 0x83, 0xC4, 0x28,
        0x48, 0x83, 0xE4, 0xF0,
        0x48, 0x8D, 0x15, 0x66, 0x00, 0x00, 0x00,
        0x48, 0x8D, 0x0D, 0x52, 0x00, 0x00, 0x00,
        0xE8, 0x9E, 0x00, 0x00, 0x00,
        0x4C, 0x8B, 0xF8,
        0x48, 0x8D, 0x0D, 0x5D, 0x00, 0x00, 0x00,
        0xFF, 0xD0,
        0x48, 0x8D, 0x15, 0x5F, 0x00, 0x00, 0x00,
        0x48, 0x8D, 0x0D, 0x4D, 0x00, 0x00, 0x00,
        0xE8, 0x7F, 0x00, 0x00, 0x00,
        0x4D, 0x33, 0xC9,
        0x4C, 0x8D, 0x05, 0x61, 0x00, 0x00, 0x00,
        0x48, 0x8D, 0x15, 0x4E, 0x00, 0x00, 0x00,
        0x48, 0x33, 0xC9,
        0xFF, 0xD0,
        0x48, 0x8D, 0x15, 0x56, 0x00, 0x00, 0x00,
        0x48, 0x8D, 0x0D, 0x0A, 0x00, 0x00, 0x00,
        0xE8, 0x56, 0x00, 0x00, 0x00,
        0x48, 0x33, 0xC9,
        0xFF, 0xD0,
        0x4B, 0x45, 0x52, 0x4E, 0x45, 0x4C, 0x33, 0x32, 0x2E, 0x44, 0x4C, 0x4C,
        0x00,
        0x4C, 0x6F, 0x61, 0x64, 0x4C, 0x69, 0x62, 0x72, 0x61, 0x72, 0x79, 0x41,
        0x00,
        0x55, 0x53, 0x45, 0x52, 0x33, 0x32, 0x2E, 0x44, 0x4C, 0x4C,
        0x00,
        0x4D, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x42, 0x6F, 0x78, 0x41,
        0x00,
        0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x77, 0x6F, 0x72, 0x6C, 0x64,
        0x00,
        0x4D, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65,
        0x00,
        0x45, 0x78, 0x69, 0x74, 0x50, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73,
        0x00,
        0x48, 0x83, 0xEC, 0x28,
        0x65, 0x4C, 0x8B, 0x04, 0x25, 0x60, 0x00, 0x00, 0x00,
        0x4D, 0x8B, 0x40, 0x18,
        0x4D, 0x8D, 0x60, 0x10,
        0x4D, 0x8B, 0x04, 0x24,
        0xFC,
        0x49, 0x8B, 0x78, 0x60,
        0x48, 0x8B, 0xF1,
        0xAC,
        0x84, 0xC0,
        0x74, 0x26,
        0x8A, 0x27,
        0x80, 0xFC, 0x61,
        0x7C, 0x03,
        0x80, 0xEC, 0x20,
        0x3A, 0xE0,
        0x75, 0x08,
        0x48, 0xFF, 0xC7,
        0x48, 0xFF, 0xC7,
        0xEB, 0xE5,
        0x4D, 0x8B, 0x00,
        0x4D, 0x3B, 0xC4,
        0x75, 0xD6,
        0x48, 0x33, 0xC0,
        0xE9, 0xA7, 0x00, 0x00, 0x00,
        0x49, 0x8B, 0x58, 0x30,
        0x44, 0x8B, 0x4B, 0x3C,
        0x4C, 0x03, 0xCB,
        0x49, 0x81, 0xC1, 0x88, 0x00, 0x00, 0x00,
        0x45, 0x8B, 0x29,
        0x4D, 0x85, 0xED,
        0x75, 0x08,
        0x48, 0x33, 0xC0,
        0xE9, 0x85, 0x00, 0x00, 0x00,
        0x4E, 0x8D, 0x04, 0x2B,
        0x45, 0x8B, 0x71, 0x04,
        0x4D, 0x03, 0xF5,
        0x41, 0x8B, 0x48, 0x18,
        0x45, 0x8B, 0x50, 0x20,
        0x4C, 0x03, 0xD3,
        0xFF, 0xC9,
        0x4D, 0x8D, 0x0C, 0x8A,
        0x41, 0x8B, 0x39,
        0x48, 0x03, 0xFB,
        0x48, 0x8B, 0xF2,
        0xA6,
        0x75, 0x08,
        0x8A, 0x06,
        0x84, 0xC0,
        0x74, 0x09,
        0xEB, 0xF5,
        0xE2, 0xE6,
        0x48, 0x33, 0xC0,
        0xEB, 0x4E,
        0x45, 0x8B, 0x48, 0x24,
        0x4C, 0x03, 0xCB,
        0x66, 0x41, 0x8B, 0x0C, 0x49,
        0x45, 0x8B, 0x48, 0x1C,
        0x4C, 0x03, 0xCB,
        0x41, 0x8B, 0x04, 0x89,
        0x49, 0x3B, 0xC5,
        0x7C, 0x2F,
        0x49, 0x3B, 0xC6,
        0x73, 0x2A,
        0x48, 0x8D, 0x34, 0x18,
        0x48, 0x8D, 0x7C, 0x24, 0x30,
        0x4C, 0x8B, 0xE7,
        0xA4,
        0x80, 0x3E, 0x2E,
        0x75, 0xFA,
        0xA4,
        0xC7, 0x07, 0x44, 0x4C, 0x4C, 0x00,
        0x49, 0x8B, 0xCC,
        0x41, 0xFF, 0xD7,
        0x49, 0x8B, 0xCC,
        0x48, 0x8B, 0xD6, 
        0xE9, 0x14, 0xFF, 0xFF, 0xFF,
        0x48, 0x03, 0xC3,
        0x48, 0x83, 0xC4, 0x28,
        0xC3
    };

    return shellCode;
}

/**
 * @brief This is the entry point of the program.
 * @param argc -> The number of arguments.
 * @param argv -> The arguments.
 * @return int -> The exit code.
 */
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <output_bin_file>" << std::endl;
        return 1;
    }

    std::string outputFileName = argv[1];

    GenShellCode generator;
    auto shellcode = generator.generateShellCode();

    std::ofstream outfile(outputFileName, std::ios::binary);
    if (outfile.is_open())
    {
        outfile.write(reinterpret_cast<const char*>(shellcode.data()), shellcode.size());
        outfile.close();
        std::cout << "Shellcode saved to " << outputFileName << std::endl;
    }
    else
    {
        std::cerr << "Failed to open file for writing: " << outputFileName << std::endl;
        return 1;
    }

    return 0;
}