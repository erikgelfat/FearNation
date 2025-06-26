call openSpeaker

mov al, n_e3_low
out 42h, al
mov al, n_e3
out 42h, al
push note_1_8_dx
push note_1_8_cx
call delayAudio

call closeSpeaker