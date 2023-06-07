
.factorial:
    cmp r0, 1
    bgt .continue

    mov r1, 1
    ret

    .continue:
        sub sp, sp, 8
        st r0, [sp]
        st ra, 4[sp]
        .print r0
        .print ra
        sub r0, r0, 1
        call .factorial
        ld ra, 4[sp]
        ld r0, [sp]
        .print ra
        .print r0
        add sp, sp, 8
        mul r1, r1, r0
        ret

.main:
    mov r0, 10
    call .factorial
    .print r1