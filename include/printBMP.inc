    proc openFile
        push bp
        mov bp, sp
        mov dx, [bp + 4]
        xor ax, ax
        mov ah, 3Dh
        int 21h
        mov [fileHandle], ax
        pop bp
        ret 2
    endp openFile

    proc readHeaderBMP
        xor ax, ax
        mov ah, 3Fh
        mov bx, [fileHandle]
        mov cx, 54
        lea dx, [BMPHeader]
        int 21h
        ret
    endp readHeaderBMP

    proc readPaletteBMP
        mov ah, 3Fh
        mov cx, 400h
        lea dx, [BMPPalette]
        int 21h
        ret
    endp readPaletteBMP

    proc copyPalleteVRAM
        lea si, [BMPPalette]
        mov cx, 256
        mov dx, 3C8h
        xor al, al
        out dx, al
        inc dx
        copyPalleteVRAM_convert:
            mov al, [si + 2]
            shr al, 2
            out dx, al
            mov al, [si + 1]
            shr al, 2
            out dx, al
            mov al, [si]
            shr al, 2
            out dx, al
            add si, 4
        loop copyPalleteVRAM_convert
        ret
    endp copyPalleteVRAM

    proc showBMP
        push cx
        mov ax, 0A000h
        mov es, ax
        mov cx, [BMPHeight]
        mov ax, [BMPWidth] 
        xor dx, dx
        mov si, 4
        div si
        mov bp, dx
        mov dx, [BMPX]
        showBMP_nextLine:
            push cx
            push dx   
            mov di, cx  
            add di, [BMPY]
            mov cx, di
            shl cx, 6
            shl di, 8
            add di, cx
            add di, dx
            mov ah, 3fh
            mov cx, [BMPWidth]  
            add cx, bp  
            mov dx, offset BMPMaxLine
            int 21h
            cld
            mov cx, [BMPWidth]  
            mov si, offset BMPMaxLine

            rep movsb
            pop dx
            pop cx
        loop showBMP_nextLine
        pop cx
        ret
    endp showBMP

    proc showBMPTransparent
        push cx
        mov ax, 0A000h
        mov es, ax
        mov cx, [BMPHeight]
        mov ax, [BMPWidth] 
        xor dx, dx
        mov si, 4
        div si
        mov bp, dx
        mov dx, [BMPX]
        showBMPTransparent_nextLine:
            push cx
            push dx
            mov di, cx  
            add di, [BMPY]
            mov cx, di
            shl cx, 6
            shl di, 8
            add di, cx
            add di, dx
            mov ah, 3fh
            mov cx, [BMPWidth]  
            add cx, bp  
            mov dx, offset BMPMaxLine
            int 21h
            mov cx, [BMPWidth]  
            mov si, offset BMPMaxLine
            showBMPTransparent_nextLine_movsbLoop:
                push cx
                mov cl, [ds:si]
                cmp cl, 58h
                je showBMPTransparent_nextLine_movsbLoop_skipPixel
                    mov [es:di], cl
                showBMPTransparent_nextLine_movsbLoop_skipPixel:
                inc si
                inc di
                pop cx
            loop showBMPTransparent_nextLine_movsbLoop
            pop dx
            pop cx
        loop showBMPTransparent_nextLine
        pop cx
        ret
    endp showBMPTransparent

    proc closeFile
        mov ah, 3Eh
        int 21h
        ret
    endp closeFile

    proc createBMP
        call readHeaderBMP
        call readPaletteBMP
        call copyPalleteVRAM
        push bp
        call showBMP
        pop bp
        call closeFile
        ret
    endp createBMP

    proc createBMPTransparent
        call readHeaderBMP
        call readPaletteBMP
        call copyPalleteVRAM
        push bp
        call showBMPTransparent
        pop bp
        call closeFile
        ret
    endp createBMPTransparent

    proc printMenu
        mov [BMPX],0
        mov [BMPY],0
        mov [BMPHeight], 200
        mov [BMPWidth], 320
        push offset menu
        call openFile
        call createBMP
        ret
    endp printMenu

    proc printClearFrame
        push offset LogoClear
        call openFile
        call createBMP
        ret
    endp printClearFrame

    proc BGLogo 
        mov [BMPX],72
        mov [BMPY],20
        mov [BMPHeight], 42
        mov [BMPWidth], 176
        push offset LogoClear
        call openFile
        call createBMP
        ret
    endp BGLogo

    proc blurRebind
        mov [BMPX],0
        mov [BMPY],0
        mov [BMPHeight], 200
        mov [BMPWidth], 320
        mov bx, offset rebindBlur1
        mov cx, 3
        xor si, si
        blurRebind_animation:
            push cx
            mov si, bx
            push bx
            push si
            call openFile
            call createBMP
            push 0FFFFh
            push 0
            call delay
            pop bx  
            add bx, 25
            pop cx
        loop blurRebind_animation
        ret
    endp blurRebind

    proc printExit
        mov [BMPX],0
        mov [BMPY],0
        mov [BMPHeight], 200
        mov [BMPWidth], 320
        mov bx, offset menuBlur1
        mov cx, 3
        xor si, si
        printExit_animation:
            push cx
            mov si, bx
            push bx
            push si
            call openFile
            call createBMP
            push 0FFFFh
            push 0
            call delay
            pop bx  
            add bx, 25
            pop cx
        loop printExit_animation
        call printMsg
        ret
    endp printExit

    proc intro
        mov [BMPX],0
        mov [BMPY],0
        mov [BMPHeight], 200
        mov [BMPWidth], 320
        mov bx, offset menuBlur3
        mov cx, 3
        xor si, si
        intro_animation:
            push cx
            mov si, bx
            push bx
            push si
            call openFile
            call createBMP
            push 0FFFFh
            push 0
            call delay
            pop bx  
            sub bx, 25
            pop cx
        loop intro_animation
        ret
    endp intro

    proc printMsg
        mov [BMPX],80
        mov [BMPY],80
        mov [BMPHeight], 40
        mov [BMPWidth], 160
        push offset exitMSG
        call openFile
        call createBMP
        ret
    endp printMsg

    proc printRebind
        mov [BMPX],0
        mov [BMPY],0
        mov [BMPHeight], 200
        mov [BMPWidth], 320
        push offset rebindKeysWP
        call openFile
        call createBMP
        ret
    endp printRebind

    proc scanScreen
        push bp
        mov bp, sp
        push [bp + 4]
        call openFileWrite
        mov [fileHandle], ax
        mov dx, [BMPX]
        mov di, [BMPY]
        mov cx, [BMPHeight]
        add di, cx
        scanScreen_toBuffer:
            push cx
            mov si, offset graphicBuffer
            mov cx, [BMPWidth]
            scanScreen_toBuffer_line:
                push cx
                mov bh, 0
                mov cx, dx
                push dx
                mov dx, di
                mov ah, 0Dh
                int 10h
                mov [si], al
                inc si
                pop dx
                inc dx
                pop cx
            loop scanScreen_toBuffer_line
            mov ah, 40h
            mov cx, [BMPWidth]
            mov dx, offset graphicBuffer
            mov bx, [fileHandle]
            int 21h
            pop cx
            mov dx, [BMPX]
            dec di
        loop scanScreen_toBuffer
        call closeFile
        pop bp
        ret 2
    endp scanScreen

    proc openFileWrite
        push bp
        mov bp, sp
        mov dx, [bp + 4]
        mov al, 1
        mov ah, 3Dh
        int 21h
        mov [fileHandle], ax
        pop bp
        ret 2
    endp openFileWrite

    proc bufferToScreen
        push bp
        mov bp, sp
        push [bp + 4]
        call openFile
        mov [fileHandle], ax
        mov bx, [fileHandle]
        call showBMP
        call closeFile
        pop bp
        ret 2
    endp bufferToScreen

    proc deleteFile
        push bp
        mov bp, sp
        mov dx, [bp + 4]
        xor cx, cx
        mov ah, 41h
        int 21h
        pop bp
        ret 2
    endp deleteFile

    proc createFile
        push bp
        mov bp, sp
        mov dx, [bp + 4]
        xor cx, cx
        mov ah, 3Ch
        int 21h
        pop bp
        ret 2
    endp createFile

    proc exitPrintSelect
        push offset exitSelect
        call openFile
        call createBMPTransparent
        ret
    endp exitPrintSelect

    proc arrowPrint
        push offset buffer
        call scanScreen
        push offset rebindArrow
        call openFile
        call createBMPTransparent
        ret
    endp arrowPrint

    proc charframePrint
        push si
        push offset buffer
        call scanScreen
        push offset charachterFrame
        call openFile
        call createBMPTransparent
        pop si
        ret
    endp charframePrint

    proc scanMenu
        mov [BMPHeight], 28
        mov [BMPWidth], 80
        push offset buffer2
        call scanScreen
        push offset menuSelect
        call openFile
        call createBMPTransparent
        ret
    endp scanMenu

    proc saveCoordinates
        mov dx, [BMPHeight]
        mov [BMPHeightBuffer], dx
        mov dx, [BMPWidth]
        mov [BMPWidthBuffer], dx
        mov dx, [BMPX]
        mov [BMPXBuffer], dx
        mov dx, [BMPY]
        mov [BMPYBuffer], dx
        ret
    endp saveCoordinates

    proc loadCoordinates
        mov dx, [BMPHeightBuffer]
        mov [BMPHeight], dx
        mov dx, [BMPWidthBuffer]
        mov [BMPWidth], dx
        mov dx, [BMPXBuffer]
        mov [BMPX], dx
        mov dx, [BMPYBuffer]
        mov [BMPY], dx
        ret
    endp loadCoordinates

    proc player_printPlayer
        push bp
        mov bp, sp

        mov [BMPHeight], 176
        mov [BMPWidth], 76
        mov [BMPY], 12

        cmp [bp + 6], offset player1Char
        jne player_printPlayer_background_2
            mov [BMPX], 0
            jmp player_printPlayer_background_1
        player_printPlayer_background_2:
            mov [BMPX], 246
        player_printPlayer_background_1:

        call print_right_bg

        cmp byte ptr [bp + 4], 1
            je player_printPlayer_1
        cmp byte ptr [bp + 4], 2
            je player_printPlayer_2
        cmp byte ptr [bp + 4], 3
            je player_printPlayer_3
        cmp byte ptr [bp + 4], 4
            je player_printPlayer_4
        player_printPlayer_1:
            push offset selectedChar1
            call openFile
            call createBMPTransparent
        jmp player_printPlayer_end
        player_printPlayer_2:
            push offset selectedChar2
            call openFile
            call createBMPTransparent
        jmp player_printPlayer_end
        player_printPlayer_3:
            push offset selectedChar3
            call openFile
            call createBMPTransparent
        jmp player_printPlayer_end
        player_printPlayer_4:
            push offset selectedChar4
            call openFile
            call createBMPTransparent
        jmp player_printPlayer_end


        player_printPlayer_end:
        pop bp
        ret 4
    endp player_printPlayer

    proc player_printPlayer_selected
        push bp
        mov bp, sp

        mov [BMPHeight], 176
        mov [BMPWidth], 76
        mov [BMPY], 12

        cmp [playerCharP], offset player1Char
        jne player_printPlayer_selected_background_2
            mov [BMPX], 0
            jmp player_printPlayer_selected_background_1
        player_printPlayer_selected_background_2:
            mov [BMPX], 246
        player_printPlayer_selected_background_1:

        mov dx, [bp + 4]

        cmp dx, 01h
            je player_printPlayer_selected_1
        cmp dx, 2
            je player_printPlayer_selected_2_bridge
        cmp dx, 3
            je player_printPlayer_selected_3_bridge
        cmp dx, 4
            je player_printPlayer_selected_4_bridge

        player_printPlayer_selected_2_bridge:
        jmp player_printPlayer_selected_2

        player_printPlayer_selected_3_bridge:
        jmp player_printPlayer_selected_3_bridge_2

        player_printPlayer_selected_1:
            call print_right_bg
            push offset selectedChar1w
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar1wb
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar1w
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar1
            call openFile
            call player_sel
        jmp player_printPlayer_selected_end

        player_printPlayer_selected_3_bridge_2:
        jmp player_printPlayer_selected_3

        player_printPlayer_selected_4_bridge:
        jmp player_printPlayer_selected_4_bridge_2

        player_printPlayer_selected_2:
            call print_right_bg
            push offset selectedChar2w
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar2wb
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar2w
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar2
            call openFile
            call player_sel
        jmp player_printPlayer_selected_end

        player_printPlayer_selected_4_bridge_2:
        jmp player_printPlayer_selected_4

        player_printPlayer_selected_3:
            call print_right_bg
            push offset selectedChar3w
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar3wb
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar3w
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar3
            call openFile
            call player_sel
        jmp player_printPlayer_selected_end
        player_printPlayer_selected_4:
            call print_right_bg
            push offset selectedChar4w
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar4wb
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar4w
            call openFile
            call player_sel
            call print_right_bg
            push offset selectedChar4
            call openFile
            call player_sel
        jmp player_printPlayer_selected_end


        player_printPlayer_selected_end:


        pop bp
        ret 2
    endp player_printPlayer_selected

    proc player_sel
        call createBMPTransparent
        push 0FFFFh
        push 1
        call delay
        ret 
    endp player_sel

    proc print_right_bg
        cmp [playerCharP], offset player1Char
        je print_right_bg_left
            push offset leftBackground
            call openFile
            call createBMPTransparent
            jmp print_right_bg_end
        print_right_bg_left:
        push offset rightBackground
        call openFile
        call createBMP
        print_right_bg_end:
        ret
    endp print_right_bg

    proc buffer2Print
        push offset buffer2
        call scanScreen
        push offset mapFrame
        call openFile
        call createBMPTransparent
        ret
    endp buffer2Print

    proc showBMPAnimated
        push cx
        mov ax, 0A000h
        mov es, ax
        mov cx, [BMPHeight]
        mov ax, [BMPWidth] 
        xor dx, dx
        mov si, 4
        div si
        mov bp, dx
        mov dx, [BMPX]
        showBMPAnimated_nextLine:
            push cx
            push dx   
            mov di, cx  
            add di, [BMPY]
            mov cx, di
            shl cx, 6
            shl di, 8
            add di, cx
            add di, dx
            mov ah, 3fh
            mov cx, [BMPWidth]  
            add cx, bp  
            mov dx, offset BMPMaxLine
            int 21h
            cld
            mov cx, [BMPWidth]  
            mov si, offset BMPMaxLine
            rep movsb
            pop dx
            pop cx
            push ax
            push cx
            push dx
            push 0CFFh
            push 0
            call delay
            pop dx
            pop cx
            pop ax
        loop showBMPAnimated_nextLine
        pop cx
        ret
    endp showBMPAnimated

    proc createBMPAnimated
        call readHeaderBMP
        call readPaletteBMP
        call copyPalleteVRAM
        push bp
        call showBMPAnimated
        pop bp
        call closeFile
        ret
    endp createBMPAnimated

    proc delay
        push bp
        mov bp, sp
        xor ax, ax
        mov ah, 86h
        mov cx, [bp + 4]
        mov dx, [bp + 6]
        int 15h
        pop bp
        ret 4
    endp delay

    proc animatedLogo

        inc [LogoCounterNext]
        cmp [LogoCounterNext], 50
        jne animatedLogo_exit_bridge
        mov [LogoCounterNext], 0

        mov [BMPX],72
        mov [BMPY],20
        mov [BMPHeight], 42
        mov [BMPWidth], 176
        add [LogoCounter], 1
        cmp [LogoCounter], 16383
        je animatedLogo_frameOne
        cmp [LogoCounter], 32766
        je animatedLogo_frameTwo
        cmp [LogoCounter], 49149
        je animatedLogo_frameThree
        cmp [LogoCounter], 65532
        je animatedLogo_frameTwo
        jne animatedLogo_exit

        animatedLogo_frameOne:
            call BGLogo
            push offset LogoFrame1
            call openFile
            call createBMPTransparent
        jmp animatedLogo_exit

        animatedLogo_exit_bridge:
        jmp animatedLogo_exit

        animatedLogo_frameTwo:
            call BGLogo
            push offset LogoFrame2
            call openFile
            call createBMPTransparent
            cmp [LogoCounter], 65532
            je animatedLogo_reset
        jmp animatedLogo_exit

        animatedLogo_reset:
            mov [LogoCounter], RESET
        jmp animatedLogo_exit

        animatedLogo_frameThree:
            call BGLogo
            push offset LogoFrame3
            call openFile
            call createBMPTransparent
        jmp animatedLogo_exit

        animatedLogo_exit:
        ret
    endp animatedLogo

    proc fadeFullScreen
        push bp
        mov bp, sp
        mov ah, [bp + 4]
        mov dx, [bp + 6]
        mov [color],ah
        mov [duration],dx
        xor si,si
        mov [drawY], 0
        fadeFullScreen_Vertical:
            mov cx,320
            mov [drawX], 0
            fadeFullScreen_Horizontal:
                push cx
                xor bx, bx
                mov cx, [drawX]
                mov dx, [drawY]
                mov al, [color]
                mov ah, 0ch
                int 10h
                lea bx, drawX
                inc word ptr [bx]
                pop cx
            loop fadeFullScreen_Horizontal
            lea bx, drawY
            inc word ptr [bx]
            inc si
        cmp si, 200
        je fadeFullScreen_finishScreen
        jne fadeFullScreen_Vertical
        fadeFullScreen_finishScreen:
        xor cx, cx
        xor ax, ax
        mov ah, 86h
        mov dx, [duration]
        int 15h
        pop bp
        ret 4
    endp fadeFullScreen

    proc transitionScreen
        xor si,si
        mov [drawY], 200
        transitionScreen_Vertical:
            mov cx,320
            mov [drawX], 0
            transitionScreen_Horizontal:
                push cx
                xor bx, bx
                mov cx, [drawX]
                mov dx, [drawY]
                mov al, 1Fh
                mov ah, 0ch
                int 10h
                lea bx, drawX
                inc word ptr [bx]
                pop cx
            loop transitionScreen_Horizontal
            push ax
            push cx
            push dx
            push 0CFFh
            push 0
            call delay
            pop dx
            pop cx
            pop ax
            lea bx, drawY
            dec word ptr [bx]
            inc si
        cmp si, 200
        je transitionScreen_finishScreen
        jne transitionScreen_Vertical
        transitionScreen_finishScreen:
        ret 
    endp transitionScreen

    proc blurCharSel
        mov [BMPX],0
        mov [BMPY],0
        mov [BMPHeight], 200
        mov [BMPWidth], 320
        mov bx, offset mapBlur1
        mov cx, 3
        xor si, si
        blurCharSel_animation:
            push cx
            mov si, bx
            push bx
            push si
            call openFile
            call createBMP
            push 0FFFFh
            push 0
            call delay
            pop bx  
            add bx, 25
            pop cx
        loop blurCharSel_animation
        ret
    endp blurCharSel