#ifndef _BUTTERFLYFISH_ORDERED_LIST_I_I_H_
#define _BUTTERFLYFISH_ORDERED_LIST_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "list_i_i.h"
#include "ordered_i_i.h"

struct butterflyfish_map_i_i_entry;

#define BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_LIST_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_LIST_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_LIST_I_I_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_LIST_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_LIST_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_LIST_I_I_ERROR_ITEM_NOT_FOUND

struct butterflyfish_ordered_list_i_i {
    int (*const as_list)(
            const struct butterflyfish_ordered_list_i_i *object,
            const struct butterflyfish_list_i_i **out);

    int (*const as_ordered)(
            const struct butterflyfish_ordered_list_i_i *object,
            const struct butterflyfish_ordered_i_i **out);
};

/**
 * @brief Return ordered list as a stream.
 * @param [in] object ordered list instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_list_i_i_as_stream(
        const struct butterflyfish_ordered_list_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return ordered list as a collection.
 * @param [in] object ordered list instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_list_i_i_as_collection(
        const struct butterflyfish_ordered_list_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Return ordered list as a list.
 * @param [in] object ordered list instance.
 * @param [out] out receive list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_list_i_i_as_list(
        const struct butterflyfish_ordered_list_i_i *object,
        const struct butterflyfish_list_i_i **out);

/**
 * @brief Return ordered list as a ordered.
 * @param [in] object ordered list instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_list_i_i_as_ordered(
        const struct butterflyfish_ordered_list_i_i *object,
        const struct butterflyfish_ordered_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_list_i_i_count(
        const struct butterflyfish_ordered_list_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the list.
 * @param [in] object ordered list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_LIST_IS_EMPTY if list is empty.
 */
int butterflyfish_ordered_list_i_i_first(
        const struct butterflyfish_ordered_list_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the list.
 * @param [in] object ordered list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_LIST_IS_EMPTY if list is empty.
 */
int butterflyfish_ordered_list_i_i_last(
        const struct butterflyfish_ordered_list_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_ordered_list_i_i_next(
        const struct butterflyfish_ordered_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_ordered_list_i_i_prev(
        const struct butterflyfish_ordered_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve item at index.
 * @param [in] object ordered list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if at does
 * not refer to an item contained within the list.
 */
int butterflyfish_ordered_list_i_i_get(
        const struct butterflyfish_ordered_list_i_i *object,
        uintmax_t at,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Get index of item.
 * @param [in] object ordered list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_ITEM_NOT_FOUND if item is not
 * contained within the list.
 */
int butterflyfish_ordered_list_i_i_at(
        const struct butterflyfish_ordered_list_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        uintmax_t *out);

#endif /* _BUTTERFLYFISH_ORDERED_LIST_I_I_H_ */
