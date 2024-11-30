#ifndef _BUTTERFLYFISH_INSERTABLE_$T$_H_
#define _BUTTERFLYFISH_INSERTABLE_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

#include "ordered_$t$.h"

$d$

#define BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_ORDERED_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_INSERTABLE_$T$_ERROR_INSERTABLE_IS_EMPTY \
    BUTTERFLYFISH_ORDERED_$T$_ERROR_ORDERED_IS_EMPTY
#define BUTTERFLYFISH_INSERTABLE_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_ORDERED_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_INSERTABLE_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_ORDERED_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_INSERTABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_INSERTABLE_$T$_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_INSERTABLE_$T$_ERROR_VALUE_IS_INVALID \
    SEA_URCHIN_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_INSERTABLE_$T$_ERROR_VALUE_ALREADY_EXISTS \
    SEA_URCHIN_ERROR_VALUE_ALREADY_EXISTS

struct butterflyfish_insertable_$t$ {
    int (*const as_ordered)(const struct butterflyfish_insertable_$t$ *object,
                            const struct butterflyfish_ordered_$t$ **out);

    int (*const insert)(struct butterflyfish_insertable_$t$ *object,
                        const $v$item,
                        const $v$value);

    int (*const insert_all)(struct butterflyfish_insertable_$t$ *object,
                            const $v$item,
                            const struct butterflyfish_stream_$t$ *other);
};

/**
 * @brief Return insertable as a stream.
 * @param [in] object insertable instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_insertable_$t$_as_stream(
        const struct butterflyfish_insertable_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return insertable as a collection.
 * @param [in] object insertable instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_insertable_$t$_as_collection(
        const struct butterflyfish_insertable_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Return insertable as an ordered.
 * @param [in] object insertable instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_insertable_$t$_as_ordered(
        const struct butterflyfish_insertable_$t$ *object,
        const struct butterflyfish_ordered_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_insertable_$t$_count(
        const struct butterflyfish_insertable_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the insertable.
 * @param [in] object insertable instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_INSERTABLE_IS_EMPTY if insertable
 * is empty.
 */
int butterflyfish_insertable_$t$_first(
        const struct butterflyfish_insertable_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the insertable.
 * @param [in] object insertable instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_INSERTABLE_IS_EMPTY if insertable
 * is empty.
 */
int butterflyfish_insertable_$t$_last(
        const struct butterflyfish_insertable_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object insertable instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_insertable_$t$_next(
        const struct butterflyfish_insertable_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object insertable instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_insertable_$t$_prev(
        const struct butterflyfish_insertable_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Insert value into the insertable.
 * @param [in] object insertable instance.
 * @param [in] item where value is to be inserted.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_VALUE_ALREADY_EXISTS if value is
 * already present.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_VALUE_IS_INVALID if value is
 * invalid.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value to the insertable.
 * @note <b>value</b> is copied and then placed into the insertable.
 */
int butterflyfish_insertable_$t$_insert(
        struct butterflyfish_insertable_$t$ *object,
        const $v$item,
        const $v$value);

/**
 * @brief Insert all the values into to the insertable.
 * @param [in] object insertable instance.
 * @param [in] item where all the values are inserted.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INSERTABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to add streamed values to the insertable.
 * @note streamed <b>values</b> are copied and then placed into the insertable.
 */
int butterflyfish_insertable_$t$_insert_all(
        struct butterflyfish_insertable_$t$ *object,
        const $v$item,
        const struct butterflyfish_stream_$t$ *other);

#endif /* _BUTTERFLYFISH_INSERTABLE_$T$_H_ */
