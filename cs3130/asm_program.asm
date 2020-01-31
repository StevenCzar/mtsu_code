/*Steven Czarnecki
  CSCI 3130
  OLA1
  1/30/20
*/
.global main

.text
main:
	/* puts text into rdi */
    mov   $message, %rdi
    call  c_function
    ret

.data
message:  .ascii  "In the setting sun\nRed leaves upon yellow sand\nAnd a silent sea\n-Richard Wright\n\0"
