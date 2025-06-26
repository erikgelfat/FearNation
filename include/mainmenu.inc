singleplayer_option:
            include include\audio\adi-msel.inc
            mov [BMPX],120
            mov [BMPY],67
            call scanMenu
            call saveCoordinates
            singleplayer_option_key:
                call animatedLogo
                xor ax, ax
                mov ah, 1
                int 16h
            jz singleplayer_option_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne singleplayer_option_skipEnter
                call selectMenu
                jmp startMenu
            singleplayer_option_skipEnter:
            cmp ah, KEY_S
        jne singleplayer_option_key
        jmp multiplayer_option

        singleplayer_option_bridge:
            call loadCoordinates
            push offset buffer2
            call bufferToScreen
        jmp singleplayer_option

        multiplayer_option:
            include include\audio\adi-msel.inc
            call loadCoordinates
            push offset buffer2
            call bufferToScreen
            mov [BMPX],120
            mov [BMPY],96
            call scanMenu
            call saveCoordinates
            multiplayer_option_key:
                call animatedLogo
                xor ax, ax
                mov ah, 1
                int 16h
            jz multiplayer_option_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            jne multiplayer_option_skipEnter
                call selectMenu
                jmp startMenu
            multiplayer_option_skipEnter:
            cmp ah, KEY_S
            je bindKeys_option
            cmp ah, KEY_W
        jne multiplayer_option_key
        jmp singleplayer_option_bridge

        bindKeys_option:
            include include\audio\adi-msel.inc
            call loadCoordinates
            push offset buffer2
            call bufferToScreen
            mov [BMPX],120
            mov [BMPY],126
            call scanMenu
            call saveCoordinates
            bindKeys_option_key:
                call animatedLogo
                xor ax, ax
                mov ah, 1
                int 16h
            jz bindKeys_option_key
            mov ah, 0
            int 16h
            cmp ah, KEY_S
            je exit_option
            cmp ah, KEY_ENTER
            je rebindKeys_bridge_1
            cmp ah, KEY_W
        jne bindKeys_option_key
        jmp multiplayer_option

        rebindKeys_bridge_1:
        jmp rebindKeys_bridge

        exit_option:
            include include\audio\adi-msel.inc
            call loadCoordinates
            push offset buffer2
            call bufferToScreen
            mov [BMPX],120
            mov [BMPY],156
            call scanMenu
            call saveCoordinates
            exit_option_key:
                call animatedLogo
                xor ax, ax
                mov ah, 1
                int 16h
            jz exit_option_key
            mov ah, 0
            int 16h
            cmp ah, KEY_ENTER
            je exit_bridge_2
            cmp ah, KEY_W
        jne exit_option_key
        jmp bindKeys_option