org 0h


RS	Equ P1.3
EN	Equ P1.2

main:
	clr RS  ; Instr_LCD
	call FuncS	; Modo de 4 bits - LCD - usar Call
	call DispC	; Liga display e Cursor
	call EntryM	; Shift Right 
next:	
	call ScanKey	; Varre tecla
	setb RS	;
	clr A	;
	mov A, R7	;
	call SendC 	;
	;call WaitRelease
	;call ESPSOL
	;call WaitRelease
	cjne R7, #'#', Next

fim: jmp $


WaitReleaseCheckRow:
	jnb P0.4, WaitReleaseCheckRow
	jnb P0.5, WaitReleaseCheckRow
	jnb P0.6, WaitReleaseCheckRow
	ret
	
WaitRelease:
	clr P0.3
	call WaitReleaseCheckRow
	setb P0.3

	clr P0.2
	call WaitReleaseCheckRow
	setb P0.2

	clr P0.1
	call WaitReleaseCheckRow
	setb P0.1
	
	clr P0.0
	call WaitReleaseCheckRow
	setb P0.0
	
	ret

FuncS:
	; Modo de 4 bits - LCD
	clr P1.7
	clr P1.6
	setb P1.5
	clr P1.4
	
	call Clk
	call Delay
	call Clk

	setb P1.7
	clr P1.6
	clr P1.5
	clr P1.4

	; LCD de 2 linhas
	call Clk
	call Delay

	ret

DispC:

	; (DAT = 00h)
	clr P1.7
	clr P1.6
	clr P1.5
	clr P1.4

	call Clk
	
	; Liga LCD e cursor (DAT = 0fh)
	setb P1.7
	setb P1.6
	setb P1.5
	setb P1.4
	
	call Clk
	call Delay

	ret

EntryM:
	
	; (DAT = 00h)
	clr P1.7
	clr P1.6
	clr P1.5
	clr P1.4
	
	call Clk		
	
	clr P1.7
	setb P1.6
	setb P1.5
	clr P1.4
	
	call Clk
	call Delay

	ret

Clk:
	setb EN
	clr EN
	
	ret

SendC:
	mov C, Acc.7
	mov P1.7, C
	mov C, Acc.6
	mov P1.6, C
	mov C, Acc.5
	mov P1.5, C
	mov C, Acc.4
	mov P1.4, C
	
	call Clk

	mov C, Acc.3
	mov P1.7, C
	mov C, Acc.2
	mov P1.6, C
	mov C, Acc.1
	mov P1.5, C
	mov C, Acc.0
	mov P1.4, C
	call Clk
	call Delay

	ret

Delay:
	mov R0, 50
	djnz R0, $
	
	ret

ScanKey:
	clr P0.3
	call lcode0	; Varre coluna
	setb P0.3
	jb F0, Done
	
	clr P0.2
	call lcode1	; Varre coluna
	setb P0.2
	jb F0, Done
	
	clr P0.1
	call lcode2	; Varre coluna
	setb P0.1
	jb F0, Done
	
	clr P0.0
	call lcode3	; Varre coluna
	setb P0.0
	jb F0, Done
	
	; Repetir até P0.0
	jmp ScanKey

Done:
	call ESPSOL
	clr F0
	ret

lcode0:
	jnb P0.4, KeyC03
	jnb P0.5, KeyC13
	jnb P0.6, KeyC23
	ret


lcode1:
	jnb P0.4, KeyC02
	jnb P0.5, KeyC12
	jnb P0.6, KeyC22
	ret
	
lcode2:
	jnb P0.4, KeyC01
	jnb P0.5, KeyC11
	jnb P0.6, KeyC21
	ret

lcode3:
	jnb P0.4, KeyC00
	jnb P0.5, KeyC10
	jnb P0.6, KeyC20
	ret


KeyC00:
	setb F0
	call ESPSOL
	mov R7, #'#'
	ret
	
KeyC10:
	setb F0
	call ESPSOL
	mov R7, #'0'
	ret

KeyC20:
	setb F0
	call ESPSOL
	mov R7, #'*'
	ret

KeyC01:
	setb F0
	call ESPSOL
	mov R7, #'9'
	ret
	
KeyC11:
	setb F0
	call ESPSOL
	mov R7, #'8'
	ret

KeyC21:
	setb F0
	call ESPSOL
	mov R7, #'7'
	ret

KeyC02:
	setb F0
	call ESPSOL
	mov R7, #'6'
	ret
	
KeyC12:
	setb F0
	call ESPSOL
	mov R7, #'5'
	ret

KeyC22:
	setb F0
	call ESPSOL
	mov R7, #'4'
	ret

KeyC03:
	setb F0
	call ESPSOL
	mov R7, #'3'
	ret

KeyC13:
	setb F0
	call ESPSOL
	mov R7, #'2'
	ret

KeyC23:
	setb F0
	call ESPSOL
	mov R7, #'1'
	ret

stop: jmp $


ESPSOL:
	mov A, P0
	anl A, #070h
	cjne A, #070h, ESPSOL
	
	mov TMOD, #01h
	mov TH0, #high(65535)
	mov TL0, #low(65535)
	setb tr0
	jnb tf0, $
	clr tr0
	clr tf0
	
	ret

	

end
org 0h


RS	Equ P1.3
EN	Equ P1.2

main:
	clr RS  ; Instr_LCD
	call FuncS	; Modo de 4 bits - LCD - usar Call
	call DispC	; Liga display e Cursor
	call EntryM	; Shift Right 
next:	
	call ScanKey	; Varre tecla
	setb RS	;
	clr A	;
	mov A, R7	;
	call SendC 	;
	call WaitRelease
	call ESPSOL
	call WaitRelease
	cjne R7, #'#', Next

fim: jmp $


WaitReleaseCheckRow:
	jnb P0.4, WaitReleaseCheckRow
	jnb P0.5, WaitReleaseCheckRow
	jnb P0.6, WaitReleaseCheckRow
	ret
	
WaitRelease:
	clr P0.3
	call WaitReleaseCheckRow
	setb P0.3

	clr P0.2
	call WaitReleaseCheckRow
	setb P0.2

	clr P0.1
	call WaitReleaseCheckRow
	setb P0.1
	
	clr P0.0
	call WaitReleaseCheckRow
	setb P0.0
	
	ret

FuncS:
	; Modo de 4 bits - LCD
	clr P1.7
	clr P1.6
	setb P1.5
	clr P1.4
	
	call Clk
	call Delay
	call Clk

	setb P1.7
	clr P1.6
	clr P1.5
	clr P1.4

	; LCD de 2 linhas
	call Clk
	call Delay

	ret

DispC:

	; (DAT = 00h)
	clr P1.7
	clr P1.6
	clr P1.5
	clr P1.4

	call Clk
	
	; Liga LCD e cursor (DAT = 0fh)
	setb P1.7
	setb P1.6
	setb P1.5
	setb P1.4
	
	call Clk
	call Delay

	ret

EntryM:
	
	; (DAT = 00h)
	clr P1.7
	clr P1.6
	clr P1.5
	clr P1.4
	
	call Clk		
	
	clr P1.7
	setb P1.6
	setb P1.5
	clr P1.4
	
	call Clk
	call Delay

	ret

Clk:
	setb EN
	clr EN
	
	ret

SendC:
	mov C, Acc.7
	mov P1.7, C
	mov C, Acc.6
	mov P1.6, C
	mov C, Acc.5
	mov P1.5, C
	mov C, Acc.4
	mov P1.4, C
	
	call Clk

	mov C, Acc.3
	mov P1.7, C
	mov C, Acc.2
	mov P1.6, C
	mov C, Acc.1
	mov P1.5, C
	mov C, Acc.0
	mov P1.4, C
	call Clk
	call Delay

	ret

Delay:
	mov R0, 50
	djnz R0, $
	
	ret

ScanKey:
	clr P0.3
	call lcode0	; Varre coluna
	setb P0.3
	jb F0, Done
	
	clr P0.2
	call lcode1	; Varre coluna
	setb P0.2
	jb F0, Done
	
	clr P0.1
	call lcode2	; Varre coluna
	setb P0.1
	jb F0, Done
	
	clr P0.0
	call lcode3	; Varre coluna
	setb P0.0
	jb F0, Done
	
	; Repetir até P0.0
	jmp ScanKey

Done:
	call ESPSOL
	clr F0
	ret

lcode0:
	jnb P0.4, KeyC03
	jnb P0.5, KeyC13
	jnb P0.6, KeyC23
	ret


lcode1:
	jnb P0.4, KeyC02
	jnb P0.5, KeyC12
	jnb P0.6, KeyC22
	ret
	
lcode2:
	jnb P0.4, KeyC01
	jnb P0.5, KeyC11
	jnb P0.6, KeyC21
	ret

lcode3:
	jnb P0.4, KeyC00
	jnb P0.5, KeyC10
	jnb P0.6, KeyC20
	ret


KeyC00:
	setb F0
	call ESPSOL
	mov R7, #'#'
	ret
	
KeyC10:
	setb F0
	call ESPSOL
	mov R7, #'0'
	ret

KeyC20:
	setb F0
	call ESPSOL
	mov R7, #'*'
	ret

KeyC01:
	setb F0
	call ESPSOL
	mov R7, #'9'
	ret
	
KeyC11:
	setb F0
	call ESPSOL
	mov R7, #'8'
	ret

KeyC21:
	setb F0
	call ESPSOL
	mov R7, #'7'
	ret

KeyC02:
	setb F0
	call ESPSOL
	mov R7, #'6'
	ret
	
KeyC12:
	setb F0
	call ESPSOL
	mov R7, #'5'
	ret

KeyC22:
	setb F0
	call ESPSOL
	mov R7, #'4'
	ret

KeyC03:
	setb F0
	call ESPSOL
	mov R7, #'3'
	ret

KeyC13:
	setb F0
	call ESPSOL
	mov R7, #'2'
	ret

KeyC23:
	setb F0
	call ESPSOL
	mov R7, #'1'
	ret

stop: jmp $


ESPSOL:
	mov A, P0
	anl A, #070h
	cjne A, #070h, ESPSOL
	
	mov TMOD, #01h
	mov TH0, #high(65535)
	mov TL0, #low(65535)
	setb tr0
	jnb tf0, $
	clr tr0
	clr tf0
	
	ret

	

end
