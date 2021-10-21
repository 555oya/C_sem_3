int compar_func(const void *a, const void *b);
void mysort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
