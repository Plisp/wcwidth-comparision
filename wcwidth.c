#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <wchar.h>
#include <locale.h>

extern int kuhn_wcwidth(wchar_t ucs, char is_cjk);
extern int rust_wcwidth(wchar_t ucs, char is_cjk);
extern int xterm_wcwidth(wchar_t ucs, char is_cjk);

int main(int argc) {
  setlocale(LC_ALL, "");
  char cjk = (argc == 1);
  char s[5];
  puts("┌char─────┬w─┬r─┬x─┐");
  for (int i = 0; i < 0x10FFFF; i++) {
    int wcw = wcwidth(i);
    int rust = rust_wcwidth(i, cjk);
    int xterm = xterm_wcwidth(i, cjk);
    memset(s, 0, 5);
    wctomb(s, i);
    if (!((wcw == rust) && (wcw == xterm))) {
      printf("│%2s  U+%04X│%2d│%2d│%2d│\n", s, i, wcw, rust, xterm);
    }
  }
  puts("└────────────────────┘");
}
