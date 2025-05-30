#include <iostream>
#include <memory>
#include <string>

using namespace std;

string get_local_appdata_path()
{
    char *localAppDataDir = nullptr;
    std::string localAppDataDirStr;
    errno_t err = _dupenv_s(&localAppDataDir, nullptr, "LOCALAPPDATA");
    if (err == 0 && localAppDataDir != nullptr)
    {
        localAppDataDirStr = std::string(localAppDataDir);
    }
    std::unique_ptr<char, decltype(&free)> dirPtr(localAppDataDir, free);
    return localAppDataDirStr.empty() ? "" : localAppDataDirStr;
}

string get_username()
{
    char *localAppDataDir = nullptr;
    std::string localAppDataDirStr;
    errno_t err = _dupenv_s(&localAppDataDir, nullptr, "USERNAME");
    if (err == 0 && localAppDataDir != nullptr)
    {
        localAppDataDirStr = std::string(localAppDataDir);
    }
    std::unique_ptr<char, decltype(&free)> dirPtr(localAppDataDir, free);
    return localAppDataDirStr.empty() ? "" : localAppDataDirStr;
}

int main(int argc, char *argv[])
{
    std::cout << get_local_appdata_path() << std::endl;
    std::cout << get_username() << std::endl;
    return 0;
}