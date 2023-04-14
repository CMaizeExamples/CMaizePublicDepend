#include "cmaize_public_depend/cmaize_public_depend.hpp"

namespace cmaize_public_depend {

int call_cmaize_public_depend() {
    return cmake_public::call_world() + 2;
}

} // namespace cmaize_public_depend
