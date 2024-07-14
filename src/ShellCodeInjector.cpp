#include "../include/Injector.h"


/**
 * @brief This is the main entry point for the shellcode injector application.
 * @param argc -> The number of command line arguments.
 * @param argv -> The command line arguments.
 * @return int -> Will retuen 0 if the shellcode was injected successfully, otherwise 1.
 */
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <path_to_shellcode_file>" << std::endl;
        return 1;
    }

    std::string shellcodePath = argv[1];
    
    Injector injector;
    auto shellcode = injector.loadShellCodeFromFile(shellcodePath);
    if (shellcode.empty())
    {
        std::cerr << "Failed to load shellcode from file." << std::endl;
        return 1;
    }

    std::cout << "Shellcode loaded successfully. Size: " << shellcode.size() << " bytes" << std::endl;

    if (!injector.executeShellCode(shellcode.data(), shellcode.size()))
    {
        std::cerr << "Shellcode injection failed." << std::endl;
        return 1;
    }

    return 0;
}
