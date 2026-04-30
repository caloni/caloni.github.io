#include windows.h
#include stdio.h

void main(void)
{
    LPWSTR pMessage = L%1!.s! %4 %5!s!;
    DWORD_PTR pArgs[] = { (DWORD_PTR)4, (DWORD_PTR)2, (DWORD_PTR)LBill,   %1!.s! refers back to the first insertion string in pMessage
         (DWORD_PTR)LBob,                                                 %4 refers back to the second insertion string in pMessage
         (DWORD_PTR)6, (DWORD_PTR)LBill };                                %5!s! refers back to the third insertion string in pMessage
    const DWORD size = 100+1;
    WCHAR buffer[size];


    if (!FormatMessage(FORMAT_MESSAGE_FROM_STRING  FORMAT_MESSAGE_ARGUMENT_ARRAY,
                       pMessage, 
                       0,
                       0,
                       buffer, 
                       size, 
                       (va_list)pArgs))
    {
        wprintf(LFormat message failed with 0x%xn, GetLastError());
        return;
    }

     Buffer contains   Bi Bob   Bill.
    wprintf(LFormatted message %sn, buffer);
}
