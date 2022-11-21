	.data
CURRENT_NOTE:
	.byte 0x00
	
.text
	.extern buzzer_set_period
	.extern swap_leds
	.global play_song_1
	.global play_song_2
	.global play_song_3
	.global play_song_4
play_song_1:
	
NOTES:
	;; B4
	.word 0x0000
	.word 0x4049
	
	.word 0x0000
	.word 0x4049
	;; A4
	.word 0x0000
	.word 0x4545

	.word 0x0000
	.word 0x4545
	;; F4
	.word 0x0000
	.word 0x5726

	.word 0x0000
	.word 0x5726
	;; B4
	.word 0x0000
	.word 0x4049
	
	.word 0x0000
	.word 0x4049
	;; A4
	.word 0x0000
	.word 0x4545

	.word 0x0000
	.word 0x4545
	;; F4
	.word 0x0000
	.word 0x5726

	.word 0x0000
	.word 0x5726
	;; B4
	.word 0x0000
	.word 0x4049
	
	.word 0x0000
	.word 0x4049
	;; A4
	.word 0x0000
	.word 0x4545

	.word 0x0000
	.word 0x4545
	;; E4
	.word 0x0000
	.word 0x6067
	;; D4
	.word 0x0000
	.word 0x6810
	;; E4
	.word 0x0000
	.word 0x6067

	.word 0x0000
	.word 0x6067

	.word 0x0000
	.word 0x6067

	.word 0x0000
	.word 0x6067
	
	.word 0x0000
	.word 0x6067

	.word 0x0000
	.word 0x6067
	;; 0

	.word 0x0000
	.word 0x0000

N:
	.word 0X0000
	.word 0X0025
S:
	.word 0x0000
	.word 0x0001
	
IF1:
	cmp current_note,n
	jc ELSE1
	CALL #buzzer_set_period
	;; got to make sure what to do in this part
	jmp DONE
IF2:
	cmp 
	jnz ELSE2
	CALL #swap_leds
	
	jmp DONE
ELSE2:
	CALL #swap_leds
	sub #1,s
	jmp DONE
ELSE1:
	mov.b #0,current_note
	jmp DONE
	
DONE:
	ret
