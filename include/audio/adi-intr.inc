call openSpeaker

mov al, n_d4_low
out 42h, al
mov al, n_d4
out 42h, al
push note_1_4_dx
push note_1_4_cx
call delayAudio

mov al, n_g4_low
out 42h, al
mov al, n_g4
out 42h, al
push note_1_4_dx
push note_1_4_cx
call delayAudio

mov al, n_a5_low
out 42h, al
mov al, n_a5
out 42h, al
push note_1_4_dx
push note_1_4_cx
call delayAudio

mov al, n_b5_low
out 42h, al
mov al, n_b5
out 42h, al
push note_1_2_dx
push note_1_2_cx
call delayAudio

mov al, n_ash5_low
out 42h, al
mov al, n_ash5
out 42h, al
push note_1_4_dx
push note_1_4_cx
call delayAudio

mov al, n_b5_low
out 42h, al
mov al, n_b5
out 42h, al
push note_1_2_dx
push note_1_2_cx
call delayAudio

call closeSpeaker