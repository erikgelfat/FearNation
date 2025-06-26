RESET               equ 0
MAX_WIDTH           equ 320
MAX_HEIGHT          equ 200
AMOUNT_OF_COLORS    equ 256
HEADER_SIZE         equ 54
COLOR_SIZE          equ 4
PLAYER_HEALTH       equ 134
GAME_TIME           equ 120
P1_DEFAULT_X        equ 20
P1_DEFAULT_Y        equ 60
P2_DEFAULT_X        equ 220
P2_DEFAULT_Y        equ 60
NUMBER_OF_KEYS      equ 13
SCANCODE_NUM        equ 128

.286
.model small
.stack 200h
.data

    include include\keysscan.inc

    BMPHeader       db HEADER_SIZE dup (RESET)
    BMPPalette      db AMOUNT_OF_COLORS * COLOR_SIZE dup (RESET)
    BMPX            dw ?
    BMPY            dw ?
    BMPWidth        dw ?
    BMPHeight       dw ?
    BMPMaxLine      db MAX_WIDTH dup (RESET)
    graphicBuffer   db MAX_WIDTH dup (RESET)
    
    Buffer          db "appdata\buffer.buf",        RESET
    Buffer2         db "appdata\buffer2.buf",       RESET
    BufferPlayer1   db "appdata\buffer3.buf",       RESET
    BufferPlayer2   db "appdata\buffer4.buf",       RESET
    VRAMBuffer      db "appdata\VRAM.buf",          RESET
    BMPXBuffer      dw ?
    BMPYBuffer      dw ?
    BMPWidthBuffer  dw ?
    BMPHeightBuffer dw ?
    KeysPressed     db NUMBER_OF_KEYS dup (RESET)
    PositiveKey     db RESET

    LogoCounter     dw RESET
    LogoCounterNext dw RESET
    LogoFrame1      db "include\bmp\FN1.bmp",       RESET
    LogoFrame2      db "include\bmp\FN2.bmp",       RESET
    LogoFrame3      db "include\bmp\FN3.bmp",       RESET
    LogoClear       db "include\bmp\LogoCF.bmp",    RESET

    introLogo01     db "include\bmp\01.bmp",        RESET
    introLogo02     db "include\bmp\02.bmp",        RESET
    introLogo03     db "include\bmp\03.bmp",        RESET
    introLogo04     db "include\bmp\04.bmp",        RESET
    introLogo05     db "include\bmp\05.bmp",        RESET
    introLogo06     db "include\bmp\06.bmp",        RESET
    introLogo07     db "include\bmp\07.bmp",        RESET
    introLogo08     db "include\bmp\08.bmp",        RESET
    introLogo09     db "include\bmp\09.bmp",        RESET
    introLogo10     db "include\bmp\10.bmp",        RESET
    introLogo11     db "include\bmp\11.bmp",        RESET
    introLogo12     db "include\bmp\12.bmp",        RESET
    introLogo13     db "include\bmp\13.bmp",        RESET
    introLogo14     db "include\bmp\14.bmp",        RESET

    menu            db "include\bmp\menu.bmp",      RESET
    menuSelect      db "include\bmp\msl.bmp",       RESET
    menuBlur1       db "include\bmp\menublr1.bmp",  RESET
    menuBlur2       db "include\bmp\menublr2.bmp",  RESET
    menuBlur3       db "include\bmp\menublr3.bmp",  RESET
    rebindKeysWP    db "include\bmp\rebind.bmp",    RESET
    exitMSG         db "include\bmp\exitmsg.bmp",   RESET
    exitSelect      db "include\bmp\exit-sel.bmp",  RESET
    rebindArrow     db "include\bmp\arrow.bmp",     RESET

    rebindKeysMSG   db "include\bmp\entrkey.bmp",   RESET
    waitdot1        db "include\bmp\rebdot1.bmp",   RESET
    waitdot2        db "include\bmp\rebdot2.bmp",   RESET
    waitdot3        db "include\bmp\rebdot3.bmp",   RESET
    pressedKey      db ?
    dotCounter      dw RESET
    dotCounterNext  dw RESET
    rebindBlur1     db "include\bmp\rebindb1.bmp",  RESET
    rebindBlur2     db "include\bmp\rebindb2.bmp",  RESET
    rebindBlur3     db "include\bmp\rebindb3.bmp",  RESET

    charachterSel   db "include\bmp\charsel.bmp",   RESET
    charachterFrame db "include\bmp\charfram.bmp",  RESET
    charachterP1    db "include\bmp\1.bmp",         RESET
    charachterP2    db "include\bmp\2.bmp",         RESET
    charachetPFill  db "include\bmp\numfillr.bmp",  RESET
    mapSelect       db "include\bmp\map.bmp",       RESET
    mapFrame        db "include\bmp\mapsel.bmp",    RESET
    rightBackground db "include\bmp\charselr.bmp",  RESET
    leftBackground  db "include\bmp\charsell.bmp",  RESET

    selectedChar1   db "include\bmp\char100.bmp",   RESET
    selectedChar1W  db "include\bmp\char1w0.bmp",   RESET
    selectedChar1WB db "include\bmp\char1wb.bmp",   RESET
    selectedChar2   db "include\bmp\char200.bmp",   RESET
    selectedChar2W  db "include\bmp\char2w0.bmp",   RESET
    selectedChar2WB db "include\bmp\char2wb.bmp",   RESET
    selectedChar3   db "include\bmp\char300.bmp",   RESET
    selectedChar3W  db "include\bmp\char3w0.bmp",   RESET
    selectedChar3WB db "include\bmp\char3wb.bmp",   RESET
    selectedChar4   db "include\bmp\char400.bmp",   RESET
    selectedChar4W  db "include\bmp\char4w0.bmp",   RESET
    selectedChar4WB db "include\bmp\char4wb.bmp",   RESET


    charachter1R1   db "include\bmp\char1p1.bmp",   RESET
    charachter1R2   db "include\bmp\char1p2.bmp",   RESET
    charachter1L1   db "include\bmp\char1p3.bmp",   RESET
    charachter1L2   db "include\bmp\char1p4.bmp",   RESET
    charachter3R1   db "include\bmp\char3p1.bmp",   RESET
    charachter3R2   db "include\bmp\char3p2.bmp",   RESET
    charachter3L1   db "include\bmp\char3p3.bmp",   RESET
    charachter3L2   db "include\bmp\char3p4.bmp",   RESET

    drawX           dw RESET
    drawY           dw RESET
    color           db ?
    duration        dw ?

    gradientColor   dw 0010h

    fileHandle      dw ?
    
    player1left     db KEY_A
    player1right    db KEY_D
    player1crouch   db KEY_S
    player1jump     db KEY_W
    player1punch    db KEY_LEFTSHIFT
    player1kick     db KEY_SPACE
    player2left     db KEY_SEMICOLON
    player2right    db KEY_BACKSLASH
    player2crouch   db KEY_SINGLEQUOTE
    player2jump     db KEY_SQUARERIGHT
    player2punch    db KEY_RIGHTSHIFT
    player2kick     db KEY_DOT

    player1Char     dw RESET
    player2Char     dw RESET
    playerCharP     dw RESET
    mapSelected     dw RESET
    mapBlur1        db "include\bmp\charseb1.bmp",  RESET
    mapBlur2        db "include\bmp\charseb2.bmp",  RESET
    mapBlur3        db "include\bmp\charseb3.bmp",  RESET

    map01           db "include\bmp\arena01.bmp",   RESET
    map02           db "include\bmp\arena02.bmp",   RESET
    map03           db "include\bmp\arena03.bmp",   RESET
    map04           db "include\bmp\arena04.bmp",   RESET
    map05           db "include\bmp\arena05.bmp",   RESET
    map06           db "include\bmp\arena06.bmp",   RESET
    map07           db "include\bmp\arena07.bmp",   RESET
    map08           db "include\bmp\arena08.bmp",   RESET
    map09           db "include\bmp\arena09.bmp",   RESET
    map10           db "include\bmp\arena10.bmp",   RESET

    countdownReg3   db "include\bmp\cd3.bmp",       RESET
    countdownWhi3   db "include\bmp\wd3.bmp",       RESET
    countdownReg2   db "include\bmp\cd2.bmp",       RESET
    countdownWhi2   db "include\bmp\wd2.bmp",       RESET
    countdownReg1   db "include\bmp\cd1.bmp",       RESET
    countdownWhi1   db "include\bmp\wd1.bmp",       RESET
    countdownRegG   db "include\bmp\cdg.bmp",       RESET
    countdownWhiG   db "include\bmp\wdg.bmp",       RESET

    timerNum0       db "include\bmp\sec0.bmp",      RESET
    timerNum1       db "include\bmp\sec1.bmp",      RESET
    timerNum2       db "include\bmp\sec2.bmp",      RESET
    timerNum3       db "include\bmp\sec3.bmp",      RESET
    timerNum4       db "include\bmp\sec4.bmp",      RESET
    timerNum5       db "include\bmp\sec5.bmp",      RESET
    timerNum6       db "include\bmp\sec6.bmp",      RESET
    timerNum7       db "include\bmp\sec7.bmp",      RESET
    timerNum8       db "include\bmp\sec8.bmp",      RESET
    timerNum9       db "include\bmp\sec9.bmp",      RESET

    timerClockSyn   db RESET
    timerSec        dw GAME_TIME
    timerHundreds   dw RESET
    timerDozen      dw RESET
    timerSingular   dw RESET  

    player1round    db RESET
    player2round    db RESET

    roundEmpt       db "include\bmp\rEmpt.bmp",      RESET
    roundFull       db "include\bmp\rFull.bmp",      RESET

    HP              db "include\bmp\HP.bmp",         RESET
    healthBar       db "include\bmp\healthBr.bmp",   RESET
    player1Health   db PLAYER_HEALTH
    player2Health   db PLAYER_HEALTH
    player1Charge   db RESET
    player2Charge   db RESET

    player2PosY     dw P2_DEFAULT_Y
    player2PosX     dw P2_DEFAULT_X
    player2rightFm  db RESET
    player2leftFm   db RESET

    player1PosY     dw P1_DEFAULT_Y
    player1PosX     dw P1_DEFAULT_X
    player1rightFm  db RESET
    player1leftFm   db RESET

    keyPressed      db RESET

    scancodeStatus  db SCANCODE_NUM dup (RESET)



.code

    include include\ISRs.inc
    include include\audio.inc
    include include\printBMP.inc
    include include\setkey.inc
    include include\charMap.inc
    include include\mapsel.inc
    include include\game.inc

    start: xor ax, ax
        mov es, ax
        mov ax,@data
        mov ds,ax

        mov ax, 13h
        int 10h

        push offset Buffer
        call createFile
        push offset Buffer2
        call createFile
        push offset BufferPlayer1
        call createFile
        push offset BufferPlayer2
        call createFile

        xor di, di
        gradientMonochrome:
            push 0FFFFh
            push [gradientColor]
            call fadeFullScreen
            lea bx, gradientColor
            inc byte ptr [bx]
            inc di
            cmp di, 15
            jne gradientMonochrome
            je gradientMonochrome_end
        gradientMonochrome_end:

        mov [BMPX],135
        mov [BMPY],75
        mov [BMPHeight], 50
        mov [BMPWidth], 50

        mov ax, 14
        mov bx, offset introLogo01 
        xor si, si
        introAnimation:
            push ax
            mov si, bx
            push bx
            push si
            call openFile
            call createBMP
            push 0FFFFh
            push 0
            call delay
            pop bx
            add bx, 19
            pop ax
            dec ax
            cmp ax, 0
        jne introAnimation
        include include\audio\adi-intr.inc

       xor di, di
        gradientMonochromeFadeOut:
            push 0FFFFh
            push [gradientColor]
            call fadeFullScreen
            lea bx, gradientColor
            dec byte ptr [bx]
            inc di
            cmp di, 15
            jne gradientMonochromeFadeOut
            je gradientMonochromeFadeOut_end
        gradientMonochromeFadeOut_end:

        call intro

        startMenu:
        call printMenu
        
        include include\mainmenu.inc

        exit_option_bridge:
        jmp exit_option

        rebindKeys_bridge:
        jmp rebindKeys

        exit_bridge_2:
            call printExit
        jmp exit

        exit:
            include include\audio\adi-msel.inc
            mov [BMPX],107
            mov [BMPY],101
            mov [BMPHeight], 15
            mov [BMPWidth], 26
            call exitPrintSelect
            exit_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz exit_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne exit_enterSkip 
                call printMenu
                jmp exit_option_bridge
            exit_enterSkip:
            cmp ah, KEY_D
        jne exit_key
        jmp exit_yes

        exit_bridge:
            call printMsg
        jmp exit

        exit_yes:
            call printMsg
            include include\audio\adi-msel.inc
            mov [BMPX],187
            mov [BMPY],101
            mov [BMPHeight], 15
            mov [BMPWidth], 26
            call exitPrintSelect
            exit_yes_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz exit_yes_key
            mov ah, 0
            int 16h
            cmp ah, KEY_A
            je exit_bridge
            cmp ah, KEY_ENTER
        jne exit_yes_key

        include include\audio\adi-entr.inc
        push offset Buffer2
        call deleteFile
        push offset Buffer
        call deleteFile
        push offset BufferPlayer2
        call deleteFile
        push offset BufferPlayer1
        call deleteFile
        mov ah, 0
        mov al, 2
        int 10h
        mov si, 0
        mov ah, 0
        mov al, ' '
        mov cx, 80*25
        cls: 
            mov es:[si], ax
            add si, 2
        loop cls
        mov ah, 4ch
        int 21h

        include include\rebind.inc
    end start