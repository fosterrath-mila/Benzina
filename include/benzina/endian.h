/* Include Guard */
#ifndef INCLUDE_BENZINA_ENDIAN_H
#define INCLUDE_BENZINA_ENDIAN_H


/**
 * Includes
 */

#include <stdint.h>
#include "benzina/config.h"
#include "benzina/inline.h"
#include "benzina/visibility.h"


/* Extern "C" Guard */
#ifdef __cplusplus
extern "C" {
#endif


/**
 * Inline Function Definitions for Endianness Support
 */

#if __GNUC__
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint16_t benz_bswap16(uint16_t x){return __builtin_bswap16(x);}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint32_t benz_bswap32(uint32_t x){return __builtin_bswap32(x);}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint64_t benz_bswap64(uint64_t x){return __builtin_bswap64(x);}
#else
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint16_t benz_bswap16(uint16_t x){return                     x <<  8 |              x >>  8;      }
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint32_t benz_bswap32(uint32_t x){return benz_bswap16(x >>  0) << 16 | benz_bswap16(x >> 16) << 0;}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint64_t benz_bswap64(uint64_t x){return benz_bswap32(x >>  0) << 32 | benz_bswap32(x >> 32) << 0;}
#endif


#undef BENZ_PICK_BE_LE
#if BENZINA_BIG_ENDIAN
# define BENZ_PICK_BE_LE(A,B) A
#else
# define BENZ_PICK_BE_LE(A,B) B
#endif

BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint16_t benz_htobe16(uint16_t x){return BENZ_PICK_BE_LE(x, benz_bswap16(x));}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint32_t benz_htobe32(uint32_t x){return BENZ_PICK_BE_LE(x, benz_bswap32(x));}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint64_t benz_htobe64(uint64_t x){return BENZ_PICK_BE_LE(x, benz_bswap64(x));}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint16_t benz_htole16(uint16_t x){return BENZ_PICK_BE_LE(benz_bswap16(x), x);}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint32_t benz_htole32(uint32_t x){return BENZ_PICK_BE_LE(benz_bswap32(x), x);}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint64_t benz_htole64(uint64_t x){return BENZ_PICK_BE_LE(benz_bswap64(x), x);}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint16_t benz_be16toh(uint16_t x){return BENZ_PICK_BE_LE(x, benz_bswap16(x));}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint32_t benz_be32toh(uint32_t x){return BENZ_PICK_BE_LE(x, benz_bswap32(x));}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint64_t benz_be64toh(uint64_t x){return BENZ_PICK_BE_LE(x, benz_bswap64(x));}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint16_t benz_le16toh(uint16_t x){return BENZ_PICK_BE_LE(benz_bswap16(x), x);}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint32_t benz_le32toh(uint32_t x){return BENZ_PICK_BE_LE(benz_bswap32(x), x);}
BENZINA_PUBLIC BENZINA_ATTRIBUTE_CONST BENZINA_INLINE uint64_t benz_le64toh(uint64_t x){return BENZ_PICK_BE_LE(benz_bswap64(x), x);}

#undef BENZ_PICK_BE_LE


/* End Extern "C" and Include Guard */
#ifdef __cplusplus
}
#endif
#endif

