// TestAsm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    char s[] = "ABC";
    //for (int i = 0; char c = s[i]; i++) {
    //    if (c >= 'a' && c <= 'z') s[i] = c - 32;
    //}

    __asm {
        xor     esi, esi // i = 0
        FOR_1:
        mov     al, s[esi] // c = s[i]
        test    al, al      // c != 0
        jz      END_FOR
        cmp     al, 'A'
        jb      NEXT
        cmp     al, 'Z'
        ja      NEXT
        add     al, 32
        mov     s[esi], al
            NEXT:
        inc     esi // i++
        jmp     FOR_1
    END_FOR:
    }
    std::cout << s;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
