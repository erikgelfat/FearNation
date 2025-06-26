proc selectMenu

    
    mov [BMPX],0
    mov [BMPY],0
    mov [BMPHeight], 200
    mov [BMPWidth], 320
    push offset charachterSel
    call openFile
    call createBMP

    mov [BMPX],130
    mov [BMPY],27
    mov [BMPHeight], 8
    mov [BMPWidth], 8
    push offset charachterP1
    call openFile
    call createBMPTransparent

    mov [playerCharP], offset player1Char
    mov cx, 1
    selectMenu_player:
        push cx

        selectMenu_player_char1:
            mov [BMPX],98
            mov [BMPY],41
            mov [BMPHeight], 56
            mov [BMPWidth], 56
            call saveCoordinates
            call charframePrint
            push [playerCharP]
            push 1
            call player_printPlayer
            selectMenu_player_char1_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz selectMenu_player_char1_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne selectMenu_player_char1_skipEnter
                mov si, [playerCharP]
                mov word ptr [si], 01h
                push 01h
                call player_printPlayer_selected
                jmp selectMenu_player_loop_end
            selectMenu_player_char1_skipEnter:
            cmp ah, KEY_ESC
            je selectMenu_player_break_bridge_2
            cmp ah, KEY_D
            je selectMenu_player_char2
            cmp ah, KEY_S
        jne selectMenu_player_char1_key
        jmp selectMenu_player_char4

        selectMenu_player_bridge_5:
        jmp selectMenu_player

        selectMenu_player_char1_bridge:
            call loadCoordinates
            push offset buffer
            call bufferToScreen
        jmp selectMenu_player_char1

        selectMenu_player_bridge_4:
        jmp selectMenu_player_bridge_5

        selectMenu_player_break_bridge_2:
        jmp selectMenu_player_break_bridge

        selectMenu_player_char1_bridge_2:
        jmp selectMenu_player_char1_bridge

        selectMenu_player_char2:
            call loadCoordinates
            push offset buffer
            call bufferToScreen
            mov [BMPX],164
            mov [BMPY],41
            mov [BMPHeight], 56
            mov [BMPWidth], 56
            call saveCoordinates
            call charframePrint
            push [playerCharP]
            push 2
            call player_printPlayer
            selectMenu_player_char2_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz selectMenu_player_char2_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne selectMenu_player_char2_skipEnter
                mov si, [playerCharP]
                mov word ptr [si], 2
                push 2
                call player_printPlayer_selected
                jmp selectMenu_player_loop_end
            selectMenu_player_char2_skipEnter:
            cmp ah, KEY_ESC
            je selectMenu_player_break_bridge
            cmp ah, KEY_A
            je selectMenu_player_char1_bridge_2
            cmp ah, KEY_S
        jne selectMenu_player_char2_key
        jmp selectMenu_player_char3

        selectMenu_player_break_bridge:
        jmp selectMenu_player_break

        selectMenu_player_bridge_3:
        jmp selectMenu_player_bridge_4

        selectMenu_player_char3:
            call loadCoordinates
            push offset buffer
            call bufferToScreen
            mov [BMPX],164
            mov [BMPY],104
            mov [BMPHeight], 56
            mov [BMPWidth], 56
            call saveCoordinates
            call charframePrint
            push [playerCharP]
            push 3
            call player_printPlayer
            selectMenu_player_char3_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz selectMenu_player_char3_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne selectMenu_player_char3_skipEnter
                mov si, [playerCharP]
                mov word ptr [si], 3
                push 3
                call player_printPlayer_selected
                jmp selectMenu_player_loop_end
            selectMenu_player_char3_skipEnter:
            cmp ah, KEY_ESC
            je selectMenu_player_break_bridge_4
            cmp ah, KEY_A
            je selectMenu_player_char4
            cmp ah, KEY_W
        jne selectMenu_player_char3_key
        jmp selectMenu_player_char2

        selectMenu_player_char3_bridge:
        jmp selectMenu_player_char3

        selectMenu_player_bridge_2:
        jmp selectMenu_player_bridge_3

        selectMenu_player_break_bridge_4:
        jmp selectMenu_player_break_bridge_3

        selectMenu_player_char4:
            call loadCoordinates
            push offset buffer
            call bufferToScreen
            mov [BMPX],98
            mov [BMPY],104
            mov [BMPHeight], 56
            mov [BMPWidth], 56
            call saveCoordinates
            call charframePrint
            push [playerCharP]
            push 4
            call player_printPlayer
            selectMenu_player_char4_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz selectMenu_player_char4_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne selectMenu_player_char4_skipEnter
                mov si, [playerCharP]
                mov word ptr [si], 4
                push 4
                call player_printPlayer_selected
                jmp selectMenu_player_loop_end
            selectMenu_player_char4_skipEnter:
            cmp ah, KEY_ESC
            je selectMenu_player_break
            cmp ah, KEY_D
            je selectMenu_player_char3_bridge
            cmp ah, KEY_W
        jne selectMenu_player_char4_key
        jmp selectMenu_player_char1_bridge

    selectMenu_player_break_bridge_3:
    jmp selectMenu_player_break

    selectMenu_player_bridge_1:
    jmp selectMenu_player_bridge_2

    selectMenu_player_loop_end:

    add [playerCharP], 2
    pop cx
    cmp cx, 0
    je selectMenu_player_loop
        dec cx
        push cx
        mov [BMPX],130
        mov [BMPY],27
        mov [BMPHeight], 8
        mov [BMPWidth], 8
        push offset charachetPFill
        call openFile
        call createBMPTransparent
        push offset charachterP2
        call openFile
        call createBMPTransparent
        pop cx
        jmp selectMenu_player_bridge_1
    selectMenu_player_loop:

        call selectMap
        call startGame

    jmp selectMenu_end

    selectMenu_player_break:
        pop cx
    selectMenu_end:
    ret
endp selectMenu
