	AREA Sum,CODE,READONLY
	ENTRY
START
    MOV R0, #10
	MOV R1, #0
Loop
	ADD R1, R1, R0
	SUBS r0, #0x01
	BNE Loop
back
	B back
	END