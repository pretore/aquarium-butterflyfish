#ifndef _BUTTERFLYFISH_COLLECTION_$T$_H_
#define _BUTTERFLYFISH_COLLECTION_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "stream_$t$.h"

$d$

#define BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_STREAM_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_STREAM_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY \
    BUTTERFLYFISH_STREAM_$T$_ERROR_STREAM_IS_EMPTY
#define BUTTERFLYFISH_COLLECTION_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_STREAM_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_STREAM_$T$_ERROR_END_OF_SEQUENCE

struct butterflyfish_collection_$t$ {
    int (*const as_stream)(const struct butterflyfish_collection_$t$ *object,
                           const struct butterflyfish_stream_$t$ **out);

    int (*const count)(const struct butterflyfish_collection_$t$ *object,
                       uintmax_t *out);

    int (*const last)(const struct butterflyfish_collection_$t$ *object,
                      const $v$*out);

    int (*const prev)(const struct butterflyfish_collection_$t$ *object,
                      const $v$item,
                      const $v$*out);
};

/**
 * @brief Return collection as a stream.
 * @param [in] object collection instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_collection_$t$_as_stream(
        const struct butterflyfish_collection_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_collection_$t$_count(
        const struct butterflyfish_collection_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int butterflyfish_collection_$t$_first(
        const struct butterflyfish_collection_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int butterflyfish_collection_$t$_last(
        const struct butterflyfish_collection_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object collection instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_collection_$t$_next(
        const struct butterflyfish_collection_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object collection instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_collection_$t$_prev(
        const struct butterflyfish_collection_$t$ *object,
        const $v$item,
        const $v$*out);

#endif /* _BUTTERFLYFISH_COLLECTION_$T$_H_ */
