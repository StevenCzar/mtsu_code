.global main

.text
main:
    mov   $message, %rdi
    mov   $12, %rsi
    call  myfunction2
    ret

.data
message:  .ascii  "Hello World\n\0"