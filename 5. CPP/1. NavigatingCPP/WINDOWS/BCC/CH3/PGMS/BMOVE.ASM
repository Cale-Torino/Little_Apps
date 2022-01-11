	.286p
	ifndef	??version
?debug	macro
	endm
publicdll macro	name
	public	name
	endm
$comm	macro	name,dist,size,count
	comm	dist name:BYTE:count*size
	endm
	else
$comm	macro	name,dist,size,count
	comm	dist name[size]:BYTE:count
	endm
	endif
	?debug	V 301h
	?debug	S "bmove.c"
	?debug	C E93D507C1F07626D6F76652E63
	?debug	C E94020CA1C19433A5C4243345C494E434C5544455C696F73747265+
	?debug	C 616D2E68
	?debug	C E94020CA1C16433A5C4243345C494E434C5544455C5F646566732E+
	?debug	C 68
	?debug	C E94020CA1C14433A5C4243345C494E434C5544455C6D656D2E68
	?debug	C E94020CA1C16433A5C4243345C494E434C5544455C5F6E756C6C2E+
	?debug	C 68
	?debug	C E94020CA1C18433A5C4243345C494E434C5544455C696F6D616E69+
	?debug	C 702E68
	?debug	C E94020CA1C17433A5C4243345C494E434C5544455C7374646C6962+
	?debug	C 2E68
	?debug	C E94020CA1C17433A5C4243345C494E434C5544455C6D656D6F7279+
	?debug	C 2E68
	?debug	C E94020CA1C14433A5C4243345C494E434C5544455C6D656D2E68
_TEXT	segment byte public 'CODE'
_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:_TEXT,ds:DGROUP
_DATA	segment word public 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public 'BSS'
b@	label	byte
b@w	label	word
_BSS	ends
_TEXT	segment byte public 'CODE'
   ;	
   ;	void *bmove(void *destptr, void *srcptr, size_t count) {
   ;	
	assume	cs:_TEXT,ds:DGROUP
@bmove$qpvt1ui	proc	near
	enter	2,0
	push	si
	push	di
	mov	dx,word ptr [bp+8]
   ;	
   ;		const int bsize = 256;								// tunable block size parameter
   ;	
	mov	word ptr [bp-2],256
   ;	
   ;		typedef unsigned char byte;
   ;		struct mblock {
   ;			byte buf[bsize];									// block buffer
   ;		};
   ;		byte *dest = static_cast<byte *>(destptr);
   ;	
	mov	si,word ptr [bp+4]
   ;	
   ;		byte *src = static_cast<byte *>(srcptr);
   ;	
	mov	di,word ptr [bp+6]
	jmp	short @1@86
@1@58:
   ;	
   ;	
   ;		while (count >= bsize) {							// transfer blocks
   ;			*reinterpret_cast<mblock *>(dest) =
   ;	
   ;	
   ;				*reinterpret_cast<mblock *>(src);		// block move
   ;	
	push	ds
	push	si
	push	ds
	push	di
	mov	cx,256
	call	near ptr N_SCOPY@
   ;	
   ;			dest += bsize;										// increment dest pointer
   ;	
	add	si,256
   ;	
   ;			src += bsize;										// increment src pointer
   ;	
	add	di,256
   ;	
   ;			count -= bsize;									// decrement count
   ;	
	sub	dx,256
@1@86:
	cmp	dx,256
	jae	short @1@58
	jmp	short @1@170
@1@142:
   ;	
   ;		}
   ;		while (count--)										// transfer remaining bytes
   ;			*dest++ = *src++;
   ;	
	mov	al,byte ptr [di]
	mov	byte ptr [si],al
	inc	di
	inc	si
@1@170:
	mov	ax,dx
	dec	dx
	or	ax,ax
	jne	short @1@142
   ;	
   ;		return destptr;										// return pointer to data
   ;	
	mov	ax,word ptr [bp+4]
	jmp	short @1@226
@1@226:
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	leave	
	ret	
@bmove$qpvt1ui	endp
   ;	
   ;	int main(int argc, const char *argv[])
   ;	
	assume	cs:_TEXT,ds:DGROUP
_main	proc	near
	enter	22,0
	push	si
	push	di
   ;	
   ;	{
   ;		if (argc != 2) {
   ;	
	cmp	word ptr [bp+4],2
	je	short @2@114
   ;	
   ;			cerr << "Usage: " << argv[0] << " length" << endl;
   ;	
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bx]
	mov	word ptr [bp-2],ax
	push	0
	push	offset DGROUP:s@
	push	offset DGROUP:_cerr
	call	near ptr @ostream@outstr$qpxct1
	add	sp,6
	push	0
	push	word ptr [bp-2]
	push	offset DGROUP:_cerr
	call	near ptr @ostream@outstr$qpxct1
	add	sp,6
	push	0
	push	offset DGROUP:s@+8
	push	offset DGROUP:_cerr
	call	near ptr @ostream@outstr$qpxct1
	add	sp,6
	push	offset DGROUP:_cerr
	call	near ptr @endl$qr7ostream
	pop	cx
   ;	
   ;			return 1;
   ;	
	mov	ax,1
	jmp	@2@674
@2@114:
   ;	
   ;		}
   ;		int i, length = atoi(argv[1]);
   ;	
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bx+2]
	mov	word ptr [bp-4],ax
	push	word ptr [bp-4]
	call	near ptr _atol
	pop	cx
	mov	di,ax
   ;	
   ;		int *a = new int[length];		int *b = new int[length];
   ;	
	mov	ax,di
	add	ax,ax
	push	ax
	call	near ptr @$bnwa$qui
	pop	cx
	mov	word ptr [bp-6],ax
	mov	ax,di
	add	ax,ax
	push	ax
	call	near ptr @$bnwa$qui
	pop	cx
	mov	word ptr [bp-8],ax
   ;	
   ;	
   ;		for (i = 0; i < length; i++)						// fill with integers
   ;	
	xor	si,si
	jmp	short @2@198
@2@142:
   ;	
   ;			b[i] = i;
   ;	
	mov	bx,si
	add	bx,bx
	add	bx,word ptr [bp-8]
	mov	word ptr [bx],si
	inc	si
@2@198:
	cmp	si,di
	jl	short @2@142
   ;	
   ;		bmove(a, b, length * sizeof(int));				// block move integer data
   ;	
	mov	ax,di
	add	ax,ax
	push	ax
	push	word ptr [bp-8]
	push	word ptr [bp-6]
	call	near ptr @bmove$qpvt1ui
	add	sp,6
   ;	
   ;		for (i = 0; i < length; i++)						// display moved data
   ;	
	xor	si,si
	jmp	short @2@394
@2@254:
   ;	
   ;	 		cout << setw(4) << a[i] << (((i+1) % 10) ? ' ' : '\n');
   ;	
	lea	ax,word ptr [si+1]
	mov	bx,10
	cwd	
	idiv	bx
	or	dx,dx
	je	short @2@310
	mov	al,32
	jmp	short @2@338
@2@310:
	mov	al,10
@2@338:
	push	ax
	mov	bx,si
	add	bx,bx
	add	bx,word ptr [bp-6]
	mov	ax,word ptr [bx]
	mov	word ptr [bp-10],ax
	push	4
	push	ss
	lea	ax,word ptr [bp-14]
	push	ax
	call	near ptr @setw$qi
	add	sp,6
	push	word ptr [bp-12]
	push	word ptr DGROUP:_cout
	call	word ptr [bp-14]
	add	sp,4
	mov	ax,word ptr [bp-10]
	cwd	
	push	dx
	push	ax
	push	offset DGROUP:_cout
	call	near ptr @ostream@$blsh$ql
	add	sp,6
	push	ax
	call	near ptr @ostream@$blsh$qc
	add	sp,4
	inc	si
@2@394:
	cmp	si,di
	jl	short @2@254
   ;	
   ;		cout << endl;
   ;	
	push	offset DGROUP:_cout
	call	near ptr @endl$qr7ostream
	pop	cx
   ;	
   ;		delete [] a;
   ;	
	push	word ptr [bp-6]
	call	near ptr @$bdla$qpv
	pop	cx
   ;	
   ;		delete [] b;
   ;	
	push	word ptr [bp-8]
	call	near ptr @$bdla$qpv
	pop	cx
   ;	
   ;	
   ;		char *c = new char[length];		char *d = new char[length];
   ;	
	push	di
	call	near ptr @$bnwa$qui
	pop	cx
	mov	word ptr [bp-16],ax
	push	di
	call	near ptr @$bnwa$qui
	pop	cx
	mov	word ptr [bp-18],ax
   ;	
   ;		memset(d, 'x', length);								// fill with char data
   ;	
	push	di
	push	120
	push	word ptr [bp-18]
	call	near ptr _memset
	add	sp,6
   ;	
   ;		bmove(c, d, length);									// block move char data
   ;	
	push	di
	push	word ptr [bp-18]
	push	word ptr [bp-16]
	call	near ptr @bmove$qpvt1ui
	add	sp,6
   ;	
   ;		for (i = 0; i < length; i++)						// display moved data
   ;	
	xor	si,si
	jmp	short @2@590
@2@450:
   ;	
   ;	 		cout << setw(4) << c[i] << (((i+1) % 10) ? ' ' : '\n');
   ;	
	lea	ax,word ptr [si+1]
	mov	bx,10
	cwd	
	idiv	bx
	or	dx,dx
	je	short @2@506
	mov	al,32
	jmp	short @2@534
@2@506:
	mov	al,10
@2@534:
	push	ax
	mov	bx,word ptr [bp-16]
	push	word ptr [bx+si]
	push	4
	push	ss
	lea	ax,word ptr [bp-22]
	push	ax
	call	near ptr @setw$qi
	add	sp,6
	push	word ptr [bp-20]
	push	word ptr DGROUP:_cout
	call	word ptr [bp-22]
	add	sp,4
	push	offset DGROUP:_cout
	call	near ptr @ostream@$blsh$qc
	add	sp,4
	push	ax
	call	near ptr @ostream@$blsh$qc
	add	sp,4
	inc	si
@2@590:
	cmp	si,di
	jl	short @2@450
   ;	
   ;		delete [] c;
   ;	
	push	word ptr [bp-16]
	call	near ptr @$bdla$qpv
	pop	cx
   ;	
   ;		delete [] d;
   ;	
	push	word ptr [bp-18]
	call	near ptr @$bdla$qpv
	pop	cx
   ;	
   ;		return 0;
   ;	
	xor	ax,ax
	jmp	short @2@674
@2@674:
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	leave	
	ret	
_main	endp
	?debug	C E9
	?debug	C FA00000000
_TEXT	ends
_DATA	segment word public 'DATA'
s@	label	byte
	db	'Usage: '
	db	0
	db	' length'
	db	0
_DATA	ends
_TEXT	segment byte public 'CODE'
_TEXT	ends
_s@	equ	s@
	extrn	@$bnwa$qui:near
	extrn	@$bdla$qpv:near
	extrn	_memset:near
	extrn	@ostream@$blsh$qc:near
	extrn	@ostream@$blsh$ql:near
	extrn	@ostream@outstr$qpxct1:near
	extrn	_cout:word
	extrn	_cerr:word
	extrn	@endl$qr7ostream:near
	extrn	@setw$qi:near
_abs	equ	abs
_atoi	equ	atoi
	extrn	_atol:near
	public	@bmove$qpvt1ui
	extrn	N_SCOPY@:far
	public	_main
	extrn	__setargv__:far
	end
