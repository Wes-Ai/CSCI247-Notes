        .global main

        .text

main:
        mov message, %rdi
        call puts
        ret

        .data
message: .asciz "Hola Mundo\n"  # Asciz is null terminated C string