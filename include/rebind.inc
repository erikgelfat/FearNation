        rebindKeys:
            include include\audio\adi-entr.inc
            call printRebind
            call printButtons
        jmp player1_left

        player1_left:
            include include\audio\adi-msel.inc
            mov [BMPX],66
            mov [BMPY],38
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player1_left_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player1_left_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne player1leftchange_next
            push offset player1left
            call setKey
            jmp player1_left
            player1leftchange_next:
            cmp ah, KEY_S
            je player1_right_bridge
            cmp ah, KEY_D
            je player2_left
            cmp ah, KEY_ESC
        jne player1_left_key
        call printMenu
        jmp bindKeys_option

        player1_right_bridge:
        jmp player1_right_bridge_2

        player1_left_bridge_3:
            push offset buffer
            call bufferToScreen
        jmp player1_left

        player2_left:
            push offset buffer
            call bufferToScreen
            include include\audio\adi-msel.inc
            mov [BMPX],222
            mov [BMPY],38
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player2_left_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player2_left_key
            mov ah, 0
            int 16h
            cmp ah, KEY_A
            je player1_left_bridge_3
            cmp ah, KEY_ENTER
            jne player2leftchange_next
            push offset player2left
            call setKey
            jmp player2_left
            player2leftchange_next:
            cmp ah, KEY_S
            je player2_right
            cmp ah, KEY_ESC
        jne player2_left_key
        call printMenu
        jmp bindKeys_option

        player1_left_bridge_2:
        jmp player1_left_bridge_3

        player1_right_bridge_2:
        jmp player1_right_bridge_3

        player2_left_bridge:
        jmp player2_left

        player2_right:
            push offset buffer
            call bufferToScreen
            include include\audio\adi-msel.inc
            mov [BMPX],222
            mov [BMPY],59
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player2_right_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player2_right_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne player2rightchange_next
            push offset player2right
            call setKey
            jmp player2_right
            player2rightchange_next:
            cmp ah, KEY_S
            je player2_down_bridge_2
            cmp ah, KEY_A
            je player1_right
            cmp ah, KEY_W
            je player2_left_bridge
            cmp ah, KEY_ESC
        jne player2_right_key
        call printMenu
        jmp bindKeys_option

        player1_left_bridge:
        jmp player1_left_bridge_2

        player1_right_bridge_3:
        jmp player1_right

        player2_right_bridge:
        jmp player2_right

        player2_down_bridge_2:
        jmp player2_down_bridge

        player1_right:
            push offset buffer
            call bufferToScreen
            include include\audio\adi-msel.inc
            mov [BMPX],66
            mov [BMPY],59
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player1_right_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player1_right_key
            mov ah, 0
            int 16h
            cmp ah, KEY_D
            je player2_right_bridge
            cmp ah, KEY_W
            je player1_left_bridge
            cmp ah, KEY_ENTER
            jne player1rightchange_next
            push offset player1right
            call setKey
            jmp player1_right
            player1rightchange_next:
            cmp ah, KEY_S
            je player1_down
            cmp ah, KEY_ESC
        jne player1_right_key
        call printMenu
        jmp bindKeys_option

        player2_down_bridge:
        jmp player2_down

        player2_right_bridge_2:
        jmp player2_right_bridge

        player1_right_bridge_4:
        jmp player1_right

        player1_down:
            push offset buffer
            call bufferToScreen
            include include\audio\adi-msel.inc
            mov [BMPX],66
            mov [BMPY],80
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player1_down_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player1_down_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne player1downchange_next
            push offset player1crouch
            call setKey
            jmp player1_down
            player1downchange_next:
            cmp ah, KEY_S
            je player1_jump_bridge
            cmp ah, KEY_D
            je player2_down
            cmp ah, KEY_W
            je player1_right_bridge_4
            cmp ah, KEY_ESC
        jne player1_down_key
        call printMenu
        jmp bindKeys_option

        player2_right_bridge_3:
        jmp player2_right_bridge_2

        player1_down_bridge:
        jmp player1_down

        player1_jump_bridge:
        jmp player1_jump_bridge_2

        player2_down:
            push offset buffer
            call bufferToScreen
            include include\audio\adi-msel.inc
            mov [BMPX],222
            mov [BMPY],80
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player2_down_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player2_down_key
            mov ah, 0
            int 16h
            cmp ah, KEY_A
            je player1_down_bridge
            cmp ah, KEY_W
            je player2_right_bridge_3
            cmp ah, KEY_ENTER
            jne player2downchange_next
            push offset player2crouch
            call setKey
            jmp player2_down
            player2downchange_next:
            cmp ah, KEY_S
            je player2_jump    
            cmp ah, KEY_ESC
        jne player2_down_key
        call printMenu
        jmp bindKeys_option

        player1_down_bridge_2:
        jmp player1_down_bridge

        player2_down_bridge_3:
        jmp player2_down

        player1_jump_bridge_2:
        jmp player1_jump

        player2_jump:
            push offset buffer
            call bufferToScreen
            include include\audio\adi-msel.inc
            mov [BMPX],222
            mov [BMPY],101
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player2_jump_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player2_jump_key
            mov ah, 0
            int 16h
            cmp ah, KEY_W
            je player2_down_bridge_3
            cmp ah, KEY_ENTER
            jne player2jumpchange_next
            push offset player2jump
            call setKey
            jmp player2_jump
            player2jumpchange_next:
            cmp ah, KEY_S
            je player2_punch_bridge
            cmp ah, KEY_A
            je player1_jump 
            cmp ah, KEY_ESC
        jne player2_jump_key
        call printMenu
        jmp bindKeys_option

        player1_down_bridge_3:
        jmp player1_down_bridge_2

        player2_jump_bridge:
        jmp player2_jump

        player2_punch_bridge:
        jmp player2_punch_bridge_2

        player1_jump:
            push offset buffer
            call bufferToScreen
            include include\audio\adi-msel.inc
            mov [BMPX],66
            mov [BMPY],101
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player1_jump_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player1_jump_key
            mov ah, 0
            int 16h
            cmp ah, KEY_D
            je player2_jump_bridge
            cmp ah, KEY_W
            je player1_down_bridge_3
            cmp ah, KEY_ENTER
            jne player1jumpchange_next
            push offset player1jump
            call setKey
            jmp player1_jump
            player1jumpchange_next:
            cmp ah, KEY_S
            je player1_punch
            cmp ah, KEY_ESC
        jne player1_jump_key
        call printMenu
        jmp bindKeys_option

        player2_jump_bridge_3:
        jmp player2_jump_bridge

        player1_jump_bridge_3:
        jmp player1_jump

        player2_punch_bridge_2:
        jmp player2_punch

        player1_punch:
            push offset buffer
            call bufferToScreen
            include include\audio\adi-msel.inc
            mov [BMPX],66
            mov [BMPY],122
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player1_punch_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player1_punch_key
            mov ah, 0
            int 16h
            cmp ah, KEY_W
            je player1_jump_bridge_3
            cmp ah, KEY_ENTER
            jne player1punchchange_next
            push offset player1punch
            call setKey
            jmp player1_punch
            player1punchchange_next:
            cmp ah, KEY_S
            je player1_kick_bridge
            cmp ah, KEY_D
            je player2_punch
            cmp ah, KEY_ESC
        jne player1_punch_key
        call printMenu
        jmp bindKeys_option

        player1_punch_bridge_4:
        jmp player1_punch

        player2_jump_bridge_2:
        jmp player2_jump_bridge_3

        player1_punch_bridge:
        jmp player1_punch

        player1_kick_bridge:
        jmp player1_kick_bridge_2

        player2_punch:
            push offset buffer
            call bufferToScreen
            include include\audio\adi-msel.inc
            mov [BMPX],222
            mov [BMPY],122
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player2_punch_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player2_punch_key
            mov ah, 0
            int 16h
            cmp ah, KEY_A
            je player1_punch_bridge
            cmp ah, KEY_W
            je player2_jump_bridge_2
            cmp ah, KEY_ENTER
            jne player2punchchange_next
            push offset player2punch
            call setKey
            jmp player2_punch
            player2punchchange_next:
            cmp ah, KEY_S
            je player2_kick
            cmp ah, KEY_ESC
        jne player2_punch_key
        call printMenu
        jmp bindKeys_option

        player1_punch_bridge_3:
        jmp player1_punch_bridge_4

        player2_punch_bridge_3:
        jmp player2_punch

        player1_kick_bridge_2:
        jmp player1_kick

        player2_kick:
            push offset buffer
            call bufferToScreen
            include include\audio\adi-msel.inc
            mov [BMPX],222
            mov [BMPY],143
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player2_kick_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player2_kick_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne player2kickchange_next
            push offset player2kick
            call setKey
            jmp player2_kick
            player2kickchange_next:
            cmp ah, KEY_A
            je player1_kick
            cmp ah, KEY_W
            je player2_punch_bridge_3
            cmp ah, KEY_ESC
        jne player2_kick_key
        call printMenu
        jmp bindKeys_option

        player1_punch_bridge_2:
        jmp player1_punch_bridge_3

        player2_kick_bridge:
        jmp player2_kick

        player1_kick:
            push offset buffer
            call bufferToScreen
            include include\audio\adi-msel.inc
            mov [BMPX],66
            mov [BMPY],143
            mov [BMPHeight], 5
            mov [BMPWidth], 12
            call arrowPrint
            player1_kick_key:
                xor ax, ax
                mov ah, 1
                int 16h
            jz player1_kick_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne player1kickchange_next
            push offset player1kick
            call setKey
            jmp player1_kick
            player1kickchange_next:
            cmp ah, KEY_D
            je player2_kick_bridge
            cmp ah, KEY_W
            je player1_punch_bridge_2
            cmp ah, KEY_ESC
        jne player1_kick_key
        call printMenu
        jmp bindKeys_option