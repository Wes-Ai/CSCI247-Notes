        .global main    # Declare main as global - "Directives"

        .text
main:   # Label = Labels memory address
        # write(1, message, 12);
        mov     $1, %rdi        # Arg 0 holds stdout
        mov     $message, %rsi  # Arg 1 holds address of message
        mov     $12, %rdx       # Arg 2 holds # of bytes

        mov     $1, %rax        # rax holds system id
        syscall                 # call into OS

        ret

        .data
message:    .ascii "Hello World\n"

# First argument is source, second is destination
# Operation arc,dest

# mov x,y == y <- x
# and x,y == x and y
# or x,y == x or y
# xor x,y == x xor y
# add x,y == y <- x+y
# inc x == x <- x+1
# dec x == x <- x-1
# sub x,y == y <- y-x
# syscall == call into OS - %rax holds which system call id