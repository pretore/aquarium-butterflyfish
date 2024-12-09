#ifndef _BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_H_
#define _BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "sorted_settable_list_i_i.h"
#include "sorted_incremental_list_i_i.h"
#include "settable_incremental_list_i_i.h"

struct butterflyfish_map_i_i_entry;

#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SORTED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SORTED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_SORTED_SETTABLE_LIST_I_I_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SORTED_SETTABLE_LIST_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SORTED_SETTABLE_LIST_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_SORTED_SETTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_SORTED_SETTABLE_LIST_I_I_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SORTED_SETTABLE_LIST_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SORTED_SETTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SORTED_SETTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_SORTED_SETTABLE_LIST_I_I_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_SORTED_INCREMENTAL_LIST_I_I_ERROR_OTHER_IS_NULL

struct butterflyfish_sorted_settable_incremental_list_i_i {
    int (*const as_sorted_settable_list)(
            struct butterflyfish_sorted_settable_incremental_list_i_i *object,
            struct butterflyfish_sorted_settable_list_i_i **out);

    int (*const as_sorted_incremental_list)(
            struct butterflyfish_sorted_settable_incremental_list_i_i *object,
            struct butterflyfish_sorted_incremental_list_i_i **out);

    int (*const as_settable_incremental_list)(
            struct butterflyfish_sorted_settable_incremental_list_i_i *object,
            struct butterflyfish_settable_incremental_list_i_i **out);
};

/**
 * @brief Return sorted settable incremental list as a stream.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_as_stream(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return sorted settable incremental list as a collection.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_as_collection(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Return sorted settable incremental list as a sorted.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive sorted.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_as_sorted(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_sorted_i_i **out);

/**
 * @brief Return sorted settable incremental list as a list.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_as_list(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_list_i_i **out);

/**
 * @brief Return sorted settable incremental list as a settable.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_as_settable(
        struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        struct butterflyfish_settable_i_i **out);

/**
 * @brief Return sorted settable incremental list as an addable.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive addable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_as_addable(
        struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        struct butterflyfish_addable_i_i **out);

/**
 * @brief Return sorted settable incremental list as a sorted list.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive sorted list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_as_sorted_list(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_sorted_list_i_i **out);

/**
 * @brief Return sorted settable incremental list as a settable list.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive settable list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_as_settable_list(
        struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        struct butterflyfish_settable_list_i_i **out);

/**
 * @brief Return sorted settable incremental list as an incremental list.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_as_incremental_list(
        struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        struct butterflyfish_incremental_list_i_i **out);

/**
 * @brief Return sorted settable incremental list as a sorted settable list.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive sorted settable list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_as_sorted_settable_list(
        struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        struct butterflyfish_sorted_settable_list_i_i **out);

/**
 * @brief Return sorted settable incremental list as a sorted incremental list.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive sorted incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_as_sorted_incremental_list(
        struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        struct butterflyfish_sorted_incremental_list_i_i **out);

/**
 * @brief Return sorted settable incremental list as a settable incremental
 * list.
 * @param [in] object ordered settable incremental set instance.
 * @param [out] out receive settable incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int
butterflyfish_sorted_settable_incremental_list_i_i_as_settable_incremental_list(
        struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        struct butterflyfish_settable_incremental_list_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_count(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the sorted settable incremental list.
 * @param [in] object sorted settable incremental list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_LIST_IS_EMPTY
 * if list is empty.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_first(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the sorted settable incremental list.
 * @param [in] object sorted settable incremental list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_LIST_IS_EMPTY
 * if list is empty.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_last(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL
 * if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_END_OF_SEQUENCE
 * if there is no next item.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_next(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL
 * if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_END_OF_SEQUENCE
 * if there is no previous item.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_prev(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve item at index.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
 * if at does not refer to an item contained within the list.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_get(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        uintmax_t at,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Get index of item.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL
 * if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_ITEM_NOT_FOUND
 * if item is not contained within the list.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_at(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        uintmax_t *out);

/**
 * @brief Set value for item.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL
 * if item is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL
 * if value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_set_item(
        struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Set value of item at index.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] at index of item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL
 * if value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
 * if at does not refer to an item contained within the mutable list.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @note <b>value</b> is copied and then item at index is set to it.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_set(
        struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        uintmax_t at,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Retrieve item for value or the next higher value.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] value to find or its next higher.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL
 * if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_NOT_FOUND
 * if no value in sorted was equal to or higher than value.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_ceiling(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *value,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve item for value or the next lower value.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] value to find or its next lower.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL
 * if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_NOT_FOUND
 * if no value in sorted was equal to or lower than value.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_floor(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *value,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve item for next higher value.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] value whose next higher value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL
 * if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_NOT_FOUND
 * if no value in sorted is greater.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_higher(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *value,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve item for the next lower value.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] value whose next lower value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL
 * if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_NOT_FOUND
 * if no value in sorted is lower.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_lower(
        const struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *value,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Add value to the end.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] value to append.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL
 * if value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to add the value.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @note <b>value</b> is copied and then added to the end.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_add(
        struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Add all the values to the end.
 * @param [in] object sorted settable incremental list instance.
 * @param [in] other stream of values which are appended.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OTHER_IS_NULL
 * if other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to add the values.
 * @note Each <b>value</b> is copied and then added to the end.
 */
int butterflyfish_sorted_settable_incremental_list_i_i_add_all(
        struct butterflyfish_sorted_settable_incremental_list_i_i *object,
        const struct butterflyfish_stream_i_i *other);

#endif /* _BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_LIST_I_I_H_ */
