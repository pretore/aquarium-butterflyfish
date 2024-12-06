#ifndef _BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_H_
#define _BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "ordered_settable_list_$t$.h"
#include "ordered_incremental_list_$t$.h"
#include "settable_incremental_list_$t$.h"

$d$

#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_ORDERED_SETTABLE_LIST_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_ORDERED_SETTABLE_LIST_$T$_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_ORDERED_SETTABLE_LIST_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_ORDERED_SETTABLE_LIST_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_ORDERED_SETTABLE_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_SETTABLE_LIST_$T$_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_ORDERED_SETTABLE_LIST_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_ORDERED_SETTABLE_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_ORDERED_SETTABLE_LIST_$T$_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OTHER_IS_NULL

struct butterflyfish_ordered_settable_incremental_list_$t$ {
    int (*const as_ordered_settable_list)(
            struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
            struct butterflyfish_ordered_settable_list_$t$ **out);

    int (*const as_ordered_incremental_list)(
            struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
            struct butterflyfish_ordered_incremental_list_$t$ **out);

    int (*const as_settable_incremental_list)(
            struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
            struct butterflyfish_settable_incremental_list_$t$ **out);
};

/**
 * @brief Return ordered settable incremental list as a stream.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_stream(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return ordered settable incremental list as a collection.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_collection(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Return ordered settable incremental list as an ordered.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_ordered(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const struct butterflyfish_ordered_$t$ **out);

/**
 * @brief Return ordered settable incremental list as a list.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_list(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const struct butterflyfish_list_$t$ **out);

/**
 * @brief Return ordered settable incremental list as an addable.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive addable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_addable(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        struct butterflyfish_addable_$t$ **out);

/**
 * @brief Return ordered settable incremental list as a settable.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_settable(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        struct butterflyfish_settable_$t$ **out);

/**
 * @brief Return ordered settable incremental list as an insertable.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive insertable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_insertable(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        struct butterflyfish_insertable_$t$ **out);

/**
 * @brief Return ordered settable incremental list as an ordered list.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive ordered list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_ordered_list(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const struct butterflyfish_ordered_list_$t$ **out);

/**
 * @brief Return ordered settable incremental list as an incremental list.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_incremental_list(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        struct butterflyfish_incremental_list_$t$ **out);

/**
 * @brief Return ordered settable incremental list as a settable list.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive settable list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_settable_list(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        struct butterflyfish_settable_list_$t$ **out);

/**
 * @brief Return ordered settable incremental list as an ordered incremental list.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive ordered incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_ordered_incremental_list(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        struct butterflyfish_ordered_incremental_list_$t$ **out);

/**
 * @brief Return ordered settable incremental list as an ordered settable list.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive ordered settable incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_as_ordered_settable_list(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        struct butterflyfish_ordered_settable_list_$t$ **out);

/**
 * @brief Return ordered settable incremental list as a settable incremental
 * list.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive settable incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int
butterflyfish_ordered_settable_incremental_list_$t$_as_settable_incremental_list(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        struct butterflyfish_settable_incremental_list_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_count(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the ordered settable incremental list.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_LIST_IS_EMPTY if
 * list is empty.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_first(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the ordered settable incremental list.
 * @param [in] object ordered settable incremental list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_LIST_IS_EMPTY if
 * list is empty.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_last(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered settable incremental list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_END_OF_SEQUENCE if
 * there is no next item.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_next(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered settable incremental list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_END_OF_SEQUENCE if
 * there is no previous item.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_prev(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve item at index.
 * @param [in] object ordered settable incremental list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS
 * if at does not refer to an item contained within the settable list.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_get(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        uintmax_t at,
        const $v$*out);

/**
 * @brief Get index of item.
 * @param [in] object ordered settable incremental list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_NOT_FOUND if
 * item is not contained within the settable list.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_at(
        const struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const $v$item,
        uintmax_t *out);

/**
 * @brief Set value of item at index.
 * @param [in] object ordered settable incremental list instance.
 * @param [in] at index of item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS
 * if at does not refer to an item contained within the settable list.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @note <b>value</b> is copied and then item at index is set to it.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_set(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        uintmax_t at,
        const $v$value);

/**
 * @brief Set value of item.
 * @param [in] object ordered settable incremental list instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to set the item to value.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_set_item(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const $v$item,
        const $v$value);

/**
 * @brief Add value to the end.
 * @param [in] object ordered settable incremental list instance.
 * @param [in] value to append.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to add the value.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @note <b>value</b> is copied and then added to the end.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_add(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const $v$value);

/**
 * @brief Add all the values to the end.
 * @param [in] object ordered settable incremental list instance.
 * @param [in] other stream of values which are appended.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to add the values.
 * @note Each <b>value</b> is copied and then added to the end.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_add_all(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

/**
 * @brief Insert value into the list.
 * @param [in] object ordered settable incremental list instance.
 * @param [in] item where value is to be inserted.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value to the list.
 * @note <b>value</b> is copied and then placed into the list.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_insert(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const $v$item,
        const $v$value);

/**
 * @brief Insert all the values into to the list.
 * @param [in] object ordered settable incremental list instance.
 * @param [in] item where all the values are inserted.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add streamed values to the list.
 * @note streamed <b>values</b> are copied and then placed into the list.
 */
int butterflyfish_ordered_settable_incremental_list_$t$_insert_all(
        struct butterflyfish_ordered_settable_incremental_list_$t$ *object,
        const $v$item,
        const struct butterflyfish_stream_$t$ *other);

#endif /* _BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_$T$_H_ */
