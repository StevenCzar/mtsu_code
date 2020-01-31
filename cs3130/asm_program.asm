.global main

.text
main:
	/* puts text into rdi */
    mov   $message, %rdi
    call  myfunction2
    ret

.data
message:  .ascii  "In the setting sun\nRed leaves upon yellow sand\nAnd a silent sea.\n-Richard Wright\n\0"
