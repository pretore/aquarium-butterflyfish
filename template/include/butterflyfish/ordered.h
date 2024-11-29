#ifndef _BUTTERFLYFISH_ORDERED_$T$_H_
#define _BUTTERFLYFISH_ORDERED_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_$t$.h"

$d$

#define BUTTERFLYFISH_ORDERED_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_$T$_ERROR_ORDERED_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE

struct butterflyfish_ordered_$t$ {
    int (*const as_collection)(
            const struct butterflyfish_ordered_$t$ *object,
            const struct butterflyfish_collection_$t$ **out);
};

/**
 * @brief Return ordered as a stream.
 * @param [in] object ordered instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_$t$_as_stream(
        const struct butterflyfish_ordered_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return ordered as a collection.
 * @param [in] object ordered instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_$t$_as_collection(
        const struct butterflyfish_ordered_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_$t$_count(
        const struct butterflyfish_ordered_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of ordered.
 * @param [in] object ordered instance.
 * @param [out] out receive the first item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_ORDERED_IS_EMPTY if ordered is empty.
 */
int butterflyfish_ordered_$t$_first(
        const struct butterflyfish_ordered_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of ordered.
 * @param [in] object ordered instance.
 * @param [out] out receive the last item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_ORDERED_IS_EMPTY if ordered is empty.
 */
int butterflyfish_ordered_$t$_last(
        const struct butterflyfish_ordered_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_END_OF_SEQUENCE if there is no next
 * item.
 */
int butterflyfish_ordered_$t$_next(
        const struct butterflyfish_ordered_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_$T$_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_ordered_$t$_prev(
        const struct butterflyfish_ordered_$t$ *object,
        const $v$item,
        const $v$*out);

#endif /* _BUTTERFLYFISH_ORDERED_$T$_H_ */
