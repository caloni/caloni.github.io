// opcodes to run a jump to the function AntiAttachAbort
BYTE jmpToAntiAttachAbort[] =
{ 0xB8, 0xCC, 0xCC, 0xCC, 0xCC,   // mov eax, 0xCCCCCCCC
0xFF, 0xE0 };                     // jmp eax

// á é í ó ú ã õ à
*reinterpret_cast<PVOID*>(&jmpToAntiAttachAbort[1]) = AntiAttachAbort;