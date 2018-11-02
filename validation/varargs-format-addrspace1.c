
extern int variadic(char *msg, ...) __attribute__((format (printf, 1, 2)));
extern int variadic2(char *msg, int , ...) __attribute__((format (printf, 1, 3)));
extern int variadic3(int, char *msg,  ...) __attribute__((format (printf, 2, 3)));

static void test(void) {
	void __attribute__((noderef, address_space(1))) *a;
	void *b;

	variadic("%s\n", a);
	variadic("%s\n", b);
	variadic("%s %s\n", b, a);
	variadic2("%s %s\n", 1, b, a);
	variadic3(1, "%s %s\n", b, a);
	variadic3(1, "%s %p\n", b, a);
}

static char __msg[] = "%s %p";

static void test2(void) {
	void __attribute__((noderef, address_space(1))) *a;
	void *b;
	int (*ptr)(char *msg, ...) __attribute__((format (printf, 1, 2))) = variadic;
	int (*ptr2)(char *msg, ...) __attribute__((format (printf, 1, 2)));

	variadic(__msg, a, b);
	ptr("hello %s %s", a, b);
	ptr2("hello %s %s", a, b);
}

/*
 * check-name: variadic formatting test with addres-space to %s
 *
 * check-error-start
varargs-format-addrspace1.c:10:26: warning: incorrect type in argument 2 (different address spaces)
varargs-format-addrspace1.c:10:26:    expected string
varargs-format-addrspace1.c:10:26:    got void [noderef] <asn:1>*a
varargs-format-addrspace1.c:12:32: warning: incorrect type in argument 3 (different address spaces)
varargs-format-addrspace1.c:12:32:    expected string
varargs-format-addrspace1.c:12:32:    got void [noderef] <asn:1>*a
varargs-format-addrspace1.c:13:36: warning: incorrect type in argument 4 (different address spaces)
varargs-format-addrspace1.c:13:36:    expected string
varargs-format-addrspace1.c:13:36:    got void [noderef] <asn:1>*a
varargs-format-addrspace1.c:14:36: warning: incorrect type in argument 4 (different address spaces)
varargs-format-addrspace1.c:14:36:    expected string
varargs-format-addrspace1.c:14:36:    got void [noderef] <asn:1>*a
varargs-format-addrspace1.c:15:36: warning: incorrect type in argument 4 (different address spaces)
varargs-format-addrspace1.c:15:36:    expected void *
varargs-format-addrspace1.c:15:36:    got void [noderef] <asn:1>*a
varargs-format-addrspace1.c:26:25: warning: incorrect type in argument 2 (different address spaces)
varargs-format-addrspace1.c:26:25:    expected string
varargs-format-addrspace1.c:26:25:    got void [noderef] <asn:1>*a
varargs-format-addrspace1.c:27:25: warning: incorrect type in argument 2 (different address spaces)
varargs-format-addrspace1.c:27:25:    expected string
varargs-format-addrspace1.c:27:25:    got void [noderef] <asn:1>*a
varargs-format-addrspace1.c:28:25: warning: incorrect type in argument 2 (different address spaces)
varargs-format-addrspace1.c:28:25:    expected string
varargs-format-addrspace1.c:28:25:    got void [noderef] <asn:1>*a
 * check-error-end
 */
