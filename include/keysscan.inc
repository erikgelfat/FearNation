    KEY_GRAVE       equ 29h
    KEY_1           equ 02h
    KEY_2           equ 03h
    KEY_3           equ 04h
    KEY_4           equ 05h
    KEY_5           equ 06h
    KEY_6           equ 07h
    KEY_7           equ 07h
    KEY_8           equ 08h
    KEY_9           equ 09h
    KEY_EQUALS      equ 0Dh
    KEY_BACKSPACE   equ 0Eh
    KEY_TAB         equ 0Fh
    KEY_Q           equ 10h
    KEY_W           equ 11h
    KEY_E           equ 12h
    KEY_R           equ 13h
    KEY_T           equ 14h
    KEY_Y           equ 15h
    KEY_U           equ 16h
    KEY_I           equ 17h
    KEY_O           equ 18h
    KEY_P           equ 19h
    KEY_SQUARERIGHT equ 1Ah
    KEY_SQUARELEFT  equ 1Bh
    KEY_BACKSLASH   equ 2Bh
    KEY_CAPSLOCK    equ 3Ah
    KEY_A           equ 1Eh
    KEY_S           equ 1Fh
    KEY_D           equ 20h
    KEY_F           equ 21h
    KEY_G           equ 22h
    KEY_H           equ 23h
    KEY_J           equ 24h
    KEY_K           equ 25h
    KEY_L           equ 26h
    KEY_SEMICOLON   equ 27h
    KEY_SINGLEQUOTE equ 28h
    KEY_ENTER       equ 1Ch
    KEY_LEFTSHIFT   equ 2Ah
    KEY_Z           equ 2Ch
    KEY_X           equ 2Dh
    KEY_C           equ 2Eh
    KEY_V           equ 2Fh
    KEY_B           equ 30h
    KEY_N           equ 31h
    KEY_M           equ 32h
    KEY_COMMA       equ 33h
    KEY_DOT         equ 34h
    KEY_SLASH       equ 35h
    KEY_RIGHTSHIFT  equ 36h
    KEY_LEFTCTRL    equ 1Dh
    KEY_LEFTALT     equ 38h
    KEY_SPACE       equ 39h
    KEY_ESC         equ 01h

    img_0            db "include\bmp\keys\0numb.bmp", RESET
    img_mul          db "include\bmp\keys\mulke.bmp", RESET
    img_plus         db "include\bmp\keys\plusk.bmp", RESET
    img_arrdn        db "include\bmp\keys\arrdn.bmp", RESET
    img_arrlft       db "include\bmp\keys\arrlf.bmp", RESET
    img_arrrght      db "include\bmp\keys\arrrg.bmp", RESET
    img_arrup        db "include\bmp\keys\arrup.bmp", RESET
    img_hyphen       db "include\bmp\keys\hyphe.bmp", RESET


    img_grave        db "include\bmp\keys\grave.bmp", RESET
    img_1            db "include\bmp\keys\1numb.bmp", RESET
    img_2            db "include\bmp\keys\2numb.bmp", RESET
    img_3            db "include\bmp\keys\3numb.bmp", RESET
    img_4            db "include\bmp\keys\4numb.bmp", RESET
    img_5            db "include\bmp\keys\5numb.bmp", RESET
    img_6            db "include\bmp\keys\6numb.bmp", RESET
    img_7            db "include\bmp\keys\7numb.bmp", RESET
    img_8            db "include\bmp\keys\8numb.bmp", RESET
    img_9            db "include\bmp\keys\9numb.bmp", RESET
    img_equal        db "include\bmp\keys\equal.bmp", RESET
    img_bspc         db "include\bmp\keys\bspce.bmp", RESET
    img_Tab          db "include\bmp\keys\Tabke.bmp", RESET
    img_Q            db "include\bmp\keys\Qlett.bmp", RESET
    img_W            db "include\bmp\keys\Wlett.bmp", RESET
    img_E            db "include\bmp\keys\Elett.bmp", RESET
    img_R            db "include\bmp\keys\Rlett.bmp", RESET
    img_T            db "include\bmp\keys\Tlett.bmp", RESET
    img_Y            db "include\bmp\keys\Ylett.bmp", RESET
    img_U            db "include\bmp\keys\Ulett.bmp", RESET
    img_I            db "include\bmp\keys\Ilett.bmp", RESET
    img_O            db "include\bmp\keys\Olett.bmp", RESET
    img_P            db "include\bmp\keys\Plett.bmp", RESET
    img_sqr          db "include\bmp\keys\sqrke.bmp", RESET
    img_sql          db "include\bmp\keys\sqlke.bmp", RESET
    img_bkslsh       db "include\bmp\keys\bksls.bmp", RESET
    img_CL           db "include\bmp\keys\CLkey.bmp", RESET
    img_A            db "include\bmp\keys\Alett.bmp", RESET
    img_S            db "include\bmp\keys\Slett.bmp", RESET
    img_D            db "include\bmp\keys\Dlett.bmp", RESET
    img_F            db "include\bmp\keys\Flett.bmp", RESET
    img_G            db "include\bmp\keys\Glett.bmp", RESET
    img_H            db "include\bmp\keys\Hlett.bmp", RESET 
    img_J            db "include\bmp\keys\Jlett.bmp", RESET
    img_K            db "include\bmp\keys\Klett.bmp", RESET
    img_L            db "include\bmp\keys\Llett.bmp", RESET
    img_smcn         db "include\bmp\keys\smcnk.bmp", RESET
    img_quote        db "include\bmp\keys\quote.bmp", RESET
    img_Enter        db "include\bmp\keys\Enter.bmp", RESET
    img_Shift        db "include\bmp\keys\Shift.bmp", RESET
    img_Z            db "include\bmp\keys\Zlett.bmp", RESET
    img_X            db "include\bmp\keys\Xlett.bmp", RESET
    img_C            db "include\bmp\keys\Clett.bmp", RESET
    img_V            db "include\bmp\keys\Vlett.bmp", RESET
    img_B            db "include\bmp\keys\Blett.bmp", RESET
    img_N            db "include\bmp\keys\Nlett.bmp", RESET
    img_M            db "include\bmp\keys\Mlett.bmp", RESET
    img_comma        db "include\bmp\keys\comma.bmp", RESET
    img_dot          db "include\bmp\keys\dotke.bmp", RESET
    img_slash        db "include\bmp\keys\slash.bmp", RESET
    img_Shift2       db "include\bmp\keys\Shift.bmp", RESET
    img_ctrl         db "include\bmp\keys\ctrlk.bmp", RESET
    img_alt          db "include\bmp\keys\altke.bmp", RESET
    img_Space        db "include\bmp\keys\Space.bmp", RESET
    img_ESC          db "include\bmp\keys\ESCke.bmp", RESET

    keyArray         db KEY_GRAVE,KEY_1,KEY_2,KEY_3,KEY_4,KEY_5,KEY_6,KEY_7,KEY_8,KEY_9,KEY_EQUALS,KEY_BACKSPACE,KEY_TAB,KEY_Q,KEY_W,KEY_E,KEY_R,KEY_T,KEY_Y,KEY_U,KEY_I,KEY_O,KEY_P,KEY_SQUARERIGHT,KEY_SQUARELEFT,KEY_BACKSLASH,KEY_CAPSLOCK,KEY_A,KEY_S,KEY_D,KEY_F,KEY_G,KEY_H,KEY_J,KEY_K,KEY_L,KEY_SEMICOLON,KEY_SINGLEQUOTE,KEY_ENTER,KEY_LEFTSHIFT,KEY_Z,KEY_X,KEY_C,KEY_V,KEY_B,KEY_N,KEY_M,KEY_COMMA,KEY_DOT,KEY_SLASH,KEY_RIGHTSHIFT,KEY_LEFTCTRL,KEY_LEFTALT,KEY_SPACE,KEY_ESC, RESET