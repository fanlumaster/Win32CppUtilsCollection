#include <iostream>
#include <windows.h>

int GetTaskbarHeight()
{
    // Main Monitor Info
    MONITORINFO monitorInfo = {sizeof(MONITORINFO)};
    GetMonitorInfo(MonitorFromWindow(GetDesktopWindow(), MONITOR_DEFAULTTOPRIMARY), &monitorInfo);

    // Get monitor entire area, including taskbar
    RECT fullRect = monitorInfo.rcMonitor;
    // Get work area, excluding taskbar
    RECT workRect = monitorInfo.rcWork;

    // Compute taskbar height
    // Suppose taskbar is at the bottom of the screen
    int taskbarHeight = fullRect.bottom - workRect.bottom;

    return taskbarHeight;
}

int GetPrimaryMonitorHeight()
{
    // Get the main monitor information
    MONITORINFO monitorInfo = {sizeof(MONITORINFO)};
    GetMonitorInfo(MonitorFromWindow(GetDesktopWindow(), MONITOR_DEFAULTTOPRIMARY), &monitorInfo);

    // Get the height of the main monitor
    int height = monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top;
    return height;
}

int main()
{
    // Set the DPI awareness to Per Monitor Aware V2
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    int height = GetTaskbarHeight();
    int anotherHeight = GetPrimaryMonitorHeight();
    std::cout << "Taskbar height: " << height << " pixels" << std::endl;
    std::cout << "Monitor height: " << anotherHeight << " pixels" << std::endl;
    return 0;
}