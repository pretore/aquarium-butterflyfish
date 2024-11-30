#ifndef _BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_H_
#define _BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "settable_list_$t$.h"
#include "incremental_list_$t$.h"

$d$

#define BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OTHER_IS_NULL

struct butterflyfish_settable_incremental_list_$t$ {
    int (*const as_settable_list)(
            struct butterflyfish_settable_incremental_list_$t$ *object,
            struct butterflyfish_settable_list_$t$ **out);

    int (*const as_incremental_list)(
            struct butterflyfish_settable_incremental_list_$t$ *object,
            struct butterflyfish_incremental_list_$t$ **out);
};

/**
 * @brief Return settable incremental list as a stream.
 * @param [in] object settable incremental list instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_settable_incremental_list_$t$_as_stream(
        const struct butterflyfish_settable_incremental_list_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return settable incremental list as a collection.
 * @param [in] object settable incremental list instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_settable_incremental_list_$t$_as_collection(
        const struct butterflyfish_settable_incremental_list_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Return settable incremental list as a settable.
 * @param [in] object settable incremental list instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_settable_incremental_list_$t$_as_settable(
        struct butterflyfish_settable_incremental_list_$t$ *object,
        struct butterflyfish_settable_$t$ **out);

/**
 * @brief Return settable incremental list as a list.
 * @param [in] object settable incremental list instance.
 * @param [out] out receive list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_settable_incremental_list_$t$_as_list(
        const struct butterflyfish_settable_incremental_list_$t$ *object,
        const struct butterflyfish_list_$t$ **out);

/**
 * @brief Return settable incremental list as an addable.
 * @param [in] object settable incremental list instance.
 * @param [out] out receive addable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_settable_incremental_list_$t$_as_addable(
        struct butterflyfish_settable_incremental_list_$t$ *object,
        struct butterflyfish_addable_$t$ **out);

/**
 * @brief Return settable incremental list as a settable list.
 * @param [in] object settable incremental list instance.
 * @param [out] out receive settable list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_settable_incremental_list_$t$_as_settable_list(
        struct butterflyfish_settable_incremental_list_$t$ *object,
        struct butterflyfish_settable_list_$t$ **out);

/**
 * @brief Return settable incremental list as an incremental list.
 * @param [in] object settable incremental list instance.
 * @param [out] out receive incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_settable_incremental_list_$t$_as_incremental_list(
        struct butterflyfish_settable_incremental_list_$t$ *object,
        struct butterflyfish_incremental_list_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_settable_incremental_list_$t$_count(
        const struct butterflyfish_settable_incremental_list_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the settable incremental list.
 * @param [in] object settable incremental list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_LIST_IS_EMPTY if
 * list is empty.
 */
int butterflyfish_settable_incremental_list_$t$_first(
        const struct butterflyfish_settable_incremental_list_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the settable incremental list.
 * @param [in] object settable incremental list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_LIST_IS_EMPTY if
 * list is empty.
 */
int butterflyfish_settable_incremental_list_$t$_last(
        const struct butterflyfish_settable_incremental_list_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object settable incremental list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_END_OF_SEQUENCE if
 * there is no next item.
 */
int butterflyfish_settable_incremental_list_$t$_next(
        const struct butterflyfish_settable_incremental_list_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object settable incremental list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_END_OF_SEQUENCE if
 * there is no previous item.
 */
int butterflyfish_settable_incremental_list_$t$_prev(
        const struct butterflyfish_settable_incremental_list_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve item at index.
 * @param [in] object settable incremental list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the list.
 */
int butterflyfish_settable_incremental_list_$t$_get(
        const struct butterflyfish_settable_incremental_list_$t$ *object,
        uintmax_t at,
        const $v$*out);

/**
 * @brief Get index of item.
 * @param [in] object settable incremental list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_NOT_FOUND if
 * item is not contained within the list.
 */
int butterflyfish_settable_incremental_list_$t$_at(
        const struct butterflyfish_settable_incremental_list_$t$ *object,
        const $v$item,
        uintmax_t *out);

/**
 * @brief Set value for item.
 * @param [in] object settable incremental list instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @throws
 * BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_settable_incremental_list_$t$_set_item(
        struct butterflyfish_settable_incremental_list_$t$ *object,
        const $v$item,
        const $v$value);

/**
 * @brief Set value of item at index.
 * @param [in] object settable incremental list instance.
 * @param [in] at index of item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the list.
 * @throws
 * BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to set the item to value.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @note <b>value</b> is copied and then item at index is set to it.
 */
int butterflyfish_settable_incremental_list_$t$_set(
        struct butterflyfish_settable_incremental_list_$t$ *object,
        uintmax_t at,
        const $v$value);

/**
 * @brief Add value to the end.
 * @param [in] object settable incremental list instance.
 * @param [in] value to append.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to add the value.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @note <b>value</b> is copied and then added to the end.
 */
int butterflyfish_settable_incremental_list_$t$_add(
        struct butterflyfish_settable_incremental_list_$t$ *object,
        const $v$value);

/**
 * @brief Add all the values to the end.
 * @param [in] object settable incremental list instance.
 * @param [in] other stream of values which are appended.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to add the values.
 * @note Each <b>value</b> is copied and then added to the end.
 */
int butterflyfish_settable_incremental_list_$t$_add_all(
        struct butterflyfish_settable_incremental_list_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

#endif /* _BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_$T$_H_ */
