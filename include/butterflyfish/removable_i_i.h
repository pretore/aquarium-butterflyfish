#ifndef _BUTTERFLYFISH_REMOVABLE_I_I_H_
#define _BUTTERFLYFISH_REMOVABLE_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_i_i.h"

struct butterflyfish_map_i_i_entry;

#define BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_REMOVABLE_I_I_ERROR_REMOVABLE_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_REMOVABLE_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_REMOVABLE_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL

struct butterflyfish_removable_i_i {
    int (*const as_collection)(const struct butterflyfish_removable_i_i *object,
                               const struct butterflyfish_collection_i_i **out);

    int (*const remove_item)(struct butterflyfish_removable_i_i *object,
                             const struct butterflyfish_map_i_i_entry *item);

    int (*const remove_all_items)(struct butterflyfish_removable_i_i *object,
                                  const struct butterflyfish_stream_i_i *other);
};

/**
 * @brief Return removable as a stream.
 * @param [in] object removable instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_removable_i_i_as_stream(
        const struct butterflyfish_removable_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return removable as a collection.
 * @param [in] object removable instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_removable_i_i_as_collection(
        const struct butterflyfish_removable_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_removable_i_i_count(
        const struct butterflyfish_removable_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the removable.
 * @param [in] object removable instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_REMOVABLE_IS_EMPTY if removable is
 * empty.
 */
int butterflyfish_removable_i_i_first(
        const struct butterflyfish_removable_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the removable.
 * @param [in] object removable instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_REMOVABLE_IS_EMPTY if removable is
 * empty.
 */
int butterflyfish_removable_i_i_last(
        const struct butterflyfish_removable_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object removable instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_removable_i_i_next(
        const struct butterflyfish_removable_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object removable instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_removable_i_i_prev(
        const struct butterflyfish_removable_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Remove item.
 * @param [in] object removable instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @note <b>item</b> is invalidated when removed.
 */
int butterflyfish_removable_i_i_remove_item(
        struct butterflyfish_removable_i_i *object,
        const struct butterflyfish_map_i_i_entry *item);

/**
 * @brief Remove all items.
 * @param [in] object removable instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REMOVABLE_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @note streamed items within <b>other</b> is invalidated when removed.
 */
int butterflyfish_removable_i_i_remove_all_items(
        struct butterflyfish_removable_i_i *object,
        const struct butterflyfish_stream_i_i *other);

#endif /* _BUTTERFLYFISH_REMOVABLE_I_I_H_ */
