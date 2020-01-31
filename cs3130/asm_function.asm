/*Steven Czarnecki
  CSCI 3130
  OLA 1
  1/30/20
*/
.global myfunction2

.text
myfunction2:
	/*message pointer into rdx, length of string as constant into rsi*/
    mov   $76, %rdx
    mov   %rdi, %rsi
    /*1 in rax is system call to write, 1 in rdi is stdout*/
    mov   $1, %rax
    mov   $1, %rdi
    /*Does actual call now*/
    syscall
    ret
