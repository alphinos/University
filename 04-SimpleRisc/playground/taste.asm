.main:
    mov r1, 1
    .print sp, ra, r0, r1
    mov r0, r1
    .print ra

    st r1, 4[r2]

    ld r3, [sp]
    .print r3

    ld r3, 8[sp]
    .print r3

    ld r3, 16[sp]
    .print r3

    ld r3, 24[sp]
    .print r3