
.array:
    mov r1, 0
    mov r3, 0
    mov r4, 0
    mov r4, sp
    .print r1, r3, r4
    .loop:
        cmp r0, r3
        beq .break
        st r1, [r4]
        .print r1, r4
        add r4, r4, 4
        add r1, r1, 1
        add r3, r3, 1
        b .loop
    .break:
        mov r0, 0
        .loop1:
            cmp r0, r3
            beq .break2
            sub r4, r4, 4
            mov r1, r4
            .print r1, r4
            sub r3, r3, 1
            b .loop1
    .break2:
        ret


.main:
    mov r0, 6 @ 4*n bytes or n positions
    call .array
    nop