#define _X86_
#include <ntddk.h>

#pragma comment(lib, "ntdll.lib")

VOID OnDriverUnload(IN PDRIVER_OBJECT   pDriverObject);
 
NTSTATUS DriverEntry(IN PDRIVER_OBJECT  pDriverObject,
                     IN PUNICODE_STRING pusRegistryPath)
{
    DbgPrint("Nasci! =) \n");
    pDriverObject->DriverUnload = OnDriverUnload;
    return STATUS_SUCCESS;
}
 
VOID OnDriverUnload(IN PDRIVER_OBJECT   pDriverObject)
{
    DbgPrint("Morri! =( \n");
}
