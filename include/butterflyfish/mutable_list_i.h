#ifndef _BUTTERFLYFISH_MUTABLE_LIST_I_H_
#define _BUTTERFLYFISH_MUTABLE_LIST_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "settable_incremental_list_i.h"
#include "settable_reducible_list_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_INVALID

struct butterflyfish_mutable_list_i {
    const struct butterflyfish_stream_i *const as_stream;
    const struct butterflyfish_collection_i *const as_collection;
    const struct butterflyfish_list_i *const as_list;
    const struct butterflyfish_settable_i *const as_settable;
    const struct butterflyfish_addable_i *const as_addable;
    const struct butterflyfish_removable_i *const as_removable;
    const struct butterflyfish_reducible_list_i *const as_reducible_list;
    const struct butterflyfish_settable_list_i *const as_settable_list;
    const struct butterflyfish_incremental_list_i *const as_incremental_list;
    const struct butterflyfish_settable_incremental_list_i *const
            as_settable_incremental_list;
    const struct butterflyfish_settable_reducible_list_i *const
            as_settable_reducible_list;

    /**
     * @brief Retrieve the count of items.
     * @param [in] object instance whose count we are to retrieve.
     * @param [out] out receive the count.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     */
    int (*const count)(const void *object, uintmax_t *out);

    /**
     * @brief First item of the list.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_LIST_IS_EMPTY if list is
     * empty.
     */
    int (*const first)(const void *object,
                       const struct sea_turtle_integer **out);

    /**
     * @brief Last item of the list.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_LIST_IS_EMPTY if list is
     * empty.
     */
    int (*const last)(const void *object,
                      const struct sea_turtle_integer **out);

    /**
     * @brief Retrieve next item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the next item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_END_OF_SEQUENCE if there is
     * no next item.
     */
    int (*const next)(const void *object,
                      const struct sea_turtle_integer *item,
                      const struct sea_turtle_integer **out);

    /**
     * @brief Retrieve the previous item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the previous item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_END_OF_SEQUENCE if there is
     * no previous item.
     */
    int (*const prev)(const void *object,
                      const struct sea_turtle_integer *item,
                      const struct sea_turtle_integer **out);

    /**
     * @brief Retrieve item at index.
     * @param [in] object instance.
     * @param [in] at index of item to retrieve.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
     * if at does not refer to an item contained within the list.
     */
    int (*const get)(const void *object,
                     uintmax_t at,
                     const struct sea_turtle_integer **out);

    /**
     * @brief Get index of item.
     * @param [in] object instance.
     * @param [in] item whose index we are to determine.
     * @param [out] out receive index of item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_ITEM_NOT_FOUND if item is
     * not contained within the list.
     */
    int (*const at)(const void *object,
                    const struct sea_turtle_integer *item,
                    uintmax_t *out);

    /**
     * @brief Set value for item.
     * @param [in] object instance.
     * @param [in] item to set.
     * @param [in] value to which item is to be set to.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_VALUE_IS_INVALID if value
     * is invalid.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_VALUE_ALREADY_EXISTS if
     * value is already present.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is not enough memory to set the item to value.
     * @note <b>value</b> is copied and then item is set to it.
     */
    int (*const set_item)(void *object,
                          const struct sea_turtle_integer *item,
                          const struct sea_turtle_integer *value);

    /**
     * @brief Set value of item at index.
     * @param [in] object instance.
     * @param [in] at index of item to set.
     * @param [in] value to which item is to be set to.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if
     * at does not refer to an item contained within the list.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is not enough memory to set the item to value.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_VALUE_IS_INVALID
     * if value is invalid.
     * @note <b>value</b> is copied and then item at index is set to it.
     */
    int (*const set)(void *object,
                     uintmax_t at,
                     const struct sea_turtle_integer *value);

    /**
     * @brief Add value.
     * @param [in] object instance.
     * @param [in] value to be added.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_VALUE_ALREADY_EXISTS if
     * value is already present.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_VALUE_IS_INVALID if value
     * is invalid.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to add value.
     * @note <b>value</b> is copied.
     */
    int (*const add)(void *object,
                     const struct sea_turtle_integer *value);

    /**
     * @brief Remove item.
     * @param [in] object instance.
     * @param [in] item to be removed.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @note <b>item</b> is invalidated when removed.
     */
    int (*const remove_item)(void *object,
                             const struct sea_turtle_integer *item);

    /**
     * @brief Remove item at index.
     * @param [in] object instance.
     * @param [in] at index of item to remove.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if
     * at does not refer to an item contained within the list.
     */
    int (*const remove)(void *object, uintmax_t at);
};

#endif /* _BUTTERFLYFISH_MUTABLE_LIST_I_H_ */
