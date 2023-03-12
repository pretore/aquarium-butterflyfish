#ifndef _BUTTERFLYFISH_REDUCIBLE_LIST_SR_H_
#define _BUTTERFLYFISH_REDUCIBLE_LIST_SR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "fixed_list_sr.h"

struct triggerfish_strong;

#define BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_FIXED_LIST_SR_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_FIXED_LIST_SR_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_FIXED_LIST_SR_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_FIXED_LIST_SR_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_FIXED_LIST_SR_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_FIXED_LIST_SR_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_ITEM_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_FIXED_LIST_SR_ERROR_ITEM_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL

struct butterflyfish_reducible_list_sr {
    const struct butterflyfish_fixed_list_sr fixed_list_sr;

    int (*const remove)(void *object,
                        uintmax_t at);

    int (*const remove_item)(void *object,
                             struct triggerfish_strong *item);

    int (*const remove_all_items)(void *object,
                                  const struct butterflyfish_stream_sr *other);
};

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OUT_IS_NULL if out is 
 * <i>NULL</i>.
 */
int butterflyfish_reducible_list_sr_count(
        const struct butterflyfish_reducible_list_sr *object,
        uintmax_t *out);

/**
 * @brief First item of the reducible list.
 * @param [in] object reducible list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OUT_IS_NULL if out is 
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_LIST_IS_EMPTY if reducible
 * list is empty.
 */
int butterflyfish_reducible_list_sr_first(
        const struct butterflyfish_reducible_list_sr *object,
        struct triggerfish_strong **out);

/**
 * @brief Last item of the reducible list.
 * @param [in] object reducible list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_LIST_IS_EMPTY if reducible
 * list is empty.
 */
int butterflyfish_reducible_list_sr_last(
        const struct butterflyfish_reducible_list_sr *object,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve next item.
 * @param [in] object reducible list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_reducible_list_sr_next(
        const struct butterflyfish_reducible_list_sr *object,
        const struct triggerfish_strong *item,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object reducible list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_reducible_list_sr_prev(
        const struct butterflyfish_reducible_list_sr *object,
        const struct triggerfish_strong *item,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve item at index.
 * @param [in] object reducible list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the reducible list.
 */
int butterflyfish_reducible_list_sr_get(
        const struct butterflyfish_reducible_list_sr *object,
        uintmax_t at,
        struct triggerfish_strong **out);

/**
 * @brief Set value of item at index.
 * @param [in] object reducible list instance.
 * @param [in] at index of item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the reducible list.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to set the item to value.
 */
int butterflyfish_reducible_list_sr_set(
        struct butterflyfish_reducible_list_sr *object,
        uintmax_t at,
        struct triggerfish_strong *value);

/**
 * @brief Get index of item.
 * @param [in] object reducible list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_ITEM_IS_OUT_OF_BOUNDS if item
 * is not contained within the reducible list.
 */
int butterflyfish_reducible_list_sr_at(
        const struct butterflyfish_reducible_list_sr *object,
        const struct triggerfish_strong *item,
        uintmax_t *out);

/**
 * @brief Remove item at index.
 * @param [in] object reducible list instance.
 * @param [in] at index of item to remove.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the reducible list.
 */
int butterflyfish_reducible_list_sr_remove(
        struct butterflyfish_reducible_list_sr *object,
        uintmax_t at);

/**
 * @brief Remove item.
 * @param [in] object reducible list instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the reducible list.
 */
int butterflyfish_reducible_list_sr_remove_item(
        struct butterflyfish_reducible_list_sr *object,
        struct triggerfish_strong *item);

/**
 * @brief Remove all items.
 * @param [in] object reducible list instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_LIST_SR_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 */
int butterflyfish_reducible_list_sr_remove_all_items(
        struct butterflyfish_reducible_list_sr *object,
        const struct butterflyfish_stream_sr *other);

#endif /* _BUTTERFLYFISH_REDUCIBLE_LIST_SR_H_ */
