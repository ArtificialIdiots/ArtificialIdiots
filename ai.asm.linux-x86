// Notice: UTF-8 only
// 工作不饱和，怪我咯

.global _start

.text

str1:
.ascii  "吗"

_start:

push    %ebp
mov     %esp, %ebp

// stack vars
sub     $12, %esp

push    $4096
call    alloc_mem
add     $0x4, %esp

// var0: mem_start
mov     %eax, -4(%ebp)

// AI 核心代码，估值十个亿
idiot_logic:
push    $4096
push    -4(%ebp)
push    $0
call    read
add     $0xc, %esp

// var1: read size
mov     %eax, -8(%ebp)

// search for str
push    $3
push    $str1
push    -8(%ebp)
push    -4(%ebp)
call    memmem
add     $0x10, %esp

// var2: position of `吗'
mov     %eax, -12(%ebp)

cmp     $0, %eax
jne     remove_ma

just_repeat:
// %eax = read_size - 2 + 4
mov     -8(%ebp), %eax
add     $3, %eax

// %ebx = read_size + mem_start
mov     -8(%ebp), %ebx
add     -4(%ebp), %ebx


push    $0x0a81bcef
push    %ebx
call    writemem_32
add     $0x8, %esp

jmp     print


remove_ma:
push    $0x0a81bcef
push    %eax
call    writemem_32
add     $0x8, %esp

// modifed size
sub     -4(%ebp), %eax
add     $3, %eax

print:
// call read(0, -4(%ebp), %eax)
push    %eax
push    -4(%ebp)
push    $0
call    write
add     $0xc, %esp

jmp     idiot_logic

test:
push    %ebp
mov     %esp, %ebp
mov     0x8(%ebp), %eax
sub     0xc(%ebp), %eax
sub     0x10(%ebp), %eax
pop     %ebp
ret

exit:
push    %ebp
mov     %esp, %ebp
mov     0x8(%ebp), %ebx
mov     $0x1, %eax
int     $0x80

// void *alloc_mem(uint32_t size)
alloc_mem:
push    %ebp
mov     %esp, %ebp

push    %ebx

// Get and save current brk
mov     $0x2d, %eax
mov     $0x0, %ebx
int     $0x80
push    %eax

// Set new brk
mov     0x8(%ebp), %ebx
add     %eax, %ebx
mov     $0x2d, %eax
int     $0x80


// Return old brk
pop     %eax
pop     %ebx
pop     %ebp
ret


// int read(int fd, void *buf, uint32_t count)
read:
push    %ebp
mov     %esp, %ebp

push    %ebx
push    %ecx
push    %edx
// fd
mov     0x8(%ebp), %ebx
// buf
mov     0xc(%ebp), %ecx
// count
mov     0x10(%ebp), %edx

mov     $0x3, %eax
int     $0x80

pop     %edx
pop     %ecx
pop     %ebx

pop     %ebp
ret


// void writemem_32(void *location, int32_t value)
writemem_32:
push    %ebp
mov     %esp, %ebp

push    %ebx
push    %ecx

// location
mov     0x8(%ebp), %ebx
sub     $1, %ebx
// value
mov     0xc(%ebp), %ecx

movl    %ecx, (%ebx)

pop     %ecx
pop     %ebx

pop     %ebp
ret


// int write(int fd, void *buf, uint32_t count)
write:
push    %ebp
mov     %esp, %ebp

push    %ebx
push    %ecx
push    %edx

// fd
mov     0x8(%ebp), %ebx
// buf
mov     0xc(%ebp), %ecx
// count
mov     0x10(%ebp), %edx

mov     $0x4, %eax
int     $0x80

pop     %edx
pop     %ecx
pop     %ebx

pop     %ebp
ret


// int memcmp(void *buf1, void *buf2, uint32_t count)
memcmp:
push    %ebp
mov     %esp, %ebp

push    %ebx
push    %ecx
push    %edx

// buf1
mov     0x8(%ebp), %ebx
// buf2
mov     0xc(%ebp), %ecx
// count
mov     0x10(%ebp), %edx

memcmp_loop:
sub     $1, %edx
movb    (%edx, %ebx), %al
cmpb    (%edx, %ecx), %al
jne     memcmp_bad
cmp     $0, %edx
jne     memcmp_loop

memcmp_good:
mov     $0, %eax
jmp     memcmp_end

memcmp_bad:
mov     $1, %eax

memcmp_end:
pop     %edx
pop     %ecx
pop     %ebx

pop     %ebp
ret


// void *memmem(void *haystack, uint32_t size_h, void *needle, uint32_t size_n)
memmem:
push    %ebp
mov     %esp, %ebp

push    %ebx
push    %ecx
push    %edx
push    %esi

// haystack
//mov     0x8(%ebp), %ebx
// haystack size
mov     0xc(%ebp), %ecx
// needle
mov     0x10(%ebp), %edx
// needle size
mov     0x14(%ebp), %esi

// max haystack offset
sub     %esi, %ecx
add     $1, %ecx

memmem_loop:
sub     $1, %ecx
push    %ecx
mov     0x10(%ebp), %edx
mov     0x8(%ebp), %ebx
// haystack ptr + offset
add     %ecx, %ebx

// Call memcmp
// count: needle size
push    %esi
// buf2: needle
push    %edx
// buf1: haystack ptr + offset
push    %ebx
call    memcmp
add     $0xc, %esp
// Done calling memcmp, check for return value
cmp     $0, %eax
je      memmem_ok

pop     %ecx
cmp     $0, %ecx
jne     memmem_loop

memmem_nah:
mov     $0, %eax
jmp     memmem_end

memmem_ok:
mov     %ebx, %eax
add     $1, %eax

memmem_end:
pop     %esi
pop     %edx
pop     %ecx
pop     %ebx

leave
ret
