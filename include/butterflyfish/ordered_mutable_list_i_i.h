#ifndef _BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_H_
#define _BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "ordered_settable_incremental_list_i_i.h"
#include "ordered_settable_reducible_list_i_i.h"
#include "mutable_list_i_i.h"

struct butterflyfish_map_i_i_entry;

#define BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_OTHER_IS_NULL

struct butterflyfish_ordered_mutable_list_i_i {
    int (*const as_ordered_settable_incremental_list)(
            struct butterflyfish_ordered_mutable_list_i_i *object,
            struct butterflyfish_ordered_settable_incremental_list_i_i **out);

    int (*const as_ordered_settable_reducible_list)(
            struct butterflyfish_ordered_mutable_list_i_i *object,
            struct butterflyfish_ordered_settable_reducible_list_i_i **out);

    int (*const as_mutable_list)(
            struct butterflyfish_ordered_mutable_list_i_i *object,
            struct butterflyfish_mutable_list_i_i **out);
};

/**
 * @brief Return ordered mutable list as a stream.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_stream(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return ordered mutable list as a collection.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_collection(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Return ordered mutable list as a list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_list(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_list_i_i **out);

/**
 * @brief Return ordered mutable list as a settable.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_settable(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_settable_i_i **out);

/**
 * @brief Return ordered mutable list as an ordered.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_ordered(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_ordered_i_i **out);

/**
 * @brief Return ordered mutable list as an addable.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive addable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_addable(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_addable_i_i **out);

/**
 * @brief Return ordered mutable list as a removable.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive removable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_removable(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_removable_i_i **out);

/**
 * @brief Return ordered mutable list as an insertable.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive insertable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_insertable(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_insertable_i_i **out);

/**
 * @brief Return ordered mutable list as a ordered list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive ordered list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_ordered_list(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_ordered_list_i_i **out);

/**
 * @brief Return ordered mutable list as a settable list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive settable list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_settable_list(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_settable_list_i_i **out);

/**
 * @brief Return ordered mutable list as an incremental list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_incremental_list(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_incremental_list_i_i **out);

/**
 * @brief Return ordered mutable list as a reducible list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive reducible list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_reducible_list(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_reducible_list_i_i **out);

/**
 * @brief Return ordered mutable list as an ordered settable list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive ordered settable list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_ordered_settable_list(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_ordered_settable_list_i_i **out);

/**
 * @brief Return ordered mutable list as an ordered incremental list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive ordered incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_ordered_incremental_list(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_ordered_incremental_list_i_i **out);

/**
 * @brief Return ordered mutable list as an ordered reducible list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive ordered reducible list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_ordered_reducible_list(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_ordered_reducible_list_i_i **out);

/**
 * @brief Return ordered mutable list as a settable incremental list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive settable incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_settable_incremental_list(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_settable_incremental_list_i_i **out);

/**
 * @brief Return ordered mutable list as a settable reducible list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive settable reducible list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_settable_reducible_list(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_settable_reducible_list_i_i **out);

/**
 * @brief Return ordered mutable list as a mutable list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive mutable list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_mutable_list(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_mutable_list_i_i **out);

/**
 * @brief Return ordered mutable list as an ordered incremental ist.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive ordered incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_ordered_settable_incremental_list(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_ordered_settable_incremental_list_i_i **out);

/**
 * @brief Return ordered mutable list as an ordered reducible list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive ordered reducible list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_as_ordered_settable_reducible_list(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        struct butterflyfish_ordered_settable_reducible_list_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_list_i_i_count(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the ordered mutable list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_LIST_IS_EMPTY if list
 * is empty.
 */
int butterflyfish_ordered_mutable_list_i_i_first(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the ordered mutable list.
 * @param [in] object ordered mutable list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_LIST_IS_EMPTY if list
 * is empty.
 */
int butterflyfish_ordered_mutable_list_i_i_last(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered mutable list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_END_OF_SEQUENCE if there
 * is no next item.
 */
int butterflyfish_ordered_mutable_list_i_i_next(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered mutable list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_END_OF_SEQUENCE if there
 * is no previous item.
 */
int butterflyfish_ordered_mutable_list_i_i_prev(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve item at index.
 * @param [in] object ordered mutable list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if
 * at does not refer to an item contained within the list.
 */
int butterflyfish_ordered_mutable_list_i_i_get(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        uintmax_t at,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Get index of item.
 * @param [in] object ordered mutable list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_ITEM_NOT_FOUND if item is
 * not contained within the list.
 */
int butterflyfish_ordered_mutable_list_i_i_at(
        const struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        uintmax_t *out);

/**
 * @brief Set value of item at index.
 * @param [in] object ordered mutable list instance.
 * @param [in] at index of item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if
 * at does not refer to an item contained within the list.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID if value
 * is invalid.
 * @note <b>value</b> is copied and then item at index is set to it.
 */
int butterflyfish_ordered_mutable_list_i_i_set(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        uintmax_t at,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Set value of item.
 * @param [in] object ordered mutable list instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to set the item to value.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID if value
 * is invalid.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_ordered_mutable_list_i_i_set_item(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Add value to the end.
 * @param [in] object ordered mutable list instance.
 * @param [in] value to append.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to add the value.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @note <b>value</b> is copied and then added to the end.
 */
int butterflyfish_ordered_mutable_list_i_i_add(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Add all the values to the end.
 * @param [in] object ordered mutable list instance.
 * @param [in] other stream of values which are appended.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to add the values.
 * @note Each <b>value</b> is copied and then added to the end.
 */
int butterflyfish_ordered_mutable_list_i_i_add_all(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_stream_i_i *other);

/**
 * @brief Insert value into the list.
 * @param [in] object ordered mutable list instance.
 * @param [in] item where value is to be inserted.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws
 * BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value to the list.
 * @note <b>value</b> is copied and then placed into the list.
 */
int butterflyfish_ordered_mutable_list_i_i_insert(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Insert all the values into to the list.
 * @param [in] object ordered mutable list instance.
 * @param [in] item where all the values are inserted.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add streamed values to the list.
 * @note streamed <b>values</b> are copied and then placed into the list.
 */
int butterflyfish_ordered_mutable_list_i_i_insert_all(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_stream_i_i *other);

/**
 * @brief Remove item.
 * @param [in] object ordered mutable list instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_ITEM_IS_NULL if item
 * is <i>NULL</i>.
 * @note <b>item</b> is invalidated when removed.
 */
int butterflyfish_ordered_mutable_list_i_i_remove_item(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item);

/**
 * @brief Remove all items.
 * @param [in] object ordered mutable list instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @note streamed items within <b>other</b> is invalidated when removed.
 */
int butterflyfish_ordered_mutable_list_i_i_remove_all_items(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_stream_i_i *other);

/**
 * @brief Remove item at index.
 * @param [in] object ordered mutable list instance.
 * @param [in] at index of item to remove.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
 * if at does not refer to an item contained within the list.
 */
int butterflyfish_ordered_mutable_list_i_i_remove(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        uintmax_t at);

/**
 * @brief Remove items at indexes.
 * @param [in] object ordered mutable list instance.
 * @param [in] other stream whose indexes will be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to gather indexes for removing items.
 */
int butterflyfish_ordered_mutable_list_i_i_remove_all(
        struct butterflyfish_ordered_mutable_list_i_i *object,
        const struct butterflyfish_stream_ni *other);

#endif /* _BUTTERFLYFISH_ORDERED_MUTABLE_LIST_I_I_H_ */
