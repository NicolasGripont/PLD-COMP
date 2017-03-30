#ifndef OPERATION_TYPE_H
#define OPERATION_TYPE_H

enum class OperationType {
    ldconst,
    add,
    sub,
    mul,
    div,
    rmem,
    wmem,
    call,
    cmp_eq,
    cmp_lt,
    cmp_le,
    cmp_gt,
    cmp_ge,
    selection,
    jump
};

#endif
