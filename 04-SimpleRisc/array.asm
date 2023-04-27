@ Being honest, I wanted to try to create an array in simple RISC and I think I achieved it
@ But, not only that. I wanted to iterate over it and this I couldn't do (not yet)
@ Well, while I was trying to do it, I learned a lot
@ One day, I'll try to do it using the sp

/*
.array:
    mov r4, 0 @helper
    mov r1, 0 @ value
    mov r2, 0 @ iterator
    mov r3, 0 @ the start of the array

    st r1, [r3]
    add r1, r1, 1
    st r1, 4[r3]
    add r1, r1, 1
    st r1, 8[r3]
    add r1, r1, 1
    st r1, 12[r3]
    add r1, r1, 1

    mov r4, sp
    ld r4, [r3]
    .print r4
    ld r4, 4[r3]
    .print r4
    ld r4, 8[r3]
    .print r4
    ld r4, 12[r3]
    .print r4

    mov r1, 4

    ld r4, r1[r3]
    .print r4, r3, sp

    ret
*/

.main:
    mov r0, 4 @ Size of the array as 4*n bytes or n positions
    mov r2, sp @helper

    mov r1, 0
    st r1, 0x2ff @ The interpreter reads it as line 13
    mov r1, 1
    st r1, 4[sp]
    mov r1, 2
    st r1, 8[sp]
    mov r1, 3
    st r1, 12[sp]

    ld r1, [sp]
    .print r1
    ld r1, 4[sp]
    .print r1
    ld r1, 8[sp]
    .print r1
    ld r1, 12[sp]
    .print r1

    .print r2