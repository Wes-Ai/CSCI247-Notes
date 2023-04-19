        .global main

        .text

main:
        mov $message, %rdi
        call puts
        ret

        .data
message: .asciz "Hola Mundo"  # Asciz is null terminated C string
