

main:       .global


            mov $0, %r1
top:        cmp %r2, %r1
            jge end
            

            inc %r1
            jmp top
end:

