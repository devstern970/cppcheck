// auto generated tests from cfg/motif.cfg
//
// Generated by command:
// ./generate_cfg_tests cfg/motif.cfg > generated-cfg-tests-motif.cpp
//
// Recommended cppcheck command line:
// $ cppcheck --enable=warning,information --inline-suppr --platform=unix64 generated-cfg-tests-motif.cpp
// => 'unmatched suppression' warnings are false negatives.
//

void test__MrmCloseHierarchy__noreturn() {
  int x = 1;
  if (cond) { x=100; MrmCloseHierarchy(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__MrmCloseHierarchy__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  MrmCloseHierarchy(x);
}

void test__MrmOpenHierarchy__noreturn() {
  int x = 1;
  if (cond) { x=100; result = MrmOpenHierarchy(arg1, arg2, arg3, arg4); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__MrmOpenHierarchy__useretval() {
  // cppcheck-suppress ignoredReturnValue
  MrmOpenHierarchy(arg1, arg2, arg3, arg4);
}

void test__MrmOpenHierarchyPerDisplay__noreturn() {
  int x = 1;
  if (cond) { x=100; result = MrmOpenHierarchyPerDisplay(arg1, arg2, arg3, arg4, arg5); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__MrmOpenHierarchyPerDisplay__useretval() {
  // cppcheck-suppress ignoredReturnValue
  MrmOpenHierarchyPerDisplay(arg1, arg2, arg3, arg4, arg5);
}

void test__XmFontListEntryFree__noreturn() {
  int x = 1;
  if (cond) { x=100; XmFontListEntryFree(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XmFontListEntryFree__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  XmFontListEntryFree(x);
}

void test__XmFontListCreate__noreturn() {
  int x = 1;
  if (cond) { x=100; result = XmFontListCreate(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XmFontListCreate__useretval() {
  // cppcheck-suppress ignoredReturnValue
  XmFontListCreate(arg1, arg2);
}

void test__XmFontListCreate__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = XmFontListCreate(x, arg2);
}

void test__XmFontListCreate__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = XmFontListCreate(arg1, x);
}

void test__XmFontListAppendEntry__noreturn() {
  int x = 1;
  if (cond) { x=100; result = XmFontListAppendEntry(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XmFontListAppendEntry__useretval() {
  // cppcheck-suppress ignoredReturnValue
  XmFontListAppendEntry(arg1, arg2);
}

void test__XmFontListAppendEntry__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = XmFontListAppendEntry(x, arg2);
}

void test__XmFontListAppendEntry__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = XmFontListAppendEntry(arg1, x);
}

void test__XmStringCreateLocalized__noreturn() {
  int x = 1;
  if (cond) { x=100; result = XmStringCreateLocalized(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XmStringCreateLocalized__useretval() {
  // cppcheck-suppress ignoredReturnValue
  XmStringCreateLocalized(arg1);
}

void test__XmStringCreateLocalized__leakignore() {
  char *p = malloc(10); *p=0;
  result = XmStringCreateLocalized(p);
  // cppcheck-suppress memleak
}

void test__XmStringCreateLocalized__arg1__notnull() {
  // cppcheck-suppress nullPointer
  result = XmStringCreateLocalized(NULL);
}

void test__XmStringCreateLocalized__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = XmStringCreateLocalized(x);
}

void test__XmStringCreateSimple__noreturn() {
  int x = 1;
  if (cond) { x=100; result = XmStringCreateSimple(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XmStringCreateSimple__useretval() {
  // cppcheck-suppress ignoredReturnValue
  XmStringCreateSimple(arg1);
}

void test__XmStringCreateSimple__leakignore() {
  char *p = malloc(10); *p=0;
  result = XmStringCreateSimple(p);
  // cppcheck-suppress memleak
}

void test__XmStringCreateSimple__arg1__notnull() {
  // cppcheck-suppress nullPointer
  result = XmStringCreateSimple(NULL);
}

void test__XmStringCreateSimple__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = XmStringCreateSimple(x);
}

void test__XmStringFree__noreturn() {
  int x = 1;
  if (cond) { x=100; XmStringFree(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XmStringFree__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  XmStringFree(x);
}

void test__XmStringGenerate__noreturn() {
  int x = 1;
  if (cond) { x=100; XmStringGenerate(arg1, arg2, arg3, arg4); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XmStringGenerate__leakignore() {
  char *p = malloc(10); *p=0;
  XmStringGenerate(p, arg2, arg3, arg4);
  // cppcheck-suppress memleak
}

void test__XmTextGetString__noreturn() {
  int x = 1;
  if (cond) { x=100; XmTextGetString(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XmTextGetString__leakignore() {
  char *p = malloc(10); *p=0;
  XmTextGetString(p);
  // cppcheck-suppress memleak
}

void test__XmTextGetString__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  XmTextGetString(x);
}

void test__XmTextGetStringWcs__noreturn() {
  int x = 1;
  if (cond) { x=100; XmTextGetStringWcs(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XmTextGetStringWcs__leakignore() {
  char *p = malloc(10); *p=0;
  XmTextGetStringWcs(p);
  // cppcheck-suppress memleak
}

void test__XmTextGetStringWcs__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  XmTextGetStringWcs(x);
}

void test__XtAsprintf__arg2__notnull() {
  // cppcheck-suppress nullPointer
  XtAsprintf(arg1, NULL);
}

void test__XtAsprintf__arg2__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  XtAsprintf(arg1, x);
}

void test__XtFree__noreturn() {
  int x = 1;
  if (cond) { x=100; XtFree(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XtFree__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  XtFree(x);
}

void test__XtSetValues__noreturn() {
  int x = 1;
  if (cond) { x=100; XtSetValues(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XtSetValues__leakignore() {
  char *p = malloc(10); *p=0;
  XtSetValues(p, arg2, arg3);
  // cppcheck-suppress memleak
}

void test__XtGetValues__noreturn() {
  int x = 1;
  if (cond) { x=100; XtGetValues(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XtGetValues__leakignore() {
  char *p = malloc(10); *p=0;
  XtGetValues(p, arg2, arg3);
  // cppcheck-suppress memleak
}

void test__XtSetSubvalues__noreturn() {
  int x = 1;
  if (cond) { x=100; XtSetSubvalues(arg1, arg2, arg3, arg4, arg5); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XtSetSubvalues__leakignore() {
  char *p = malloc(10); *p=0;
  XtSetSubvalues(p, arg2, arg3, arg4, arg5);
  // cppcheck-suppress memleak
}

void test__XtGetSubvalues__noreturn() {
  int x = 1;
  if (cond) { x=100; XtGetSubvalues(arg1, arg2, arg3, arg4, arg5); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XtGetSubvalues__leakignore() {
  char *p = malloc(10); *p=0;
  XtGetSubvalues(p, arg2, arg3, arg4, arg5);
  // cppcheck-suppress memleak
}

void test__XtMalloc__noreturn() {
  int x = 1;
  if (cond) { x=100; result = XtMalloc(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XtMalloc__useretval() {
  // cppcheck-suppress ignoredReturnValue
  XtMalloc(arg1);
}

void test__XtMalloc__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = XtMalloc(x);
}

void test__XtNew__noreturn() {
  int x = 1;
  if (cond) { x=100; result = XtNew(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XtNew__useretval() {
  // cppcheck-suppress ignoredReturnValue
  XtNew(arg1);
}

void test__XtNew__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = XtNew(x);
}

void test__XtNewString__noreturn() {
  int x = 1;
  if (cond) { x=100; result = XtNewString(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XtNewString__useretval() {
  // cppcheck-suppress ignoredReturnValue
  XtNewString(arg1);
}

void test__XtNewString__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = XtNewString(x);
}

void test__XtCalloc__noreturn() {
  int x = 1;
  if (cond) { x=100; result = XtCalloc(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XtCalloc__useretval() {
  // cppcheck-suppress ignoredReturnValue
  XtCalloc(arg1, arg2);
}

void test__XtCalloc__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = XtCalloc(x, arg2);
}

void test__XtCalloc__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = XtCalloc(arg1, x);
}

void test__XOpenDisplay__noreturn() {
  int x = 1;
  if (cond) { x=100; XOpenDisplay(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XOpenDisplay__leakignore() {
  char *p = malloc(10); *p=0;
  XOpenDisplay(p);
  // cppcheck-suppress memleak
}

void test__XOpenDisplay__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  XOpenDisplay(x);
}

void test__XCloseDisplay__noreturn() {
  int x = 1;
  if (cond) { x=100; XCloseDisplay(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XCloseDisplay__leakignore() {
  char *p = malloc(10); *p=0;
  XCloseDisplay(p);
  // cppcheck-suppress memleak
}

void test__XCloseDisplay__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  XCloseDisplay(x);
}

void test__XtDatabase__noreturn() {
  int x = 1;
  if (cond) { x=100; XtDatabase(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XtDatabase__leakignore() {
  char *p = malloc(10); *p=0;
  XtDatabase(p);
  // cppcheck-suppress memleak
}

void test__XtDatabase__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  XtDatabase(x);
}

void test__XtScreenDatabase__noreturn() {
  int x = 1;
  if (cond) { x=100; XtScreenDatabase(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__XtScreenDatabase__leakignore() {
  char *p = malloc(10); *p=0;
  XtScreenDatabase(p);
  // cppcheck-suppress memleak
}

void test__XtScreenDatabase__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  XtScreenDatabase(x);
}

