#pragma once

#include <type_traits>

namespace SSVM {
namespace Support {

template <typename X, typename Y> inline bool isa(const Y ptr) {
  return dynamic_cast<const X *>(ptr) != nullptr;
}

template <typename T>
inline T bytesToInt(const std::vector<unsigned char> &Bytes) {
  if (std::is_same<T, int32_t>::value) {
    T Int = 0;
    for (unsigned int I = 3; I >= 0; I--) {
      Int |= Bytes[I] << (I * 8);
    }
    return Int;
  } else if (std::is_same<T, int64_t>::value) {
    T Int = 0;
    for (unsigned int I = 7; I >= 0; I--) {
      Int |= Bytes[I] << (I * 8);
    }
    return Int;
  } else {
    /// TODO: We do not handle the `t.loadN_sx` instructions.
    return 0;
  }
}

template <typename T> inline std::vector<unsigned char> intToBytes(T Int) {
  std::vector<unsigned char> Bytes;
  if (std::is_same<T, int32_t>::value) {
    for (unsigned int I = 0; I <= 3; I++) {
      Bytes.push_back((Int >> (I * 8)) & 0xFF);
    }
  } else if (std::is_same<T, int64_t>::value) {
    for (unsigned int I = 0; I <= 7; I++) {
      Bytes.push_back((Int >> (I * 8)) & 0xFF);
    }
  }

  return Bytes;
}

template <typename T> inline T signedInterpretation(T Int) {
  if (Int >> (sizeof(T) * 8 - 1))
    return Int - (0x01 << (sizeof(T) * 8 - 1));
  return Int;
}

} // namespace Support
} // namespace SSVM