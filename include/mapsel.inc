proc selectMap

    call blurCharSel

    mov [BMPX],13
    mov [BMPY],40
    mov [BMPHeight], 120
    mov [BMPWidth], 294
    push offset mapSelect
    call openFile
    call createBMP

    mov [BMPHeight], 28
    mov [BMPWidth], 48

    selectMap_1:
        mov [BMPX], 21
        mov [BMPY], 75
        call buffer2Print
        selectMap_1_key:
            xor ax, ax
            mov ah, 1
            int 16h
        jz selectMap_1_key
        mov ah, 0
        int 16h
        cmp ah, KEY_ENTER
        jne selectMap_1_skipEnter
            mov [mapSelected], 01h
            jmp selectMap_end
        selectMap_1_skipEnter:
        cmp ah, KEY_S
        je selectMap_6
        cmp ah, KEY_D
        jne selectMap_1_key
    jmp selectMap_2

    selectMap_1_bridge:
        push offset buffer2
        call bufferToScreen
    jmp selectMap_1

    selectMap_2:
        push offset buffer2
        call bufferToScreen
        mov [BMPX], 79
        mov [BMPY], 75
        call buffer2Print
        selectMap_2_key:
            xor ax, ax
            mov ah, 1
            int 16h
        jz selectMap_2_key
        mov ah, 0
        int 16h
        cmp ah, KEY_ENTER
        jne selectMap_2_skipEnter
            mov [mapSelected], 02h
            jmp selectMap_end
        selectMap_2_skipEnter:
        cmp ah, KEY_D
        je selectMap_3_bridge_2
        cmp ah, KEY_S
        je selectMap_7
        cmp ah, KEY_A
        jne selectMap_2_key
    jmp selectMap_1_bridge

    selectMap_6:
        push offset buffer2
        call bufferToScreen
        mov [BMPX], 21
        mov [BMPY], 114
        call buffer2Print
        selectMap_6_key:
            xor ax, ax
            mov ah, 1
            int 16h
        jz selectMap_6_key
        mov ah, 0
        int 16h
        cmp ah, KEY_ENTER
        jne selectMap_6_skipEnter
            mov [mapSelected], 06h
            jmp selectMap_end
        selectMap_6_skipEnter:
        cmp ah, KEY_D
        je selectMap_7
        cmp ah, KEY_W
        jne selectMap_6_key
    jmp selectMap_1_bridge

    selectMap_6_bridge:
    jmp selectMap_6

    selectMap_2_bridge:
    jmp selectMap_2

    selectMap_3_bridge_2:
    jmp selectMap_3

    selectMap_7:
        push offset buffer2
        call bufferToScreen
        mov [BMPX], 79
        mov [BMPY], 114
        call buffer2Print
        selectMap_7_key:
            xor ax, ax
            mov ah, 1
            int 16h
        jz selectMap_7_key
        mov ah, 0
        int 16h
        cmp ah, KEY_ENTER
        jne selectMap_7_skipEnter
            mov [mapSelected], 07h
            jmp selectMap_end
        selectMap_7_skipEnter:
        cmp ah, KEY_D
        je selectMap_8_bridge
        cmp ah, KEY_A
        je selectMap_6_bridge
        cmp ah, KEY_W
        jne selectMap_7_key
    jmp selectMap_2

    selectMap_2_bridge_2:
    jmp selectMap_2_bridge

    selectMap_3:
        push offset buffer2
        call bufferToScreen
        mov [BMPX], 137
        mov [BMPY], 75
        call buffer2Print
        selectMap_3_key:
            xor ax, ax
            mov ah, 1
            int 16h
        jz selectMap_3_key
        mov ah, 0
        int 16h
        cmp ah, KEY_ENTER
        jne selectMap_3_skipEnter
            mov [mapSelected], 03h
            jmp selectMap_end
        selectMap_3_skipEnter:
        cmp ah, KEY_D
        je selectMap_4
        cmp ah, KEY_A
        je selectMap_2_bridge_2
        cmp ah, KEY_S
        jne selectMap_3_key
    jmp selectMap_8

    selectMap_3_bridge:
    jmp selectMap_3

    selectMap_8_bridge:
    jmp selectMap_8

    selectMap_4:
        push offset buffer2
        call bufferToScreen
        mov [BMPX], 195
        mov [BMPY], 75
        call buffer2Print
        selectMap_4_key:
            xor ax, ax
            mov ah, 1
            int 16h
        jz selectMap_4_key
        mov ah, 0
        int 16h
        cmp ah, KEY_ENTER
        jne selectMap_4_skipEnter
            mov [mapSelected], 04h
            jmp selectMap_end
        selectMap_4_skipEnter:
        cmp ah, KEY_D
        je selectMap_5_bridge
        cmp ah, KEY_A
        je selectMap_3_bridge
        cmp ah, KEY_S
        jne selectMap_4_key
    jmp selectMap_9

    selectMap_3_bridge_3:
    jmp selectMap_3_bridge

    selectMap_8:
        push offset buffer2
        call bufferToScreen
        mov [BMPX], 137
        mov [BMPY], 114
        call buffer2Print
        selectMap_8_key:
            xor ax, ax
            mov ah, 1
            int 16h
        jz selectMap_8_key
        mov ah, 0
        int 16h
        cmp ah, KEY_ENTER
        jne selectMap_8_skipEnter
            mov [mapSelected], 08h
            jmp selectMap_end
        selectMap_8_skipEnter:
        cmp ah, KEY_D
        je selectMap_9
        cmp ah, KEY_W
        je selectMap_3_bridge_3
        cmp ah, KEY_A
        jne selectMap_8_key
    jmp selectMap_7

    selectMap_8_bridge_2:
    jmp selectMap_8

    selectMap_4_bridge:
    jmp selectMap_4

    selectMap_5_bridge:
    jmp selectMap_5

    selectMap_9:
        push offset buffer2
        call bufferToScreen
        mov [BMPX], 195
        mov [BMPY], 114
        call buffer2Print
        selectMap_9_key:
            xor ax, ax
            mov ah, 1
            int 16h
        jz selectMap_9_key
        mov ah, 0
        int 16h
        cmp ah, KEY_ENTER
        jne selectMap_9_skipEnter
            mov [mapSelected], 09h
            jmp selectMap_end
        selectMap_9_skipEnter:
        cmp ah, KEY_D
        je selectMap_10
        cmp ah, KEY_A
        je selectMap_8_bridge_2
        cmp ah, KEY_W
        jne selectMap_9_key
    jmp selectMap_4

    selectMap_4_bridge_2:
    jmp selectMap_4_bridge

    selectMap_9_bridge:
    jmp selectMap_9

    selectMap_5:
        push offset buffer2
        call bufferToScreen
        mov [BMPX], 253
        mov [BMPY], 75
        call buffer2Print
        selectMap_5_key:
            xor ax, ax
            mov ah, 1
            int 16h
        jz selectMap_5_key
        mov ah, 0
        int 16h
        cmp ah, KEY_ENTER
        jne selectMap_5_skipEnter
            mov [mapSelected], 05h
            jmp selectMap_end
        selectMap_5_skipEnter:
        cmp ah, KEY_A
        je selectMap_4_bridge_2
        cmp ah, KEY_S
        jne selectMap_5_key
    jmp selectMap_10

    selectMap_10:
        push offset buffer2
        call bufferToScreen
        mov [BMPX], 253
        mov [BMPY], 114
        call buffer2Print
        selectMap_10_key:
            xor ax, ax
            mov ah, 1
            int 16h
        jz selectMap_10_key
        mov ah, 0
        int 16h
        cmp ah, KEY_ENTER
        jne selectMap_10_skipEnter
            mov [mapSelected], 0Ah
            jmp selectMap_end
        selectMap_10_skipEnter:
        cmp ah, KEY_A
        je selectMap_9_bridge
        cmp ah, KEY_W
        jne selectMap_10_key
    jmp selectMap_5

    
    selectMap_end:
    ret
endp selectMap