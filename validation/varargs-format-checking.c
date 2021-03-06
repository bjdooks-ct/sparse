
extern void pf(char *msg, ...) __attribute__((format (printf, 1, 2)));

static void test(void) {
	pf("%u %lu %llu\n", 1U, 1UL, 1ULL);
	pf("%d %ld %lld\n", 1, 1L, 1LL);
	pf("%x %lx %llx\n", 1U, 1UL, 1ULL);
	pf("%d %ld %lld\n", 1, 1L, 1L);
}

/*
 * check-name: variadic formatting test type checking
 *
 * check-error-start
varargs-type-checking.c:8:36: warning: incorrect type in argument 4 (different types)
varargs-type-checking.c:8:36:    expected long long
varargs-type-checking.c:8:36:    got long
 * check-error-end
 */
