#ifndef SBND_CRTENUMS_CXX
#define SBND_CRTENUMS_CXX

#include "sbnobj/SBND/CRT/CRTEnums.hh"

sbnd::crt::CoordSet operator|(sbnd::crt::CoordSet lhs, sbnd::crt::CoordSet rhs) {
  return static_cast<sbnd::crt::CoordSet>(
      static_cast<std::underlying_type_t<sbnd::crt::CoordSet>>(lhs) |
      static_cast<std::underlying_type_t<sbnd::crt::CoordSet>>(rhs)
  );
}

sbnd::crt::CoordSet operator&(sbnd::crt::CoordSet lhs, sbnd::crt::CoordSet rhs) {
  return static_cast<sbnd::crt::CoordSet>(
      static_cast<std::underlying_type_t<sbnd::crt::CoordSet>>(lhs) &
      static_cast<std::underlying_type_t<sbnd::crt::CoordSet>>(rhs)
  );
}

#endif
