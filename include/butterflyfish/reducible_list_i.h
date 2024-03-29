#ifndef _BUTTERFLYFISH_REDUCIBLE_LIST_I_H_
#define _BUTTERFLYFISH_REDUCIBLE_LIST_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "fixed_list_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_FIXED_LIST_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_FIXED_LIST_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_FIXED_LIST_I_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_FIXED_LIST_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_FIXED_LIST_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_FIXED_LIST_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_FIXED_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_FIXED_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_FIXED_LIST_I_ERROR_ITEM_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_FIXED_LIST_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL

struct butterflyfish_reducible_list_i {
    const struct butterflyfish_fixed_list_i fixed_list_i;

    int (*const remove)(void *object,
                        uintmax_t at);

    int (*const remove_item)(void *object,
                             const struct sea_turtle_integer *item);

    int (*const remove_all_items)(void *object,
                                  const struct butterflyfish_stream_i *other);
};

/**
 * @brief Return reducible list as a stream.
 * @param [in] object reducible list instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_reducible_list_i_as_stream(
        const struct butterflyfish_reducible_list_i *object,
        const struct butterflyfish_stream_i **out);

/**
 * @brief Return reducible list as a collection.
 * @param [in] object reducible list instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_reducible_list_i_as_collection(
        const struct butterflyfish_reducible_list_i *object,
        const struct butterflyfish_collection_i **out);

/**
 * @brief Return reducible list as a fixed list.
 * @param [in] object reducible list instance.
 * @param [out] out receive fixed list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_reducible_list_i_as_fixed_list(
        struct butterflyfish_reducible_list_i *object,
        struct butterflyfish_fixed_list_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL if out is 
 * <i>NULL</i>.
 */
int butterflyfish_reducible_list_i_count(
        const struct butterflyfish_reducible_list_i *object,
        uintmax_t *out);

/**
 * @brief First item of the reducible list.
 * @param [in] object reducible list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL if out is 
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_LIST_IS_EMPTY if reducible
 * list is empty.
 */
int butterflyfish_reducible_list_i_first(
        const struct butterflyfish_reducible_list_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Last item of the reducible list.
 * @param [in] object reducible list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_LIST_IS_EMPTY if reducible
 * list is empty.
 */
int butterflyfish_reducible_list_i_last(
        const struct butterflyfish_reducible_list_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve next item.
 * @param [in] object reducible list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_reducible_list_i_next(
        const struct butterflyfish_reducible_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object reducible list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_reducible_list_i_prev(
        const struct butterflyfish_reducible_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve item at index.
 * @param [in] object reducible list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the reducible list.
 */
int butterflyfish_reducible_list_i_get(
        const struct butterflyfish_reducible_list_i *object,
        uintmax_t at,
        const struct sea_turtle_integer **out);

/**
 * @brief Set value of item at index.
 * @param [in] object reducible list instance.
 * @param [in] at index of item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the reducible list.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to set the item to value.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_VALUE_IS_INVALID if value is
 * invalid.
 * @note <b>value</b> is copied and then item at index is set to it.
 */
int butterflyfish_reducible_list_i_set(
        struct butterflyfish_reducible_list_i *object,
        uintmax_t at,
        const struct sea_turtle_integer *value);

/**
 * @brief Set value of item.
 * @param [in] object reducible list instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to set the item to value.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_VALUE_IS_INVALID if value is
 * invalid.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_reducible_list_i_set_item(
        struct butterflyfish_reducible_list_i *object,
        struct sea_turtle_integer *item,
        const struct sea_turtle_integer *value);

/**
 * @brief Get index of item.
 * @param [in] object reducible list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_OUT_OF_BOUNDS if item
 * is not contained within the reducible list.
 */
int butterflyfish_reducible_list_i_at(
        const struct butterflyfish_reducible_list_i *object,
        const struct sea_turtle_integer *item,
        uintmax_t *out);

/**
 * @brief Remove item at index.
 * @param [in] object reducible list instance.
 * @param [in] at index of item to remove.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the reducible list.
 */
int butterflyfish_reducible_list_i_remove(
        struct butterflyfish_reducible_list_i *object,
        uintmax_t at);

/**
 * @brief Remove item.
 * @param [in] object reducible list instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 */
int butterflyfish_reducible_list_i_remove_item(
        struct butterflyfish_reducible_list_i *object,
        const struct sea_turtle_integer *item);

/**
 * @brief Remove all items.
 * @param [in] object reducible list instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 */
int butterflyfish_reducible_list_i_remove_all_items(
        struct butterflyfish_reducible_list_i *object,
        const struct butterflyfish_stream_i *other);

#endif /* _BUTTERFLYFISH_REDUCIBLE_LIST_I_H_ */
