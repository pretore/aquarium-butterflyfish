#ifndef _BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_H_
#define _BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "ordered_set_$t$.h"
#include "reducible_set_$t$.h"

$d$

#define BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_VALUE_NOT_FOUND

struct butterflyfish_ordered_reducible_set_$t$ {
    int (*const as_ordered_set)(
            const struct butterflyfish_ordered_reducible_set_$t$ *object,
            const struct butterflyfish_ordered_set_$t$ **out);

    int (*const as_reducible_set)(
            struct butterflyfish_ordered_reducible_set_$t$ *object,
            struct butterflyfish_reducible_set_$t$ **out);
};

/**
 * @brief Return ordered reducible set as a stream.
 * @param [in] object ordered reducible set instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_reducible_set_$t$_as_stream(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return ordered reducible set as a collection.
 * @param [in] object ordered reducible set instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_reducible_set_$t$_as_collection(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Return ordered reducible set as ordered.
 * @param [in] object ordered reducible set instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_reducible_set_$t$_as_ordered(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const struct butterflyfish_ordered_$t$ **out);

/**
 * @brief Return ordered reducible set as a set.
 * @param [in] object ordered reducible set instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_reducible_set_$t$_as_set(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const struct butterflyfish_set_$t$ **out);

/**
 * @brief Return ordered reducible set as a removable.
 * @param [in] object ordered reducible set instance.
 * @param [out] out receive removable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_reducible_set_$t$_as_removable(
        struct butterflyfish_ordered_reducible_set_$t$ *object,
        struct butterflyfish_removable_$t$ **out);

/**
 * @brief Return ordered reducible set as an ordered set.
 * @param [in] object ordered reducible set instance.
 * @param [out] out receive ordered set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_reducible_set_$t$_as_ordered_set(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const struct butterflyfish_ordered_set_$t$ **out);

/**
 * @brief Return ordered reducible set as a reducible set.
 * @param [in] object reducible set instance.
 * @param [out] out receive reducible set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_reducible_set_$t$_as_reducible_set(
        struct butterflyfish_ordered_reducible_set_$t$ *object,
        struct butterflyfish_reducible_set_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_reducible_set_$t$_count(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the ordered reducible set.
 * @param [in] object ordered reducible set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_SET_IS_EMPTY if set is
 * empty.
 */
int butterflyfish_ordered_reducible_set_$t$_first(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the ordered reducible set.
 * @param [in] object ordered reducible set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_SET_IS_EMPTY if set is
 * empty.
 */
int butterflyfish_ordered_reducible_set_$t$_last(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered reducible set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_END_OF_SEQUENCE if
 * there is no next item.
 */
int butterflyfish_ordered_reducible_set_$t$_next(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered reducible set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_END_OF_SEQUENCE if
 * there is no previous item.
 */
int butterflyfish_ordered_reducible_set_$t$_prev(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Check if ordered reducible set contains the given value.
 * @param [in] object ordered reducible set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_ordered_reducible_set_$t$_contains(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const $v$value,
        bool *out);

/**
 * @brief Check if ordered reducible set contains all the given values.
 * @param [in] object ordered reducible set instance.
 * @param [in] other stream whose values will be checked for presence in set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_ordered_reducible_set_$t$_contains_all(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const struct butterflyfish_stream_$t$ *other,
        bool *out);

/**
 * @brief Retrieve item for value.
 * @param [in] object set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_VALUE_NOT_FOUND if
 * value is not in the set instance.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_ordered_reducible_set_$t$_get(
        const struct butterflyfish_ordered_reducible_set_$t$ *object,
        const $v$value,
        const $v$*out);

/**
 * @brief Remove item.
 * @param [in] object ordered reducible set instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL if item
 * is <i>NULL</i>.
 * @note <b>item</b> is invalidated when removed.
 */
int butterflyfish_ordered_reducible_set_$t$_remove_item(
        struct butterflyfish_ordered_reducible_set_$t$ *object,
        const $v$item);

/**
 * @brief Remove all items.
 * @param [in] object set instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @note streamed items within <b>other</b> is invalidated when removed.
 */
int butterflyfish_ordered_reducible_set_$t$_remove_all_items(
        struct butterflyfish_ordered_reducible_set_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

/**
 * @brief Remove value from the ordered reducible set.
 * @param [in] object ordered reducible set instance.
 * @param [in] value to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_VALUE_NOT_FOUND if
 * value is not in the set instance.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the value.
 */
int butterflyfish_ordered_reducible_set_$t$_remove(
        struct butterflyfish_ordered_reducible_set_$t$ *object,
        const $v$value);

/**
 * @brief Remove values from the ordered reducible set.
 * @param [in] object ordered reducible set instance.
 * @param [in] other stream whose values will be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the streamed values in the set.
 */
int butterflyfish_ordered_reducible_set_$t$_remove_all(
        struct butterflyfish_ordered_reducible_set_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

/**
 * @brief Retain all the values present in both.
 * @param [in] object ordered reducible set instance.
 * @param [in] other stream whose values, if present in set too, will be
 * retained.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_ordered_reducible_set_$t$_retain_all(
        struct butterflyfish_ordered_reducible_set_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

#endif /* _BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_$T$_H_ */
