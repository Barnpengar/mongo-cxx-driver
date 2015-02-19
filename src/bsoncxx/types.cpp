// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <bsoncxx/types.hpp>
#include <bsoncxx/json.hpp>

namespace bsoncxx {
BSONCXX_INLINE_NAMESPACE_BEGIN

std::string to_string(type rhs) {
    switch (static_cast<uint8_t>(rhs)) {
#define BSONCXX_ENUM(name, val) \
    case val:                   \
        return (#name);         \
        break;
#include <bsoncxx/enums/type.hpp>
#undef BSONCXX_ENUM
        default:
            return "?";
    }
}

std::string to_string(binary_sub_type rhs) {
    switch (static_cast<uint8_t>(rhs)) {
#define BSONCXX_ENUM(name, val) \
    case val:                   \
        return (#name);         \
        break;
#include <bsoncxx/enums/binary_sub_type.hpp>
#undef BSONCXX_ENUM
        default:
            return "?";
    }
}

namespace types {

#define BSONCXX_ENUM(name, val)                                        \
    std::ostream& operator<<(std::ostream& out, const b_##name& rhs) { \
        json_visitor jv(out, false, 0);                                \
        jv.visit_value(rhs);                                           \
        return out;                                                    \
    }
#include <bsoncxx/enums/type.hpp>
#undef BSONCXX_ENUM

}  // namespace types
BSONCXX_INLINE_NAMESPACE_END
}  // namespace bsoncxx
