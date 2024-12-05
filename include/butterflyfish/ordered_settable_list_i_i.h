#ifndef _BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_H_
#define _BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "settable_list_i_i.h"
#include "ordered_list_i_i.h"

struct butterflyfish_map_i_i_entry;

#define BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID

struct butterflyfish_ordered_settable_list_i_i {
    int (*const as_settable_list)(
            struct butterflyfish_ordered_settable_list_i_i *object,
            struct butterflyfish_settable_list_i_i **out);

    int (*const as_ordered_list)(
            const struct butterflyfish_ordered_settable_list_i_i *object,
            const struct butterflyfish_ordered_list_i_i **out);
};

/**
 * @brief Return ordered settable list as a stream.
 * @param [in] object ordered settable list instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_list_i_i_as_stream(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return ordered settable list as a collection.
 * @param [in] object ordered settable list instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_list_i_i_as_collection(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Return ordered settable list as a list.
 * @param [in] object ordered settable list instance.
 * @param [out] out receive list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_list_i_i_as_list(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        const struct butterflyfish_list_i_i **out);

/**
 * @brief Return ordered settable list as a settable.
 * @param [in] object ordered settable list instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_list_i_i_as_settable(
        struct butterflyfish_ordered_settable_list_i_i *object,
        struct butterflyfish_settable_i_i **out);

/**
 * @brief Return ordered settable list as a ordered.
 * @param [in] object ordered settable list instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_list_i_i_as_ordered(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        const struct butterflyfish_ordered_i_i **out);

/**
 * @brief Return ordered settable list as a settable list.
 * @param [in] object ordered settable list instance.
 * @param [out] out receive settable list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_list_i_i_as_settable_list(
        struct butterflyfish_ordered_settable_list_i_i *object,
        struct butterflyfish_settable_list_i_i **out);

/**
 * @brief Return ordered settable list as a ordered list.
 * @param [in] object ordered settable list instance.
 * @param [out] out receive ordered list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_list_i_i_as_ordered_list(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        const struct butterflyfish_ordered_list_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_list_i_i_count(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the ordered settable list.
 * @param [in] object ordered settable list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_LIST_IS_EMPTY if list
 * is empty.
 */
int butterflyfish_ordered_settable_list_i_i_first(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the ordered settable list.
 * @param [in] object ordered settable list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_LIST_IS_EMPTY if list
 * is empty.
 */
int butterflyfish_ordered_settable_list_i_i_last(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered settable list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_END_OF_SEQUENCE if there
 * is no next item.
 */
int butterflyfish_ordered_settable_list_i_i_next(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered settable list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_END_OF_SEQUENCE if there
 * is no previous item.
 */
int butterflyfish_ordered_settable_list_i_i_prev(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve item at index.
 * @param [in] object ordered settable list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
 * if at does not refer to an item contained within the settable list.
 */
int butterflyfish_ordered_settable_list_i_i_get(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        uintmax_t at,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Get index of item.
 * @param [in] object ordered settable list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_ITEM_NOT_FOUND if item
 * is not contained within the settable list.
 */
int butterflyfish_ordered_settable_list_i_i_at(
        const struct butterflyfish_ordered_settable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        uintmax_t *out);

/**
 * @brief Set value of item at index.
 * @param [in] object ordered settable list instance.
 * @param [in] at index of item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
 * if at does not refer to an item contained within the settable list.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @note <b>value</b> is copied and then item at index is set to it.
 */
int butterflyfish_ordered_settable_list_i_i_set(
        struct butterflyfish_ordered_settable_list_i_i *object,
        uintmax_t at,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Set value of item.
 * @param [in] object ordered settable list instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to set the item to value.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_ordered_settable_list_i_i_set_item(
        struct butterflyfish_ordered_settable_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry *value);

#endif /* _BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_I_H_ */
