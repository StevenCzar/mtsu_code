.global myfunction2

.text
myfunction2:
	/*message pointer into rdx, length of string as constant into rsi*/
    mov   %rsi, %rdx
    mov   $, %rsi
    /*1 in rax is system call to write, 1 in rdi is stdout*/
    mov   $1, %rax
    mov   $1, %rdi
    /*Does actual call now*/
    syscall
    ret
