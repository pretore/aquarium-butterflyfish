#ifndef _BUTTERFLYFISH_FIXED_LIST_WR_H_
#define _BUTTERFLYFISH_FIXED_LIST_WR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_wr.h"

struct triggerfish_weak;

#define BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_WR_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_WR_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_FIXED_LIST_WR_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_WR_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_WR_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_FIXED_LIST_WR_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_WR_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_FIXED_LIST_WR_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_FIXED_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_FIXED_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    SEA_URCHIN_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_OUT_OF_BOUNDS \
    SEA_URCHIN_ERROR_ITEM_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_FIXED_LIST_WR_ERROR_VALUE_IS_INVALID \
    SEA_URCHIN_ERROR_VALUE_IS_INVALID

struct butterflyfish_fixed_list_wr {
    const struct butterflyfish_collection_wr collection_wr;

    int (*const get)(const void *object,
                     uintmax_t at,
                     const struct triggerfish_weak **out);

    int (*const set)(void *object,
                     uintmax_t at,
                     const struct triggerfish_weak *value);

    int (*const set_item)(void *object,
                          struct triggerfish_weak *item,
                          const struct triggerfish_weak *value);

    int (*const at)(const void *object,
                    const struct triggerfish_weak *item,
                    uintmax_t *out);
};

/**
 * @brief Return fixed list as a stream.
 * @param [in] object fixed list instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_fixed_list_wr_as_stream(
        const struct butterflyfish_fixed_list_wr *object,
        const struct butterflyfish_stream_wr **out);

/**
 * @brief Return fixed list as a collection.
 * @param [in] object fixed list instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_fixed_list_wr_as_collection(
        const struct butterflyfish_fixed_list_wr *object,
        const struct butterflyfish_collection_wr **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL if object is 
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_fixed_list_wr_count(
        const struct butterflyfish_fixed_list_wr *object,
        uintmax_t *out);

/**
 * @brief First item of the fixed list.
 * @param [in] object fixed list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL if object is 
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_LIST_IS_EMPTY if fixed list is
 * empty.
 */
int butterflyfish_fixed_list_wr_first(
        const struct butterflyfish_fixed_list_wr *object,
        const struct triggerfish_weak **out);

/**
 * @brief Last item of the fixed list.
 * @param [in] object fixed list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_LIST_IS_EMPTY if fixed list
 * is empty.
 */
int butterflyfish_fixed_list_wr_last(
        const struct butterflyfish_fixed_list_wr *object,
        const struct triggerfish_weak **out);

/**
 * @brief Retrieve next item.
 * @param [in] object fixed list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_fixed_list_wr_next(
        const struct butterflyfish_fixed_list_wr *object,
        const struct triggerfish_weak *item,
        const struct triggerfish_weak **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object fixed list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_fixed_list_wr_prev(
        const struct butterflyfish_fixed_list_wr *object,
        const struct triggerfish_weak *item,
        const struct triggerfish_weak **out);

/**
 * @brief Retrieve item at index.
 * @param [in] object fixed list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS if at does
 * not refer to an item contained within the fixed list.
 */
int butterflyfish_fixed_list_wr_get(
        const struct butterflyfish_fixed_list_wr *object,
        uintmax_t at,
        const struct triggerfish_weak **out);

/**
 * @brief Set value of item at index.
 * @param [in] object fixed list instance.
 * @param [in] at index of item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS if at does
 * not refer to an item contained within the fixed list.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is not enough memory to set the item to value.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_VALUE_IS_INVALID if value is
 * invalid.
 * @note <b>value</b> is copied and then item at index is set to it.
 */
int butterflyfish_fixed_list_wr_set(
        struct butterflyfish_fixed_list_wr *object,
        uintmax_t at,
        const struct triggerfish_weak *value);

/**
 * @brief Set value of item.
 * @param [in] object fixed list instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is not enough memory to set the item to value.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_VALUE_IS_INVALID if value is
 * invalid.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_fixed_list_wr_set_item(
        struct butterflyfish_fixed_list_wr *object,
        struct triggerfish_weak *item,
        const struct triggerfish_weak *value);

/**
 * @brief Get index of item.
 * @param [in] object fixed list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_OUT_OF_BOUNDS if item is
 * not contained within the fixed list.
 */
int butterflyfish_fixed_list_wr_at(
        const struct butterflyfish_fixed_list_wr *object,
        const struct triggerfish_weak *item,
        uintmax_t *out);

#endif /* _BUTTERFLYFISH_FIXED_LIST_WR_H_ */
