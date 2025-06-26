n_e3        equ 1Ch
n_e3_low    equ 47h
n_a3        equ 15h
n_a3_low    equ 2Fh
n_d4        equ 0Fh
n_d4_low    equ 0DFh
n_g4        equ 0Bh
n_g4_low    equ 0E4h
n_a5        equ 0Ah
n_a5_low    equ 98h
n_ash5      equ 0Ah
n_ash5_low  equ 0
n_b5        equ 09h
n_b5_low    equ 70h

note_1_2_cx equ 4
note_1_2_dx equ 8480h
note_1_4_cx equ 2
note_1_4_dx equ 4240h
note_1_8_cx equ 1
note_1_8_dx equ 2120h

proc openSpeaker
    in al, 61h
    or al, 03h
    out 61h, al
    ret
endp openSpeaker

proc closeSpeaker
    in al, 61h
    and al, 0FCh
    out 61h, al
    ret
endp closeSpeaker

proc delayAudio
    push bp
    mov bp, sp
    xor cx, cx
    xor ax, ax
    mov ah, 86h
    mov cx, [bp + 4]
    mov dx, [bp + 6]
    int 15h
    pop bp
    ret 4
endp delayAudio