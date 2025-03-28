#include <iostream>
#include <utility>
#include <windows.h>

std::pair<std::pair<int, int>, std::pair<int, int>> GetMonitorPositionAndSize(HWND hwnd)
{
    HMONITOR hMonitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);

    if (!hMonitor)
    {
        std::cerr << "Cannot find monitor associated with hwnd!" << std::endl;
        return {{0, 0}, {0, 0}};
    }

    MONITORINFO monitorInfo = {sizeof(monitorInfo)};
    if (GetMonitorInfo(hMonitor, &monitorInfo))
    {
        int width = monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left;
        int height = monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top;
        int x = monitorInfo.rcMonitor.left;
        int y = monitorInfo.rcMonitor.top;

        return {{x, y}, {width, height}};
    }

    std::cerr << "Failed to get monitor information!" << std::endl;
    return {{0, 0}, {0, 0}}; // Return default values when failed
}

int main(int argc, char *argv[])
{
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    HWND hwnd = GetForegroundWindow();
    GetMonitorPositionAndSize(hwnd);
    auto [position, size] = GetMonitorPositionAndSize(hwnd);
    auto [x, y] = position;
    auto [width, height] = size;
    std::cout << "Monitor position: (" << x << ", " << y << ")" << std::endl;
    std::cout << "Monitor size: (" << width << ", " << height << ")" << std::endl;
    return 0;
}