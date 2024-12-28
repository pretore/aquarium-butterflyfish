#ifndef _BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_H_
#define _BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "insertable_i_i.h"
#include "ordered_list_i_i.h"
#include "incremental_list_i_i.h"

struct butterflyfish_map_i_i_entry;

#define BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_INSERTABLE_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_INSERTABLE_I_I_ERROR_INSERTABLE_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_INSERTABLE_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_INSERTABLE_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_INSERTABLE_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_INSERTABLE_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_INSERTABLE_I_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_LIST_I_I_ERROR_ITEM_NOT_FOUND

struct butterflyfish_ordered_incremental_list_i_i {
    const struct butterflyfish_stream_i_i *const as_stream;
    const struct butterflyfish_collection_i_i *const as_collection;
    const struct butterflyfish_ordered_i_i *const as_ordered;
    const struct butterflyfish_addable_i_i *const as_addable;
    const struct butterflyfish_insertable_i_i *const as_insertable;
    const struct butterflyfish_list_i_i *const as_list;
    const struct butterflyfish_ordered_list_i_i *const as_ordered_list;
    const struct butterflyfish_incremental_list_i_i *const as_incremental_list;

    /**
     * @brief Retrieve the count of items.
     * @param [in] object instance whose count we are to retrieve.
     * @param [out] out receive the count.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     */
    int (*const count)(const void *object, uintmax_t *out);

    /**
     * @brief First item of the list.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_LIST_IS_EMPTY
     * if list is empty.
     */
    int (*const first)(const void *object,
                       const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Last item of the list.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_LIST_IS_EMPTY
     * if list is empty.
     */
    int (*const last)(const void *object,
                      const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Retrieve next item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the next item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL
     * if item is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_END_OF_SEQUENCE
     * if there is no next item.
     */
    int (*const next)(const void *object,
                      const struct butterflyfish_map_i_i_entry *item,
                      const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Retrieve the previous item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the previous item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL
     * if item is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_END_OF_SEQUENCE
     * if there is no previous item.
     */
    int (*const prev)(const void *object,
                      const struct butterflyfish_map_i_i_entry *item,
                      const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Retrieve item at index.
     * @param [in] object instance.
     * @param [in] at index of item to retrieve.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
     * if at does not refer to an item contained within the list.
     */
    int (*const get)(const void *object,
                     uintmax_t at,
                     const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Get index of item.
     * @param [in] object instance.
     * @param [in] item whose index we are to determine.
     * @param [out] out receive index of item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL
     * if item is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_ITEM_NOT_FOUND
     * if item is not contained within the list.
     */
    int (*const at)(const void *object,
                    const struct butterflyfish_map_i_i_entry *item,
                    uintmax_t *out);

    /**
     * @brief Add value.
     * @param [in] object instance.
     * @param [in] value to be added.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL
     * if value is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_VALUE_ALREADY_EXISTS
     * if value is already present.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_INVALID
     * if value is invalid.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to add value.
     * @note <b>value</b> is copied.
     */
    int (*const add)(void *object,
                     const struct butterflyfish_map_i_i_entry *value);

    /**
     * @brief Insert value into the insertable.
     * @param [in] object instance.
     * @param [in] item where value is to be inserted.
     * @param [in] value to be added.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL
     * if item is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL
     * if value is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_VALUE_ALREADY_EXISTS
     * if value is already present.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_INVALID
     * if value is invalid.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to add value to the insertable.
     * @note <b>value</b> is copied and then placed into the insertable.
     */
    int (*const insert)(void *object,
                        const struct butterflyfish_map_i_i_entry *item,
                        const struct butterflyfish_map_i_i_entry *value);

};

#endif /* _BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_I_H_ */
