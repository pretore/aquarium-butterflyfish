#ifndef _BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_H_
#define _BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "incremental_set_$t$.h"
#include "ordered_set_$t$.h"

$d$

#define BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_ALREADY_EXISTS \
    BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_NOT_FOUND

struct butterflyfish_ordered_incremental_set_$t$ {
    int (*const as_insertable)(
            struct butterflyfish_ordered_incremental_set_$t$ *object,
            struct butterflyfish_insertable_$t$ **out);

    int (*const as_ordered_set)(
            const struct butterflyfish_ordered_incremental_set_$t$ *object,
            const struct butterflyfish_ordered_set_$t$ **out);

    int (*const as_incremental_set)(
            struct butterflyfish_ordered_incremental_set_$t$ *object,
            struct butterflyfish_incremental_set_$t$ **out);
};

/**
 * @brief Return ordered incremental set as a stream.
 * @param [in] object incremental set instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_incremental_set_$t$_as_stream(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return ordered incremental set as a collection.
 * @param [in] object incremental set instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_incremental_set_$t$_as_collection(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Return ordered incremental set as an addable.
 * @param [in] object ordered incremental set instance.
 * @param [out] out receive addable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_incremental_set_$t$_as_addable(
        struct butterflyfish_ordered_incremental_set_$t$ *object,
        struct butterflyfish_addable_$t$ **out);

/**
 * @brief Return ordered incremental set as an ordered.
 * @param [in] object ordered incremental set instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_incremental_set_$t$_as_ordered(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const struct butterflyfish_ordered_$t$ **out);

/**
 * @brief Return ordered incremental set as an insertable.
 * @param [in] object ordered incremental set instance.
 * @param [out] out receive insertable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_incremental_set_$t$_as_insertable(
        struct butterflyfish_ordered_incremental_set_$t$ *object,
        struct butterflyfish_insertable_$t$ **out);

/**
 * @brief Return ordered incremental set as a set.
 * @param [in] object ordered incremental set instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_incremental_set_$t$_as_set(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const struct butterflyfish_set_$t$ **out);

/**
 * @brief Return ordered incremental set as an incremental set.
 * @param [in] object ordered incremental set instance.
 * @param [out] out receive incremental set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_incremental_set_$t$_as_incremental_set(
        struct butterflyfish_ordered_incremental_set_$t$ *object,
        struct butterflyfish_incremental_set_$t$ **out);

/**
 * @brief Return ordered incremental set as an ordered set.
 * @param [in] object ordered incremental set instance.
 * @param [out] out receive ordered set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_incremental_set_$t$_as_ordered_set(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const struct butterflyfish_ordered_set_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_incremental_set_$t$_count(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the ordered incremental set.
 * @param [in] object incremental set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_SET_IS_EMPTY if set is
 * empty.
 */
int butterflyfish_ordered_incremental_set_$t$_first(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the ordered incremental set.
 * @param [in] object ordered incremental set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_SET_IS_EMPTY if set
 * is empty.
 */
int butterflyfish_ordered_incremental_set_$t$_last(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered incremental set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_END_OF_SEQUENCE if
 * there is no next item.
 */
int butterflyfish_ordered_incremental_set_$t$_next(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered incremental set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL if item
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_END_OF_SEQUENCE if
 * there is no previous item.
 */
int butterflyfish_ordered_incremental_set_$t$_prev(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Check if ordered incremental set contains the given value.
 * @param [in] object ordered incremental set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_ordered_incremental_set_$t$_contains(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const $v$value,
        bool *out);

/**
 * @brief Check if ordered incremental set contains all the given values.
 * @param [in] object ordered incremental set instance.
 * @param [in] other stream whose values will be checked for presence in set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_ordered_incremental_set_$t$_contains_all(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const struct butterflyfish_stream_$t$ *other,
        bool *out);

/**
 * @brief Retrieve item for value.
 * @param [in] object ordered incremental set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_NOT_FOUND if
 * value is not in the set instance.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_ordered_incremental_set_$t$_get(
        const struct butterflyfish_ordered_incremental_set_$t$ *object,
        const $v$value,
        const $v$*out);

/**
 * @brief Add value to the ordered incremental set.
 * @param [in] object ordered incremental set instance.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_ALREADY_EXISTS
 * if value is already present in the set.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value to the set.
 * @note <b>value</b> is copied and then placed into the set.
 */
int butterflyfish_ordered_incremental_set_$t$_add(
        struct butterflyfish_ordered_incremental_set_$t$ *object,
        const $v$value);

/**
 * @brief Add all the values to the ordered incremental set.
 * @param [in] object ordered incremental set instance.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add streamed values to the set.
 * @note streamed <b>values</b> are copied and then placed into the set.
 */
int butterflyfish_ordered_incremental_set_$t$_add_all(
        struct butterflyfish_ordered_incremental_set_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

/**
 * @brief Insert value into the ordered incremental set.
 * @param [in] object ordered incremental set instance.
 * @param [in] item where value is to be inserted.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_ALREADY_EXISTS
 * if value is already present in the set.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value to the set.
 * @note <b>value</b> is copied and then placed into the set.
 */
int butterflyfish_ordered_incremental_set_$t$_insert(
        struct butterflyfish_ordered_incremental_set_$t$ *object,
        const $v$item,
        const $v$value);

/**
 * @brief Insert all the values into to the ordered incremental set.
 * @param [in] object ordered incremental set instance.
 * @param [in] item where all the values are inserted.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add streamed values to the set.
 * @note streamed <b>values</b> are copied and then placed into the set.
 */
int butterflyfish_ordered_incremental_set_$t$_insert_all(
        struct butterflyfish_ordered_incremental_set_$t$ *object,
        const $v$item,
        const struct butterflyfish_stream_$t$ *other);

#endif /* _BUTTERFLYFISH_ORDERED_INCREMENTAL_SET_$T$_H_ */
