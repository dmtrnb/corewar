.name "sw"
.comment "sw"

live %-1
ld -5, r2
zjmp %10
ld %0, r3
zjmp %3
add r1, r2, r3
sub r1, r2, r3
and r1, r2, r4
and %10, r2, r4
and -10, r2, r4
and r1, %20, r4
and r1, 20, r4
and %0, %10, r4
and -100, -10, r4
and %12, 13, r4
and -208, %108, r4
or r1, r2, r4
or %10, r2, r4
or -10, r2, r4
or r1, %20, r4
or r1, 20, r4
or %0, %10, r4
or -100, -10, r4
or %12, 13, r4
or -208, %108, r4
xor r1, r2, r4
xor %10, r2, r4
xor -10, r2, r4
xor r1, %20, r4
xor r1, 20, r4
xor %0, %10, r4
xor -100, -10, r4
xor %12, 13, r4
xor -208, %108, r4
ldi r1, r2, r5
ldi r1, %100, r5
ldi %100, r1, r5
ldi -100, r1, r5
ldi -100, %100, r5
ldi %-108, %5, r5
sti r5, r1, r2
sti r5, r1, %100
sti r5, %100, r1
sti r5, -100, r1
sti r5, -100, %100
sti r5, %-108, %5
live %-1
fork %1000
live %-1
lfork %1000
live %-1
ld %72, r2
aff r2
aff r1
lldi r1, r2, r5
lldi r1, %100, r5
lldi %100, r1, r5
lldi -100, r1, r5
lldi -100, %100, r5
lldi %-108, %5, r5
lld %100, r2
lld -100, r3
