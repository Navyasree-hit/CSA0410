

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

DWORD get_parent_pid(DWORD pid) {
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) {
        return 0; 
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(snap, &pe)) {
        CloseHandle(snap);
        return 0;
    }

    do {
        if (pe.th32ProcessID == pid) {
            DWORD ppid = pe.th32ParentProcessID;
            CloseHandle(snap);
            return ppid;
        }
    } while (Process32Next(snap, &pe));

    CloseHandle(snap);
    return 0; 
}

int main(void) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    DWORD parentPid = GetCurrentProcessId();
    printf("Current (this) Process ID: %lu\n", (unsigned long)parentPid);

    DWORD parentOfThis = get_parent_pid(parentPid);
    if (parentOfThis != 0)
        printf("Parent PID of current process: %lu\n", (unsigned long)parentOfThis);
    else
        printf("Could not determine parent PID of current process.\n");

    
    char cmd[] = "notepad.exe";
    if (!CreateProcess(
            NULL,       
            cmd,        
            NULL,       
            NULL,       
            FALSE,      
            0,         
            NULL,       
            NULL,      
            &si,        
            &pi        
        )) 
    {
        DWORD err = GetLastError();
        printf("CreateProcess failed. Error: %lu\n", (unsigned long)err);
        return 1;
    }

    printf("Child process created successfully.\n");
    printf("Child Process ID (from CreateProcess): %lu\n", (unsigned long)pi.dwProcessId);

  
    DWORD parentOfChild = get_parent_pid(pi.dwProcessId);
    if (parentOfChild != 0)
        printf("Parent PID of child process (from snapshot): %lu\n", (unsigned long)parentOfChild);
    else
        printf("Could not determine parent PID of child process.\n");

    
    
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

