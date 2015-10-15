#include <assert.h>
#include <pp_mage.h>

typedef struct foo_t {
  int bar;
  float baz;
} foo_t;

int main() {
  foo_t foo;
  int* pbar = &foo.bar;
  float* pbaz = &foo.baz;

  assert(PP_CONTAINER_OF(pbar, struct foo_t, bar) == &foo);
  assert(PP_CONTAINER_OF(pbaz, foo_t, baz) == &foo);
}