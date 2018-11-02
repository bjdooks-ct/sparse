
extern int variadic(char *msg, ...) __attribute__((format (printf, 0, 0)));
extern int variadic2(char *msg, int , ...) __attribute__((format (printf, 2, 2)));
extern int variadic3(char *msg, int , ...) __attribute__((format (printf, 2, 1)));

static void test(void) {
}

/*
 * check-name: variadic formatting test with bad formatting parameters
 *
 * check-error-start
varargs-format-bad.c:2:72: warning: bad format positions
varargs-format-bad.c:3:79: warning: bad format positions
varargs-format-bad.c:4:79: warning: format cannot be after va_args
* check-error-end
 */


