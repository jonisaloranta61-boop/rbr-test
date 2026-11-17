#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE h, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        HANDLE f = CreateFileA("C:\\rbr_test.txt", GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0);
        if (f != INVALID_HANDLE_VALUE) {
            DWORD w;
            WriteFile(f, "loaded", 6, &w, 0);
            CloseHandle(f);
        }
    }
    return TRUE;
}
