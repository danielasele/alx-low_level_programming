section .data
    hello db "Hello, Holberton", 0   ; Null-terminated string

section .text
    global main
    extern printf

main:
    sub rsp, 8    ; Align the stack
    mov rdi, hello
    call printf
    add rsp, 8    ; Restore the stack

    mov rax, 60   ; Exit system call
    xor rdi, rdi  ; Return code 0
    syscall
