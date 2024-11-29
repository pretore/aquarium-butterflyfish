#ifndef _BUTTERFLYFISH_REMOVABLE_$T$_H_
#define _BUTTERFLYFISH_REMOVABLE_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_$t$.h"

$d$

#define BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_REMOVABLE_$T$_ERROR_REMOVABLE_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_REMOVABLE_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_REMOVABLE_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL

struct butterflyfish_removable_$t$ {
    int (*const as_collection)(const struct butterflyfish_removable_$t$ *object,
                               const struct butterflyfish_collection_$t$ **out);

    int (*const remove_item)(struct butterflyfish_removable_$t$ *object,
                             const $v$item);

    int (*const remove_all_items)(struct butterflyfish_removable_$t$ *object,
                                  const struct butterflyfish_stream_$t$ *other);
};

/**
 * @brief Return removable as a stream.
 * @param [in] object removable instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_removable_$t$_as_stream(
        const struct butterflyfish_removable_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return removable as a collection.
 * @param [in] object removable instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_removable_$t$_as_collection(
        const struct butterflyfish_removable_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_removable_$t$_count(
        const struct butterflyfish_removable_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the removable.
 * @param [in] object removable instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_REMOVABLE_IS_EMPTY if removable is
 * empty.
 */
int butterflyfish_removable_$t$_first(
        const struct butterflyfish_removable_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the removable.
 * @param [in] object removable instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_REMOVABLE_IS_EMPTY if removable is
 * empty.
 */
int butterflyfish_removable_$t$_last(
        const struct butterflyfish_removable_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object removable instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_removable_$t$_next(
        const struct butterflyfish_removable_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object removable instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_removable_$t$_prev(
        const struct butterflyfish_removable_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Remove item.
 * @param [in] object removable instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @note <b>item</b> is invalidated when removed.
 */
int butterflyfish_removable_$t$_remove_item(
        struct butterflyfish_removable_$t$ *object,
        const $v$item);

/**
 * @brief Remove all items.
 * @param [in] object removable instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @note streamed items within <b>other</b> is invalidated when removed.
 */
int butterflyfish_removable_$t$_remove_all_items(
        struct butterflyfish_removable_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

#endif /* _BUTTERFLYFISH_REMOVABLE_$T$_H_ */
