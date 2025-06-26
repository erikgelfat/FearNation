proc startGame
    mov [player1PosX], P1_DEFAULT_X
    mov [player1PosY], P1_DEFAULT_Y
    mov [player2PosX], P2_DEFAULT_X
    mov [player2PosY], P2_DEFAULT_Y
    mov [timerSec], 120
    call transitionScreen
    mov [BMPX], 0
    mov [BMPY], 0
    mov [BMPWidth], 320
    mov [BMPHeight], 200
    mov dx, offset map01
    mov cx, [mapSelected]
    dec cx
    startGame_loop:
        add dx, 24
    loop startGame_loop
    push dx
    call openFile
    call createBMPAnimated
    mov [BMPHeight], 8
    mov [BMPWidth], 24
    mov [BMPX], 148
    mov [BMPY], 16
    push offset buffer2
    call scanScreen
    call roundPrint
    call printHealthBars
    call updateHealth
    call scanPlayer1
    push 0
    push 0
    push 1
    call printPlayer
    call scanPlayer2
    push 2
    push 0
    push 2
    call printPlayer
    call countdown
    xor ax, ax
    mov es, ax
    cli
    push word ptr es:[9*4+2]
    push word ptr es:[9*4]
    mov word ptr es:[9*4], offset keyscanISR
    mov es:[9*4+2],cs
    sti

    startGame_player_char1:
        startGame_player_char1_key:
            call timerUpdate
            mov bl, [player1left]
            cbw
            mov al, [scancodeStatus + bx]
            or al, al
            jz startGame_checkKeys_skipP1L
                call player1leftProc
            startGame_checkKeys_skipP1L:
            mov bl, [player1right]
            cbw
            mov al, [scancodeStatus + bx]
            or al, al
            jz startGame_checkKeys_skipP1R
                call player1rightProc
            startGame_checkKeys_skipP1R:
            mov bl, [player2left]
            cbw
            mov al, [scancodeStatus + bx]
            or al, al
            jz startGame_checkKeys_skipP2L
                call player2leftProc
            startGame_checkKeys_skipP2L:
            mov bl, [player2right]
            cbw
            mov al, [scancodeStatus + bx]
            or al, al
            jz startGame_checkKeys_skipP2R
                call player2rightProc
            startGame_checkKeys_skipP2R:
            mov al, [scancodeStatus + KEY_ESC]
            or al, al
            jz startGame_checkKeys_skipExit
                jmp startGame_exit
            startGame_checkKeys_skipExit:
        jmp startGame_player_char1_key

    startGame_exit:
        xor ax, ax
        mov es, ax
        cli
        pop word ptr es:[9*4]
        pop word ptr es:[9*4+2]
        sti
        mov di, offset scancodeStatus
        mov cx, SCANCODE_NUM
        startGame_exit_clearBuffer:
            mov byte ptr [di], RESET
            inc di
        loop startGame_exit_clearBuffer
    ret
endp startGame

proc player1rightProc

    inc [player1rightFm]
    mov al, [player1rightFm]
    cmp al, 5
    jle player1right_frameOne
    jg player1right_frameTwo

    player1right_frameOne:

        push 0
        push 2
        push 1
        call printPlayer
        jmp player1right_end

    player1right_frameTwo:
        cmp al, 10
        jne player1right_frameTwo_skipReset
            mov [player1rightFm], 0
        player1right_frameTwo_skipReset:
        push 1
        push 2
        push 1
        call printPlayer

    player1right_end:
    ret
endp player1rightProc

proc player1leftProc

    inc [player1leftFm]
    mov al, [player1leftFm]
    cmp al, 5
    jle player1left_frameOne
    jg player1left_frameTwo

    player1left_frameOne:

        push 2
        push 4
        push 1
        call printPlayer
        jmp player1left_end

    player1left_frameTwo:
        cmp al, 10
        jne player1left_frameTwo_skipReset
            mov [player1leftFm], 0
        player1left_frameTwo_skipReset:
        push 3
        push 4
        push 1
        call printPlayer

    player1left_end:
    ret
endp player1leftProc

proc player2rightProc

    inc [player2rightFm]
    mov al, [player2rightFm]
    cmp al, 5
    jle player2right_frameOne
    jg player2right_frameTwo

    player2right_frameOne:

        push 0
        push 2
        push 2
        call printPlayer
        jmp player2right_end

    player2right_frameTwo:
        cmp al, 10
        jne player2right_frameTwo_skipReset
            mov [player2rightFm], 0
        player2right_frameTwo_skipReset:
        push 1
        push 2
        push 2
        call printPlayer

    player2right_end:
    ret
endp player2rightProc

proc player2leftProc

    inc [player2leftFm]
    mov al, [player2leftFm]
    cmp al, 5
    jle player2left_frameOne
    jg player2left_frameTwo

    player2left_frameOne:

        push 2
        push 4
        push 2
        call printPlayer
        jmp player2left_end

    player2left_frameTwo:
        cmp al, 10
        jne player2left_frameTwo_skipReset
            mov [player2leftFm], 0
        player2left_frameTwo_skipReset:
        push 3
        push 4
        push 2
        call printPlayer

    player2left_end:
    ret
endp player2leftProc

proc printPlayer
    push bp
    mov bp, sp
    mov [BMPHeight], 120
    mov [BMPWidth], 80
    
    mov ax, [bp + 4]
    mov bx, [bp + 6]
    cmp ax, 1
    je printPlayer_player1_bridge

        mov ax, [player2PosX]
        mov [BMPX], ax
        mov ax, [player2PosY]
        mov [BMPY], ax

        push bx
        push offset bufferPlayer2
        call bufferToScreen
        pop bx

        cmp bx, 1
        je printPlayer_player2_YP
        cmp bx, 2
        je printPlayer_player2_XP
        cmp bx, 3
        je printPlayer_player2_YN
        cmp bx, 4
        je printPlayer_player2_XN

        printPlayer_player2_YP:
            inc [player2PosY]
        jmp printPlayer_player2_print

        printPlayer_player2_XP:
            cmp [player2PosX], 240
            je printPlayer_player2_XP_skip
                add [player2PosX], 1
            printPlayer_player2_XP_skip:
        jmp printPlayer_player2_print

        printPlayer_player2_YN:
            dec [player2PosY]
        jmp printPlayer_player2_print

        printPlayer_player1_bridge:
        jmp printPlayer_player1

        printPlayer_player2_XN:
            cmp [player2PosX], 0
            je printPlayer_player2_XN_skip
                sub [player2PosX], 1
            printPlayer_player2_XN_skip:
        jmp printPlayer_player2_print

        printPlayer_player2_print:
            mov ax, [player2PosX]
            mov [BMPX], ax
            mov ax, [player2PosY]
            mov [BMPY], ax
            push offset bufferPlayer2
            call scanScreen
            push [player2Char]
            call returnCharFrame
            mov cx, [bp + 8]
            printPlayer_player2_print_frame:
                add bx, 24
            loop printPlayer_player2_print_frame
            push bx
            call openFile
            call createBMPTransparent
            jmp printPlayer_end

    printPlayer_player1:
        mov ax, [player1PosX]
        mov [BMPX], ax
        mov ax, [player1PosY]
        mov [BMPY], ax

        push bx
        push offset bufferPlayer1
        call bufferToScreen
        pop bx

        cmp bx, 1
        je printPlayer_player1_YP
        cmp bx, 2
        je printPlayer_player1_XP
        cmp bx, 3
        je printPlayer_player1_YN
        cmp bx, 4
        je printPlayer_player1_XN

        printPlayer_player1_YP:
            inc [player1PosY]
        jmp printPlayer_player1_print

        printPlayer_player1_XP:
            cmp [player1PosX], 240
            je printPlayer_player1_XP_skip
                add [player1PosX], 1
            printPlayer_player1_XP_skip:
        jmp printPlayer_player1_print

        printPlayer_player1_YN:
            dec [player1PosY]
        jmp printPlayer_player1_print

        printPlayer_player1_XN:
            cmp [player1PosX], 0
            je printPlayer_player1_XN_skip
                sub [player1PosX], 1
            printPlayer_player1_XN_skip:
        jmp printPlayer_player1_print

        printPlayer_player1_print:
            mov ax, [player1PosX]
            mov [BMPX], ax
            mov ax, [player1PosY]
            mov [BMPY], ax
            push offset bufferPlayer1
            call scanScreen
            push [player1Char]
            call returnCharFrame
            mov cx, [bp + 8]
            printPlayer_player1_print_frame:
                add bx, 24
            loop printPlayer_player1_print_frame
            push bx
            call openFile
            call createBMPTransparent

    printPlayer_end:
    pop bp
    ret 6
endp printPlayer

proc scanPlayer1
    mov ax, [player1PosX]
    mov [BMPX], ax
    mov ax, [player1PosY]
    mov [BMPY], ax
    mov [BMPHeight], 120
    mov [BMPWidth], 80
    push offset bufferPlayer1
    call scanScreen
    ret
endp scanPlayer1

proc scanPlayer2
    mov ax, [player2PosX]
    mov [BMPX], ax
    mov ax, [player2PosY]
    mov [BMPY], ax
    mov [BMPHeight], 120
    mov [BMPWidth], 80
    push offset bufferPlayer2
    call scanScreen
    ret
endp scanPlayer2

proc countdown

    mov [BMPX], 108
    mov [BMPY], 48
    mov [BMPWidth], 104
    mov [BMPHeight], 104
    push offset buffer
    call scanScreen
    mov bx, offset countdownReg3
    mov cx, 4
    countdown_loop:
        push cx
        mov dx, bx
        push bx
        push dx
        call openFile
        call createBMPTransparent 
        push 0FFFFh
        push 10
        call delay
        pop bx
        add bx, 20
        push bx
        mov dx, bx
        push dx
        call openFile
        call createBMPTransparent
        push 0FFFFh
        push 1
        call delay
        push offset buffer
        call bufferToScreen
        pop bx
        add bx, 20
        pop cx
    loop countdown_loop

    ret
endp countdown

proc timerUpdate
    push ax
    push bx
    push cx
    mov ah, 2Ch
    int 21h
    cmp dh, [timerClockSyn]
    je timerUpdate_jump
        mov [timerClockSyn], dh
        dec [timerSec]
        mov [BMPHeight], 8
        mov [BMPWidth], 24
        mov [BMPX], 148
        mov [BMPY], 16
        push offset buffer2
        call bufferToScreen
        call convertTimer
        call printTimer
    timerUpdate_jump:
    pop cx
    pop bx
    pop ax
    ret
endp timerUpdate

proc printTimer
    mov [BMPHeight], 8
    mov [BMPWidth], 8
    mov [BMPX], 150
    mov [BMPY], 16
    mov bx, offset timerHundreds
    mov cx, 3
    printTimer_loop:
        mov si, offset timerNum0
        push cx
        mov cx, [bx]
        printTimer_loop_number:
            add si, 21
        loop printTimer_loop_number
        push bx
        push si
        call openFile
        call createBMPTransparent
        pop bx
        pop cx
        add bx, 2
        add [BMPX], 8
    loop printTimer_loop
    ret
endp printTimer

proc convertTimer
    xor dx, dx
    mov ax, [timerSec]
    mov bx, 100
    div bx
    mov [timerHundreds], ax
    xor dx, dx
    mov ax, [timerSec]
    mov bx, 10
    div bx
    xor dx, dx
    mov bx, 10
    div bx
    mov [timerDozen], dx
    mov ax, [timerSec]
    xor dx, dx
    mov bx, 10
    div bx
    mov [timerSingular], dx
    ret
endp convertTimer

proc roundPrint
    mov [BMPHeight], 16
    mov [BMPWidth], 16
    mov [BMPX], 110
    mov [BMPY], 30
    mov si, offset player1round
    mov cx, 2
    roundPrint_loop:
        mov bx, offset roundEmpt
        push cx
        push si
        mov dl, [si]
        cmp dl, 1
        jl roundPrint_loop_p1oo
        je roundPrint_loop_p1xo
            add bx, 22
        jmp roundPrint_loop_p1oo
        roundPrint_loop_p1oo:
            push bx
            push bx
            call openFile
            call createBMPTransparent
            pop bx
            add [BMPX], 24
            push bx
            call openFile
            call createBMPTransparent
        jmp roundPrint_loop_finish
        roundPrint_loop_p1xo:
            add bx, 22
            push bx
            push bx
            call openFile
            call createBMPTransparent
            pop bx
            add [BMPX], 24
            sub bx, 22
            push bx
            call openFile
            call createBMPTransparent
        roundPrint_loop_finish:
        pop si
        inc si
        add [BMPX], 39
        pop cx
    loop roundPrint_loop

    ret
endp roundPrint

proc printHealthBars
    mov [BMPHeight], 16
    mov [BMPWidth], 136
    mov [BMPX], 12
    mov [BMPY], 12
    mov cx, 2
    printHealthBars_loop:
        push cx
        push offset healthBar
        call openFile
        call createBMP
        mov [BMPX], 175
        pop cx
    loop printHealthBars_loop
    ret
endp printHealthBars

proc updateHealth

    mov [BMPHeight], 16
    mov [BMPWidth], 8
    mov [BMPX], 6
    mov [BMPY], 12
    xor ch, ch
    mov cl, [player1Health]
    updateHealth_player1Print:
        push cx
        push offset HP
        call openFile
        call createBMPTransparent
        inc [BMPX]
        pop cx
    loop updateHealth_player1Print

    mov [BMPX], 302

    mov cl, [player2Health]
    updateHealth_player2Print:
        push cx
        push offset HP
        call openFile
        call createBMPTransparent
        dec [BMPX]
        pop cx
    loop updateHealth_player2Print

    ret
endp updateHealth

proc returnCharFrame
    push bp
    mov bp, sp
    push ax

    mov ax, [bp + 4]
    cmp ax, 1
    jne returnCharFrame_skipChar1
        mov bx, offset charachter1R1
        jmp returnCharFrame_exit
    returnCharFrame_skipChar1:
    cmp ax, 2
    jne returnCharFrame_skipChar2
        mov bx, offset charachter1R1
        jmp returnCharFrame_exit
    returnCharFrame_skipChar2:
    cmp ax, 3
    jne returnCharFrame_skipChar3
        mov bx, offset charachter3R1
        jmp returnCharFrame_exit
    returnCharFrame_skipChar3:
    cmp ax, 4
    jne returnCharFrame_skipChar4
        mov bx, offset charachter3R1
        jmp returnCharFrame_exit
    returnCharFrame_skipChar4:

    returnCharFrame_exit:
    pop ax
    pop bp
    ret 2
endp returnCharFrame