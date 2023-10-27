#define USE_VIRTUAL false
#if USE_VIRTUAL
  #define MAYBE_VIRTUAL_PREFIX virtual 
#else
  #define MAYBE_VIRTUAL_PREFIX 
#endif