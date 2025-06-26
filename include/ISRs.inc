proc keyscanISR far
    pusha

    in      al, 60h

    xor     bh, bh
    mov     bl, al
    and     bl, 7Fh
    shr     al, 7
    xor     al, 1
    mov     ds:[scancodeStatus + bx], al
    
    in      al, 61h
    mov     ah, al
    or      al, 80h
    out     61h, al
    mov     al, ah
    out     61h, al

    mov     al, 20h
    out     20h, al

    popa
    iret
endp keyscanISR