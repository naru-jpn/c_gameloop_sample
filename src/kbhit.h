
#ifndef _INCLUDE_KBHIT_
#define _INCLUDE_KBHIT_

#define KEY_ESC 0x1B

enum {
	IKEYTYPE_NONE,
	IKEYTYPE_CHAR,
	IKEYTYPE_ESC,
	IKEYTYPE_ARRUP,
	IKEYTYPE_ARRDOWN,
	IKEYTYPE_ARRRIGHT,
	IKEYTYPE_ARRLEFT	
};

// [ref]: http://hatenaclang.blogspot.jp/2011/03/kbhit.html
// 何かキーが押されている場合は 1 を返し、そうでない場合は 0 を返します。
int kbhit();

// 標準入力から文字を読み取ります。
void readikey(int *ikeytype, char *ch, int flush);

/* deprecated */
// 標準入力から一文字読み込みます。
void read_key(char *ch);

#endif
