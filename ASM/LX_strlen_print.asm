section .text
global _start

_strlen:
	enter 0,0
	mov eax, 0x0
	mov ecx, [ebp + 8]
	
_strlen_is_null:
	cmp byte [ecx], 0x0
	je _strlen_loop_end

	inc eax
	add ecx, 0x01
	jmp _strlen_is_null

_strlen_loop_end:
	leave
	ret

_print_msg:
	enter 0,0
	mov eax, 0x04
	mov ebx, 0x1
	mov ecx, [ebp + 8]
	push eax
	push ecx
	push dword [ebp + 8]
	call _strlen

	mov edx, eax
	add esp, 0x4
	pop ecx
	pop eax

	int 0x80
	leave
	ret

_start:
	enter 0,0
	push text
	call _print_msg
	mov eax, 0x01
	mov ebx, 0x0
	int 0x80

section .data
	text: db "Kek kek kek!", 0xA, 0x0
