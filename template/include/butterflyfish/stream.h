#ifndef _BUTTERFLYFISH_STREAM_$T$_H_
#define _BUTTERFLYFISH_STREAM_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

$d$

#define BUTTERFLYFISH_STREAM_$T$_ERROR_OBJECT_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_STREAM_$T$_ERROR_ITEM_IS_NULL \
    SEA_URCHIN_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_STREAM_$T$_ERROR_OUT_IS_NULL \
    SEA_URCHIN_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_STREAM_$T$_ERROR_STREAM_IS_EMPTY \
    SEA_URCHIN_ERROR_IS_EMPTY
#define BUTTERFLYFISH_STREAM_$T$_ERROR_END_OF_SEQUENCE \
    SEA_URCHIN_ERROR_END_OF_SEQUENCE

struct butterflyfish_stream_$t$ {
    /**
     * @brief First item of the stream.
     * @param [in] object instance.
     * @param [out] out receive the item
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_STREAM_$T$_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_STREAM_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_STREAM_$T$_ERROR_STREAM_IS_EMPTY if stream is empty.
     */
    int (*const first)(const void *object,
                       const $v$*out);

    /**
     * @brief Retrieve next item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the next item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_STREAM_$T$_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_STREAM_$T$_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
     * @throws BUTTERFLYFISH_STREAM_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_STREAM_$T$_ERROR_END_OF_SEQUENCE if there is no next
     * item.
     */
    int (*const next)(const void *object,
                      const $v$item,
                      const $v$*out);
};

#endif /* _BUTTERFLYFISH_STREAM_$T$_H_ */
