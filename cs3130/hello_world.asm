/*
Hello World Example
*/

.text
.global main
main:
        /* write(1, message, 13); */
        mov     $1, %rax       /* system call 1 is write */
        mov     $1, %rdi       /* file handle 1 is stdout */
        mov     $message, %rsi /* address of string to output */
        mov     $13, %rdx      /* number of bytes */
        syscall                /* invoke operating system */

        /* exit(0); */
        mov     $60, %rax /* system call 60 is exit */
        mov     $0, %rdi  /* exit code 0 */
        syscall           /* invoke operating system to exit */


.data
message:  .ascii      "Hello, World\n"   /* note the newline/term at the end */