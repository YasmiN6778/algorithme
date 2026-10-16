#include <stdio.h> 
 #include <string.h>
 struct sexp {
     char txt[8];
 };
 typedef struct sexp *exp;
 exp  text(char *t) {
     exp e = malloc(sizeof(struct sexp));
     strncpy(e->txt, t, 8);
     return e;
 }
main () {
     exp e1 = text("123");
     printf("%s", e1->txt);
     free(e1);
     exp e2 = text("456");
     exp e3 = text ();
 } 
