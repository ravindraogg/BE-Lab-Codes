	AREA Multiply,CODE,READONLY
	ENTRY
START
    LDR R0, =VALUE_1      
    LDRH R1, [R0]         
    LDR R0, =VALUE_2      
    LDRH R2, [R0]         
    MUL R3, R2, R1        
BACK
    B BACK
VALUE_1 DCD 0xBBBB        
VALUE_2 DCD 0xCCCC   

END
