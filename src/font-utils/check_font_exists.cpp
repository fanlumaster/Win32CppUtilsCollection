#include <iostream>
#include <string>
#include <windows.h>

int CALLBACK EnumFontFamExProc(ENUMLOGFONTEX *lpelfe, NEWTEXTMETRICEX *lpntme, DWORD FontType, LPARAM lParam)
{
    std::wstring *pFontName = reinterpret_cast<std::wstring *>(lParam);
    std::wstring currentFontName(lpelfe->elfLogFont.lfFaceName);
    std::wcout.flush();
    if (lpelfe->elfLogFont.lfFaceName == *pFontName)
    {
        // Found
        *pFontName = L"";
        return 1;
    }
    return 1;
}

bool IsFontExists(const std::wstring &fontName)
{
    HDC hdc = GetDC(NULL);
    if (!hdc)
    {
        std::cerr << "Failed to get device context." << std::endl;
        return false;
    }

    LOGFONT lf = {0};
    lf.lfCharSet = DEFAULT_CHARSET;
    wcscpy_s(lf.lfFaceName, LF_FACESIZE, fontName.c_str());

    std::wstring targetFontName = fontName;

    EnumFontFamiliesEx(hdc, &lf, (FONTENUMPROC)EnumFontFamExProc, (LPARAM)&targetFontName, 0);
    ReleaseDC(NULL, hdc);

    return targetFontName.empty();
}

int main()
{
    std::wstring fontName = L"Microsoft YaHei UI";
    fontName = L"CaskaydiaCove NF";

    if (IsFontExists(fontName))
    {
        std::wcout << L"Font '" << fontName << L"' exists." << std::endl;
    }
    else
    {
        std::wcout << L"Font '" << fontName << L"' does not exist." << std::endl;
    }

    return 0;
}