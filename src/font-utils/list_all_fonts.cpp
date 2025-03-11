#include <iostream>
#include <windows.h>

// Callback function to enumerate font families
int CALLBACK EnumFontFamExProc(ENUMLOGFONTEX *lpelfe, NEWTEXTMETRICEX *lpntme, DWORD FontType, LPARAM lParam)
{
    // Print the font family name
    std::wcout << lpelfe->elfLogFont.lfFaceName << std::endl;
    return 1; // Continue enumeration
}

int main()
{
    HDC hdc = GetDC(NULL); // Get a device context for the entire screen

    LOGFONT lf;
    ZeroMemory(&lf, sizeof(LOGFONT));
    lf.lfCharSet = DEFAULT_CHARSET; // Use the default character set

    // Enumerate all font families
    EnumFontFamiliesEx(hdc, &lf, (FONTENUMPROC)EnumFontFamExProc, 0, 0);

    ReleaseDC(NULL, hdc); // Release the device context

    return 0;
}