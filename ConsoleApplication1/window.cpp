#include "window.h"


// Bunch of boilerplate

HWND* editBox;
HWND* startX;
HWND* endX;
HWND* result;

Window::Window() 
    : m_hInstance(GetModuleHandle(nullptr)) {
    // Register the window class.
    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = m_hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    m_hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Metode Romberg",    // Window text
        WS_OVERLAPPED | WS_CAPTION |
        WS_SYSMENU | WS_MINIMIZEBOX,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 340, 120,

        NULL,       // Parent window    
        NULL,       // Menu
        m_hInstance,  // Instance handle
        NULL        // Additional application data
    );

    m_editBox = CreateWindowEx(0, L"EDIT", L"Enter Data", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_HSCROLL | ES_MULTILINE, 0, 0, 200, 60, m_hwnd, NULL, NULL, NULL);
    m_startX = CreateWindowEx(0, L"EDIT", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER |  WS_HSCROLL | ES_MULTILINE, 200, 0, 20, 40, m_hwnd, NULL, NULL, NULL);
    m_endX = CreateWindowEx(0, L"EDIT", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER  | WS_HSCROLL | ES_MULTILINE, 220, 0, 20, 40, m_hwnd, NULL, NULL, NULL);
    m_result = CreateWindowEx(0, L"Static", L"Result : ", WS_CHILD | WS_VISIBLE , 240, 0, 100, 40, m_hwnd, NULL, NULL, NULL);
    editBox = &m_editBox;
    startX = &m_startX;
    endX = &m_endX;
    result = &m_result;
    m_button = CreateWindowEx(0, L"BUTTON", L"Calculate", WS_CHILD | WS_VISIBLE, 0, 60, 100, 20, m_hwnd, (HMENU)CALC_BUTTON, NULL, NULL);

    if (m_hwnd == NULL)
    {
        return;
    }

    ShowWindow(m_hwnd, SW_SHOW);
    
    return;
}

// Execute procedures based on the recieved messages
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == CALC_BUTTON) {
            myInput::parseInput(*editBox, *startX, *endX, *result);
        }
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_QUIT:
        DestroyWindow(0);
        return 0;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        // ps.rcPaint is the update region
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
        return 0;
    case WM_LBUTTONDOWN:
    {
        std::cout << "Left Mouse Down!\n" << "X : " << LOWORD(lParam) << "\nY : " << HIWORD(lParam) << "\n";
    }
    return 0;
    }
    

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Process messages of the window
bool Window::processMessages() {
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg); // Calls WindProc
        return true;
    }
    return false;
}

