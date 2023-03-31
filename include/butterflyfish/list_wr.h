#ifndef _BUTTERFLYFISH_LIST_WR_H_
#define _BUTTERFLYFISH_LIST_WR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "reducible_list_wr.h"

struct triggerfish_weak;

#define BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_LIST_WR_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_LIST_WR_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_LIST_WR_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_LIST_WR_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_ITEM_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_LIST_WR_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OTHER_IS_NULL

struct butterflyfish_list_wr {
    const struct butterflyfish_reducible_list_wr reducible_list_wr;

    int (*const add)(void *object,
                     const struct triggerfish_weak *value);

    int (*const add_all)(void *object,
                         const struct butterflyfish_stream_wr *other);

    int (*const insert)(void *object,
                        uintmax_t at,
                        const struct triggerfish_weak *value);

    int (*const insert_item)(void *object,
                             struct triggerfish_weak *item,
                             const struct triggerfish_weak *value);

    int (*const insert_all)(void *object,
                            uintmax_t at,
                            const struct butterflyfish_stream_wr *other);

    int (*const insert_all_item)(void *object,
                                 struct triggerfish_weak *item,
                                 const struct butterflyfish_stream_wr *other);

};

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_list_wr_count(
        const struct butterflyfish_list_wr *object,
        uintmax_t *out);

/**
 * @brief First item of the list.
 * @param [in] object list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_LIST_IS_EMPTY if list is empty.
 */
int butterflyfish_list_wr_first(
        const struct butterflyfish_list_wr *object,
        const struct triggerfish_weak **out);

/**
 * @brief Last item of the list.
 * @param [in] object list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_LIST_IS_EMPTY if list is empty.
 */
int butterflyfish_list_wr_last(
        const struct butterflyfish_list_wr *object,
        const struct triggerfish_weak **out);

/**
 * @brief Retrieve next item.
 * @param [in] object list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_END_OF_SEQUENCE if there is no next item.
 */
int butterflyfish_list_wr_next(
        const struct butterflyfish_list_wr *object,
        const struct triggerfish_weak *item,
        const struct triggerfish_weak **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_END_OF_SEQUENCE if there is no previous
 * item.
 */
int butterflyfish_list_wr_prev(
        const struct butterflyfish_list_wr *object,
        const struct triggerfish_weak *item,
        const struct triggerfish_weak **out);

/**
 * @brief Retrieve item at index.
 * @param [in] object list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS if at does not
 * refer to an item contained within the list.
 */
int butterflyfish_list_wr_get(
        const struct butterflyfish_list_wr *object,
        uintmax_t at,
        const struct triggerfish_weak **out);

/**
 * @brief Set value of item at index.
 * @param [in] object list instance.
 * @param [in] at index of item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS if at does not
 * refer to an item contained within the list.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to set the item to value.
 * @note <b>value</b> is copied and then item at index is set to it.
 */
int butterflyfish_list_wr_set(
        struct butterflyfish_list_wr *object,
        uintmax_t at,
        const struct triggerfish_weak *value);

/**
 * @brief Set value of item.
 * @param [in] object list instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_OUT_OF_BOUNDS if item is not
 * contained within the list.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to set the item to value.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_list_wr_set_item(
        struct butterflyfish_list_wr *object,
        struct triggerfish_weak *item,
        const struct triggerfish_weak *value);

/**
 * @brief Get index of item.
 * @param [in] object list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_OUT_OF_BOUNDS if item is not
 * contained within the list.
 */
int butterflyfish_list_wr_at(
        const struct butterflyfish_list_wr *object,
        const struct triggerfish_weak *item,
        uintmax_t *out);

/**
 * @brief Remove item at index.
 * @param [in] object list instance.
 * @param [in] at index of item to remove.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS if at does not
 * refer to an item contained within the list.
 */
int butterflyfish_list_wr_remove(
        struct butterflyfish_list_wr *object,
        uintmax_t at);

/**
 * @brief Remove item.
 * @param [in] object list instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_OUT_OF_BOUNDS if item is not
 * contained within the list.
 */
int butterflyfish_list_wr_remove_item(
        struct butterflyfish_list_wr *object,
        const struct triggerfish_weak *item);

/**
 * @brief Remove all items.
 * @param [in] object list instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 */
int butterflyfish_list_wr_remove_all_items(
        struct butterflyfish_list_wr *object,
        const struct butterflyfish_stream_wr *other);

/**
 * @brief Add value to the end.
 * @param [in] object list instance.
 * @param [in] value to append.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to add the value.
 * @note <b>value</b> is copied and then added to the end.
 */
int butterflyfish_list_wr_add(
        struct butterflyfish_list_wr *object,
        const struct triggerfish_weak *value);

/**
 * @brief Add all the values to the end.
 * @param [in] object list instance.
 * @param [in] other stream of values which are appended.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to add the values.
 * @note Each <b>value</b> is copied and then added to the end.
 */
int butterflyfish_list_wr_add_all(
        struct butterflyfish_list_wr *object,
        const struct butterflyfish_stream_wr *other);

/**
 * @brief Insert value at index.
 * @param [in] object list instance.
 * @param [in] at index of where value is to be inserted.
 * @param [in] value to insert.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS if at does not
 * refer to an item contained within the list.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to insert value.
 * @note <b>value</b> is copied and then inserted at index.
 */
int butterflyfish_list_wr_insert(
        struct butterflyfish_list_wr *object,
        uintmax_t at,
        const struct triggerfish_weak *value);

/**
 * @brief Insert value at item.
 * @param [in] object list instance.
 * @param [in] item where value is to be inserted.
 * @param [in] value to insert.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_OUT_OF_BOUNDS if item is not
 * contained within the list.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to insert value.
 * @note <b>value</b> is copied and then inserted at item.
 */
int butterflyfish_list_wr_insert_item(
        struct butterflyfish_list_wr *object,
        struct triggerfish_weak *item,
        const struct triggerfish_weak *value);

/**
 * @brief Insert all the values at index.
 * @param [in] object list instance.
 * @param [in] at index of where values are to be inserted.
 * @param [in] other stream of values which are to be inserted.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS if at does not
 * refer to an item contained within the list.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to add the values.
 * @note Each <b>value</b> is copied and then inserted in order.
 */
int butterflyfish_list_wr_insert_all(
        struct butterflyfish_list_wr *object,
        uintmax_t at,
        const struct butterflyfish_stream_wr *other);

/**
 * @brief Insert all the values at item.
 * @param [in] object list instance.
 * @param [in] item where values are to be inserted.
 * @param [in] other stream of values which are to be inserted.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_ITEM_IS_OUT_OF_BOUNDS if item is not
 * contained within the list.
 * @throws BUTTERFLYFISH_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to add the values.
 * @note Each <b>value</b> is copied and then inserted in order.
 */
int butterflyfish_list_wr_insert_all_item(
        struct butterflyfish_list_wr *object,
        struct triggerfish_weak *item,
        const struct butterflyfish_stream_wr *other);

#endif /* _BUTTERFLYFISH_LIST_WR_H_ */
