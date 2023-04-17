# print "Hello World" ten times

            .global main

            .text
main:       mov $10, %r8        # i = 10, r8 is a general purpose register.

top:        cmp $0, %r8         # Once r8 = 0, jump to the end
            je bottom

            # write(1, message, 12);
            mov     $1, %rdi        # Arg 0 holds stdout
            mov     $message, %rsi  # Arg 1 holds address of message
            mov     $12, %rdx       # Arg 2 holds # of bytes

            mov     $1, %rax        # rax holds system id
            syscall                 # call into OS

            dec     %r8
            jmp     top

bottom:
            ret

            .data
message:    .ascii "Hello World\n"
