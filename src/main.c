#include "test.h"

int main(void) {
  Suite *suites[] = {test(), NULL};
  for (Suite **pS = suites; *pS != NULL; pS++) {
    SRunner *sr = srunner_create(*pS);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }
  return 0;
}
