#ifndef _BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_H_
#define _BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "sorted_list_$t$.h"
#include "reducible_list_$t$.h"

$d$

#define BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED

struct butterflyfish_sorted_reducible_list_$t$ {
    int (*const as_sorted_list)(
            const struct butterflyfish_sorted_reducible_list_$t$ *object,
            const struct butterflyfish_sorted_list_$t$ **out);

    int (*const as_reducible_list)(
            struct butterflyfish_sorted_reducible_list_$t$ *object,
            struct butterflyfish_reducible_list_$t$ **out);
};

/**
 * @brief Return sorted reducible list as a stream.
 * @param [in] object sorted reducible list instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_reducible_list_$t$_as_stream(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return sorted reducible list as a collection.
 * @param [in] object sorted reducible list instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_reducible_list_$t$_as_collection(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Return sorted reducible list as a list.
 * @param [in] object sorted reducible list instance.
 * @param [out] out receive list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_reducible_list_$t$_as_list(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const struct butterflyfish_list_$t$ **out);

/**
 * @brief Return sorted reducible list as sorted.
 * @param [in] object sorted reducible list instance.
 * @param [out] out receive sorted.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_reducible_list_$t$_as_sorted(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const struct butterflyfish_sorted_$t$ **out);

/**
 * @brief Return sorted reducible list as removable.
 * @param [in] object sorted reducible list instance.
 * @param [out] out receive removable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_reducible_list_$t$_as_removable(
        struct butterflyfish_sorted_reducible_list_$t$ *object,
        struct butterflyfish_removable_$t$ **out);

/**
 * @brief Return sorted reducible list as sorted list.
 * @param [in] object sorted reducible list instance.
 * @param [out] out receive sorted list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_reducible_list_$t$_as_sorted_list(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const struct butterflyfish_sorted_list_$t$ **out);

/**
 * @brief Return sorted reducible list as reducible list.
 * @param [in] object sorted reducible list instance.
 * @param [out] out receive reducible list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_reducible_list_$t$_as_reducible_list(
        struct butterflyfish_sorted_reducible_list_$t$ *object,
        struct butterflyfish_reducible_list_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_reducible_list_$t$_count(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the list.
 * @param [in] object list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_LIST_IS_EMPTY if list
 * is empty.
 */
int butterflyfish_sorted_reducible_list_$t$_first(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the list.
 * @param [in] object list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_LIST_IS_EMPTY if list
 * is empty.
 */
int butterflyfish_sorted_reducible_list_$t$_last(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_END_OF_SEQUENCE if
 * there is no next item.
 */
int butterflyfish_sorted_reducible_list_$t$_next(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_END_OF_SEQUENCE if
 * there is no previous item.
 */
int butterflyfish_sorted_reducible_list_$t$_prev(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve item at index.
 * @param [in] object list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS
 * if at does not refer to an item contained within the list.
 */
int butterflyfish_sorted_reducible_list_$t$_get(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        uintmax_t at,
        const $v$*out);

/**
 * @brief Get index of item.
 * @param [in] object list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_ITEM_NOT_FOUND if item
 * is not contained within the list.
 */
int butterflyfish_sorted_reducible_list_$t$_at(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const $v$item,
        uintmax_t *out);

/**
 * @brief Retrieve item for value or the next higher value.
 * @param [in] object sorted reducible list instance.
 * @param [in] value to find or its next higher.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_VALUE_NOT_FOUND if no
 * value in sorted was equal to or higher than value.
 * @throws
 * BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_sorted_reducible_list_$t$_ceiling(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const $v$value,
        const $v$*out);

/**
 * @brief Retrieve item for value or the next lower value.
 * @param [in] object sorted reducible list instance.
 * @param [in] value to find or its next lower.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_VALUE_NOT_FOUND if no
 * value in sorted was equal to or lower than value.
 * @throws
 * BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_sorted_reducible_list_$t$_floor(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const $v$value,
        const $v$*out);

/**
 * @brief Retrieve item for next higher value.
 * @param [in] object sorted reducible list instance.
 * @param [in] value whose next higher value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_VALUE_NOT_FOUND if no
 * value in sorted is greater.
 * @throws
 * BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_sorted_reducible_list_$t$_higher(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const $v$value,
        const $v$*out);

/**
 * @brief Retrieve item for the next lower value.
 * @param [in] object sorted reducible list instance.
 * @param [in] value whose next lower value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_VALUE_NOT_FOUND if no
 * value in sorted is lower.
 * @throws
 * BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_sorted_reducible_list_$t$_lower(
        const struct butterflyfish_sorted_reducible_list_$t$ *object,
        const $v$value,
        const $v$*out);

/**
 * @brief Remove item.
 * @param [in] object reducible list instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @note <b>item</b> is invalidated when removed.
 */
int butterflyfish_sorted_reducible_list_$t$_remove_item(
        struct butterflyfish_sorted_reducible_list_$t$ *object,
        const $v$item);

/**
 * @brief Remove all items.
 * @param [in] object reducible list instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @note streamed items within <b>other</b> is invalidated when removed.
 */
int butterflyfish_sorted_reducible_list_$t$_remove_all_items(
        struct butterflyfish_sorted_reducible_list_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

/**
 * @brief Remove item at index.
 * @param [in] object reducible list instance.
 * @param [in] at index of item to remove.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS
 * if at does not refer to an item contained within the list.
 */
int butterflyfish_sorted_reducible_list_$t$_remove(
        struct butterflyfish_sorted_reducible_list_$t$ *object,
        uintmax_t at);

/**
 * @brief Remove items at indexes.
 * @param [in] object reducible list instance.
 * @param [in] other stream whose indexes will be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to gather indexes for removing items.
 */
int butterflyfish_sorted_reducible_list_$t$_remove_all(
        struct butterflyfish_sorted_reducible_list_$t$ *object,
        const struct butterflyfish_stream_ni *other);

#endif /* _BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_$T$_H_ */
