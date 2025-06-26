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

    startGame_player_char1:
        startGame_player_char1_key:
            call timerUpdate
            xor ax, ax
            in al, 64h
            cmp al, 10b
        je startGame_player_char1_key
        in al, 60h
        mov bx, offset KeysPressed
        cmp al, [player1left]
        jne startGame_player_char1_skipP1L
            mov byte ptr [bx], 1
        startGame_player_char1_skipP1L:
        cmp al, [player1right]
        jne startGame_player_char1_skipP1R
            inc bx
            mov byte ptr [bx], 1
        startGame_player_char1_skipP1R:
        cmp al, [player1crouch]
        jne startGame_player_char1_skipP1C
            add bx, 2
            mov byte ptr [bx], 1
        startGame_player_char1_skipP1C:
        cmp al, [player1jump]
        jne startGame_player_char1_skipP1J
            add bx, 3
            mov byte ptr [bx], 1
        startGame_player_char1_skipP1J:
        cmp al, [player1punch]
        jne startGame_player_char1_skipP1P
            add bx, 4
            mov byte ptr [bx], 1
        startGame_player_char1_skipP1P:
        cmp al, [player1kick]
        jne startGame_player_char1_skipP1K
            add bx, 5
            mov byte ptr [bx], 1
        startGame_player_char1_skipP1K:
        cmp al, [player2left]
        jne startGame_player_char1_skipP2L
            add bx, 6
            mov byte ptr [bx], 1
        startGame_player_char1_skipP2L:
        cmp al, [player2right]
        jne startGame_player_char1_skipP2R
            add bx, 7
            mov byte ptr [bx], 1
        startGame_player_char1_skipP2R:
        cmp al, [player2crouch]
        jne startGame_player_char1_skipP2C
            add bx, 8
            mov byte ptr [bx], 1
        startGame_player_char1_skipP2C:
        cmp al, [player2jump]
        jne startGame_player_char1_skipP2J
            add bx, 9
            mov byte ptr [bx], 1
        startGame_player_char1_skipP2J:
        cmp al, [player2punch]
        jne startGame_player_char1_skipP2P
            add bx, 10
            mov byte ptr [bx], 1
        startGame_player_char1_skipP2P:
        cmp al, [player2kick]
        jne startGame_player_char1_skipP2K
            add bx, 11
            mov byte ptr [bx], 1
        startGame_player_char1_skipP2K:
        mov bx, offset KeysPressed
        mov dl, [player1left]
        add dl, 80h
        cmp al, dl
        jne startGame_player_char1_skipP1LZ
            mov byte ptr [bx], 0
        startGame_player_char1_skipP1LZ:
        mov dl, [player1right]
        add dl, 80h
        cmp al, dl 
        jne startGame_player_char1_skipP1RZ
            inc bx
            mov byte ptr [bx], 0
        startGame_player_char1_skipP1RZ:
        mov dl, [player1crouch]
        add dl, 80h
        cmp al, dl 
        jne startGame_player_char1_skipP1CZ
            add bx, 2
            mov byte ptr [bx], 0
        startGame_player_char1_skipP1CZ:
        mov dl,  [player1jump]
        add dl, 80h
        cmp al, dl
        jne startGame_player_char1_skipP1JZ
            add bx, 3
            mov byte ptr [bx], 0
        startGame_player_char1_skipP1JZ:
        mov dl, [player1punch]
        add dl, 80h
        cmp al, dl 
        jne startGame_player_char1_skipP1PZ
            add bx, 4
            mov byte ptr [bx], 0
        startGame_player_char1_skipP1PZ:
        mov dl, [player1kick]
        add dl, 80h
        cmp al, dl 
        jne startGame_player_char1_skipP1KZ
            add bx, 5
            mov byte ptr [bx], 0
        startGame_player_char1_skipP1KZ:
        mov dl, [player2left]
        add dl, 80h
        cmp al, dl 
        jne startGame_player_char1_skipP2LZ
            add bx, 6
            mov byte ptr [bx], 0
        startGame_player_char1_skipP2LZ:
        mov dl, [player2right]
        add dl, 80h
        cmp al, dl 
        jne startGame_player_char1_skipP2RZ
            add bx, 7
            mov byte ptr [bx], 0
        startGame_player_char1_skipP2RZ:
        mov dl, [player2crouch]
        add dl, 80h
        cmp al, dl 
        jne startGame_player_char1_skipP2CZ
            add bx, 8
            mov byte ptr [bx], 0
        startGame_player_char1_skipP2CZ:
        mov dl, [player2jump]
        add dl, 80h
        cmp al, dl 
        jne startGame_player_char1_skipP2JZ
            add bx, 9
            mov byte ptr [bx], 0
        startGame_player_char1_skipP2JZ:
        mov dl,[player2punch]
        add dl, 80h
        cmp al, dl 
        jne startGame_player_char1_skipP2PZ
            add bx, 10
            mov byte ptr [bx], 0
        startGame_player_char1_skipP2PZ:
        mov dl, [player2kick]
        add dl, 80h
        cmp al, dl 
        jne startGame_player_char1_skipP2KZ
            add bx, 11
            mov byte ptr [bx], 0
        startGame_player_char1_skipP2KZ:


        mov bx, offset KeysPressed

        cmp byte ptr [bx], 1
        jne startGame_checkKeys_skipP1L
            call player1leftProc
        startGame_checkKeys_skipP1L:
        inc bx
        cmp byte ptr [bx], 1
        jne startGame_checkKeys_skipP1R
            call player1rightProc
        startGame_checkKeys_skipP1R:
        add bx, 5
        cmp byte ptr [bx], 1
        jne startGame_checkKeys_skipP2L
            call player2leftProc
        startGame_checkKeys_skipP2L:
        inc bx
        cmp byte ptr [bx], 1
        jne startGame_checkKeys_skipP2R
            call player2rightProc
        startGame_checkKeys_skipP2R:
        inc bx

        jmp startGame_player_char1_key

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
            mov bx, offset charachter3R1
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
            mov bx, offset charachter3R1
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

proc keyCheck
    push bx
    mov bx, offset KeysPressed
    mov cx, 12
    keyCheck_CheckIfPos:
        cmp [bx], 0001b
        je keyCheck_CheckIfPos_no
            mov [PositiveKey], 1
        keyCheck_CheckIfPos_no:
        inc bx
    loop keyCheck_CheckIfPos
    cmp [PositiveKey], 1
    jne keyCheck_delaySkip
        push 1
        push 0
        call delay
    keyCheck_delaySkip:
    keyCheck_key:
        xor ax, ax
        mov ah, 1
        int 16h
    jz keyCheck_key
    mov ah, 0
    int 16h
    pop bx
    ret
endp keyCheck