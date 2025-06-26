    proc printButtons
        mov ax, 33
        mov dx, 86
        mov bx, offset player1left
        mov [BMPHeight], 16
        mov [BMPWidth], 16
        mov cx, 12
        printButtons_checkVars:
            mov di, offset keyArray
            mov si, offset img_grave
            push cx
            mov [BMPY], ax
            mov [BMPX], dx
            push ax
            push dx
            printButtons_checkVars_img:
                mov dh, [di]
                cmp [bx], dh
                jne printButtons_checkVars_img_key
                    push bx
                    push di
                    mov cx, si
                    push cx
                    push si
                    call openFile
                    call createBMPTransparent
                    pop cx
                    mov si, cx
                    pop di
                    pop bx
                printButtons_checkVars_img_key:
                inc di
                add si, 27
                cmp byte ptr [di], RESET
            jne printButtons_checkVars_img
            pop dx
            pop ax
            add ax, 21
            inc bx
            cmp bx, offset player2left
            jne printButtons_checkVars_noTransition
                mov dx, 242
                mov ax, 33
            printButtons_checkVars_noTransition:
            pop cx
        loop printButtons_checkVars
        ret
    endp printButtons
    
    
     proc animatedWait
        inc [dotCounterNext]
        cmp [dotCounterNext], 100
        jne animatedWait_exit_bridge
        mov [dotCounterNext], 0
        mov [BMPX],141
        mov [BMPY],105
        mov [BMPHeight], 6
        mov [BMPWidth], 38
        add [dotCounter], 1
        cmp [dotCounter], 21845 
        je animatedWait_frameOne
        cmp [dotCounter], 43690
        je animatedWait_frameTwo
        cmp [dotCounter], 65535 
        je animatedWait_frameThree
        jne animatedWait_exit
        animatedWait_frameOne:
            push offset waitdot1
            call openFile
            call createBMP
        jmp animatedWait_exit
        animatedWait_exit_bridge:
        jmp animatedWait_exit
        animatedWait_frameTwo:
            push offset waitdot2
            call openFile
            call createBMP
        jmp animatedWait_exit
        animatedWait_reset:
            mov [dotCounter], RESET
        jmp animatedWait_exit
        animatedWait_frameThree:
            push offset waitdot3
            call openFile
            call createBMP
            cmp [dotCounter], 65535
            je animatedWait_reset
        jmp animatedWait_exit
        animatedWait_exit:
        ret
    endp animatedWait
    
    proc setKey
        mov ax, [BMPX]
        mov [BMPXBUFFER], ax
        mov ax, [BMPY]
        mov [BMPYBUFFER], ax
        mov ax, [BMPWIDTH]
        mov [BMPWIDTHBUFFER], ax
        mov ax, [BMPHEIGHT]
        mov [BMPHEIGHTBUFFER], ax
        call blurRebind
        push bp
        mov bp, sp
        mov [BMPX],80
        mov [BMPY],80
        mov [BMPHeight], 40
        mov [BMPWidth], 160
        push offset rebindKeysMSG
        call openFile
        call createBMP
        setKey_key:
            call animatedWait
            xor ax, ax
            mov ah, 1
            int 16h
        jz setKey_key
        mov ah, 0
        int 16h
        mov bx, [bp + 4]
        mov [bx], ah
        
        call printRebind
        call printButtons
        pop bp
        mov ax, [BMPXBUFFER]
        mov [BMPX], ax
        mov ax, [BMPYBUFFER]
        mov [BMPY], ax
        mov ax, [BMPWIDTHBUFFER]
        mov [BMPWIDTH], ax
        mov ax, [BMPHEIGHTBUFFER]
        mov [BMPHEIGHT], ax
        ret 2
    endp setKey ;+ 61 x for the dots